# Sxript

## Abstract

Sxript is an interpreted functional/procedural programming language designed for numerical evaluation and problem solving with high-order functions, variable storage, scoped subprograms, and arbitrary-precision numbers, along with file I/O, graphical output, and more. Sxript may be used as a stand-alone tool on most devices, or included as a component of any BASIC, JavaScript, or C++ application. All source code is written in a strict subset of the QB45 language, and is auto-translated by the BAS-TO-X utility into other languages.

## Browser Instances (use now)

[Console](http://wfbarnes.net/sxript/docs/console/console.html)

[Calculator](http://wfbarnes.net/sxript/docs/calculator/calculator.html)

## Build

To compile/build, place the /sxript/ directory at the same level as (not inside) the QB64 folder and run setup*, depending on system.

Linux Users: To handle problems with line endings, run the following line from terminal in base directory:

``` find . -name '*.sh' -exec sed -i "s/\r//g" {} \; ```

## Guide

### Numerical Operators

Arithmetic operations are defined as one-character symbols ``` ! ^ * / % + - ``` that embed between on two base-ten numbers (or rarely, one number) to produce a result of double precision. Operators are regarded in strict descending order - no two operators are of equal precedence. The body result of a numerical operation is always prefixed with a sign ```+```, or ```-```, and suffixed with a decimal remainder, even if ```.0```. Expressions containing multiple operators are evaluated recursively.

### Operator Reduction

Before any numerical operations are considered, all input passes through an operator reduction filter, which reduces things like ```+++``` to a single ```+```, and so on. Occurrences of ```-+``` are interpreted as ```-```, making inputs such as ```3-+3``` evaluate to ```+0.0```, as expected. Occurrences of a "double negative" ```--``` are interpreted as a single positive ```+```.

### Dual role of the Negative Sign

Following the (unfortunate) convention of traditional notation, the negative sign ( ```-``` ) plays a dual rule in numerical expressions. Apart from acting as the subtraction operator, the same symbol is used to denote stand-alone negative numbers, such as ```-3.5```, in where no "operation" taking place at all.

We adopt the convention where the negative sign prefers to bind to numbers (like an electron) to make them negative, instead of going between numbers to act as a subtraction operator.

#### Example:

> Predict the result of ```0-3^2```.

> Solution: By operator precedence, the power operator ( ```^``` ) is regarded first, which triggers a "search" for numbers surrounding the operator. On the right, we have ```2```, whereas on the left, the operator captures ```-3```. This means ```-3*-3``` is treated as a stand-alone problem, solved by ```+9.0```. The original expression, then, becomes ```0+9.0```, simplifying to ```+9.0```.

#### Example:

> Predict the result of ```0--3^2```.

> Solution: By operator reduction, the expression reduces to ```0+3^2``` before any numerical operations take place. This of course becomes ```0+9.0```, simplifying to ```+9.0```.


