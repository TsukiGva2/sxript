# Sxript

![screenshot](img/sxgrey.png)

## Abstract

Sxript is an interpreted functional/procedural programming language designed for numerical evaluation and problem solving with high-order functions, variable storage, scoped subprograms, and arbitrary-precision numbers, along with file I/O, graphical output, and more. Sxript may be used as a stand-alone tool on most devices, or included as a component of any BASIC, JavaScript, or C++ application. All source code is written in a strict subset of the QB45 language, and is auto-translated by the BAS-TO-X utility into other languages.

## Browser Instances (use now)

[Console](http://wfbarnes.net/sxript/docs/console/console.html)

[Calculator](http://wfbarnes.net/sxript/docs/calculator/calculator.html)

## Download

The latest codebase shall always be hosted at GitHub:

https://github.com/wfbarnes/sxript.git

 Ignore any versions appearing on forums, private servers, archives, etc.

## Build

To compile/build, place the /sxript/ directory at the same level as (not inside) the QB64 folder and run setup*, depending on system.

Linux Users: To handle problems with line endings, run the following line from terminal in base directory:

` find . -name '*.sh' -exec sed -i "s/\r//g" {} \; `

## Legal

Sxript is conveyed as open source free software. Do what thou wilt.

## Logo

*Signature of a Medieval Illiterate* - Frederick W. Umminger Jr., Yale Record, 1959.

***

# Guide

[Guide - Section 1: Numbers and Operators](guide/guide1.md)

[Guide - Section 2: Quotes (Strings)](guide/guide2.md)

[Guide - Section 3: Output Formatting](guide/guide3.md)

[Guide - Section 4: Code Blocks](guide/guide4.md)

[Guide - Section 5: Procedural Subsystem](guide/guide5.md)

[Guide - Section 6: Vectors (Lists)](guide/guide6.md)

[Guide - Section 7: Operator Overloading](guide/guide7.md)