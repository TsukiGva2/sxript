$CONSOLE
_DEST _CONSOLE
_SOURCE _CONSOLE
$SCREENHIDE
$CONSOLE:ONLY

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

DIM TheMode AS STRING
TheMode = COMMAND$ '"CPP"

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

DIM TheFileIn AS STRING
DIM TheFileOut AS STRING
TheFileIn = "sxriptcomb.bas"
IF (TheMode = "CPP") THEN
    TheFileOut = "sxript.h"
END IF
IF (TheMode = "JavaScript") THEN
    TheFileOut = "sxript.js"
END IF
PRINT "Converting "; TheFileIn; " into "; TheFileOut; "..."
DIM InputFileLines$(50000)
DIM NumInputLines

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
' Global declarations and initializations
' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

DIM SHARED FuncList(1000) AS STRING
DIM SHARED FunctionListPop AS INTEGER
FunctionListPop = 0

CALL AddKeyword("ABS")
CALL AddKeyword("ASC")
CALL AddKeyword("CHR$")
CALL AddKeyword("INSTR")
CALL AddKeyword("INT")
CALL AddKeyword("LCASE$")
CALL AddKeyword("LEFT$")
CALL AddKeyword("LEN")
CALL AddKeyword("LTRIM$")
CALL AddKeyword("MID$")
CALL AddKeyword("RIGHT$")
CALL AddKeyword("RTRIM$")
CALL AddKeyword("SGN")
CALL AddKeyword("SQR")
CALL AddKeyword("STR$")
CALL AddKeyword("UCASE$")
CALL AddKeyword("VAL")

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FunctionName$ = ""

' ''''''''''

DIM ArrayList$(1000)
DIM ArrayListPop
ArrayListPop = 0

' ''''''''''

DIM LineLeadingSpaces(50000)

' ''''''''''

DIM OutputFileLines$(50000)
DIM NumOutputFileLines

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

IF (TheMode = "CPP") THEN
    startskiptag$ = "CPP: STARTSKIP"
    endskiptag$ = "CPP: ENDSKIP"
END IF
IF (TheMode = "JavaScript") THEN
    startskiptag$ = "JavaScript: STARTSKIP"
    endskiptag$ = "JavaScript: ENDSKIP"
END IF

LineCounter = 0
skipflag = 0
OPEN TheFileIn FOR INPUT AS #1
DO WHILE NOT EOF(1)
    LINE INPUT #1, a$
    IF INSTR(a$, startskiptag$) > 0 THEN
        skipflag = 1
    END IF
    IF skipflag = 0 THEN
        LineCounter = LineCounter + 1
        InputFileLines$(LineCounter) = a$
    END IF
    IF INSTR(a$, endskiptag$) > 0 THEN skipflag = 0
LOOP
CLOSE #1
NumInputLines = LineCounter

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FOR k = 1 TO NumInputLines
    a$ = InputFileLines$(k)
    IF a$ = "" THEN
        LineLeadingSpaces(k) = 0
    ELSE
        b$ = LTRIM$(a$)
        LineLeadingSpaces(k) = LEN(a$) - LEN(b$)
        InputFileLines$(k) = b$
    END IF
NEXT

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
' Deal with FUNCTION definitions.

FOR k = 1 TO NumInputLines
    a$ = InputFileLines$(k)

    Temp$ = ""

    IF Temp$ = "" THEN
        key$ = "FUNCTION"
        IF LEFT$(a$, LEN(key$)) = key$ THEN

            ' Pick out the function name and add it to the function array.
            nleft = INSTR(a$, " ") + 1
            nright = INSTR(a$, "(") - 1
            FunctionName$ = MID$(a$, nleft, nright - nleft)
            FunctionNameOrig$ = FunctionName$
            CALL AddKeyword(FunctionNameOrig$)

            ' Step through list of arguments.
            a$ = RIGHT$(a$, LEN(a$) - LEN("FUNCTION ") - LEN(FunctionName$))
            a$ = LTRIM$(RTRIM$(a$))
            n = CountElements(a$, ",")
            c$ = "("
            FOR j = 1 TO n
                b$ = ReturnElement$(a$, j)
                b$ = RemoveWrapping$(b$, "()")
                b$ = LTRIM$(RTRIM$(b$))
                IF (TheMode = "CPP") THEN
                    b$ = SuffixToPrefix$(b$, " AS STRING", "std::string ")
                    b$ = SuffixToPrefix$(b$, " AS INTEGER", "int ")
                    b$ = SuffixToPrefix$(b$, " AS DOUBLE", "double ")
                END IF
                IF (TheMode = "JavaScript") THEN
                    b$ = SuffixToPrefix$(b$, " AS STRING", "")
                    b$ = SuffixToPrefix$(b$, " AS INTEGER", "")
                    b$ = SuffixToPrefix$(b$, " AS DOUBLE", "")
                END IF
                c$ = c$ + b$
                IF (j < n) THEN
                    c$ = c$ + ", "
                END IF
            NEXT
            c$ = c$ + ")"

            ' Handle actual function name. (Blank type becomes int in CPP.)
            FunctionName$ = LCASE$(LEFT$(FunctionName$, 1)) + RIGHT$(FunctionName$, LEN(FunctionName$) - 1)
            tmp$ = FunctionName$
            IF (TheMode = "CPP") THEN
                FunctionName$ = SuffixToPrefix$(FunctionName$, "$", "std::string ")
                FunctionName$ = SuffixToPrefix$(FunctionName$, "#", "double ")
            END IF
            IF (TheMode = "JavaScript") THEN
                FunctionName$ = SuffixToPrefix$(FunctionName$, "$", "")
                FunctionName$ = SuffixToPrefix$(FunctionName$, "#", "")
            END IF

            IF (TheMode = "CPP") THEN
                IF (tmp$ = FunctionName$) THEN
                    FunctionName$ = "int " + FunctionName$
                END IF
            END IF
            IF (TheMode = "JavaScript") THEN
                FunctionName$ = "function " + FunctionName$
            END IF

            IF (TheMode = "CPP") THEN
                a$ = FunctionName$ + " " + c$ + " {"
            END IF
            IF (TheMode = "JavaScript") THEN
                a$ = FunctionName$ + "" + c$ + " {"
            END IF

            InputFileLines$(k) = a$
            Temp$ = "0"
        END IF
    END IF

    IF Temp$ = "" THEN
        IF FunctionNameOrig$ <> "" THEN
            key$ = FunctionNameOrig$ + " ="
            IF LEFT$(a$, LEN(key$)) = key$ THEN
                a$ = ReplaceRaw$(a$, key$, "return")
                InputFileLines$(k) = a$
                Temp$ = ""
            END IF
        END IF
    END IF

    IF Temp$ = "" THEN
        key$ = "END FUNCTION"
        IF LEFT$(a$, LEN(key$)) = key$ THEN
            FunctionNameOrig$ = ""
            b$ = RIGHT$(a$, LEN(a$) - LEN(key$))
            b$ = "}" + b$
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF
    END IF

    IF Temp$ = "" AND FunctionNameOrig$ <> "" AND a$ <> "" THEN
        LineLeadingSpaces(k) = LineLeadingSpaces(k) + 4
    END IF

NEXT

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FOR k = 1 TO NumInputLines

    Temp$ = ""

    a$ = InputFileLines$(k)

    IF (Temp$ = "") AND (LEFT$(a$, 5) = "PRINT") THEN
        b$ = "// " + a$
        InputFileLines$(k) = b$
        Temp$ = "1"
    END IF

    IF (Temp$ = "") AND (LEFT$(a$, 3) = "'\\") THEN
        b$ = RIGHT$(a$, LEN(a$) - 3)
        b$ = "" + b$
        InputFileLines$(k) = b$
        Temp$ = "1"
    END IF

    IF (Temp$ = "") AND (LEFT$(a$, 1) = "'") THEN
        b$ = RIGHT$(a$, LEN(a$) - 1)
        b$ = "//" + b$
        InputFileLines$(k) = b$
        Temp$ = "1"
    END IF

    IF (Temp$ = "") AND (LEFT$(a$, 3) = "REM") THEN
        b$ = RIGHT$(a$, LEN(a$) - 3)
        b$ = "//" + b$
        InputFileLines$(k) = b$
        Temp$ = "1"
    END IF

    IF (Temp$ = "") AND (LEFT$(a$, 7) = "DECLARE") THEN
        b$ = RIGHT$(a$, LEN(a$) - 7)
        b$ = "// DECLARE" + b$ + ";"
        InputFileLines$(k) = b$
        Temp$ = "1"
    END IF

NEXT

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FOR k = 1 TO NumInputLines
    a$ = InputFileLines$(k)

    IF LEFT$(a$, 2) <> "//" THEN

        Temp$ = ""

        a$ = ReplaceRaw$(a$, "CHR$(9)", CHR$(34) + "\t" + CHR$(34))
        a$ = ReplaceRaw$(a$, "CHR$(10)", CHR$(34) + "\n" + CHR$(34))
        a$ = ReplaceRaw$(a$, "CHR$(13)", CHR$(34) + "\r" + CHR$(34))
        a$ = ReplaceRaw$(a$, "MOD", "%")

        IF (TheMode = "CPP") THEN
            a$ = ReplaceRaw$(a$, "RND *", "rand() %")
            a$ = ReplaceRaw$(a$, "COS(", "cos(")
            a$ = ReplaceRaw$(a$, "SIN(", "sin(")
            a$ = ReplaceRaw$(a$, "TAN(", "tan(")
            a$ = ReplaceRaw$(a$, "ATN(", "atan(")
        END IF
        IF (TheMode = "JavaScript") THEN
            a$ = ReplaceRaw$(a$, "RND", "Math.random()")
            a$ = ReplaceRaw$(a$, " COS(", " Math.cos(")
            a$ = ReplaceRaw$(a$, " SIN(", " Math.sin(")
            a$ = ReplaceRaw$(a$, " TAN(", " Math.tan(")
            a$ = ReplaceRaw$(a$, " ATN(", " Math.atan(")
        END IF

        a$ = ReplaceRaw$(a$, CHR$(34) + "\" + CHR$(34), CHR$(34) + "\\" + CHR$(34))

        'IF (Temp$ = "") AND LEFT$(a$, 5) = "CONST" THEN
        '    b$ = RIGHT$(a$, LEN(a$) - 5)
        '    b$ = "var" + b$ + ";"
        '    InputFileLines$(k) = b$
        '    Temp$ = "1"
        'END IF

        IF (Temp$ = "") AND LEFT$(a$, 4) = "DIM " THEN
            b$ = RIGHT$(a$, LEN(a$) - 4)
            b$ = ReplaceRaw$(b$, "SHARED ", "")
            c = INSTR(b$, "(")
            IF c > 0 THEN
                ArrayListPop = ArrayListPop + 1
                ArrayList$(ArrayListPop) = LTRIM$(RTRIM$(LEFT$(b$, c - 1)))

                IF (TheMode = "CPP") THEN
                    b$ = ReplaceRaw$(b$, "(", "[")
                    b$ = ReplaceRaw$(b$, ")", "]")
                    b$ = ReplaceRaw$(b$, ", ", "][")
                END IF
                IF (TheMode = "JavaScript") THEN
                    b$ = LEFT$(b$, c - 1) + " = [undefined]"
                END IF

            END IF
            b$ = ReplaceRaw$(b$, "$", "")

            IF (TheMode = "CPP") THEN
                b$ = SuffixToPrefix$(b$, " AS STRING", "std::string ")
                b$ = SuffixToPrefix$(b$, " AS INTEGER", "int ")
                b$ = SuffixToPrefix$(b$, " AS DOUBLE", "double ")
                b$ = "" + b$ + ";"
            END IF
            IF (TheMode = "JavaScript") THEN
                b$ = SuffixToPrefix$(b$, " AS STRING", "")
                b$ = SuffixToPrefix$(b$, " AS INTEGER", "")
                b$ = SuffixToPrefix$(b$, " AS DOUBLE", "")
                b$ = "var " + b$ + ";"
            END IF

            InputFileLines$(k) = b$
            Temp$ = "1"
        END IF

        IF Temp$ = "" THEN
            b$ = a$
            keeplookingforarray:
            FOR j = 1 TO ArrayListPop
                c = INSTR(b$, ArrayList$(j) + "(")
                IF c > 0 THEN
                    g$ = LEFT$(b$, c + LEN(ArrayList$(j)) - 1)
                    h$ = RIGHT$(a$, LEN(b$) - LEN(g$))
                    d = INSTR(h$, ")")
                    p$ = LEFT$(h$, d)
                    w$ = RIGHT$(h$, LEN(h$) - LEN(p$))
                    x = CountElements(p$, ",")
                    r$ = ""
                    FOR m = 1 TO x
                        r$ = r$ + "[" + LTRIM$(RTRIM$(RemoveWrapping$(ReturnElement$(p$, m), "()"))) + "]"
                    NEXT
                    b$ = g$ + r$ + w$
                    GOTO keeplookingforarray
                END IF
            NEXT
            a$ = b$
            InputFileLines$(k) = b$
            Temp$ = ""
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 2) = "IF" THEN
            b$ = RIGHT$(a$, LEN(a$) - 2)
            b$ = "if" + b$

            IF (TheMode = "CPP") THEN
                b$ = ReplaceRaw$(b$, " AND ", " & ")
                b$ = ReplaceRaw$(b$, " OR ", " | ")
                b$ = ReplaceRaw$(b$, " = ", " == ")
                b$ = ReplaceRaw$(b$, " <> ", " != ")
            END IF
            IF (TheMode = "JavaScript") THEN
                b$ = ReplaceRaw$(b$, " AND ", " && ")
                b$ = ReplaceRaw$(b$, " OR ", " || ")
                b$ = ReplaceRaw$(b$, " = ", " === ")
                b$ = ReplaceRaw$(b$, " <> ", " !== ")
            END IF

            b$ = ReplaceRaw$(b$, "THEN", "{")
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 4) = "ELSE" THEN
            b$ = RIGHT$(a$, LEN(a$) - 4)
            b$ = "} else {"
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 6) = "END IF" THEN
            b$ = RIGHT$(a$, LEN(a$) - 6)
            b$ = "}" + b$
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 4) = "FOR " THEN
            b$ = RIGHT$(a$, LEN(a$) - LEN("FOR "))
            equalpos = INSTR(b$, " = ")
            thevar$ = LEFT$(b$, equalpos - 1)
            b$ = RIGHT$(b$, LEN(b$) - LEN(thevar$) - LEN(" = "))
            topos = INSTR(b$, " TO ")
            thefirstnum$ = LEFT$(b$, topos - 1)
            b$ = RIGHT$(b$, LEN(b$) - LEN(thefirstnum$) - LEN(" TO "))
            steppos = INSTR(b$, " STEP ")
            IF steppos > 0 THEN
                thestepfactor$ = RIGHT$(b$, LEN(b$) - INSTR(b$, " STEP ") - LEN(" STEP ") + 1)
                b$ = LEFT$(b$, LEN(b$) - LEN(thestepfactor$) - LEN(" STEP "))
                thesecondnum$ = b$
                IF LEFT$(thestepfactor$, 1) = "-" THEN
                    b$ = "for (" + thevar$ + " = " + thefirstnum$ + "; " + thevar$ + " >= " + thesecondnum$ + "; " + thevar$ + " += (" + thestepfactor$ + ")) {"
                ELSE
                    b$ = "for (" + thevar$ + " = " + thefirstnum$ + "; " + thevar$ + " <= " + thesecondnum$ + "; " + thevar$ + " += (" + thestepfactor$ + ")) {"
                END IF
            ELSE
                thesecondnum$ = b$
                b$ = "for (" + thevar$ + " = " + thefirstnum$ + "; " + thevar$ + " <= " + thesecondnum$ + "; " + thevar$ + " += 1) {"
            END IF
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 8) = "EXIT FOR" THEN
            b$ = RIGHT$(a$, LEN(a$) - 8)
            b$ = "break;"
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 3) = "DO " THEN
            b$ = RIGHT$(a$, LEN(a$) - 3)

            IF (TheMode = "CPP") THEN
                b$ = ReplaceRaw$(b$, " AND ", " & ")
                b$ = ReplaceRaw$(b$, " OR ", " | ")
                b$ = ReplaceRaw$(b$, " = ", " == ")
                b$ = ReplaceRaw$(b$, " <> ", " != ")
            END IF
            IF (TheMode = "JavaScript") THEN
                b$ = ReplaceRaw$(b$, " AND ", " && ")
                b$ = ReplaceRaw$(b$, " OR ", " || ")
                b$ = ReplaceRaw$(b$, " = ", " === ")
                b$ = ReplaceRaw$(b$, " <> ", " !== ")
            END IF

            b$ = ReplaceRaw$(b$, "WHILE", "while")
            b$ = b$ + " {"
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 7) = "EXIT DO" THEN
            b$ = RIGHT$(a$, LEN(a$) - 7)
            b$ = "break;"
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 4) = "LOOP" THEN
            b$ = RIGHT$(a$, LEN(a$) - 4)
            b$ = "}" + b$
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF (Temp$ = "") AND LEFT$(a$, 4) = "NEXT" THEN
            b$ = RIGHT$(a$, LEN(a$) - 4)
            b$ = "}" + b$
            InputFileLines$(k) = b$
            Temp$ = "0"
        END IF

        IF Temp$ = "" THEN
            a$ = InputFileLines$(k)
            flag = 1
            IF (a$ = "") THEN
                flag = 0
            END IF
            IF (LEFT$(a$, 2) = "//") THEN
                flag = 0
            END IF
            IF (RIGHT$(a$, 1) = "}") THEN
                flag = 0
            END IF
            IF (RIGHT$(a$, 1) = "{") THEN
                flag = 0
            END IF
            IF (RIGHT$(a$, 1) = ",") THEN
                flag = 0
            END IF
            IF (RIGHT$(a$, 1) = ";") THEN
                flag = 0
            END IF
            IF (flag = 1) THEN
                InputFileLines$(k) = InputFileLines$(k) + ";"
            END IF
        END IF

    END IF

NEXT

' ''''''''''

FOR k = 1 TO NumInputLines
    a$ = InputFileLines$(k)
    funcrepl:
    FOR j = 1 TO FunctionListPop
        b$ = FuncList(j)
        c = INSTR(a$, b$ + "(")
        IF c > 0 THEN
            a$ = ReplaceFuncCall$(a$, b$)
            GOTO funcrepl
        END IF
    NEXT
    InputFileLines$(k) = a$
NEXT

' ''''''''''

IF (TheMode = "CPP") THEN
    b$ = ReplaceRaw$(b$, " AND ", " & ")
    b$ = ReplaceRaw$(b$, " OR ", " | ")
    b$ = ReplaceRaw$(b$, " = ", " == ")
    b$ = ReplaceRaw$(b$, " <> ", " != ")
END IF
IF (TheMode = "JavaScript") THEN
    FOR k = 1 TO NumInputLines
        a$ = InputFileLines$(k)
        Temp$ = ""
        IF Temp$ = "" THEN
            IF LEFT$(a$, 9) = "function " THEN
                InputFileLines$(k) = InputFileLines$(k) + CHR$(13) + CHR$(10) + "    " + CHR$(34) + "use strict" + CHR$(34) + ";"
            END IF
        END IF
    NEXT
END IF

' ''''''''''

OPEN TheFileOut FOR OUTPUT AS #1
IF (TheMode = "CPP") THEN
    PRINT #1, "#include " + CHR$(34) + "qbf.h" + CHR$(34)
END IF
IF (TheMode = "JavaScript") THEN
    'PRINT #1, "<script type=" + CHR$(34) + "text/javascript" + CHR$(34) + " src=" + CHR$(34) + "qbf.js" + CHR$(34) + "></script>"
END IF
FOR k = 1 TO NumInputLines
    a$ = ""
    b$ = ""
    c$ = ""
    FOR w = 1 TO LineLeadingSpaces(k)
        a$ = " " + a$
    NEXT
    b$ = InputFileLines$(k)
    c$ = a$ + b$
    PRINT #1, c$
NEXT
CLOSE #1

SYSTEM

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION SuffixToPrefix$ (TheStringIn AS STRING, TheSuffixIn AS STRING, ThePrefixIn AS STRING)
    DIM TheReturn AS STRING
    DIM TheString AS STRING
    DIM TheSuffix AS STRING
    DIM ThePrefix AS STRING
    DIM tmp AS STRING
    TheString = TheStringIn
    TheSuffix = TheSuffixIn
    ThePrefix = ThePrefixIn
    tmp = TheString
    TheString = ReplaceRaw$(TheString, TheSuffix, "")
    IF (tmp <> TheString) THEN
        TheString = ThePrefix + TheString
    END IF
    TheReturn = TheString
    SuffixToPrefix$ = TheReturn
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

SUB AddKeyword (TheWordIn AS STRING)
    DIM TheWord AS STRING
    TheWord = TheWordIn
    FunctionListPop = FunctionListPop + 1
    FuncList(FunctionListPop) = TheWord
END SUB

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION ReplaceFuncCall$ (TheStringIn AS STRING, TheWordIn AS STRING)
    DIM TheString AS STRING
    DIM TheWord AS STRING
    TheString = TheStringIn
    TheWord = TheWordIn
    c = INSTR(TheString, TheWord)
    repl$ = LCASE$(LEFT$(TheWord, 1)) + RIGHT$(TheWord, LEN(TheWord) - 1)
    IF RIGHT$(repl$, 1) = "$" THEN
        repl$ = LEFT$(repl$, LEN(repl$) - 1)
    END IF
    IF RIGHT$(repl$, 1) = "#" THEN
        repl$ = LEFT$(repl$, LEN(repl$) - 1)
    END IF
    lfrag$ = LEFT$(TheString, c - 1)
    rfrag$ = RIGHT$(TheString, LEN(TheString) - c - LEN(TheWord) + 1)
    a$ = lfrag$ + repl$ + rfrag$
    ReplaceFuncCall$ = a$
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION ReplaceRaw$ (TheStringIn AS STRING, TheWordIn AS STRING, TheReplacementIn AS STRING)
    DIM TheReturn AS STRING
    DIM TheString AS STRING
    DIM TheWord AS STRING
    DIM TheReplacement AS STRING
    DIM k AS INTEGER
    DIM c AS STRING
    TheString = TheStringIn
    TheWord = TheWordIn
    TheReplacement = TheReplacementIn
    TheReturn = TheString
    IF (INSTR(TheReturn, TheWord) > 0) THEN
        FOR k = 1 TO LEN(TheReturn) - LEN(TheWord) + 1
            c = MID$(TheReturn, k, LEN(TheWord))
            IF (c = TheWord) THEN
                TheReturn = LEFT$(TheReturn, k - 1) + TheReplacement + RIGHT$(TheReturn, LEN(TheReturn) - k - LEN(TheWord) + 1)
                EXIT FOR
            END IF
        NEXT
    END IF
    IF (TheReturn <> TheString) THEN
        TheReturn = ReplaceRaw$(TheReturn, TheWord, TheReplacement)
    END IF
    ReplaceRaw$ = TheReturn
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION CountElements (TheStringIn AS STRING, TheSeparatorIn AS STRING)
    ' This function can me made as a special case of the one below.
    DIM TheReturn AS INTEGER
    DIM TheString AS STRING
    DIM TheSeparator AS STRING
    TheString = TheStringIn
    TheSeparator = TheSeparatorIn
    DIM c AS STRING
    DIM k AS INTEGER
    DIM BrackBal AS INTEGER
    DIM QuoteBal AS INTEGER
    BrackBal = 0
    QuoteBal = 0
    TheReturn = 1
    FOR k = 1 TO LEN(TheString)
        c = MID$(TheString, k, 1)
        IF (c = "`") THEN
            QuoteBal = QuoteBal + 1
        END IF
        IF (c = "'") THEN
            QuoteBal = QuoteBal - 1
        END IF
        IF (QuoteBal = 0) THEN
            IF (INSTR("(<{[", c) > 0) THEN
                BrackBal = BrackBal + 1
            END IF
            IF (INSTR(")>}]", c) > 0) THEN
                BrackBal = BrackBal - 1
            END IF
            IF (BrackBal = 1) THEN
                IF (c = TheSeparator) THEN
                    TheReturn = TheReturn + 1
                END IF
            END IF
        END IF
    NEXT
    CountElements = TheReturn
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION RemoveWrapping$ (TheStringIn AS STRING, TheWrapIn AS STRING)
    DIM TheReturn AS STRING
    DIM TheString AS STRING
    DIM TheWrap AS STRING
    DIM TheWidth AS INTEGER
    TheString = TheStringIn
    TheWrap = TheWrapIn
    TheReturn = TheString
    TheWidth = LEN(TheWrap) / 2
    IF (TheWrap <> "") THEN
        IF (LEFT$(TheString, TheWidth) = LEFT$(TheWrap, TheWidth)) THEN
            IF (RIGHT$(TheReturn, TheWidth) = RIGHT$(TheWrap, TheWidth)) THEN
                TheReturn = RIGHT$(TheReturn, LEN(TheReturn) - TheWidth)
                TheReturn = LEFT$(TheReturn, LEN(TheReturn) - TheWidth)
            END IF
        END IF
    END IF
    RemoveWrapping$ = TheReturn
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION GetSeparatorPos (TheStringIn AS STRING, TheSeparatorTypeIn AS STRING, TheSeparatorNumIn AS INTEGER, TheStartPosIn AS INTEGER)
    DIM TheReturn AS INTEGER
    DIM TheString AS STRING
    DIM TheSeparatorType AS STRING
    DIM TheSeparatorNum AS INTEGER
    DIM TheStartPos AS INTEGER
    DIM c AS STRING
    DIM k AS INTEGER
    DIM BrackBal AS INTEGER
    DIM QuoteBal AS INTEGER
    DIM SepCounter AS INTEGER
    DIM BrackConst AS INTEGER
    TheString = TheStringIn
    TheSeparatorType = TheSeparatorTypeIn
    TheSeparatorNum = TheSeparatorNumIn
    TheStartPos = TheStartPosIn
    BrackBal = 0
    QuoteBal = 0
    SepCounter = 0
    TheReturn = -1
    IF (TheStartPos > 1) THEN
        BrackConst = 0
        TheSeparatorNum = 1
    ELSE
        BrackConst = 1
    END IF
    IF (INSTR(TheString, TheSeparatorType) > 0) THEN
        FOR k = TheStartPos TO LEN(TheString)
            c = MID$(TheString, k, 1)
            IF (c = "`") THEN
                QuoteBal = QuoteBal + 1
            END IF
            IF (c = "'") THEN
                QuoteBal = QuoteBal - 1
            END IF
            IF (QuoteBal = 0) THEN
                IF (INSTR("(<{[", c) > 0) THEN
                    BrackBal = BrackBal + 1
                END IF
                IF (INSTR(")>}]", c) > 0) THEN
                    BrackBal = BrackBal - 1
                END IF
                IF (BrackBal = BrackConst) THEN
                    IF (c = TheSeparatorType) THEN
                        SepCounter = SepCounter + 1
                        IF (SepCounter = TheSeparatorNum) THEN
                            TheReturn = k
                            EXIT FOR
                        END IF
                    END IF
                END IF
            END IF
        NEXT
    END IF
    GetSeparatorPos = TheReturn
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

FUNCTION ReturnElement$ (TheStringIn AS STRING, TheArgNumberIn AS INTEGER)
    DIM TheReturn AS STRING
    DIM TheString AS STRING
    DIM TheArgNumber AS INTEGER
    DIM n AS INTEGER
    DIM m AS INTEGER
    TheString = TheStringIn
    TheArgNumber = TheArgNumberIn
    TheReturn = "_null"
    n = CountElements(TheString, ",")
    ' If seeking first argument:
    IF (TheReturn = "_null") THEN
        IF (TheArgNumber = 1) THEN
            IF (n = 1) THEN
                TheReturn = RemoveWrapping$(TheString, "<>")
            END IF
            IF (n > 1) THEN
                TheReturn = TheString
                TheReturn = LEFT$(TheReturn, GetSeparatorPos(TheReturn, ",", 1, 1) - 1)
                TheReturn = RIGHT$(TheReturn, LEN(TheReturn) - 1)
            END IF
        END IF
    END IF
    ' If seeking last argument:
    IF (TheReturn = "_null") THEN
        IF (TheArgNumber = n) THEN
            TheReturn = TheString
            TheReturn = RIGHT$(TheReturn, LEN(TheReturn) - GetSeparatorPos(TheReturn, ",", n - 1, 1))
            TheReturn = LEFT$(TheReturn, LEN(TheReturn) - 1)
        END IF
    END IF
    ' Must have three or more arguments:
    IF (TheReturn = "_null") THEN
        TheReturn = TheString
        n = GetSeparatorPos(TheReturn, ",", TheArgNumber - 1, 1)
        m = GetSeparatorPos(TheReturn, ",", TheArgNumber, n + 1)
        TheReturn = MID$(TheReturn, n + 1, (m - n) - 1)
    END IF
    ReturnElement$ = TheReturn
END FUNCTION

' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

