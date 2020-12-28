$CONSOLE
_DEST _CONSOLE
_SOURCE _CONSOLE
$SCREENHIDE
$CONSOLE:ONLY

DIM LineList(10000) AS STRING
CmdNum = _COMMANDCOUNT

PRINT "Combining files..."
k = 0

FOR j = 1 TO CmdNum - 1
    OPEN COMMAND$(j) FOR INPUT AS #1
    k = k + 1
    LineList(k) = "' BEGIN " + COMMAND$(j)
    DO WHILE NOT EOF(1)
        LINE INPUT #1, a$
        k = k + 1
        LineList(k) = a$
    LOOP
    CLOSE #1
    k = k + 1
    LineList(k) = ""
NEXT

OPEN COMMAND$(CmdNum) FOR OUTPUT AS #1
FOR n = 1 TO k
    PRINT #1, LineList(n)
NEXT
CLOSE #1

SYSTEM
'END

