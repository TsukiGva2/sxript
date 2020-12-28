#!/bin/bash

cp ../src/sxmath.bi sxmath.bi
cp ../src/sxript.bi sxript.bi
cp ../src/sxript.bm sxript.bm
cp ../src/sxmath.bm sxmath.bm

./BAS-COMB sxmath.bi sxript.bi sxmath.bm sxript.bm sxriptcomb.bas
./BAS-TO-X CPP

./BAS-COMB sxmath.bi sxript.bi sxript.bm sxmath.bm sxriptcomb.bas
./BAS-TO-X JavaScript

rm sxmath.bi
rm sxript.bi
rm sxript.bm
rm sxmath.bm

mv sxriptcomb.bas ../src/sxriptcomb.bas
mv sxript.js ../src/sxript.js
mv sxript.h ../src/sxript.h

