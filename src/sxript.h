#include "qbf.h"
// BEGIN sxmath.bi
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// DECLARE FUNCTION GetDecimalPos (TheStringIn AS STRING);
// DECLARE FUNCTION InsertCharacter$ (TheStringIn AS STRING, TheCharIn AS STRING, TheDigitIn AS INTEGER, NumTimesIn AS INTEGER);
// DECLARE FUNCTION ReadManyCharacter$ (TheStringIn AS STRING, StartDigitIn AS INTEGER, FinishDigitIn AS INTEGER);
// DECLARE FUNCTION ReadOneCharacter$ (TheStringIn AS STRING, TheDigitIn AS INTEGER);
// DECLARE FUNCTION RemoveCharacter$ (TheStringIn AS STRING, TheDigitIn AS INTEGER);
// DECLARE FUNCTION RemoveDecimal$ (TheStringIn AS STRING);
// DECLARE FUNCTION RemoveSign$ (TheStringIn AS STRING);
// DECLARE FUNCTION RemoveZerosLeft$ (TheStringIn AS STRING, TheStartingDigitIn AS INTEGER);
// DECLARE FUNCTION RemoveZerosRight$ (TheStringIn AS STRING);
// DECLARE FUNCTION ReverseSign$ (TheStringIn AS STRING);
// DECLARE FUNCTION SelectLargerInteger$ (Num1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION RepairFormat$ (TheStringIn AS STRING);
// DECLARE FUNCTION InternalAdd$ (Num1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION InternalSub$ (Num1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION InternalMul$ (Nusm1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION InternalInv$ (DenomIn AS STRING, NumDigitsIn AS INTEGER);
// DECLARE FUNCTION InternalDiv$ (NumerIn AS STRING, DenomIn AS STRING, NumDigitsIn AS INTEGER);
// DECLARE FUNCTION BigNumAdd$ (Num1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION BigNumSub$ (Num1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION BigNumMul$ (Num1In AS STRING, Num2In AS STRING);
// DECLARE FUNCTION BigNumInv$ (DenomIn AS STRING, NumDigitsIn AS INTEGER);
// DECLARE FUNCTION BigNumDiv$ (NumerIn AS STRING, DenomIn AS STRING, NumDigitsIn AS INTEGER);

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// BEGIN sxript.bi
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// JavaScript: STARTSKIP
std::string subExecute (std::string TheScriptIn, std::string TheModeIn, std::string ScopeSwitchIn);
std::string numberCrunch (std::string TheStringIn);
std::string sxriptEval (std::string TheStringIn);
std::string evalStep (std::string TheStringIn);
// JavaScript: ENDSKIP

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// DECLARE FUNCTION CountElements (TheStringIn AS STRING, TheSeparatorIn AS STRING);
// DECLARE FUNCTION FindMatching (TheStringIn AS STRING, TheSymbolIn AS STRING, TheStartPosIn AS INTEGER);
// DECLARE FUNCTION FindMostEmbedded (TheStringIn AS STRING);
// DECLARE FUNCTION GetSeparatorPos (TheStringIn AS STRING, TheSeparatorTypeIn AS STRING, TheSeparatorNumIn AS INTEGER, TheStartPosIn AS INTEGER);
// DECLARE FUNCTION ManageWhiteSpace$ (TheStringIn AS STRING);
// DECLARE FUNCTION RemoveWrapping$ (TheStringIn AS STRING, TheWrapIn AS STRING);
// DECLARE FUNCTION ReplaceWord$ (TheStringIn AS STRING, TheWordIn AS STRING, TheReplacementIn AS STRING, CurlyDepthIn As INTEGER);
// DECLARE FUNCTION ReplaceRaw$ (TheStringIn AS STRING, TheWordIn AS STRING, TheReplacementIn AS STRING);
// DECLARE FUNCTION ScanForName (TheStringIn AS STRING, TheCritPosIn AS INTEGER, TheSwitchIn AS STRING);
// DECLARE FUNCTION ScanForOperator (TheStringIn AS STRING, TheSymbolIn AS STRING);
// DECLARE FUNCTION TypeCheck$ (TheStringIn AS STRING);
// DECLARE FUNCTION ManageOperators$ (TheStringIn AS STRING);
// DECLARE FUNCTION PlotASCII$ (TheFuncIn AS STRING, LowLimitIn AS DOUBLE, HighLimitIn AS DOUBLE, StepSizeIn AS DOUBLE, WindowWidthIn AS INTEGER, WindowHeightIn AS INTEGER, DetailSwitchIn AS INTEGER);
// DECLARE FUNCTION PlotScatter$ (TheListIn AS STRING, WindowWidthIn AS INTEGER, WindowHeightIn AS INTEGER, DetailSwitchIn AS INTEGER);
// DECLARE FUNCTION HistASCII$ (TheListIn AS STRING, DetailSwitchIn AS INTEGER);
// DECLARE FUNCTION ReturnElement$ (TheStringIn AS STRING, TheArgNumberIn AS INTEGER, TheSeparatorIn AS STRING);
// DECLARE FUNCTION VectorASMD$ (Vector1In AS STRING, Vector2In AS STRING, TheOperatorIn AS STRING);
// DECLARE FUNCTION StructureEval$ (TheVectorIn AS STRING, TheLeftBrackIn AS STRING, TheRightBrackIn AS STRING);
// DECLARE FUNCTION StructureApplyFunc$ (TheVectorIn AS STRING, TheFunctionIn AS STRING, TheBracketsIn AS STRING);
// DECLARE FUNCTION StructureTailOp$ (TheVectorIn AS STRING, TheFunctionIn AS STRING, TheBracketsIn AS STRING);
// DECLARE FUNCTION FormatForTerminal$ (TheStringIn AS STRING);
// DECLARE FUNCTION EvalStep$ (TheStringIn AS STRING);
// DECLARE FUNCTION InternalEval$ (TheStringIn AS STRING);
// DECLARE FUNCTION FunctionCrunch$ (ScannedNameIn AS STRING, MidFragmentIn AS STRING);
// DECLARE FUNCTION SxriptEval$ (TheStringIn AS STRING);
// DECLARE FUNCTION NumberCrunch$ (TheStringIn AS STRING);
// DECLARE FUNCTION SubExecute$ (TheScriptIn AS STRING, TheModeIn AS STRING, ScopeSwitchIn AS STRING);

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// Initialize globals and startup variables.
//DIM kglob AS INTEGER
//DIM jglob AS INTEGER
std::string BrackList;
std::string OpList;
std::string EscapeChar;

// Define array for Sxript logo.
std::string SxriptLogoText[30];
int SxriptLogoSize;

// Define structure for function and variable storage.
int FunctionListSize;
int VariableListSize;
int ScopeLevel;
std::string FunctionList[131][2];
std::string VariableList[131][2];
std::string FunctionListScope[131][2][24];
std::string VariableListScope[131][2][24];

//kglob = 0
//jglob = 0

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''



// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// BEGIN sxmath.bm
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int getDecimalPos (std::string TheStringIn) {
        int TheReturn;
        std::string TheString;
        TheString = TheStringIn;
        TheReturn = iNSTR(TheString, ".");
        if (TheReturn < 1) {
            TheReturn = -1;
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string insertCharacter (std::string TheStringIn, std::string TheCharIn, int TheDigitIn, int NumTimesIn) {
        std::string TheReturn;
        std::string TheString;
        std::string TheChar;
        int TheDigit;
        int NumTimes;
        std::string a;
        std::string b;
        std::string c;
        int k;
        TheString = TheStringIn;
        TheChar = TheCharIn;
        TheDigit = TheDigitIn;
        NumTimes = NumTimesIn;
        a = lEFT(TheString, TheDigit - 1);
        b = "";
        for (k = 1; k <= NumTimes; k += 1) {
            b = b + TheChar;
        }
        c = rIGHT(TheString, lEN(TheString) - TheDigit + 1);
        TheReturn = a + b + c;
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string readManyCharacter (std::string TheStringIn, int StartDigitIn, int FinishDigitIn) {
        std::string TheReturn;
        std::string TheString;
        int StartDigit;
        int FinishDigit;
        TheString = TheStringIn;
        StartDigit = StartDigitIn;
        FinishDigit = FinishDigitIn;
        TheReturn = "";
        if ((StartDigit > 0) & ((FinishDigit - StartDigit) >= 0)) {
            TheReturn = mID(TheString, StartDigit, (FinishDigit - StartDigit) + 1);
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string readOneCharacter (std::string TheStringIn, int TheDigitIn) {
        std::string TheReturn;
        std::string TheString;
        int TheDigit;
        TheString = TheStringIn;
        TheDigit = TheDigitIn;
        TheReturn = "";
        if (TheDigit > 0) {
            TheReturn = mID(TheString, TheDigit, 1);
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string removeCharacter (std::string TheStringIn, int TheDigitIn) {
        std::string TheReturn;
        std::string TheString;
        int TheDigit;
        std::string a;
        std::string b;
        TheString = TheStringIn;
        TheDigit = TheDigitIn;
        a = lEFT(TheString, TheDigit - 1);
        b = rIGHT(TheString, lEN(TheString) - TheDigit);
        TheReturn = a + b;
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string removeDecimal (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        int n;
        TheString = TheStringIn;
        TheReturn = TheString;
        n = getDecimalPos(TheString);
        if (n != -1) {
            if (n == lEN(TheString)) {
                TheReturn = lEFT(TheString, lEN(TheString) - 1);
            } else {
                TheReturn = lEFT(TheString, n - 1) + rIGHT(TheString, (lEN(TheString) - n));
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string removeSign (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        TheString = TheStringIn;
        if ((lEFT(TheString, 1) == "+") | (lEFT(TheString, 1) == "-")) {
            TheReturn = removeCharacter(TheString, 1);
        } else {
            TheReturn = TheString;
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string removeZerosLeft (std::string TheStringIn, int TheStartingDigitIn) {
        std::string TheReturn;
        std::string TheString;
        int TheStartingDigit;
        int n;
        int i;
        std::string c;
        TheString = TheStringIn;
        TheStartingDigit = TheStartingDigitIn;
        n = 0;
        for (i = TheStartingDigit; i <= lEN(TheString); i += 1) {
            c = readOneCharacter(TheString, i);
            if (c == "0") {
                n = n + 1;
            } else {
                break;
            }
        }
        TheReturn = lEFT(TheString, TheStartingDigit - 1) + rIGHT(TheString, lEN(TheString) - TheStartingDigit - n + 1);
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string removeZerosRight (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        int n;
        int i;
        std::string c;
        TheString = TheStringIn;
        n = 0;
        for (i = lEN(TheString); i >= 1; i += (-1)) {
            c = readOneCharacter(TheString, i);
            if (c == "0") {
                n = n + 1;
            } else {
                break;
            }
        }
        TheReturn = lEFT(TheString, lEN(TheString) - n);
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string reverseSign (std::string TheStringIn) {
        std::string Temp;
        std::string TheString;
        TheString = TheStringIn;
        Temp = "";
        if (lEFT(TheString, 1) == "+") {
            Temp = removeCharacter(TheString, 1);
            Temp = "-" + Temp;
        }
        if (lEFT(TheString, 1) == "-") {
            Temp = removeCharacter(TheString, 1);
            Temp = "+" + Temp;
        }
        if (Temp == "") {
            Temp = "-" + TheString;
        }
        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string selectLargerInteger (std::string Num1In, std::string Num2In) {
        // Select the larger of two integers. The arguments must have no sign and no decimal.
        std::string Num1;
        std::string Num2;
        std::string Temp;
        int LenDiff;
        int TempDiff;
        int k;
        Num1 = Num1In;
        Num2 = Num2In;
        Temp = "";
        LenDiff = lEN(Num1) - lEN(Num2);
        if (LenDiff > 0) {
            Temp = "first";
        }
        if (LenDiff < 0) {
            Temp = "second";
        }
        if (LenDiff == 0) {
            for (k = 1; k <= lEN(Num1); k += 1) {
                TempDiff = vAL(readOneCharacter(Num1, k)) - vAL(readOneCharacter(Num2, k));
                if (TempDiff != 0) {
                    if (TempDiff > 0) {
                        Temp = "first";
                        break;
                    } else {
                        Temp = "second";
                        break;
                    }
                }
            }
        }
        if (Temp == "") {
            Temp = "neither";
        }
        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string repairFormat (std::string TheStringIn) {
        // Repair the format of a number.
        std::string Temp;
        std::string NewSign;
        int n;
        std::string c;
        int i;

        Temp = TheStringIn;

        // Remove and store the sign if there is one.
        NewSign = "";
        if (lEFT(Temp, 1) == "+") {
            NewSign = "+";
            Temp = removeSign(Temp);
        }
        if (lEFT(Temp, 1) == "-") {
            NewSign = "-";
            Temp = removeSign(Temp);
        }
        if (NewSign == "") {
            NewSign = "+";
        }

        // If the string has no decimal, place one at the end of the string.
        if (getDecimalPos(Temp) == -1) {
            // This can be made faster.
            Temp = insertCharacter(Temp, ".", lEN(Temp) + 1, 1);
        }

        // Remove unnecessary zeros on the left.
        n = 0;
        for (i = 1; i <= lEN(Temp); i += 1) {
            c = readOneCharacter(Temp, i);
            if (c == "0") {
                n = n + 1;
            } else {
                break;
            }
        }
        Temp = rIGHT(Temp, lEN(Temp) - n);

        // Remove unnecessary zeros on the right.
        n = 0;
        for (i = lEN(Temp); i >= 1; i += (-1)) {
            c = readOneCharacter(Temp, i);
            if (c == "0") {
                n = n + 1;
            } else {
                break;
            }
        }
        Temp = lEFT(Temp, lEN(Temp) - n);

        // If last character is a decimal then add a zero to the right.
        if (rIGHT(Temp, 1) == ".") {
            Temp = Temp + "0";
        }

        // If leading character is a decimal then insert a zero to the left.
        if (lEFT(Temp, 1) == ".") {
            Temp = "0" + Temp;
        }

        // Attach the sign on the left.
        Temp = NewSign + Temp;

        if (Temp == "-0.0") {
            Temp = "+0.0";
        }

        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string internalAdd (std::string Num1In, std::string Num2In) {
        std::string Num1;
        std::string Num2;
        double fac1;
        double fac2;
        int LenDiff;
        std::string TempSwap;
        std::string Temp1;
        std::string Temp2;
        std::string Oper;
        std::string NewSign;
        int ChunkSize;
        std::string TheSum;
        int Remainder;
        int SubFactor;
        int psum;
        std::string PartialSum;
        int TempDiff;
        int TotalDecimalPlaces;
        int k;
        Num1 = Num1In;
        Num2 = Num2In;

        // Add zeros to the right of the decimal of the shorter partial string.
        LenDiff = (lEN(Num1) - getDecimalPos(Num1)) - (lEN(Num2) - getDecimalPos(Num2));
        if (LenDiff > 0) {
            Num2 = insertCharacter(Num2, "0", lEN(Num2) + 1, LenDiff);
        } else {
            Num1 = insertCharacter(Num1, "0", lEN(Num1) + 1, -LenDiff);
        }

        // Force Num1 to be the number with the greatest magnitude.
        LenDiff = lEN(Num1) - lEN(Num2);
        if (LenDiff < 0) {
            TempSwap = Num1;
            Num1 = Num2;
            Num2 = TempSwap;
        }
        if (LenDiff == 0) {
            Temp1 = removeDecimal(Num1);
            Temp2 = removeDecimal(Num2);
            Temp1 = removeSign(Temp1);
            Temp2 = removeSign(Temp2);
            for (k = 1; k <= lEN(Temp1); k += 1) {
                TempDiff = vAL(readOneCharacter(Temp1, k)) - vAL(readOneCharacter(Temp2, k));
                if (TempDiff != 0) {
                    if (TempDiff > 0) {
                        break;
                    } else {
                        TempSwap = Num1;
                        Num1 = Num2;
                        Num2 = TempSwap;
                        break;
                    }
                }
            }
        }

        //Add zeros to the left of Num2 to normalize lengths.
        Num2 = insertCharacter(Num2, "0", 2, lEN(Num1) - lEN(Num2));

        // Determine the sign of the result.
        if ((lEFT(Num1, 1) == "+") & (lEFT(Num2, 1) == "+")) {
            Oper = "add";
            NewSign = "+";
        }
        if ((lEFT(Num1, 1) == "-") & (lEFT(Num2, 1) == "-")) {
            Oper = "add";
            NewSign = "-";
        }
        if ((lEFT(Num1, 1) == "+") & (lEFT(Num2, 1) == "-")) {
            Oper = "subtract";
            NewSign = "+";
        }
        if ((lEFT(Num1, 1) == "-") & (lEFT(Num2, 1) == "+")) {
            Oper = "subtract";
            NewSign = "-";
        }

        // Remove the leading sign from each string.
        Num1 = removeSign(Num1);
        Num2 = removeSign(Num2);

        // Remove the decimal from each number after storing the total number of
        // decimal places in a new variable (to be restored after the operation).
        TotalDecimalPlaces = (lEN(Num1) - getDecimalPos(Num1));
        if (TotalDecimalPlaces > 0) {
            Num1 = removeDecimal(Num1);
            Num2 = removeDecimal(Num2);
        }

        // Initialize internal addition and subtraction loop.
        ChunkSize = 4;
        TheSum = "";
        Remainder = 0;

        // This formula is nice but a hardcoded value is faster.
        //SubFactor = vAL(insertCharacter("1", "0", 2, ChunkSize))
        SubFactor = 10000;

        //''
        for (k = 1; k <= ChunkSize - (lEN(Num1) % ChunkSize); k += 1) {
            Num1 = "0" + Num1;
            Num2 = "0" + Num2;
        }
        //''

        //IF (lEN(Num1) < ChunkSize) THEN
        //    FOR k = 1 TO ChunkSize - lEN(Num1)
        //        Num1 = "0" + Num1
        //        Num2 = "0" + Num2
        //    NEXT
        //END IF

        //IF (lEN(Num1) > ChunkSize) THEN
        //    FOR k = 1 TO ChunkSize - (lEN(Num1) MOD ChunkSize)
        //        Num1 = "0" + Num1
        //        Num2 = "0" + Num2
        //    NEXT
        //END IF

        //IF (lEN(Num1) > ChunkSize) THEN
        while ((lEN(Num1) % ChunkSize) != 0) {
            Num1 = "0" + Num1;
            Num2 = "0" + Num2;
        }
        //END IF

        // Execute internal addition and subtraction loop.

        if (Oper == "add") {
            for (k = lEN(Num1); k >= 1; k += (-ChunkSize)) {
                fac1 = vAL(readManyCharacter(Num1, k - ChunkSize + 1, k));
                fac2 = vAL(readManyCharacter(Num2, k - ChunkSize + 1, k));
                psum = fac1 + fac2 + Remainder;
                PartialSum = lTRIM(rTRIM(sTR(psum)));
                while (lEN(PartialSum) < ChunkSize) {
                    PartialSum = "0" + PartialSum;
                }
                if (lEN(PartialSum) == ChunkSize + 1) {
                    Remainder = 1;
                    PartialSum = removeCharacter(PartialSum, 1);
                } else {
                    Remainder = 0;
                }
                TheSum = lEFT(lTRIM(PartialSum), ChunkSize) + TheSum;
            }
        }

        if (Oper == "subtract") {
            for (k = lEN(Num1); k >= 1; k += (-ChunkSize)) {
                fac1 = vAL(readManyCharacter(Num1, k - ChunkSize + 1, k));
                fac2 = vAL(readManyCharacter(Num2, k - ChunkSize + 1, k));
                psum = fac1 - fac2 + SubFactor - Remainder;
                PartialSum = lTRIM(sTR(psum));
                while (lEN(PartialSum) < ChunkSize) {
                    PartialSum = "0" + PartialSum;
                }
                if (lEN(PartialSum) > ChunkSize) {
                    PartialSum = removeCharacter(PartialSum, 1);
                    Remainder = 0;
                } else {
                    Remainder = 1;
                }
                TheSum = lEFT(lTRIM(PartialSum), ChunkSize) + TheSum;
            }
        }

        // Correct the string format.
        TheSum = removeSign(TheSum);

        // Restore the decimal point.
        TheSum = insertCharacter(TheSum, ".", lEN(TheSum) - TotalDecimalPlaces + 1, 1);

        // If the result ends in a decimal then fix the format.
        if (rIGHT(TheSum, 1) == ".") {
            TheSum = TheSum + "0";
        }

        // Remove unnecessary zeros.
        TheSum = removeZerosLeft(TheSum, 1);

        // If the result begins in a decimal then fix the format.
        if (lEFT(TheSum, 1) == ".") {
            TheSum = "0" + TheSum;
        }

        // Assign the proper sign to the result.
        TheSum = NewSign + TheSum;

        return TheSum;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string internalSub (std::string Num1In, std::string Num2In) {
        std::string Num1;
        std::string Num2;
        Num1 = Num1In;
        Num2 = Num2In;
        return internalAdd(Num1, reverseSign(Num2));
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string internalMul (std::string Num1In, std::string Num2In) {
        std::string Num1;
        std::string Num2;
        std::string Temp;
        std::string NewSign;
        std::string Prod;
        std::string TheProd;
        std::string TempMult;
        int CarryOver;
        int PresentDigit;
        int TotalDecimalPlaces;
        int WorkingDigit;
        std::string tempswap;
        int i;
        int k;
        int q;

        Num1 = Num1In;
        Num2 = Num2In;
        Temp = "";

        // Problem requires post-DOUBLE precision.
        if (Temp == "") {

            // Remove unneessary zeros.
            Num1 = removeZerosRight(Num1);
            Num2 = removeZerosRight(Num2);

            // Remove the decimal from each number after storing the total number of
            // decimal places in a new variable (to be restored after the multiplication).
            TotalDecimalPlaces = (lEN(Num1) - getDecimalPos(Num1)) + (lEN(Num2) - getDecimalPos(Num2));
            Num1 = removeDecimal(Num1);
            Num2 = removeDecimal(Num2);

            // Determine the sign of the result.
            if ((lEFT(Num1, 1) == "+") & (lEFT(Num2, 1) == "+")) {
                NewSign = "+";
            }
            if ((lEFT(Num1, 1) == "-") & (lEFT(Num2, 1) == "-")) {
                NewSign = "+";
            }
            if ((lEFT(Num1, 1) == "+") & (lEFT(Num2, 1) == "-")) {
                NewSign = "-";
            }
            if ((lEFT(Num1, 1) == "-") & (lEFT(Num2, 1) == "+")) {
                NewSign = "-";
            }

            // Remove the leading sign from each string.
            Num1 = removeSign(Num1);
            Num2 = removeSign(Num2);

            // Force Num1 to be the number with the greatest length.
            if (lEN(Num2) > lEN(Num1)) {

                tempswap = Num1;
                Num1 = Num2;
                Num2 = tempswap;
            }

            // Add a zero to the left of each string.
            // This is necessary when the length of the result surpasses that of the input.
            Num1 = "0" + Num1;
            Num2 = "0" + Num2;

            // Initialize internal multiplication loop.
            TheProd = "+0.0";
            TempMult = "";
            CarryOver = 0;

            // Execute internal multiplication loop.
            for (k = lEN(Num2); k >= 1; k += (-1)) {
                WorkingDigit = vAL(readOneCharacter(Num2, k));
                TempMult = "";
                CarryOver = 0;
                for (i = lEN(Num1); i >= 1; i += (-1)) {
                    PresentDigit = vAL(readOneCharacter(Num1, i));
                    Prod = sTR(PresentDigit * WorkingDigit + CarryOver);
                    Prod = lTRIM(rTRIM(Prod));
                    if (lEN(Prod) == 1) {
                        CarryOver = 0;
                        TempMult = Prod + TempMult;
                    }
                    if (lEN(Prod) == 2) {
                        CarryOver = vAL(lEFT(Prod, 1));
                        TempMult = rIGHT(Prod, 1) + TempMult;
                    }
                }
                TempMult = removeZerosLeft(TempMult, 1);

                if (TempMult == "") {
                    TempMult = "+0.0";
                } else {
                    TempMult = "+" + insertCharacter(TempMult, "0", lEN(TempMult) + 1, lEN(Num2) - k) + ".0";
                }
                TheProd = internalAdd(TheProd, TempMult);
            }

            // Correct the string format.
            TheProd = removeSign(TheProd);
            TheProd = lEFT(TheProd, lEN(TheProd) - 2);

            // Restore the decimal point.
            if (TotalDecimalPlaces > 0) {
                q = TotalDecimalPlaces - lEN(TheProd);
                if (q >= 0) {
                    TheProd = insertCharacter(TheProd, "0", 1, q);
                    TheProd = "." + TheProd;
                } else {
                    TheProd = insertCharacter(TheProd, ".", lEN(TheProd) - TotalDecimalPlaces + 1, 1);
                }
                TheProd = removeZerosRight(TheProd);
                if (rIGHT(TheProd, 1) == ".") {
                    TheProd = TheProd + "0";
                }
                if (lEFT(TheProd, 1) == ".") {
                    TheProd = "0" + TheProd;
                }
            } else {
                TheProd = TheProd + ".0";
            }

            // Assign the proper sign to the result.
            TheProd = NewSign + TheProd;

            Temp = TheProd;

        }

        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string internalInv (std::string DenomIn, int NumDigitsIn) {
        // The output of this function does not have fixed length. The output is made such that
        // NumDigits only counts numerical character 0-9. The sign and decimal are ignored. The overall
        // string length (zero between decimal and first sig-fig) is thus variable.
        std::string Denom;
        int NumDigits;
        Denom = DenomIn;
        NumDigits = NumDigitsIn;
        std::string Temp;
        std::string NewSign;
        std::string Numerator;
        std::string TempDiff;
        std::string TempFactor;
        std::string TheQuot;
        int TotalDecimalPlaces;
        int dpd;
        int k;
        int m;
        int n;

        Temp = "";

        if (removeSign(Denom) == "0.0") {
            Temp = "{ERROR: Division by zero detected in InternalInv.}";
        }

        if (Temp == "") {

            // Determine the sign of the result.
            if (lEFT(Denom, 1) == "+") {
                NewSign = "+";
            }
            if (lEFT(Denom, 1) == "-") {
                NewSign = "-";
            }

            // Remove the sign from the string.
            Denom = removeSign(Denom);

            // Remove leading zeros such that string is not of the format 00.000###
            // but instead #.##
            m = 0;
            while (m > -1) {
                if ((lEFT(Denom, 1) == ".") | (lEFT(Denom, 1) == "0")) {
                    m = m + 1;
                    Denom = removeSign(internalMul("+" + Denom, "+10.0"));
                } else {
                    break;
                }
            }

            // Remove the decimal from the number after storing the total number of
            // decimal places in a new variable (to be restored after the inversion).
            dpd = getDecimalPos(Denom);
            TotalDecimalPlaces = lEN(Denom) - dpd;
            Denom = removeDecimal(Denom);

            // Initialize internal inversion loop.
            Numerator = "+1.0";
            TheQuot = "";
            TempFactor = Numerator;

            // Execute internal inversion loop.
            for (k = 1; k <= NumDigits + TotalDecimalPlaces + dpd - 2; k += 1) {
                // ^ The "2" is compensation for the sign and decimal. ^
                n = 0;
                while (n > -1) {
                    //Check for a zero in the result.
                    TempFactor = removeSign(TempFactor);
                    TempFactor = removeDecimal(TempFactor);
                    if (selectLargerInteger(TempFactor, Denom) != "first") {
                        break;
                    }

                    TempDiff = internalAdd("+" + TempFactor + ".0", "-" + Denom + ".0");
                    TempDiff = removeSign(TempDiff);
                    TempDiff = lEFT(TempDiff, lEN(TempDiff) - 2);
                    // ^ Removes the ".0". ^
                    n = n + 1;
                    TempFactor = TempDiff;

                    if (selectLargerInteger(TempDiff, Denom) == "second") {
                        break;
                    }

                }
                if (k > 1) {
                    TheQuot = TheQuot + lTRIM(sTR(n));
                }
                TempFactor = TempFactor + "0";
            }

            // Insert the decimal into the string.
            TheQuot = insertCharacter(TheQuot, ".", TotalDecimalPlaces + m, 1);

            // If string begins with a decimal then add a zero to the left.
            if (lEFT(TheQuot, 1) == ".") {
                TheQuot = "0" + TheQuot;
            }

            // Assign the proper sign to the result.
            TheQuot = NewSign + TheQuot;

            Temp = TheQuot;

        }

        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string internalDiv (std::string NumerIn, std::string DenomIn, int NumDigitsIn) {
        std::string Numer;
        std::string Denom;
        int NumDigits;
        std::string Temp;
        std::string Factor;
        Numer = NumerIn;
        Denom = DenomIn;
        NumDigits = NumDigitsIn;
        Factor = internalInv(Denom, NumDigits);
        if (lEFT(Factor, 6) != "{ERROR") {
            Temp = internalMul(Numer, Factor);
        } else {
            Temp = "{ERROR: Division by zero passed to InternalDiv.}";
        }
        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string bigNumAdd (std::string Num1In, std::string Num2In) {
        std::string Num1;
        std::string Num2;
        Num1 = Num1In;
        Num2 = Num2In;
        Num1 = repairFormat(Num1);
        Num2 = repairFormat(Num2);
        return internalAdd(Num1, Num2);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string bigNumSub (std::string Num1In, std::string Num2In) {
        std::string Num1;
        std::string Num2;
        Num1 = Num1In;
        Num2 = Num2In;
        Num1 = repairFormat(Num1);
        Num2 = repairFormat(Num2);
        return internalAdd(Num1, reverseSign(Num2));
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string bigNumMul (std::string Num1In, std::string Num2In) {
        std::string Num1;
        std::string Num2;
        Num1 = Num1In;
        Num2 = Num2In;
        Num1 = repairFormat(Num1);
        Num2 = repairFormat(Num2);
        return internalMul(Num1, Num2);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string bigNumInv (std::string DenomIn, int NumDigitsIn) {
        std::string Denom;
        int NumDigits;
        Denom = repairFormat(DenomIn);
        NumDigits = NumDigitsIn;
        return internalInv(Denom, NumDigits);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string bigNumDiv (std::string NumerIn, std::string DenomIn, int NumDigitsIn) {
        std::string Numer;
        std::string Denom;
        int NumDigits;
        std::string Temp;
        std::string Factor;
        Numer = repairFormat(NumerIn);
        Denom = repairFormat(DenomIn);
        NumDigits = NumDigitsIn;
        Factor = internalInv(Denom, NumDigits);
        Temp = "";
        if (lEFT(Factor, 6) != "{ERROR") {
            if (Temp == "") {
                Temp = internalMul(Numer, Factor);
            }
        } else {
            Temp = "{ERROR: Division by zero passed to BigNumDiv.}";
        }
        return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// BEGIN sxript.bm
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

//REM $Include: 'sxmath.bi'
//REM $Include: 'sxript.bi'
//REM $Include: 'sxmath.bm'

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// 2019-01-22 Experimenting with ManageWhiteSpace.
// 2018-12-12 Passing "goto" target through SxriptEval.
//            Added switch to show or hide details on all plots.
// 2018-12-11 Upgraded x-axis labeling in existing plotascii function.
// 2018-12-10 Added scatter plot function.
// 2021-01-13 Improved plotascii function to be safer in c++ implementation.
//            To do: Test and apply similar to scatter plot.
// 2021-01-27 Added support for abs().
//            Added support for sgn().
//            Added support for sqrt().
// 2021-01-30 Fixed handling of chr(32).
// 2021-01-31 Changing behavior of quote subtraction.
//            Added unf() primitive.
// 2021-02-04 Modified vector bitwise handling.
// 2021-02-05 Expanded quote-number multiplication via operator.
//            Expanded vector-number multiplication via operator.
//            Expanded vector-quote multiplication via operator.
// 2021-02-09 Fixed bug in scientific notation evident in JS/C++ implementatins.
//            Added trivial "identity" functions.
// 2021-02-10 Added function StructureApplyTailOp$.
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int countElements (std::string TheStringIn, std::string TheSeparatorIn) {
        int TheReturn;
        std::string TheString;
        std::string TheSeparator;
        TheString = TheStringIn;
        TheSeparator = TheSeparatorIn;
        std::string c;
        std::string d;
        int k;
        int BrackBal;
        int QuoteBal;
        BrackBal = 0;
        QuoteBal = 0;
        TheReturn = 1;
        if (iNSTR(TheString, TheSeparator) > 0) {
            k = 1;
            while (k <= lEN(TheString)) {
                c = mID(TheString, k, 1);
                if (k > 1) {
                    d = mID(TheString, k - 1, 1);
                }
                if (d != EscapeChar) {
                    if (c == "`") {
                        QuoteBal = QuoteBal + 1;
                    }
                    if (c == "'") {
                        QuoteBal = QuoteBal - 1;
                    }
                    if (QuoteBal == 0) {
                        if (iNSTR("(<{[", c) > 0) {
                            BrackBal = BrackBal + 1;
                        }
                        if (iNSTR(")>}]", c) > 0) {
                            BrackBal = BrackBal - 1;
                        }
                        if (BrackBal == 1) {
                            if (c == TheSeparator) {
                                TheReturn = TheReturn + 1;
                            }
                        }
                    }
                }
                k = k + 1;
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int findMatching (std::string TheStringIn, std::string TheSymbolIn, int TheStartPosIn) {
        int TheReturn;
        std::string TheString;
        std::string TheSymbol;
        int TheStartPos;
        TheString = TheStringIn;
        TheSymbol = TheSymbolIn;
        TheStartPos = TheStartPosIn;
        std::string c;
        std::string d;
        int k;
        std::string ClosingSymbol;
        int TheDirection;
        int TheEndPos;
        int BrackBal;
        int QuoteBal;
        ClosingSymbol = "";
        TheDirection = 0;
        BrackBal = 0;
        QuoteBal = 0;
        TheEndPos = 0;
        TheReturn = -1;
        c = "`(<{[";
        d = "')>}]";
        k = iNSTR(c, TheSymbol);
        if (k > 0) {
            ClosingSymbol = mID(d, k, 1);
            TheDirection = 1;
            TheEndPos = lEN(TheString);
        }

        k = iNSTR(d, TheSymbol);
        if (k > 0) {
            ClosingSymbol = mID(c, k, 1);
            TheDirection = -1;
            TheEndPos = 1;
        }

        k = TheStartPos;
        while (1 == 1) {
            c = mID(TheString, k, 1);
            if (k > 1) {
                d = mID(TheString, k - 1, 1);
            }
            if (d != EscapeChar) {
                if (c == "`") {
                    QuoteBal = QuoteBal + 1;
                }
                if (c == "'") {
                    QuoteBal = QuoteBal - 1;
                }
                if (QuoteBal == 0) {
                    if (iNSTR("(<{[", c) > 0) {
                        BrackBal = BrackBal + 1;
                    }
                    if (iNSTR(")>}]", c) > 0) {
                        BrackBal = BrackBal - 1;
                    }
                    if (BrackBal == 0) {
                        if (c == ClosingSymbol) {
                            TheReturn = k;
                            break;
                        }
                    }
                }
            }

            if (k == TheEndPos) {
                break;
            }
            k = k + TheDirection;
            if (k == TheStartPos) {
                break;
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int findMostEmbedded (std::string TheStringIn) {
        int TheReturn;
        std::string TheString;
        int MainBal;
        int QuoteBal;
        int AltBal;
        int MainCrit;
        int LeftPos;
        int k;
        std::string c;
        std::string d;
        TheString = TheStringIn;
        TheReturn = 0;
        MainBal = 0;
        QuoteBal = 0;
        AltBal = 0;
        MainCrit = 0;
        LeftPos = -1;
        if ((iNSTR(TheString, "(") > 0) & (iNSTR(TheString, ")") > 0)) {
            k = 1;
            while (k <= lEN(TheString)) {
                c = mID(TheString, k, 1);
                if (k > 1) {
                    d = mID(TheString, k - 1, 1);
                }
                if (d != EscapeChar) {
                    if (c == "`") {
                        QuoteBal = QuoteBal + 1;
                    }
                    if (c == "'") {
                        QuoteBal = QuoteBal - 1;
                    }
                    if (QuoteBal == 0) {
                        if (iNSTR("<{[", c) > 0) {
                            AltBal = AltBal + 1;
                        }
                        if (iNSTR(">}]", c) > 0) {
                            AltBal = AltBal - 1;
                        }
                        if (AltBal == 0) {
                            if (c == "(") {
                                MainBal = MainBal + 1;
                                if (MainBal > MainCrit) {
                                    MainCrit = MainBal;
                                    LeftPos = k;
                                }
                            }
                            if (c == ")") {
                                MainBal = MainBal - 1;
                            }
                        }
                    }
                }
                k = k + 1;
            }
            TheReturn = LeftPos;
        } else {
            TheReturn = -1;
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int getSeparatorPos (std::string TheStringIn, std::string TheSeparatorTypeIn, int TheSeparatorNumIn, int TheStartPosIn) {
        int TheReturn;
        std::string TheString;
        std::string TheSeparatorType;
        int TheSeparatorNum;
        int TheStartPos;
        std::string c;
        std::string d;
        int k;
        int BrackBal;
        int QuoteBal;
        int SepCounter;
        int BrackConst;
        TheString = TheStringIn;
        TheSeparatorType = TheSeparatorTypeIn;
        TheSeparatorNum = TheSeparatorNumIn;
        TheStartPos = TheStartPosIn;
        BrackBal = 0;
        QuoteBal = 0;
        SepCounter = 0;
        TheReturn = -1;
        if (TheStartPos > 1) {
            BrackConst = 0;
            TheSeparatorNum = 1;
        } else {
            BrackConst = 1;
        }
        if (iNSTR(TheString, TheSeparatorType) > 0) {
            k = TheStartPos;
            while (k <= lEN(TheString)) {
                c = mID(TheString, k, 1);
                if (k > 1) {
                    d = mID(TheString, k - 1, 1);
                }
                if (d != EscapeChar) {
                    if (c == "`") {
                        QuoteBal = QuoteBal + 1;
                    }
                    if (c == "'") {
                        QuoteBal = QuoteBal - 1;
                    }
                    if (QuoteBal == 0) {
                        if (iNSTR("(<{[", c) > 0) {
                            BrackBal = BrackBal + 1;
                        }
                        if (iNSTR(")>}]", c) > 0) {
                            BrackBal = BrackBal - 1;
                        }
                        if (BrackBal == BrackConst) {
                            if (c == TheSeparatorType) {
                                SepCounter = SepCounter + 1;
                                if (SepCounter == TheSeparatorNum) {
                                    TheReturn = k;
                                    break;
                                }
                            }
                        }
                    }
                }
                k = k + 1;
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string manageWhiteSpace (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        int QuoteBal;
        int k;
        std::string c;
        std::string d;
        TheString = TheStringIn;
        TheReturn = "";
        QuoteBal = 0;
        d = "";
        if ((iNSTR(TheString, " ") > 0) | (iNSTR(TheString, "\t") > 0) | (iNSTR(TheString, "\n") > 0) | (iNSTR(TheString, "\r") > 0)) {
            k = 1;
            while (k <= lEN(TheString)) {
                c = mID(TheString, k, 1);
                if (k > 1) {
                    d = mID(TheString, k - 1, 1);
                }
                if (d != EscapeChar) {
                    if (c == "`") {
                        QuoteBal = QuoteBal + 1;
                    }
                    if (c == "'") {
                        QuoteBal = QuoteBal - 1;
                    }
                    if (QuoteBal == 0) {
                        if ((c != " ") & (c != "\t") & (c != "\n") & (c != "\r")) {
                            TheReturn = TheReturn + c;
                        }
                    } else {
                        TheReturn = TheReturn + c;
                    }
                } else {
                    TheReturn = TheReturn + c;
                }
                k = k + 1;
            }
        } else {
            TheReturn = TheString;
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string removeWrapping (std::string TheStringIn, std::string TheWrapIn) {
        std::string TheReturn;
        std::string TheString;
        std::string TheWrap;
        int TheWidth;
        TheString = TheStringIn;
        TheWrap = TheWrapIn;
        TheReturn = TheString;
        TheWidth = lEN(TheWrap) / 2;
        if (TheWrap != "") {
            if (lEFT(TheString, TheWidth) == lEFT(TheWrap, TheWidth)) {
                if (rIGHT(TheReturn, TheWidth) == rIGHT(TheWrap, TheWidth)) {
                    TheReturn = rIGHT(TheReturn, lEN(TheReturn) - TheWidth);
                    TheReturn = lEFT(TheReturn, lEN(TheReturn) - TheWidth);
                }
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string replaceWord (std::string TheStringIn, std::string TheWordIn, std::string TheReplacementIn, int CurlyDepthIn) {
        std::string TheReturn;
        std::string TheString;
        std::string TheWord;
        std::string TheReplacement;
        int CurlyDepth;
        int QuoteBal;
        int CurlyBal;
        int k;
        std::string c;
        std::string d;
        TheString = TheStringIn;
        TheWord = TheWordIn;
        TheReplacement = TheReplacementIn;
        CurlyDepth = CurlyDepthIn;
        TheReturn = TheString;
        if (iNSTR(TheReturn, TheWord) > 0) {
            QuoteBal = 0;
            CurlyBal = 0;
            k = 1;
            while (k <= lEN(TheReturn) - lEN(TheWord) + 1) {
                c = mID(TheReturn, k, 1);
                if (k > 1) {
                    d = mID(TheString, k - 1, 1);
                }
                if (d != EscapeChar) {
                    if (c == "`") {
                        QuoteBal = QuoteBal + 1;
                    }
                    if (c == "'") {
                        QuoteBal = QuoteBal - 1;
                    }
                    if (QuoteBal == 0) {
                        if (CurlyDepth > -1) {
                            if (c == "{") {
                                CurlyBal = CurlyBal + 1;
                            }
                            if (c == "}") {
                                CurlyBal = CurlyBal - 1;
                            }
                        } else {
                            CurlyBal = CurlyDepth;
                        }
                        if (CurlyBal <= CurlyDepth) {
                            c = mID(TheReturn, k, lEN(TheWord));
                            if (c == TheWord) {
                                TheReturn = lEFT(TheReturn, k - 1) + TheReplacement + rIGHT(TheReturn, lEN(TheReturn) - k - lEN(TheWord) + 1);
                                break;
                            }
                        }
                    }
                }
                k = k + 1;
            }
        }
        if ((iNSTR(TheReturn, TheWord) > 0) & (TheReturn != TheString)) {
            TheReturn = replaceWord(TheReturn, TheWord, TheReplacement, CurlyDepth);
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string replaceRaw (std::string TheStringIn, std::string TheWordIn, std::string TheReplacementIn) {
        std::string TheReturn;
        std::string TheString;
        std::string TheWord;
        std::string TheReplacement;
        int CurlyBal;
        int k;
        std::string c;
        TheString = TheStringIn;
        TheWord = TheWordIn;
        TheReplacement = TheReplacementIn;
        TheReturn = TheString;
        if (iNSTR(TheReturn, TheWord) > 0) {
            CurlyBal = 0;
            for (k = 1; k <= lEN(TheReturn) - lEN(TheWord) + 1; k += 1) {
                c = mID(TheReturn, k, lEN(TheWord));
                if (c == "{") {
                    CurlyBal = CurlyBal + 1;
                }
                if (c == "}") {
                    CurlyBal = CurlyBal - 1;
                }
                if (CurlyBal == 0) {
                    if (c == TheWord) {
                        TheReturn = lEFT(TheReturn, k - 1) + TheReplacement + rIGHT(TheReturn, lEN(TheReturn) - k - lEN(TheWord) + 1);
                        break;
                    }
                }
            }
        }
        if ((iNSTR(TheReturn, TheWord) > 0) & (TheReturn != TheString)) {
            TheReturn = replaceRaw(TheReturn, TheWord, TheReplacement);
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int scanForName (std::string TheStringIn, int TheCritPosIn, std::string TheSwitchIn) {
        // Returns the position of the beginning of a word or function name or number.
        int TheReturn;
        std::string TheString;
        std::string TheSwitch;
        int TheCritPos;
        std::string TheNaughtyList;
        std::string c;
        int k;
        int j;
        TheString = TheStringIn;
        TheSwitch = TheSwitchIn;
        TheCritPos = TheCritPosIn;
        TheNaughtyList = BrackList + OpList;
        TheReturn = -1;
        if (TheSwitch == "left") {
            for (k = TheCritPos - 1; k >= 1; k += (-1)) {
                c = mID(TheString, k, 1);
                for (j = 1; j <= lEN(TheNaughtyList); j += 1) {
                    if (c == mID(TheNaughtyList, j, 1)) {
                        TheReturn = k + 1;
                        break;
                    }
                }
                if (TheReturn > -1) {
                    break;
                }
            }
            if (TheReturn == -1) {
                TheReturn = 1;
            }
        }
        if (TheSwitch == "right") {
            for (k = TheCritPos + 1; k <= lEN(TheString); k += 1) {
                c = mID(TheString, k, 1);
                for (j = 1; j <= lEN(TheNaughtyList); j += 1) {
                    if (c == mID(TheNaughtyList, j, 1)) {
                        TheReturn = k - 1;
                    }
                }
                if (TheReturn > -1) {
                    break;
                }
            }
            if (TheReturn == -1) {
                TheReturn = lEN(TheString);
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

int scanForOperator (std::string TheStringIn, std::string TheSymbolIn) {
        int TheReturn;
        std::string TheString;
        std::string TheSymbol;
        TheString = TheStringIn;
        TheSymbol = TheSymbolIn;
        int BrackBal;
        int QuoteBal;
        int k;
        std::string c;
        std::string d;
        BrackBal = 0;
        QuoteBal = 0;
        TheReturn = -1;
        if (iNSTR(TheString, TheSymbol) > 0) {
            k = lEN(TheString);
            while (k >= 1) {
                c = mID(TheString, k, 1);
                if (k > 1) {
                    d = mID(TheString, k - 1, 1);
                }
                if (d != EscapeChar) {
                    if (c == "`") {
                        QuoteBal = QuoteBal + 1;
                    }
                    if (c == "'") {
                        QuoteBal = QuoteBal - 1;
                    }
                    if (QuoteBal == 0) {
                        if (iNSTR("(<{[", c) > 0) {
                            BrackBal = BrackBal + 1;
                        }
                        if (iNSTR(")>}]", c) > 0) {
                            BrackBal = BrackBal - 1;
                        }
                        if (BrackBal == 0) {
                            c = "_yes";
                            if (mID(TheString, k, lEN(TheSymbol)) == TheSymbol) {
                                // Prevents leading "+" and "-" signs from causing false triggers.
                                if ((TheSymbol == "+") | (TheSymbol == "-")) {
                                    if (k == 1) {
                                        c = "_no";
                                    }
                                }
                                if (k > 1) {
                                    if (iNSTR(OpList, mID(TheString, k - 1, 1)) > 0) {
                                        c = "_no";
                                    }
                                }
                                if (c == "_yes") {
                                    TheReturn = k;
                                    break;
                                }
                            }
                        }
                    }
                }
                k = k - 1;
            }
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string typeCheck (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        TheString = TheStringIn;
        if (lEN(TheString) > 1) {
            TheString = lEFT(TheString, 1);
        }
        TheReturn = "";
        if (TheReturn == "") {
            if (iNSTR("+-.0123456789", TheString) > 0) {
                TheReturn = "number";
            }
        }
        if (TheReturn == "") {
            if (iNSTR("()", TheString) > 0) {
                TheReturn = "paren";
            }
            if (iNSTR("`'", TheString) > 0) {
                TheReturn = "quote";
            }
            if (iNSTR("<>", TheString) > 0) {
                TheReturn = "vector";
            }
            if (iNSTR("{}", TheString) > 0) {
                TheReturn = "occult";
            }
            if (iNSTR("[]", TheString) > 0) {
                TheReturn = "symbol";
            }
            if (TheString == ",") {
                TheReturn = "separator";
            }
        }
        if (TheReturn == "") {
            TheReturn = "word";
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string manageOperators (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        TheString = TheStringIn;
        TheReturn = TheString;
        TheReturn = replaceWord(TheReturn, "^+", "^", -1);
        TheReturn = replaceWord(TheReturn, "*+", "*", -1);
        TheReturn = replaceWord(TheReturn, "/+", "/", -1);
        TheReturn = replaceWord(TheReturn, "++", "+", -1);
        TheReturn = replaceWord(TheReturn, "+-", "-", -1);
        TheReturn = replaceWord(TheReturn, "-+", "-", -1);
        TheReturn = replaceWord(TheReturn, "--", "+", -1);
        if (TheReturn != TheString) {
            TheReturn = manageOperators(TheReturn);
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string returnElement (std::string TheStringIn, int TheArgNumberIn, std::string TheSeparatorIn) {
        std::string TheReturn;
        std::string TheString;
        int TheArgNumber;
        std::string TheSeparator;
        int n;
        int m;
        TheString = TheStringIn;
        TheArgNumber = TheArgNumberIn;
        TheSeparator = TheSeparatorIn;
        TheReturn = "_null";
        n = countElements(TheString, TheSeparator);
        // If seeking first argument:
        if (TheReturn == "_null") {
            if (TheArgNumber == 1) {
                if (n == 1) {
                    if (TheSeparator == ",") {
                        TheReturn = removeWrapping(TheString, "<>");
                    }
                    if (TheSeparator == ":") {
                        TheReturn = TheString;
                    }
                }
                if (n > 1) {
                    TheReturn = TheString;
                    TheReturn = lEFT(TheReturn, getSeparatorPos(TheReturn, TheSeparator, 1, 1) - 1);
                    TheReturn = rIGHT(TheReturn, lEN(TheReturn) - 1);
                }
            }
        }
        // If seeking last argument:
        if (TheReturn == "_null") {
            if (TheArgNumber == n) {
                TheReturn = TheString;
                TheReturn = rIGHT(TheReturn, lEN(TheReturn) - getSeparatorPos(TheReturn, TheSeparator, n - 1, 1));
                TheReturn = lEFT(TheReturn, lEN(TheReturn) - 1);
            }
        }
        // Must have three or more arguments:
        if (TheReturn == "_null") {
            TheReturn = TheString;
            n = getSeparatorPos(TheReturn, TheSeparator, TheArgNumber - 1, 1);
            m = getSeparatorPos(TheReturn, TheSeparator, TheArgNumber, n + 1);
            TheReturn = mID(TheReturn, n + 1, (m - n) - 1);
        }
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string vectorASMD (std::string Vector1In, std::string Vector2In, std::string TheOperatorIn) {
        std::string TheReturn;
        std::string Vector1;
        std::string Vector2;
        std::string TheOperator;
        int size;
        int size2;
        int k;
        Vector1 = Vector1In;
        Vector2 = Vector2In;
        TheOperator = TheOperatorIn;
        size = countElements(Vector1, ",");
        size2 = countElements(Vector2, ",");
        if (size > size2) {
            size = size2;
        }
        TheReturn = "<";
        for (k = 1; k <= size; k += 1) {
            TheReturn = TheReturn + "(" + returnElement(Vector1, k, ",") + " " + TheOperator + " " + returnElement(Vector2, k, ",") + ")";
            if (k < size) {
                TheReturn = TheReturn + ",";
            }
        }
        TheReturn = TheReturn + ">";
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string internalEval (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        TheString = TheStringIn;
        TheString = manageWhiteSpace(TheString);
        TheReturn = "";
        while (TheString != TheReturn) {
            TheReturn = TheString;
            TheString = evalStep(TheString);
        }
        TheReturn = TheString;
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string structureEval (std::string TheVectorIn, std::string TheLeftBrackIn, std::string TheRightBrackIn) {
        std::string TheReturn;
        std::string TheVector;
        std::string TheLeftBrack;
        std::string TheRightBrack;
        std::string c;
        std::string c1;
        std::string c2;
        std::string d;
        int k;
        TheVector = TheVectorIn;
        TheLeftBrack = TheLeftBrackIn;
        TheRightBrack = TheRightBrackIn;
        d = "";
        k = findMatching(TheVector, TheLeftBrack, 1);
        c1 = lEFT(TheVector, k);
        c1 = removeWrapping(c1, TheLeftBrack + TheRightBrack);
        c2 = rIGHT(TheVector, lEN(TheVector) - k);
        while (1 == 1) {
            k = getSeparatorPos(TheLeftBrack + c1 + TheRightBrack, ",", 1, 1) - 1;
            if (k > -1) {
                c = lEFT(c1, k - 1);
                c = internalEval(c);
                d = d + c + ",";
                c1 = rIGHT(c1, lEN(c1) - k);
            } else {
                c = c1;
                c = internalEval(c);
                d = d + c;
                break;
            }
        }
        d = TheLeftBrack + d + TheRightBrack;
        TheReturn = d + internalEval(c2);
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string plotASCII (std::string TheFuncIn, double LowLimitIn, double HighLimitIn, double StepSizeIn, int WindowWidthIn, int WindowHeightIn, int DetailSwitchIn) {
        std::string TheReturn;
        std::string TheFunc;
        double LowLimit;
        double HighLimit;
        double StepSize;
        int WindowWidth;
        int WindowHeight;
        int DetailSwitch;
        TheFunc = TheFuncIn;
        LowLimit = LowLimitIn;
        HighLimit = HighLimitIn;
        StepSize = StepSizeIn;
        WindowWidth = WindowWidthIn;
        WindowHeight = WindowHeightIn;
        DetailSwitch = DetailSwitchIn;
        double j;
        int k;
        double kd;
        int n;
        int NumPoints;
        std::string tmp;
        std::string c;
        std::string d;
        double xmin;
        double xmax;
        double ymin;
        double ymax;
        double xave;
        double yave;
        double xzoom;
        double yzoom;
        int xtext;
        int ytext;
        double x;
        double y;

        NumPoints = 2 + (HighLimit - LowLimit) / (StepSize);

        // Factors of +1 added to accomodate C++ implementation.
        double PointArrayX[NumPoints + 1];
        double PointArrayY[NumPoints + 1];

        if (WindowWidth == 0) {
            WindowWidth = 25;
        }
        if (WindowHeight == 0) {
            WindowHeight = 10;
        }

        std::string AsciiPlane[WindowWidth + 1][WindowHeight + 1];


        for (k = 1; k <= WindowHeight; k += 1) {
            for (n = 1; n <= WindowWidth; n += 1) {
                AsciiPlane[n][k] = "_";
            }
        }

        xmin = LowLimit;
        xmax = HighLimit;
        ymin = 999999;
        ymax = -999999;
        k = 0;
        for (j = LowLimit; j <= HighLimit + StepSize; j += (StepSize)) {
            tmp = TheFunc + "(" + lTRIM(rTRIM(sTR(j))) + ")";
            tmp = internalEval(tmp);
            y = vAL(tmp);
            if (y > ymax) {
                ymax = y;
            }
            if (y < ymin) {
                ymin = y;
            }
            k = k + 1;
            PointArrayX[k] = j;
            PointArrayY[k] = y;
        }
        NumPoints = k;

        yave = (1 / 2) * (ymax + ymin);
        xave = (1 / 2) * (HighLimit + LowLimit);
        yzoom = (0.85 + 0.15) * aBS((WindowHeight) / (ymax - ymin));
        xzoom = (0.85 + 0.15) * aBS((WindowWidth) / (HighLimit - LowLimit));
        for (k = 1; k <= NumPoints; k += 1) {
            x = PointArrayX[k];
            y = PointArrayY[k];
            x = (x - xave) * xzoom;
            y = (y - yave) * yzoom;
            xtext = iNT(x + WindowWidth / 2);
            ytext = iNT(WindowHeight / 2 - y);
            tmp = "*";
            if (xtext < 1) {
                tmp = "<";
                xtext = 1;
            }
            if (xtext > WindowWidth) {
                tmp = ">";
                xtext = WindowWidth;
            }
            if (ytext < 1) {
                tmp = "^";
                ytext = 1;
            }
            if (ytext > WindowHeight) {
                tmp = ".";
                ytext = WindowHeight;
            }
            AsciiPlane[xtext][ytext] = tmp;
        }

        for (k = 1; k <= FunctionListSize; k += 1) {
            if (TheFunc == FunctionList[k][1]) {
                TheFunc = FunctionList[k][2];
            }
        }

        TheReturn = "`";
        TheReturn = TheReturn + "\n";
        if (DetailSwitch == 1) {
            TheReturn = TheReturn + TheFunc + " {" + lTRIM(rTRIM(sTR(LowLimit))) + ", " + lTRIM(rTRIM(sTR(HighLimit))) + "}";
            TheReturn = TheReturn + "\n";
        }
        for (k = 1; k <= WindowHeight; k += 1) {
            kd = k;

            // JavaScript: STARTSKIP
            kd = double(k);
            // JavaScript: ENDSKIP

            tmp = "";
            for (n = 1; n <= WindowWidth; n += 1) {
                TheReturn = TheReturn + AsciiPlane[n][k];
            }
            if (DetailSwitch == 1) {
                TheReturn = TheReturn + sTR(ymax - ((kd - 1) / WindowHeight) * (ymax - ymin) * (WindowHeight / (WindowHeight - 1)));
            }
            if (k < WindowHeight) {
                TheReturn = TheReturn + "\n";
            }
        }

        if (DetailSwitch == 1) {
            tmp = "";
            tmp = tmp + "\n";
            for (k = 1; k <= 10; k += 1) {
                for (j = WindowWidth; j >= 1; j += (-1)) {
                    c = sTR(xmax - ((j - 1) / WindowWidth) * (xmax - xmin) * (WindowWidth / (WindowWidth - 1)));
                    c = internalEval("1 * " + c);
                    if (k <= lEN(c)) {
                        d = mID(c, k, 1);
                        if (d == "") {
                            d = "0";
                        }
                        tmp = tmp + d;
                    }
                }
                tmp = tmp + "\n";
            }
            TheReturn = TheReturn + "\n";
            TheReturn = TheReturn + tmp;
        }

        TheReturn = TheReturn + "\n";
        TheReturn = TheReturn + "'";
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string plotScatter (std::string TheListIn, int WindowWidthIn, int WindowHeightIn, int DetailSwitchIn) {
        std::string TheReturn;
        std::string TheList;
        int WindowWidth;
        int WindowHeight;
        int DetailSwitch;
        TheList = TheListIn;
        WindowWidth = WindowWidthIn;
        WindowHeight = WindowHeightIn;
        DetailSwitch = DetailSwitchIn;
        double j;
        int k;
        int n;
        int NumPoints;
        std::string tmp;
        std::string c;
        std::string d;
        double xmin;
        double xmax;
        double ymin;
        double ymax;
        double xave;
        double yave;
        double xzoom;
        double yzoom;
        int xtext;
        int ytext;
        double x;
        double y;

        NumPoints = countElements(TheList, ",");

        // Factors of +1 added to accomodate C++ implementation.
        double PointArrayX[NumPoints + 1];
        double PointArrayY[NumPoints + 1];

        if (WindowWidth == 0) {
            WindowWidth = 25;
        }
        if (WindowHeight == 0) {
            WindowHeight = 10;
        }

        std::string AsciiPlane[WindowWidth + 1][WindowHeight + 1];


        for (k = 1; k <= WindowHeight; k += 1) {
            for (n = 1; n <= WindowWidth; n += 1) {
                AsciiPlane[n][k] = " ";
            }
        }

        xmin = 999999;
        xmax = -999999;
        ymin = 999999;
        ymax = -999999;
        for (k = 1; k <= NumPoints; k += 1) {
            tmp = returnElement(TheList, k, ",");
            x = vAL(returnElement(tmp, 1, ","));
            y = vAL(returnElement(tmp, 2, ","));
            if (x > xmax) {
                xmax = x;
            }
            if (x < xmin) {
                xmin = x;
            }
            if (y > ymax) {
                ymax = y;
            }
            if (y < ymin) {
                ymin = y;
            }
            PointArrayX[k] = x;
            PointArrayY[k] = y;
        }

        yave = (1 / 2) * (ymax + ymin);
        xave = (1 / 2) * (xmax + xmin);
        yzoom = (0.85 + 0.15) * aBS((WindowHeight) / (ymax - ymin));
        xzoom = (0.85 + 0.15) * aBS((WindowWidth) / (xmax - xmin));
        for (k = 1; k <= NumPoints; k += 1) {
            x = PointArrayX[k];
            y = PointArrayY[k];
            x = (x - xave) * xzoom;
            y = (y - yave) * yzoom;
            xtext = iNT(x + WindowWidth / 2);
            ytext = iNT(WindowHeight / 2 - y);
            tmp = "*";
            if (xtext < 1) {
                tmp = "*";
                xtext = 1;
            }
            if (xtext > WindowWidth) {
                tmp = "*";
                xtext = WindowWidth;
            }
            if (ytext < 1) {
                tmp = "*";
                ytext = 1;
            }
            if (ytext > WindowHeight) {
                tmp = "*";
                ytext = WindowHeight;
            }
            AsciiPlane[xtext][ytext] = tmp;
        }

        TheReturn = "`";
        TheReturn = TheReturn + "\n";
        for (k = 1; k <= WindowHeight; k += 1) {
            tmp = "";
            for (n = 1; n <= WindowWidth; n += 1) {
                TheReturn = TheReturn + AsciiPlane[n][k];
            }
            if (DetailSwitch == 1) {
                TheReturn = TheReturn + sTR(ymax - ((k - 1) / WindowHeight) * (ymax - ymin) * (WindowHeight / (WindowHeight - 1)));
            }
            if (k < WindowHeight) {
                TheReturn = TheReturn + "\n";
            }
        }

        if (DetailSwitch == 1) {
            tmp = "";
            tmp = tmp + "\n";
            for (k = 1; k <= 10; k += 1) {
                for (j = WindowWidth; j >= 1; j += (-1)) {
                    c = sTR(xmax - ((j - 1) / WindowWidth) * (xmax - xmin) * (WindowWidth / (WindowWidth - 1)));
                    c = internalEval("1 * " + c);
                    d = mID(c, k, 1);
                    if (d == "") {
                        d = "0";
                    }
                    tmp = tmp + d;
                }
                tmp = tmp + "\n";
            }
            TheReturn = TheReturn + "\n";
            TheReturn = TheReturn + tmp;
        }

        TheReturn = TheReturn + "\n";
        TheReturn = TheReturn + "'";
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string histASCII (std::string TheListIn, int DetailSwitchIn) {
        std::string TheReturn;
        std::string TheList;
        int DetailSwitch;
        TheList = TheListIn;
        int WindowHeight;
        int WindowWidth;
        DetailSwitch = DetailSwitchIn;
        int j;
        int k;
        int n;
        int NumPoints;
        std::string tmp;
        std::string c;
        std::string d;
        double xmin;
        double xmax;
        double ymin;
        double ymax;
        double x;
        double y;

        NumPoints = countElements(TheList, ",");

        // Factors of +1 added to accomodate C++ implementation.
        double PointArrayX[NumPoints + 1];
        double PointArrayY[NumPoints + 1];

        WindowWidth = NumPoints;
        WindowHeight = 10 + 1;

        std::string AsciiPlane[WindowWidth + 1][WindowHeight + 1];


        for (k = 1; k <= WindowHeight; k += 1) {
            for (n = 1; n <= WindowWidth; n += 1) {
                AsciiPlane[n][k] = "_";
            }
        }

        xmin = 999999;
        xmax = -999999;
        for (j = 1; j <= NumPoints; j += 1) {
            tmp = "elem(elem(" + TheList + "," + lTRIM(rTRIM(sTR(j))) + "), 1)";
            tmp = internalEval(tmp);
            x = vAL(tmp);
            if (x < xmin) {
                xmin = x;
            }
            if (x > xmax) {
                xmax = x;
            }
            PointArrayX[j] = x;
        }

        ymin = 999999;
        ymax = -999999;
        for (j = 1; j <= NumPoints; j += 1) {
            tmp = "elem(elem(" + TheList + "," + lTRIM(rTRIM(sTR(j))) + "), 2)";
            tmp = internalEval(tmp);
            y = vAL(tmp);
            if (y < ymin) {
                ymin = y;
            }
            if (y > ymax) {
                ymax = y;
            }
            PointArrayY[j] = y;
        }

        for (k = 1; k <= NumPoints; k += 1) {
            n = iNT(WindowHeight - (PointArrayY[k] * (WindowHeight - 1) / ymax));
            AsciiPlane[k][n] = "*";
        }

        TheReturn = "`";
        TheReturn = TheReturn + "\n";
        for (k = 1; k <= WindowHeight; k += 1) {
            for (n = 1; n <= WindowWidth; n += 1) {
                TheReturn = TheReturn + AsciiPlane[n][k];
            }
            if (DetailSwitch == 1) {
                TheReturn = TheReturn + sTR(ymax - ((k - 1) / WindowHeight) * (ymax - ymin) * (WindowHeight / (WindowHeight - 1)));
            }
            if (k < WindowHeight) {
                TheReturn = TheReturn + "\n";
            }
        }

        if (DetailSwitch == 1) {
            tmp = "";
            tmp = tmp + "\n";
            for (k = 1; k <= 10; k += 1) {
                for (j = 1; j <= NumPoints; j += 1) {
                    c = lTRIM(rTRIM(sTR(PointArrayX[j])));
                    c = internalEval("1 * " + c);
                    d = mID(c, k, 1);
                    if (d == "") {
                        d = "0";
                    }
                    tmp = tmp + d;
                }
                tmp = tmp + "\n";
            }
            TheReturn = TheReturn + "\n";
            TheReturn = TheReturn + tmp;
        }

        TheReturn = TheReturn + "\n";
        TheReturn = TheReturn + "'";
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string structureApplyFunc (std::string TheVectorIn, std::string TheFunctionIn, std::string TheBracketsIn) {
        std::string TheReturn;
        std::string TheVector;
        std::string TheFunction;
        std::string TheBrackets;
        int size;
        TheVector = TheVectorIn;
        TheFunction = TheFunctionIn;
        TheBrackets = TheBracketsIn;
        int k;
        TheReturn = lEFT(TheBrackets, 1);
        size = countElements(TheVector, ",");
        for (k = 1; k <= size; k += 1) {
            TheReturn = TheReturn + TheFunction + "(" + returnElement(TheVector, k, ",") + ")";
            if (k < size) {
                TheReturn = TheReturn + ",";
            }
        }
        TheReturn = TheReturn + rIGHT(TheBrackets, 1);
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string structureApplyTailOp (std::string TheVectorIn, std::string TheFunctionIn, std::string TheBracketsIn) {
        std::string TheReturn;
        std::string TheVector;
        std::string TheFunction;
        std::string TheBrackets;
        int size;
        TheVector = TheVectorIn;
        TheFunction = TheFunctionIn;
        TheBrackets = TheBracketsIn;
        int k;
        TheReturn = lEFT(TheBrackets, 1);
        size = countElements(TheVector, ",");
        for (k = 1; k <= size; k += 1) {
            TheReturn = TheReturn + "(" + returnElement(TheVector, k, ",") + TheFunction + ")";
            if (k < size) {
                TheReturn = TheReturn + ",";
            }
        }
        TheReturn = TheReturn + rIGHT(TheBrackets, 1);
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string formatForTerminal (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        TheString = TheStringIn;

        TheString = replaceRaw(TheString, cHR(26), "");

        TheString = replaceRaw(TheString, EscapeChar + "t", "\t");
        TheString = replaceRaw(TheString, EscapeChar + "n", "\n");
        TheString = replaceRaw(TheString, EscapeChar + "r", "\r");

        TheString = replaceRaw(TheString, EscapeChar + "`", cHR(26));
        TheString = replaceRaw(TheString, "`", "");
        TheString = replaceRaw(TheString, cHR(26), "`");

        TheString = replaceRaw(TheString, EscapeChar + "'", cHR(26));
        TheString = replaceRaw(TheString, "'", "");
        TheString = replaceRaw(TheString, cHR(26), "'");

        TheString = replaceRaw(TheString, "{" + EscapeChar + "}", "");

        TheString = replaceRaw(TheString, EscapeChar + EscapeChar, cHR(26));
        TheString = replaceRaw(TheString, EscapeChar, "");
        TheString = replaceRaw(TheString, cHR(26), EscapeChar);

        TheReturn = TheString;
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string functionCrunch (std::string ScannedNameIn, std::string MidFragmentIn) {
        std::string TheReturn;
        std::string ScannedName;
        std::string MidFragment;

        std::string ArgArray[101];
        int ArgArraySize;

        int k;
        int m;
        int n;

        double t;
        double z;

        std::string c;
        std::string d;
        std::string e;
        std::string f;
        std::string g;

        ScannedName = ScannedNameIn;
        MidFragment = MidFragmentIn;

        // Evaluate argument list.
        MidFragment = internalEval(MidFragment);

        if (typeCheck(MidFragment) == "paren") {
            ArgArraySize = countElements(MidFragment, ",");
            for (n = 1; n <= ArgArraySize; n += 1) {
                ArgArray[n] = returnElement(MidFragment, n, ",");
            }
        } else {
            ArgArray[1] = MidFragment;
        }

        // Identity:

        if (ScannedName == "identity") {
            ScannedName = "";
            c = ArgArray[1];
            //d = ArgArray(2)
            MidFragment = c;
        }

        if (ScannedName == "join") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            MidFragment = c + d;
        }

        // Variables:

        if (ScannedName == "let") {
            ScannedName = "";
            n = countElements(MidFragment, ",");
            c = removeWrapping(ArgArray[1], "`'");
            m = -1;
            for (k = 1; k <= VariableListSize; k += 1) {
                if (c == VariableList[k][1]) {
                    m = k;
                }
            }
            if (m == -1) {
                VariableListSize = VariableListSize + 1;
                m = VariableListSize;
                VariableList[m][1] = c;
            }
            if (n == 2) {
                d = ArgArray[2];
            } else {
                d = "";
                for (k = 2; k <= ArgArraySize; k += 1) {
                    d = d + ArgArray[k];
                    if (k < ArgArraySize) {
                        d = d + ",";
                    }
                }
            }
            VariableList[m][2] = d;
            MidFragment = d;
        }

        if (ScannedName == "alet") {
            ScannedName = "";
            c = removeWrapping(ArgArray[1], "`'");
            d = "-1";
            for (k = 1; k <= VariableListSize; k += 1) {
                if (c == VariableList[k][1]) {
                    d = lTRIM(rTRIM(sTR(k)));
                    break;
                }
            }
            MidFragment = d;
        }

        if (ScannedName == "input") {
            ScannedName = "";
            f = ArgArray[1];
            g = formatForTerminal(ArgArray[2]);

            // JavaScript: ENDSKIP


            // JavaScript: STARTSKIP
            std::cout << g;
            std::cin >> c;
            // JavaScript: ENDSKIP

            MidFragment = internalEval("let(" + f + "," + c + ")");
        }

        // Function:

        if (ScannedName == "func") {
            ScannedName = "";
            c = removeWrapping(ArgArray[1], "`'");
            d = ArgArray[2];
            for (k = 1; k <= FunctionListSize; k += 1) {
                if (c == FunctionList[k][1]) {
                    FunctionList[k][2] = d;
                    MidFragment = c;
                    c = "_null";
                    break;
                }
            }
            if (c != "_null") {
                FunctionListSize = FunctionListSize + 1;
                FunctionList[FunctionListSize][1] = c;
                FunctionList[FunctionListSize][2] = d;
                MidFragment = c;
            }
        }

        // Lambda:

        if ((ScannedName == "lambda") | (ScannedName == "$")) {
            ScannedName = "";
            c = "lambda" + lTRIM(rTRIM(sTR(iNT(rand() % 9999))));
            d = ArgArray[1];
            for (k = 1; k <= FunctionListSize; k += 1) {
                if (d == FunctionList[k][2]) {
                    MidFragment = FunctionList[k][1];
                    c = "_null";
                    break;
                }
            }
            if (c != "_null") {
                FunctionListSize = FunctionListSize + 1;
                FunctionList[FunctionListSize][1] = c;
                FunctionList[FunctionListSize][2] = d;
                MidFragment = c;
            }
        }

        // Date / Time:

        if (ScannedName == "time") {
            ScannedName = "";

            // JavaScript: STARTSKIP



            MidFragment = "`" + c + "'";
        }

        if (ScannedName == "date") {
            ScannedName = "";

            // JavaScript: STARTSKIP


            // JavaScript: STARTSKIP
            // JavaScript: ENDSKIP

            MidFragment = "`" + c + "'";
        }

        // Memory:

        if (ScannedName == "report") {
            ScannedName = "";
            if (MidFragment == "()") {
                c = "{";
                for (k = 1; k <= FunctionListSize; k += 1) {
                    c = c + "func(" + FunctionList[k][1] + "," + FunctionList[k][2] + ")";
                    c = c + " : ";
                }
                for (k = 1; k <= VariableListSize; k += 1) {
                    c = c + "let(" + VariableList[k][1] + "," + VariableList[k][2] + ")";
                    c = c + " : ";
                }
                c = c + "print_()}";
            } else {
                d = ArgArray[1];
                for (k = 1; k <= FunctionListSize; k += 1) {
                    if (d == FunctionList[k][1]) {
                        c = FunctionList[k][2];
                        break;
                    }
                }
            }
            MidFragment = c;
        }

        if (ScannedName == "reset") {
            ScannedName = "";
            VariableListSize = 0;
            FunctionListSize = 0;
            MidFragment = "report()";
        }

        // Type-wrapping and unwrapping:

        if (ScannedName == "type") {
            ScannedName = "";
            MidFragment = "`" + typeCheck(lEFT(ArgArray[1], 1)) + "'";
        }
        if (ScannedName == "quote") {
            ScannedName = "";
            MidFragment = "`" + ArgArray[1] + "'";
        }
        if (ScannedName == "unquote") {
            ScannedName = "";
            MidFragment = removeWrapping(ArgArray[1], "`'");
        }
        if (ScannedName == "vector") {
            ScannedName = "";
            MidFragment = "<" + ArgArray[1] + ">";
        }
        if (ScannedName == "unvector") {
            ScannedName = "";
            MidFragment = removeWrapping(ArgArray[1], "<>");
        }
        if (ScannedName == "occult") {
            ScannedName = "";
            MidFragment = "{" + ArgArray[1] + "}";
        }
        if (ScannedName == "unoccult") {
            ScannedName = "";
            MidFragment = removeWrapping(ArgArray[1], "{}");
        }
        if (ScannedName == "symbol") {
            ScannedName = "";
            MidFragment = "[" + ArgArray[1] + "]";
        }
        if (ScannedName == "unsymbol") {
            ScannedName = "";
            MidFragment = removeWrapping(ArgArray[1], "[]");
        }

        // Subprograms:

        if (ScannedName == "sub") {
            ScannedName = "";
            MidFragment = subExecute(removeWrapping(MidFragment, "{}"), "inline", "_yes");
        }
        if (ScannedName == "block") {
            ScannedName = "";
            MidFragment = subExecute(removeWrapping(MidFragment, "{}"), "inline", "_no");
        }
        if (ScannedName == "exe") {
            ScannedName = "";
            MidFragment = subExecute(removeWrapping(MidFragment, "`'"), "file", "_yes");
        }
        if (ScannedName == "include") {
            ScannedName = "";
            MidFragment = subExecute(removeWrapping(MidFragment, "`'"), "file", "_no");
        }

        // Flow-Control:

        if (ScannedName == "iff") {
            ScannedName = "";
            c = ArgArray[1];
            if (vAL(c) == 1) {
                MidFragment = removeWrapping(ArgArray[2], "{}");
            } else {
                if (countElements(MidFragment, ",") == 2) {
                    MidFragment = "";
                }
                if (countElements(MidFragment, ",") == 3) {
                    MidFragment = removeWrapping(ArgArray[3], "{}");
                }
            }
        }

        if (ScannedName == "for") {
            ScannedName = "";
            c = ArgArray[1];
            d = removeWrapping(ArgArray[2], "{}");
            e = "";
            if (vAL(returnElement(c, 2, ",")) < vAL(returnElement(c, 3, ","))) {
                z = vAL(returnElement(c, 4, ","));
                for (t = vAL(returnElement(c, 2, ",")); t <= vAL(returnElement(c, 3, ",")); t += (z)) {
                    f = internalEval("let(" + returnElement(c, 1, ",") + "," + sTR(t) + "+0)");
                    e = e + internalEval(d);
                }
            } else {
                if (vAL(returnElement(c, 2, ",")) == vAL(returnElement(c, 3, ","))) {
                    f = internalEval("let(" + returnElement(c, 1, ",") + "," + returnElement(c, 2, ",") + ")");
                    e = e + internalEval(d);
                } else {
                    z = aBS(vAL(returnElement(c, 4, ",")));
                    for (t = vAL(returnElement(c, 2, ",")); t >= vAL(returnElement(c, 3, ",")); t += (-1 * z)) {
                        f = internalEval("let(" + returnElement(c, 1, ",") + "," + sTR(t) + "+0)");
                        e = e + internalEval(d);
                    }
                }
            }
            MidFragment = e;
        }

        // Numeric (strict):

        if (ScannedName == "abs") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = aBS(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "atan") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = atan(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "cos") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = cos(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "greater") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            if (vAL(c) > vAL(d)) {
                MidFragment = "1";
            } else {
                MidFragment = "0";
            }
        }

        if (ScannedName == "int") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = iNT(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "ln") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                z = vAL(ArgArray[1]);

                // JavaScript: STARTSKIP


                // JavaScript: STARTSKIP
                t = log(z);
                // JavaScript: ENDSKIP

                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "rand") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                z = vAL(ArgArray[1]);

                // JavaScript: STARTSKIP


                // JavaScript: STARTSKIP
                t = (rand() % RAND_MAX) * (z / RAND_MAX);
                // JavaScript: ENDSKIP

                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "sgn") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = sGN(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "sin") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = sin(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "sqrt") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                if (t >= 0) {
                    t = sQR(t);
                    MidFragment = lTRIM(rTRIM(sTR(t)));
                } else {
                    MidFragment = "{ERROR: Negative argument sent to sqrt().}";
                }
            }
        }

        if (ScannedName == "tan") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                t = vAL(ArgArray[1]);
                t = tan(t);
                MidFragment = lTRIM(rTRIM(sTR(t)));
            }
        }

        if (ScannedName == "unf") {
            ScannedName = "";
            if (typeCheck(lEFT(ArgArray[1], 1)) == "number") {
                MidFragment = lTRIM(rTRIM(sTR(vAL(ArgArray[1]))));
            } else {
                MidFragment = ArgArray[1];
            }
        }

        // Graphics:

        if (ScannedName == "plot") {
            ScannedName = "";
            MidFragment = plotASCII(ArgArray[1], vAL(ArgArray[2]), vAL(ArgArray[3]), vAL(ArgArray[4]), vAL(ArgArray[5]), vAL(ArgArray[6]), vAL(ArgArray[7]));
        }

        if (ScannedName == "scatter") {
            ScannedName = "";
            MidFragment = plotScatter(ArgArray[1], vAL(ArgArray[2]), vAL(ArgArray[3]), vAL(ArgArray[4]));
        }

        if (ScannedName == "hist") {
            ScannedName = "";
            MidFragment = histASCII(ArgArray[1], vAL(ArgArray[2]));
        }

        // Largenum:

        if (ScannedName == "largeadd") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            MidFragment = bigNumAdd(c, d);
        }

        if (ScannedName == "largesub") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            MidFragment = bigNumSub(c, d);
        }

        if (ScannedName == "largemul") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            MidFragment = bigNumMul(c, d);
        }

        if (ScannedName == "largediv") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            k = lEN(c);
            n = lEN(d);
            n = n + k;
            if (n < 16) {
                n = 16;
            }
            MidFragment = bigNumDiv(c, d, n);
        }

        // Strings (strict):


        if (ScannedName == "chr") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "number") {
                c = cHR(vAL(ArgArray[1]));
                if (c == " ") {
                    c = EscapeChar + c;
                }
                MidFragment = c;
            }
        }

        if (ScannedName == "instr") {
            ScannedName = "";
            c = removeWrapping(ArgArray[1], "`'");
            d = removeWrapping(ArgArray[2], "`'");
            MidFragment = lTRIM(rTRIM(sTR(iNSTR(c, d))));
        }

        if (ScannedName == "lcase") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "quote") {
                MidFragment = lCASE(ArgArray[1]);
            }
        }

        if (ScannedName == "ucase") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[1], 1, 1)) == "quote") {
                MidFragment = uCASE(ArgArray[1]);
            }
        }

        // Elements (shared):

        if (ScannedName == "mid") {
            ScannedName = "";
            c = ArgArray[1];
            d = typeCheck(lEFT(c, 1));
            if (d == "number") {
                f = ArgArray[2];
                g = ArgArray[3];
                c = mID(c, vAL(f), vAL(g));
                MidFragment = c;
            }
            if (d == "quote") {
                c = removeWrapping(c, "`'");
                f = ArgArray[2];
                g = ArgArray[3];
                c = mID(c, vAL(f), vAL(g));
                MidFragment = "`" + c + "'";
            }
            if (d == "vector") {
                f = ArgArray[2];
                g = ArgArray[3];
                if ((vAL(f) > 0) & (vAL(g) > 0)) {
                    k = getSeparatorPos(c, ",", vAL(f) - 1, 1);
                    if (k == -1) {
                        k = 1;
                    }
                    n = getSeparatorPos(c, ",", vAL(f) + vAL(g) - 1, 1);
                    if (n == -1) {
                        n = findMatching(c, lEFT(c, 1), 1);
                    }
                    if ((k > -1) & (n > -1)) {
                        MidFragment = lEFT(c, 1) + mID(c, k + 1, n - k - 1) + rIGHT(c, 1);
                    }
                } else {
                    MidFragment = lEFT(c, 1) + rIGHT(c, 1);
                }
            }
            if (d == "occult") {
                f = ArgArray[2];
                g = ArgArray[3];
                if ((vAL(f) > 0) & (vAL(g) > 0)) {
                    k = getSeparatorPos(c, ":", vAL(f) - 1, 1);
                    if (k == -1) {
                        k = 1;
                    }
                    n = getSeparatorPos(c, ":", vAL(f) + vAL(g) - 1, 1);
                    if (n == -1) {
                        n = findMatching(c, lEFT(c, 1), 1);
                    }
                    if ((k > -1) & (n > -1)) {
                        MidFragment = lEFT(c, 1) + mID(c, k + 1, n - k - 1) + rIGHT(c, 1);
                    }
                } else {
                    MidFragment = lEFT(c, 1) + rIGHT(c, 1);
                }
            }
        }

        if (ScannedName == "left") {
            ScannedName = "";
            c = ArgArray[1];
            d = typeCheck(lEFT(c, 1));
            if (d == "number") {
                e = ArgArray[2];
                c = lEFT(c, vAL(e));
                MidFragment = c;
            }
            if (d == "quote") {
                c = removeWrapping(c, "`'");
                e = ArgArray[2];
                c = lEFT(c, vAL(e));
                MidFragment = "`" + c + "'";
            }
            if (d == "vector") {
                e = ArgArray[2];
                if (vAL(e) > 0) {
                    k = getSeparatorPos(c, ",", vAL(e), 1);
                    if (k == -1) {
                        k = findMatching(c, lEFT(c, 1), 1);
                    }
                    if (k > -1) {
                        MidFragment = lEFT(c, k - 1) + rIGHT(c, 1);
                    }
                } else {
                    MidFragment = lEFT(c, 1) + rIGHT(c, 1);
                }
            }
            if (d == "occult") {
                e = ArgArray[2];
                if (vAL(e) > 0) {
                    k = getSeparatorPos(c, ":", vAL(e), 1);
                    if (k == -1) {
                        k = findMatching(c, lEFT(c, 1), 1);
                    }
                    if (k > -1) {
                        MidFragment = lEFT(c, k - 1) + rIGHT(c, 1);
                    }
                } else {
                    MidFragment = lEFT(c, 1) + rIGHT(c, 1);
                }
            }
        }

        if (ScannedName == "right") {
            ScannedName = "";
            c = ArgArray[1];
            d = typeCheck(lEFT(c, 1));
            if (d == "number") {
                e = ArgArray[2];
                c = rIGHT(c, vAL(e));
                MidFragment = c;
            }
            if (d == "quote") {
                c = removeWrapping(c, "`'");
                e = ArgArray[2];
                c = rIGHT(c, vAL(e));
                MidFragment = "`" + c + "'";
            }
            if (d == "vector") {
                e = ArgArray[2];
                if (vAL(e) > 0) {
                    k = getSeparatorPos(c, ",", countElements(c, ",") - vAL(e), 1);
                    if (k == -1) {
                        k = 1;
                    }
                    if (k > -1) {
                        MidFragment = lEFT(c, 1) + rIGHT(c, lEN(c) - k);
                    }
                } else {
                    MidFragment = lEFT(c, 1) + rIGHT(c, 1);
                }
            }
            if (d == "occult") {
                e = ArgArray[2];
                if (vAL(e) > 0) {
                    k = getSeparatorPos(c, ":", countElements(c, ":") - vAL(e), 1);
                    if (k == -1) {
                        k = 1;
                    }
                    if (k > -1) {
                        MidFragment = lEFT(c, 1) + rIGHT(c, lEN(c) - k);
                    }
                } else {
                    MidFragment = lEFT(c, 1) + rIGHT(c, 1);
                }
            }
        }

        if (ScannedName == "len") {
            ScannedName = "";
            d = typeCheck(ArgArray[1]);
            if ((d == "number") | (d == "word")) {
                c = ArgArray[1];
                MidFragment = lTRIM(rTRIM(sTR(lEN(c))));
            }
            if (d == "quote") {
                c = removeWrapping((ArgArray[1]), "`'");
                MidFragment = lTRIM(rTRIM(sTR(lEN(c))));
            }
            if (d == "vector") {
                MidFragment = lTRIM(rTRIM(sTR(countElements(ArgArray[1], ","))));
            }
            if (d == "occult") {
                MidFragment = lTRIM(rTRIM(sTR(countElements(ArgArray[1], ":"))));
            }
        }

        if (ScannedName == "elem") {
            ScannedName = "";
            d = typeCheck(ArgArray[1]);
            if (d == "vector") {
                c = returnElement(ArgArray[1], vAL(ArgArray[2]), ",");
            }
            if (d == "occult") {
                c = returnElement(ArgArray[1], vAL(ArgArray[2]), ":");
                c = "{" + c + "}";
            }
            MidFragment = c;
        }

        if (ScannedName == "stack") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            f = typeCheck(c);
            if (f == "vector") {
                c = removeWrapping(c, "<>");
                d = removeWrapping(d, "<>");
                e = "<" + c + "," + d + ">";
            }
            if (f == "occult") {
                c = removeWrapping(c, "{}");
                d = removeWrapping(d, "{}");
                e = "{" + c + ":" + d + "}";
            }
            MidFragment = e;
        }

        if (ScannedName == "replace") {
            ScannedName = "";
            c = ArgArray[1];
            n = vAL(ArgArray[2]);
            d = removeWrapping(ArgArray[3], "{}");
            e = typeCheck(c);
            if (e == "vector") {
                k = countElements(c, ",");
                if (n == 1) {
                    c = rIGHT(c, lEN(c) - getSeparatorPos(c, ",", 1, 1) + 1);
                    c = "<" + d + c;
                }
                if (n == k) {
                    c = lEFT(c, getSeparatorPos(c, ",", k - 1, 1));
                    c = c + d + ">";
                }
                if ((n > 1) & (n < countElements(c, ","))) {
                    c = lEFT(c, getSeparatorPos(c, ",", n - 1, 1)) + d + rIGHT(c, lEN(c) - getSeparatorPos(c, ",", n, 1) + 1);
                }
            }
            if (e == "occult") {
                k = countElements(c, ":");
                if (n == 1) {
                    c = rIGHT(c, lEN(c) - getSeparatorPos(c, ":", 1, 1) + 1);
                    c = "{" + d + c;
                }
                if (n == k) {
                    c = lEFT(c, getSeparatorPos(c, ":", k - 1, 1));
                    c = c + d + "}";
                }
                if ((n > 1) & (n < countElements(c, ":"))) {
                    c = lEFT(c, getSeparatorPos(c, ":", n - 1, 1)) + d + rIGHT(c, lEN(c) - getSeparatorPos(c, ":", n, 1) + 1);
                }
            }
            MidFragment = c;
        }

        // Vectors (strict):

        if (ScannedName == "column") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[2];
            n = countElements(c, ",");
            e = "";
            if (countElements(returnElement(c, 1, ","), ",") > 1) {
                for (k = 1; k <= n; k += 1) {
                    e = e + returnElement(returnElement(c, k, ","), vAL(d), ",");
                    if (k < n) {
                        e = e + ",";
                    }
                }
                e = "<" + e + ">";
            } else {
                e = returnElement(c, vAL(d), ",");
            }
            MidFragment = e;
        }

        if (ScannedName == "smooth") {
            ScannedName = "";
            c = ArgArray[1];
            d = typeCheck(c);
            if (d == "vector") {
                c = replaceWord(c, ",,", ",", -1);
                c = replaceWord(c, "<,", "<", -1);
                c = replaceWord(c, ",>", ">", -1);
            }
            if (d == "occult") {
                c = replaceWord(c, "::", ":", -1);
                c = replaceWord(c, "{:", "{", -1);
                c = replaceWord(c, ":}", "}", -1);
            }
            MidFragment = c;
        }

        // Vectors (processing):

        if (ScannedName == "apply") {
            ScannedName = "";
            if (typeCheck(mID(ArgArray[2], 1, 1)) == "vector") {
                MidFragment = structureApplyFunc(ArgArray[2], ArgArray[1], "<>");
            }
        }

        if (ScannedName == "map") {
            ScannedName = "";
            c = ArgArray[1];
            d = ArgArray[3];
            e = ArgArray[2];
            n = countElements(c, ",");
            m = countElements(d, ",");
            if (n > m) {
                n = m;
            }
            f = lEFT(c, 1);
            for (k = 1; k <= n; k += 1) {
                f = f + e + "(" + returnElement(c, k, ",") + "," + returnElement(d, k, ",") + ")";
                if (k < n) {
                    f = f + ",";
                }
            }
            f = f + rIGHT(c, 1);
            MidFragment = f;
        }

        if (ScannedName == "reduce") {
            ScannedName = "";
            d = ArgArray[1];
            e = ArgArray[2];
            c = d + "(" + returnElement(e, 1, ",") + "," + returnElement(e, 2, ",") + ")";
            for (k = 2; k <= countElements(e, ",") - 1; k += 1) {
                c = d + "(" + c + "," + returnElement(e, k + 1, ",") + ")";
            }
            MidFragment = c;
        }

        TheReturn = ScannedName + MidFragment;

        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string evalStep (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        int LeftBrackPos;
        int RightBrackPos;
        int ScannedNameStart;
        std::string ScannedName;
        std::string LeftFragment;
        std::string MidFragment;
        std::string RightFragment;
        int k;
        int n;
        int m;
        //DIM t AS DOUBLE
        //DIM z AS DOUBLE
        std::string c;
        std::string d;
        TheString = TheStringIn;
        TheReturn = "";
        LeftBrackPos = -1;
        RightBrackPos = -1;
        ScannedNameStart = -1;
        ScannedName = "";
        LeftFragment = "";
        MidFragment = "";
        RightFragment = "";

        // Replace variable references with literal representations:
        //   Variables in square brackets ( [] ) are replaced outside of all occulted ( {} ) brackets.
        //   Variables in curvy brackets ( {} ) are replaced down to the fourth (4th) level of occulted ( {} ) brackets.
        if (TheReturn == "") {
            c = TheString;
            for (k = 1; k <= VariableListSize; k += 1) {
                c = replaceWord(c, "[" + VariableList[k][1] + "]", VariableList[k][2], 0);
                c = replaceWord(c, "{" + VariableList[k][1] + "}", VariableList[k][2], 4);
            }
            if (c != TheString) {
                TheReturn = c;
            }
        }

        // Scan for most-embedded structure and break the input string into fragments:
        //   LeftFragment = Everything to the left of the inner-most parenthesized structure or ScannedName (can be empty).
        //   ScannedName = Word to the left of the most-embedded set of parentheses (if found).
        //   MidFragment = (i)  Most-embedded structure contained in parens ( ), OR
        //                 (ii) If no parens detected, the whole input string.
        //   RightFragment = Everything to the right of the inner-most parenthesized structure (can be empty).
        //   Note: LeftFragment and RightFragment remain static. All changes occur in ScannedName and MidFragment.
        if (TheReturn == "") {
            LeftBrackPos = findMostEmbedded(TheString);
            if (LeftBrackPos > -1) {
                RightBrackPos = findMatching(TheString, "(", LeftBrackPos);
            } else {
                MidFragment = TheString;
            }
            if (RightBrackPos > -1) {
                MidFragment = mID(TheString, LeftBrackPos, (RightBrackPos - LeftBrackPos) + 1);
                RightFragment = rIGHT(TheString, lEN(TheString) - RightBrackPos);
                ScannedNameStart = scanForName(TheString, LeftBrackPos, "left");
                if (ScannedNameStart != LeftBrackPos) {
                    LeftFragment = lEFT(TheString, ScannedNameStart - 1);
                    ScannedName = mID(TheString, ScannedNameStart, (LeftBrackPos - ScannedNameStart));
                } else {
                    LeftFragment = lEFT(TheString, LeftBrackPos - 1);
                }
            }
        }

        // If input expression contains no zero-level (unocculted) parens:
        if ((LeftBrackPos == -1) & (RightBrackPos == -1) & (ScannedName == "")) {

            // Pass through NumberCrunch (regardless of input type).
            //   If NumberCrunch changes input string, loop until a stable result is reached. (--> ^)
            //   If input was already stable (emerges unchanged), pass control downward.
            if (TheReturn == "") {
                d = TheString;
                c = "";
                while (TheString != c) {
                    c = TheString;
                    TheString = numberCrunch(TheString);
                }
                c = TheString;
                if (c == d) {
                    TheReturn = "";
                } else {
                    TheReturn = c;
                }
            }

            // If handed a vector, evaluate* each component. (--> ^)
            if (TheReturn == "") {
                c = TheString;
                if (typeCheck(c) == "vector") {
                    d = c;
                    c = structureEval(c, "<", ">");
                }
                if (c == d) {
                    TheReturn = "";
                } else {
                    TheReturn = c;
                }
            }

        }

        // If input expression contains zero-level parens but no scanned function name:
        if ((LeftBrackPos > -1) & (RightBrackPos > -1) & (ScannedName == "")) {

            if (TheReturn == "") {
                n = countElements(MidFragment, ",");
                if (n == 1) {
                    // If argument is singular, strip the outer parens and evaluate* content. (--> ^)
                    c = removeWrapping(MidFragment, "()");
                    c = internalEval(c);
                    MidFragment = c;
                    TheReturn = LeftFragment + MidFragment + RightFragment;
                }
                if (n > 1) {
                    // If argument is a parenthesized list, evaluate* each component and retain parens. (--> ^)
                    c = structureEval(MidFragment, "(", ")");
                    MidFragment = c;
                    TheReturn = LeftFragment + MidFragment + RightFragment;
                }
            }

        }

        // If input expression contains parens and a name was scanned:
        if ((LeftBrackPos > -1) & (RightBrackPos > -1) & (ScannedName != "")) {

            // If ScannedName is a user-defined function:
            //   Replace the function call with the literal function content.
            //   Replace variables [x], [y], etc. with arguments sent to the function. (--> ^)
            if (TheReturn == "") {
                m = countElements(MidFragment, ",");
                for (k = FunctionListSize; k >= 1; k += (-1)) {
                    if (ScannedName == FunctionList[k][1]) {
                        c = FunctionList[k][2];
                        c = removeWrapping(c, "{}");

                        if (m > 0) {
                            d = internalEval(returnElement(MidFragment, 1, ","));
                            c = replaceWord(c, "[x]", d, 1);
                        }
                        if (m > 1) {
                            d = internalEval(returnElement(MidFragment, 2, ","));
                            c = replaceWord(c, "[y]", d, 1);
                        }
                        if (m > 2) {
                            d = internalEval(returnElement(MidFragment, 3, ","));
                            c = replaceWord(c, "[z]", d, 1);
                        }
                        if (m > 3) {
                            d = internalEval(returnElement(MidFragment, 4, ","));
                            c = replaceWord(c, "[t]", d, 1);
                        }
                        if (m > 4) {
                            d = internalEval(returnElement(MidFragment, 5, ","));
                            c = replaceWord(c, "[u]", d, 1);
                        }
                        if (m > 5) {
                            d = internalEval(returnElement(MidFragment, 6, ","));
                            c = replaceWord(c, "[v]", d, 1);
                        }

                        MidFragment = c;
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                        break;
                    }
                }
            }

            // If ScannedName is a primitive, pass through FunctionCrunch. (--> ^)
            if (TheReturn == "") {
                MidFragment = functionCrunch(ScannedName, MidFragment);
                TheReturn = LeftFragment + MidFragment + RightFragment;
            }

        }

        if (TheReturn == "") {
            TheReturn = TheString;
        }

        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string sxriptEval (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        TheString = TheStringIn;
        TheString = internalEval(TheString);
        TheString = formatForTerminal(TheString);
        TheReturn = TheString;
        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string numberCrunch (std::string TheStringIn) {
        std::string TheReturn;
        std::string TheString;
        std::string TypeLeft;
        std::string TypeRight;
        std::string ArgLeft;
        std::string ArgRight;
        std::string LeftFragment;
        std::string MidFragment;
        std::string RightFragment;
        std::string TheOperator;
        int k;
        int m;
        int n;
        double t1;
        double t2;
        double t3;
        std::string c;
        std::string c1;
        std::string c2;
        std::string c3;
        int Divergence;
        TheString = TheStringIn;
        TheReturn = "";
        TypeLeft = "";
        TypeRight = "";
        ArgLeft = "";
        ArgRight = "";
        TheOperator = "";
        k = -1;
        m = -1;
        n = -1;
        c = "";
        c1 = "";
        c2 = "";
        c3 = "";
        Divergence = 0;

        TheString = manageOperators(TheString);
        c3 = TheString;

        TheString = replaceWord(TheString, "D+", "Dp", -1);
        TheString = replaceWord(TheString, "D-", "Dm", -1);
        TheString = replaceWord(TheString, "E+", "Ep", -1);
        TheString = replaceWord(TheString, "E-", "Em", -1);
        TheString = replaceWord(TheString, "e+", "ep", -1);
        TheString = replaceWord(TheString, "e-", "em", -1);
        TheString = replaceWord(TheString, "DE", "00", -1);
        TheReturn = TheString;

        if (TheReturn == TheString) {

            for (n = 1; n <= lEN(OpList); n += 1) {
                c = mID(OpList, n, 1);
                k = scanForOperator(TheString, c);
                if (k > -1) {
                    m = k;
                    TheOperator = c;
                    break;
                }
            }

            // Special case (1 of 2) for tilde operator.
            if (TheOperator == "~") {
                m = scanForName(TheString, k - 1, "left") - 1;
                TheOperator = mID(TheString, m, k - m + 1);
                k = m;
            }

        }

        if (TheOperator == "") {
            TheString = c3;
            TheReturn = TheString;
        }

        if (TheOperator != "") {

            c1 = mID(TheString, k - 1, 1);
            c2 = mID(TheString, k + lEN(TheOperator), 1);

            // Special case (1 of 2) for factorial symbol as an operator.
            if (TheOperator == "!") {
                c2 = "0";
            }

            if ((c1 != "") & (c2 != "")) {

                TypeLeft = typeCheck(c1);
                TypeRight = typeCheck(c2);

                // Handle left side of operator.
                if (TypeLeft == "number") {
                    m = scanForName(TheString, k - 1, "left");
                    if (m > 1) {
                        if ((mID(TheString, m - 1, 1) == "+") | (mID(TheString, m - 1, 1) == "-")) {
                            m = m - 1;
                        }
                    }
                }
                if ((TypeLeft == "vector") | (TypeLeft == "quote") | (TypeLeft == "occulted")) {
                    m = findMatching(TheString, c1, k - 1);
                    if (m == -1) {
                        m = 1;
                    }
                }
                if (TypeLeft == "word") {
                    m = scanForName(TheString, k - 1, "left");
                }

                // Handle right side of operator.
                if (TypeRight == "number") {
                    n = scanForName(TheString, k + lEN(TheOperator), "right");
                }
                if ((TypeRight == "vector") | (TypeRight == "quote") | (TypeRight == "occulted")) {
                    n = findMatching(TheString, c2, k + lEN(TheOperator));
                    if (n == -1) {
                        n = lEN(TheString);
                    }
                }
                if (TypeRight == "word") {
                    n = scanForName(TheString, k + lEN(TheOperator), "right");
                }

                // Special case (2 of 2) for factorial symbol as an operator.
                if (TheOperator == "!") {
                    n = k;
                    TypeRight = "number";
                }

                // Break the string into fragments.

                TheString = c3;
                TheReturn = TheString;

                ArgLeft = mID(TheString, m, k - m);
                ArgRight = mID(TheString, k + lEN(TheOperator), n - k - lEN(TheOperator) + 1);
                LeftFragment = lEFT(TheString, m - 1);
                RightFragment = rIGHT(TheString, lEN(TheString) - n);

                // Special case (2 of 2) for tilde operator.
                if (TheReturn == TheString) {
                    if (lEFT(TheOperator, 1) == "~") {
                        TheOperator = removeWrapping(TheOperator, "~~");
                        MidFragment = "(" + TheOperator + "(" + ArgLeft + "," + ArgRight + ")" + ")";
                        MidFragment = internalEval(MidFragment);
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                // Special case for ? operator.
                if (TheReturn == TheString) {
                    if (TheOperator == "?") {
                        MidFragment = ArgLeft + "(" + ArgRight + ")";
                        MidFragment = internalEval(MidFragment);
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                // Case: word @ word
                if (TheReturn == TheString) {
                    if ((TypeLeft == "word") & (TypeRight == "word")) {
                        if (TheOperator == "=") {
                            if (ArgLeft == ArgRight) {
                                MidFragment = "1";
                            } else {
                                MidFragment = "0";
                            }
                        }
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                // Case: number @ number
                if (TheReturn == TheString) {
                    if ((TypeLeft == "number") & (TypeRight == "number")) {

                        t1 = vAL(ArgLeft);
                        t2 = vAL(ArgRight);

                        if (TheOperator == "!") {
                            t2 = aBS(t1);
                            t1 = t1 / aBS(t1);
                            t3 = 1;
                            for (k = 1; k <= t2; k += 1) {
                                t3 = t3 * k;
                            }
                            t3 = t3 * t1;
                        }

                        if (TheOperator == "^") {
                            // JavaScript: ENDSKIP
                            // JavaScript: STARTSKIP
                            t3 = pow(t1, t2);
                            // JavaScript: ENDSKIP
                        }

                        if (TheOperator == "*") {
                            t3 = t1 * t2;
                        }

                        if (TheOperator == "/") {
                            if (t2 == 0) {
                                Divergence = 1;
                            } else {
                                t3 = t1 / t2;
                            }
                        }

                        if (TheOperator == "%") {
                            t3 = t1;
                            if (t2 != 0) {
                            }
                        }

                        if (TheOperator == "+") {
                            t3 = t1 + t2;
                        }

                        if (TheOperator == "-") {
                            t3 = t1 - t2;
                        }

                        if (TheOperator == "=") {
                            if ((t1 - t2) == 0) {
                                t3 = 1;
                            } else {
                                t3 = 0;
                            }
                        }

                        if (TheOperator == "&") {
                            if ((t1 > 0) & (t2 > 0)) {
                                t3 = 1;
                            } else {
                                t3 = 0;
                            }
                        }

                        if (TheOperator == "|") {
                            if ((t1 > 0) | (t2 > 0)) {
                                t3 = 1;
                            } else {
                                t3 = 0;
                            }
                        }

                        if (Divergence == 0) {

                            // Inserts a "+" sign in front of positive results.
                            if (t3 >= 0) {
                                MidFragment = "+" + lTRIM(rTRIM(sTR(t3)));
                            } else {
                                MidFragment = lTRIM(rTRIM(sTR(t3)));
                            }

                            //''
                            //2021 edit: Added this.
                            // This could be faster with a non-recursive word replacement function.
                            if ((iNSTR(MidFragment, ".") < 1) & (iNSTR(MidFragment, "e") > 1)) {
                                MidFragment = replaceWord(MidFragment, "e", ".0X", -1);
                                MidFragment = replaceWord(MidFragment, "X", "e", -1);
                            }
                            //''

                            // Inserts ".0" for numbers not containing decimals.
                            if (iNSTR(MidFragment, ".") < 1) {
                                MidFragment = MidFragment + ".0";
                            }

                            // More strict format for small decimals.
                            MidFragment = replaceWord(MidFragment, "+.", "+0.", -1);
                            MidFragment = replaceWord(MidFragment, "-.", "-0.", -1);

                        } else {
                            MidFragment = "{ERROR: Division by zero.}";
                        }

                        TheReturn = LeftFragment + MidFragment + RightFragment;

                    }
                }

                // Case: number @ quote
                if (TheReturn == TheString) {
                    if ((TypeLeft == "number") & (TypeRight == "quote")) {
                        if (TheOperator == "*") {
                            ArgRight = removeWrapping(ArgRight, "`'");
                            c = "";
                            for (k = 1; k <= iNT(vAL(ArgLeft)); k += 1) {
                                c = c + ArgRight;
                            }
                            c = "`" + c + "'";
                            MidFragment = c;
                        }
                        if (TheOperator == "+") {
                            ArgRight = removeWrapping(ArgRight, "`'");
                            c = ArgLeft + ArgRight;
                            c = "`" + c + "'";
                            MidFragment = c;
                        }
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                // Case: quote @ number
                if (TheReturn == TheString) {
                    if ((TypeLeft == "quote") & (TypeRight == "number")) {
                        if (TheOperator == "*") {
                            ArgLeft = removeWrapping(ArgLeft, "`'");
                            c = "";
                            for (k = 1; k <= iNT(vAL(ArgRight)); k += 1) {
                                c = c + ArgLeft;
                            }
                            c = "`" + c + "'";
                            MidFragment = c;
                        }
                        if (TheOperator == "+") {
                            ArgLeft = removeWrapping(ArgLeft, "`'");
                            c = ArgLeft + ArgRight;
                            c = "`" + c + "'";
                            MidFragment = c;
                        }
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                // Case: number @ vector
                if (TheReturn == TheString) {
                    if ((TypeLeft == "number") & (TypeRight == "vector")) {
                        MidFragment = structureApplyFunc(ArgRight, ArgLeft + TheOperator, "<>");
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                //''
                // Case: vector @ number
                if (TheReturn == TheString) {
                    if ((TypeLeft == "vector") & (TypeRight == "number")) {
                        MidFragment = structureApplyTailOp(ArgLeft, TheOperator + ArgRight, "<>");
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }
                //''

                // Case: quote @ vector
                if (TheReturn == TheString) {
                    if ((TypeLeft == "quote") & (TypeRight == "vector")) {
                        MidFragment = structureApplyFunc(ArgRight, ArgLeft + TheOperator, "<>");
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                //''
                // Case: vector @ quote
                if (TheReturn == TheString) {
                    if ((TypeLeft == "vector") & (TypeRight == "quote")) {
                        MidFragment = structureApplyTailOp(ArgLeft, TheOperator + ArgRight, "<>");
                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }
                //''

                // Case: quote @ quote
                if (TheReturn == TheString) {
                    if ((TypeLeft == "quote") & (TypeRight == "quote")) {

                        ArgLeft = removeWrapping(ArgLeft, "`'");
                        ArgRight = removeWrapping(ArgRight, "`'");

                        if (TheOperator == "*") {
                            c = "";
                            for (k = 1; k <= lEN(ArgLeft); k += 1) {
                                c = c + mID(ArgLeft, k, 1) + ArgRight;
                            }
                            MidFragment = "`" + c + "'";
                        }

                        if (TheOperator == "/") {
                            c1 = ArgLeft;
                            n = -1;
                            while (n == -1) {
                                k = iNSTR(c1, ArgRight);
                                if (k > 0) {
                                    c1 = lEFT(c1, k - 1) + rIGHT(c1, lEN(c1) - k - lEN(ArgRight) + 1);
                                } else {
                                    n = 1;
                                }
                            }
                            MidFragment = "`" + c1 + "'";
                        }

                        if (TheOperator == "+") {
                            MidFragment = "`" + ArgLeft + ArgRight + "'";
                        }

                        if (TheOperator == "-") {
                            if (rIGHT(ArgLeft, lEN(ArgRight)) == ArgRight) {
                                MidFragment = "`" + lEFT(ArgLeft, lEN(ArgLeft) - lEN(ArgRight)) + "'";
                            } else {
                                //''MidFragment = "`" + ArgLeft + "'-`" + ArgRight + "'"
                                MidFragment = "`" + ArgLeft + "'";
                            }
                        }

                        if (TheOperator == "=") {
                            if (ArgLeft == ArgRight) {
                                c = "1";
                            } else {
                                c = "0";
                            }
                            MidFragment = c;
                        }

                        if (TheOperator == "&") {
                            if ((ArgLeft != "") & (ArgRight != "")) {
                                c = "1";
                            } else {
                                c = "0";
                            }
                            MidFragment = c;
                        }

                        if (TheOperator == "|") {
                            if ((ArgLeft != "") | (ArgRight != "")) {
                                c = "1";
                            } else {
                                c = "0";
                            }
                            MidFragment = c;
                        }

                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }
                }

                // Case: vector @ vector
                if (TheReturn == TheString) {
                    if ((TypeLeft == "vector") & (TypeRight == "vector")) {

                        if (TheOperator == "^") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "^");
                        }
                        if (TheOperator == "*") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "*");
                        }
                        if (TheOperator == "/") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "/");
                        }
                        if (TheOperator == "%") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "/");
                        }
                        if (TheOperator == "+") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "+");
                        }
                        if (TheOperator == "-") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "-");
                        }
                        if (TheOperator == "=") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "=");
                        }
                        if (TheOperator == "&") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "&");
                        }
                        if (TheOperator == "|") {
                            MidFragment = vectorASMD(ArgLeft, ArgRight, "|");
                        }

                        TheReturn = LeftFragment + MidFragment + RightFragment;
                    }

                }
            } else {
                TheString = c3;
                TheReturn = TheString;
            }

        }

        if (TheReturn == "") {
            TheReturn = TheString;
        }

        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

std::string subExecute (std::string TheScriptIn, std::string TheModeIn, std::string ScopeSwitchIn) {
        std::string TheReturn;
        std::string TheScript;
        std::string TheMode;
        std::string ScopeSwitch;
        std::string TheFile;
        int AnchorCount;
        int LineCount;
        int LoopCounter;
        int LoopIndex;
        int LineIndex;
        int k;
        int m;
        std::string c;
        std::string d;
        int EvalDone;
        int FunctionListSizeOrig;
        int VariableListSizeOrig;
        TheReturn = "";
        TheScript = TheScriptIn;
        TheMode = TheModeIn;
        ScopeSwitch = ScopeSwitchIn;
        AnchorCount = 0;
        LineCount = 0;
        LoopCounter = 0;
        LoopIndex = 0;
        LineIndex = 0;
        EvalDone = 0;

        if (ScopeSwitch == "_yes") {
            // Increment function and variable scope.
            FunctionListSizeOrig = FunctionListSize;
            VariableListSizeOrig = VariableListSize;
            ScopeLevel = ScopeLevel + 1;
            for (k = 1; k <= FunctionListSize; k += 1) {
                FunctionListScope[k][1][ScopeLevel] = FunctionList[k][1];
                FunctionListScope[k][2][ScopeLevel] = FunctionList[k][2];
            }
            for (k = 1; k <= VariableListSize; k += 1) {
                VariableListScope[k][1][ScopeLevel] = VariableList[k][1];
                VariableListScope[k][2][ScopeLevel] = VariableList[k][2];
            }
        }

        if (TheMode == "file") {
            TheFile = removeWrapping(TheScript, "`'");
            TheScript = "";

            // JavaScript: ENDSKIP

            // JavaScript: STARTSKIP
            // JavaScript: ENDSKIP


            // JavaScript: STARTSKIP
            std::ifstream myfile(TheFile.c_str());
            if (myfile.is_open()) {
                while (std::getline(myfile, d)) {
                    c = lTRIM(rTRIM(d));
                    TheScript.append("\n");
                    TheScript.append(c);
                }
                myfile.close();
            }
            // JavaScript: ENDSKIP

            TheScript = manageWhiteSpace(TheScript);
        }

        LineCount = countElements("(" + TheScript + ")", ":");

        // Scale arrays according to line count.
        // Offsets of +1 added to accomodate C++ implementation.

        std::string ScriptLine[LineCount + 1];
        int ScriptLinePrintFlag[LineCount + 1];
        int LoopStartPosition[LineCount + 1];
        int LoopIterationCount[LineCount + 1];
        std::string AnchorList[LineCount + 1][2];


        // Break input string apart at each (:) symbol.
        m = 0;
        while (1 == 1) {
            k = getSeparatorPos("(" + TheScript + ")", ":", 1, 1) - 1;
            if (k > -1) {
                m = m + 1;
                ScriptLine[m] = lEFT(TheScript, k - 1);
                TheScript = rIGHT(TheScript, lEN(TheScript) - k);
            } else {
                m = m + 1;
                ScriptLine[m] = TheScript;
                break;
            }
        }

        // Prepare loops.
        k = LineCount;
        while (k > 1) {
            for (k = LineCount; k >= 1; k += (-1)) {
                if (ScriptLine[k] == "do") {
                    LoopCounter = LoopCounter + 1;
                    ScriptLine[k] = "_do " + lTRIM(sTR(LoopCounter));
                    LoopStartPosition[LoopCounter] = k;
                    for (m = k; m <= LineCount; m += 1) {
                        if (ScriptLine[m] == "loop") {
                            ScriptLine[m] = "_loop " + lTRIM(sTR(LoopCounter));
                            break;
                        }
                    }
                    break;
                }
            }
        }

        // Prepare `print' and `anchor'.
        for (k = 1; k <= LineCount; k += 1) {
            c = ScriptLine[k];
            ScriptLinePrintFlag[k] = 0;
            if (lEFT(c, 6) == "print_") {
                ScriptLinePrintFlag[k] = 1;
                ScriptLine[k] = rIGHT(c, lEN(c) - 6);
            }
            if (lEFT(c, 7) == "anchor_") {
                AnchorCount = AnchorCount + 1;
                AnchorList[AnchorCount][1] = rIGHT(c, lEN(c) - 7);
                AnchorList[AnchorCount][2] = lTRIM(sTR(k));
            }
        }

        //
        // Main script evaluation loop.
        //
        while (LineIndex < LineCount) {
            LineIndex = LineIndex + 1;
            c = ScriptLine[LineIndex];
            EvalDone = 0;

            if (lEFT(c, 3) == "_do") {
                EvalDone = 1;
                LoopIndex = vAL(rIGHT(c, lEN(c) - 3));
                LoopIterationCount[LoopIndex] = vAL(internalEval(ScriptLine[LineIndex - 1]));
            }

            if (lEFT(c, 5) == "_loop") {
                EvalDone = 1;
                LoopIndex = vAL(rIGHT(c, lEN(c) - 5));
                if (LoopIterationCount[LoopIndex] > 1) {
                    LoopIterationCount[LoopIndex] = LoopIterationCount[LoopIndex] - 1;
                    LineIndex = LoopStartPosition[LoopIndex];
                }
            }

            if (lEFT(c, 5) == "goto_") {
                EvalDone = 1;
                for (k = 1; k <= AnchorCount; k += 1) {
                    if (AnchorList[k][1] == internalEval(rIGHT(c, lEN(c) - 5))) {
                        LineIndex = vAL(AnchorList[k][2]);
                    }
                }
            }

            if (lEFT(c, 3) == "if_") {
                EvalDone = 1;
                c = rIGHT(c, lEN(c) - 3);
                k = scanForOperator(c, "@");
                d = rIGHT(c, lEN(c) - k);
                c = lEFT(c, k - 1);
                c = internalEval(c);
                if (vAL(c) == 1) {
                    for (k = 1; k <= AnchorCount; k += 1) {
                        if (AnchorList[k][1] == d) {
                            LineIndex = vAL(AnchorList[k][2]);
                            break;
                        }
                    }
                }
            }

            if (lEFT(c, 7) == "anchor_") {
                EvalDone = 1;
            }

            if (EvalDone == 0) {
                EvalDone = 1;
                c = internalEval(c);
                if (ScriptLinePrintFlag[LineIndex] == 1) {
                    TheReturn = TheReturn + c;
                }
            }

        }

        if (ScopeSwitch == "_yes") {
            // Decrement function and variable scope.
            for (k = 1; k <= FunctionListSize; k += 1) {
                FunctionList[k][1] = FunctionListScope[k][1][ScopeLevel];
                FunctionList[k][2] = FunctionListScope[k][2][ScopeLevel];
            }
            for (k = 1; k <= VariableListSize; k += 1) {
                VariableList[k][1] = VariableListScope[k][1][ScopeLevel];
                VariableList[k][2] = VariableListScope[k][2][ScopeLevel];
            }
            ScopeLevel = ScopeLevel - 1;
            FunctionListSize = FunctionListSizeOrig;
            VariableListSize = VariableListSizeOrig;
        }

        return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

