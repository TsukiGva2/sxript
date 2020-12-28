copy ..\src\*   ..\..\qb64\
copy ..\src\*   ..\..\freebasic\

cd ..\
cd ..\qb64

qb64.exe -x sxript.bas
move sxript.exe ..\sxript\bin

cd ..\freebasic
fbc sxriptfb.bas
move sxriptfb.exe ..\sxript\bin





