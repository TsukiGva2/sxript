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

## Guide: Numbers and Operators

### Numerical Operators

Numerical expressions are defined as one-character operators ``` ! ^ * / % + - ``` embedded between on two base-ten numbers (or rarely, one number) to produce a numerical result of double precision. Operators are treated in strict descending order as listed: no two operators are of equal precedence. The result of a numerical operation is always prefixed with a sign ```+```, or ```-```, and suffixed with a decimal remainder, even if ```.0```. Expressions containing multiple operators are evaluated recursively.

### Operator Reduction

Before any numerical operations are considered, all input passes through an operator reduction filter, which reduces things like ```+++``` to a single ```+```, and so on. Occurrences of ```-+``` are interpreted as ```-```, making inputs such as ```3-+3``` evaluate to ```+0.0```, as expected. Occurrences of a "double negative" ```--``` are interpreted as a single positive ```+```.

### Duality of the Negative Sign

Following the (unfortunate) convention of traditional notation, the negative sign ( ```-``` ) plays a dual rule in numerical expressions. Apart from acting as the subtraction operator, the same symbol is used to denote stand-alone negative numbers, such as ```-3.5```, in where no "operation" taking place at all.

We adopt the convention where the negative sign prefers to bind to numbers (like an electron) to make them negative, instead of going between numbers to act as a subtraction operator.

#### Exercise:

> Predict the result of ```0-3^2```.

> Solution: By operator precedence, the power operator ( ```^``` ) is regarded first, which triggers a "search" for numbers surrounding the operator. On the right, we have ```2```, whereas on the left, the operator captures ```-3```. This means ```-3*-3``` is treated as a stand-alone problem, solved by ```+9.0```. The original expression becomes ```0+9.0```, simplifying to ```+9.0```.

#### Exercise:

> Predict the result of ```0--3^2```.

> Solution: By operator reduction, the expression reduces to ```0+3^2``` before any numerical operations take place. The expression becomes ```0+9.0```, simplifying to ```+9.0```.

### Comparison and Logic

The comparison operator, denoted by a single "equal" symbol ( ```=``` ), tests for equivalency between two numbers. If the left- and right-arguments are numerically equal, the returned result is ```+1.0```. Non-equal arguments return ```+0.0```.

The logical AND, along with logical OR, are represented by the ampersand ( ```&``` ) and vertical slash ( ```|``` ), respectively. Like the comparison operator, the logical operators, as applied to numbers, return a ```+1.0``` for the affirmative case, and ```+0.0``` otherwise.

## Guide: Strings

Strings, henceforth called "quotes", are always enclosed by the back-tick symbol ( ``` ` ``` ) on the left, and the apostrophe ( ``` ' ``` ) on the right. The double-quote symbol ( ``` " ``` ) is not reserved. For example, ``` `horse' ``` is a valid quote, and so too is ``` `aB"1e3"cD'```.

Quotes can embed within quotes, meaning, for instance, ``` `cows say `moo''```, is a perfectly valid quote.

The range of allowed characters is dependent on the host environment. Terminal implementations tend to only resolve ASCII characters, whereas JavaScript implementations extend to allows Unicode characters in quotes.

### Quote Operations

Quotes can be manipulated using (some of) the same operators that apply to numbers. Allowed operators ```* / + -``` follow the same precedence as their mathematical counterparts.

#### Concatenation

Much as one would expect, quotes are concatenated with the plus ( ```+``` ) operator, for instance ``` `apple' + `juice' ``` becomes ``` `applejuice' ```.

#### Subtraction

If [quote2] exactly matches the rightmost characters of [quote1], then the combination ```[quote1] - [quote2]``` returns a truncated version of [quote1] that excludes [quote2]. For example, ``` `file.txt' - `.txt' ``` resolves to ``` `file'```.

If [quote2] is not equal to the right-most part of [quote1], then only [quote1] is returned. As a corollary to this, the combination ``` `' - `xyz'``` returns the empty quote, ``` `'```.

#### Multiplication

One quote can also be "multiplied" into another, where the combination ```[quote1] * [quote2]``` returns a version of [quote1] with [quote2] inserted after each character. For instance ``` `abc' * `xy'``` results in ``` `axybxycxy'```.

#### Division

The inverse of quote multiplication is quote division. That is, the combination ``` `axybxycxy' / `xy'``` returns `abc'. If [quote2] is not a sub-quote of [quote1], then only [quote1] is returned.

#### Exercise:

> Predict the result of ``` `abc' / `xy' * `xy'```.

> Solution: By operator precedence, the combination ``` `xy' * `xy'``` is considered first, resulting in ``` `xxyyxy'```. The problem translates to ``` `abc' / `xxyyxy'```, resulting in simply ``` `abc'```.

## Guide: Formatting

Sxript output is passed through a final formatting step before entering the environment. Most notably, quotes lose their bracketing characters, i.e. ``` ` ``` and ``` ' ``` vanish. This also applies to embedded quotes, so ``` `cows say `moo''``` flattens to ```cows say moo```.

### Escape Character

When the backslash character ( ```\``` ), or "escape character" appears in any output, the character to the right receives special treatment.

The most obvious need for the escape character is for including the backtick ( ``` ` ``` ) or apostrophe ( ``` ' ``` ) in a quote. This is achieved using respective combinations ``` \` ```, and ``` \' ```.

Tabs and returns are handled by the following:
* ```\t``` becomes ASCII-9  (Tab)
* ```\n``` becomes ASCII-10 (LF)
* ```\r``` becomes ASCII-13 (CR)
* ```\\``` becomes ``` \ ``` after all other formatting takes place.

#### Carriage Return

Note that the role of ASCII-13, the Carriage Return, behaves differently per implementation. Through JavaScript, the quote ``` `hello\rthere'``` is broken apart at "hello", and "there" is printed on a new line. Meanwhile, the QB64 and C++ terminal implementations return ``` `thereo'```, because the cursor returns to the left-most position without starting a new line.

## Guide: Functions

(Coming soon.)