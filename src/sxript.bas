' '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
' Meta stuff.
'
OPTION _EXPLICIT

REM $Include: 'sxmath.bi'
REM $Include: 'sxript.bi'

_DELAY 1

$EXEICON:'sxript.ico'
$CHECKING:OFF

$SCREENHIDE
$CONSOLE
_DEST _CONSOLE
$CONSOLE:ONLY

RANDOMIZE TIMER
ON ERROR GOTO ErrHand

DIM GeneralInput AS STRING
DIM GeneralOutput AS STRING
DIM OutputFile AS STRING

IF (COMMAND$ <> "") THEN
    GeneralInput = COMMAND$(1)
    GeneralOutput = SxriptEval$(GeneralInput)
    IF (COMMAND$(2) <> "") THEN
        OutputFile = COMMAND$(2)
        OPEN OutputFile FOR OUTPUT AS #1
        PRINT #1, GeneralOutput
        CLOSE #1
    ELSE
        PRINT GeneralOutput
    END IF
    SYSTEM
END IF

PRINT
DIM k AS INTEGER
FOR k = 1 TO SxriptLogoSize
    PRINT SxriptLogoText$(k)
NEXT
PRINT
PRINT " *** Welcome to Sxript *** "
PRINT "       (QB64 Build)        "
PRINT

DO
    LINE INPUT ":"; GeneralInput
    GeneralOutput = SxriptEval$(GeneralInput)
    PRINT ":"; GeneralOutput: PRINT
LOOP

ErrHand:
RESUME NEXT

REM $Include: 'sxmath.bm'
REM $Include: 'sxript.bm'
