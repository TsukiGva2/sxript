$CONSOLE
_DEST _CONSOLE
_SOURCE _CONSOLE
$SCREENHIDE
$CONSOLE:ONLY

'INPUT "Specify Sxript executable: (W)ine, (F)reeBasic, (Q)B64 (W/F/Q): ", TheCompiler$
'TheCompiler$ = LCASE$(TheCompiler$)
'PRINT

TheCompiler$ = "q" 'COMMAND$
TheCompiler$ = LCASE$(TheCompiler$)

IF INSTR(_OS$, "[WINDOWS]") THEN
    SHELL "DIR  /b /a-d *.txt" + ">" + "state.tmp"
ELSEIF INSTR(_OS$, "[MACOSX]") THEN
    SHELL "ls *.txt" + ">" + "state.tmp"
ELSEIF INSTR(_OS$, "[LINUX]") THEN
    SHELL "ls *.txt" + ">" + "state.tmp"
END IF

NumOfFiles = 0
DIM TheInputArray$(9999)

OPEN "state.tmp" FOR INPUT AS #1
DO UNTIL EOF(1)
    LINE INPUT #1, a$
    'PRINT a$
    IF ((INSTR(a$, "-test.txt") <> 0) AND (INSTR(a$, ".txt~") = 0)) THEN
        NumOfFiles = NumOfFiles + 1
        TheInputArray$(NumOfFiles) = a$
    END IF
LOOP
CLOSE #1

CHDIR "../bin/"

'IF INSTR(_OS$, "[WINDOWS]") THEN
'    CHDIR "..\bin\"
'ELSEIF INSTR(_OS$, "[MACOSX]") THEN
'    CHDIR "../bin/"
'ELSEIF INSTR(_OS$, "[LINUX]") THEN
'    CHDIR "../bin/"
'END IF

PRINT "Your OS: " + _OS$
PRINT "Number of test files:"; NumOfFiles

FOR k = 1 TO NumOfFiles
    PRINT "Running " + TheInputArray$(k) + "..." + "(" + TheCompiler$ + ")"
    IF INSTR(_OS$, "[WINDOWS]") THEN
        IF (TheCompiler$ = "f") THEN SHELL "sxriptfb 'exe(`..\\test\\" + TheInputArray$(k) + "')"
        IF (TheCompiler$ = "q") THEN SHELL "sxript exe(`..\\test\\" + TheInputArray$(k) + "')"
    ELSEIF INSTR(_OS$, "[MACOSX]") THEN
        IF (TheCompiler$ = "f") THEN SHELL "./sxriptfb 'exe(../test/" + TheInputArray$(k) + ")'"
        IF (TheCompiler$ = "q") THEN SHELL "./sxript 'exe(../test/" + TheInputArray$(k) + ")'"
    ELSEIF INSTR(_OS$, "[LINUX]") THEN
        IF (TheCompiler$ = "w") THEN SHELL "wine sxript.exe 'exe(`../test/" + TheInputArray$(k) + "'\'')'"
        IF (TheCompiler$ = "f") THEN SHELL "./sxriptfb 'exe(`../test/" + TheInputArray$(k) + "'\'')'"
        IF (TheCompiler$ = "q") THEN SHELL "./sxript 'exe(`../test/" + TheInputArray$(k) + "'\'')'"
        IF (TheCompiler$ = "c") THEN SHELL "./sxriptcpp 'exe(`../test/" + TheInputArray$(k) + "'\'')'"
    END IF
NEXT

SYSTEM
