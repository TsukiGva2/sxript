//#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <stdio.h>
#include <sstream>

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
// Begin: C++ version of BASIC functions.
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// INSTR (Start position is 1.)
int iNSTR (std::string TheString, std::string TheArg) {
    int Temp;
    int t;
    t = TheString.find(TheArg);
    if (t <= -1) {
        Temp = -1;
    } else {
        Temp = t + 1;
    }
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LEN
int lEN (std::string TheString) {
    return (TheString.length());
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// INT
int iNT(double TheNum) {
    return (int)TheNum;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// ABS
int aBS (double TheNum) {
    return abs(TheNum);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LEFT
std::string lEFT (std::string TheString, int ThePos) {
    std::string Temp;
    int index;
    for (index = 0; index < ThePos; index += 1) {
        Temp += TheString[index];
    }
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// RIGHT
std::string rIGHT (std::string TheString, int ThePos) {
    std::string Temp;
    for ( int index = 0; index < ThePos; index++ ) Temp += TheString[TheString.length()-ThePos+index];
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// MID (Three arguments.)
std::string mID (std::string TheString, int StartPos, int Width) {
    std::string Temp = "";
    if (StartPos > 0) {
        for ( int index = StartPos-1 ; index < StartPos+Width-1 ; index++ ) {
            Temp += TheString[index];
        }
    }
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// SQR
double sQR (double TheNum) {
    return sqrt(TheNum);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// SGN
double sGN (double TheNum) {
    double Temp;
    if (TheNum == 0) {
        Temp = 0;
    } else {
        Temp = TheNum / aBS(TheNum);
    }
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LCASE
std::string lCASE(std::string TheString) {
    return TheString;
}

// '''''''''' '''''''''' ''''''''' '''''''''' ''''''''''

// UCASE
std::string uCASE (std::string TheString) {
    return TheString;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// STR
std::string sTR (double TheNum) {
    std::string Temp;
    std::ostringstream os;
    os << TheNum;
    Temp = os.str();
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// VAL (For type double.)
double vAL (std::string TheString) {
    double TheVal;
    std::stringstream conv(TheString);
    conv >> TheVal;
    return TheVal;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LTRIM
std::string lTRIM (std::string TheString) {
    std::string TheReturn = "";
    std::string Temp;
    int Satisfied = 0;
    for ( int index = 0 ; index < TheString.length() ; index++ ) {
        Temp = TheString[index];
        if (Satisfied == 1) {
            TheReturn = TheReturn + Temp;
        } else {
            if (Temp != " ") {
                Satisfied = 1;
                TheReturn = Temp;
            }
        }
    }
    return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// RTRIM
std::string rTRIM (std::string TheString) {
    std::string TheReturn = "";
    std::string Temp;
    int Satisfied = 0;
    for ( int index = TheString.length()-1 ; index >= 0 ; index-- ) {
        Temp = TheString[index];
        if (Satisfied == 1) {
            TheReturn = Temp + TheReturn;
        } else {
            if (Temp != " ") {
                Satisfied = 1;
                TheReturn = Temp;
            }
        }
    }
    return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// CHR
std::string cHR (int TheNum) {
   std::string TheReturn;
   TheReturn = (char)TheNum;
   return TheReturn;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// ASC
// int aSC (std::string TheChar) {
//    int TheReturn;
//    TheReturn = int(TheChar);
//    return TheReturn;
// }

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
// End: C++ version of BASIC functions.
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
