#!/bin/bash

echo "cpp"
g++ ../src/sxript.cpp ../src/sxript.h -o sxriptcpp -std=c++11
mv sxriptcpp ../bin

echo "fb"
fbc ../src/sxriptfb.bas
mv ../src/sxriptfb ../bin

echo "qb64"
cp ../src/* ../../qb64/

cd ../
cd ../qb64

./qb64 -x sxript.bas
mv sxript ../sxript/bin






