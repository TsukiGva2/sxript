// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
// Begin: JavaScript version of BASIC functions.
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// INSTR (Start position is 1.)
function iNSTR(TheString, TheArg) {
    "use strict";
    var Temp = 0;
    var t;
    t = TheString.indexOf(TheArg);
    if (t === -1) {
        Temp = 0;
    } else {
        Temp = t + 1;
    }
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LEN
function lEN(TheString) {
    "use strict";
    return TheString.length;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// INT
function iNT(TheNum) {
    "use strict";
    return Math.floor(TheNum);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// ABS
function aBS(TheNum) {
    "use strict";
    return Math.abs(TheNum);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LEFT
function lEFT(TheString, ThePos) {
    "use strict";
    var Temp = "";
    Temp = TheString.substring(0, ThePos);
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// RIGHT
function rIGHT(TheString, ThePos) {
    "use strict";
    var Temp = "";
    Temp = TheString.substring(lEN(TheString) - ThePos, lEN(TheString));
    return Temp;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// MID (Three arguments.)
function mID(TheString, StartPos, Width) {
    "use strict";
    return TheString.slice(StartPos - 1, StartPos + Width - 1);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// SQR
function sQR(TheNum) {
    "use strict";
    return Math.sqrt(TheNum);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// SGN
function sGN(TheNum) {
    "use strict";
    return Math.sign(TheNum);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LCASE
function lCASE(TheString) {
    "use strict";
    return TheString.toLowerCase();
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// UCASE
function uCASE(TheString) {
    "use strict";
    return TheString.toUpperCase();
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// STR
function sTR(TheNum) {
    "use strict";
    return TheNum.toString();
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// VAL (For type double.)
function vAL(TheString) {
    "use strict";
    return Number(TheString);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// LTRIM
function lTRIM(TheString) {
    "use strict";
    return TheString;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// RTRIM
function rTRIM(TheString) {
    "use strict";
    return TheString;
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// ASC
function aSC(TheChar) {
    "use strict";
    return TheChar.charCodeAt(0);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// CHR
function cHR(TheCode) {
    "use strict";
    return String.fromCharCode(TheCode);
}

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''

// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
// End: JavaScript version of BASIC functions.
// '''''''''' '''''''''' '''''''''' '''''''''' ''''''''''
