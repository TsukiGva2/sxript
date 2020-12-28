#lang "qb"
#Include "sxmath.bi"
#Include "sxript.bi"
#Include "sxmath.bm"
#Include "sxript.bm"

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

