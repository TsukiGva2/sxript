copy ..\src\*.bi
copy ..\src\*.bm

BAS-COMB.exe sxmath.bi sxript.bi sxmath.bm sxript.bm sxriptcomb.bas
BAS-TO-X.exe CPP

BAS-COMB.exe sxmath.bi sxript.bi sxript.bm sxmath.bm sxriptcomb.bas
BAS-TO-X.exe JavaScript

move sxriptcomb.bas ..\src\sxriptcomb.bas
move sxript.js ..\src\sxript.js
move sxript.h ..\src\sxript.h

del *.bi
del *.bm