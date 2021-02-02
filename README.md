# Sxript

## Abstract

Sxript is an interpreted functional/procedural programming language designed for numerical evaluation and problem solving with high-order functions, variable storage, scoped subprograms, and arbitrary-precision numbers, along with file I/O, graphical output, and more. Sxript may be used as a stand-alone tool on most devices, or included as a component of any BASIC, JavaScript, or C++ application. All source code is written in a strict subset of the QB45 language, and is auto-translated by the BAS-TO-X utility into other languages.

## Browser Instances (use now)

[Console](http://wfbarnes.net/sxript/docs/console/console.html)

[Calculator](http://wfbarnes.net/sxript/docs/calculator/calculator.html)

## Build

To compile/build, place the /sxript/ directory at the same level as (not inside) the QB64 folder and run setup*, depending on system.

Linux Users: To handle problems with line endings, run the following line from terminal in base directory:

` find . -name '*.sh' -exec sed -i "s/\r//g" {} \; `

***

# Guide: Numbers and Operators

## Numerical Operators

Numerical expressions are defined as one-character operators ` ! ^ * / % + - ` embedded between on two base-ten numbers (or rarely, one number) to produce a numerical result of double precision. Operators are treated in strict descending order as listed: no two operators are of equal precedence. The result of a numerical operation is always prefixed with a sign `+`, or `-`, and suffixed with a decimal remainder, even if `.0`. Expressions containing multiple operators are evaluated recursively.

## Operator Reduction

Before any numerical operations are considered, all input passes through an operator reduction filter, which reduces things like `+++` to a single `+`, and so on. Occurrences of `-+` are interpreted as `-`, making inputs such as `3-+3` evaluate to `+0.0`, as expected. Occurrences of a "double negative" `--` are interpreted as a single positive `+`.

## Duality of the Negative Sign

Following the (unfortunate) convention of traditional notation, the negative sign ( `-` ) plays a dual rule in numerical expressions. Apart from acting as the subtraction operator, the same symbol is used to denote stand-alone negative numbers, such as `-3.5`, in where no "operation" taking place at all.

Sxript adopts a convention where the negative sign prefers to bind to numbers (like an electron) to make them negative, instead of going between numbers to act as a subtraction operator.

#### Exercise:

> Predict the result of `0-3^2`.

> Solution: By operator precedence, the power operator ( `^` ) is regarded first, which triggers a "search" for numbers surrounding the operator. On the right, we have `2`, whereas on the left, the operator captures `-3`. This means `-3*-3` is treated as a stand-alone problem, solved by `+9.0`. The original expression becomes `0+9.0`, simplifying to `+9.0`.

#### Exercise:

> Predict the result of `0--3^2`.

> Solution: By operator reduction, the expression reduces to `0+3^2` before any numerical operations take place. The expression becomes `0+9.0`, simplifying to `+9.0`.

...

## Numerical Comparison and Logic

The equivalency operator, denoted by a single "equal" symbol ( `=` ), tests for equivalency between two numbers. If the left- and right-arguments are numerically equal, the returned result is `+1.0`. Non-equal arguments return `+0.0`.

The logical AND, along with logical OR, are represented by the ampersand ( `&` ) and vertical slash ( `|` ), respectively. Any non-zero inputs are considered "on", and a zero-input is considered "off". Like the equivalency operator, the logical operators, as applied to numbers, return a `+1.0` for the affirmative case, and `+0.0` otherwise.

Side note: There is no operator notation for "less than" ( `<` ) and "greater than" ( `>` ), because the angle bracket symbols are reserved for vectors (see below). To perform such comparisons, we'll soon meet the `greater(x,y)` function.

***

# Guide: Strings

Strings, henceforth called *quotes*, are always enclosed by the back-tick symbol ( ``` ` ``` ) on the left, and the apostrophe ( ` ' ` ) on the right. The double-quote symbol ( ` " ` ) is not reserved. For example, ``` `horse' ``` is a valid quote, and so too is ``` `aB"1e3"cD'```.

Quotes can embed within quotes, meaning, for instance, ``` `cows say `moo''```, is a perfectly valid quote.

The range of allowed characters is dependent on the host environment. Terminal implementations tend to only resolve ASCII characters, whereas JavaScript implementations extend to allows Unicode characters in quotes.

## Quote Operations

Quotes can be manipulated using (some of) the same operators that apply to numbers. Allowed operators `* / + -` follow the same precedence as their mathematical counterparts.

### Concatenation

Much as one would expect, quotes are concatenated with the plus ( `+` ) operator, for instance ``` `apple' + `juice' ``` becomes ``` `applejuice' ```.

### Subtraction

If [quote2] exactly matches the rightmost characters of [quote1], then the combination `[quote1] - [quote2]` returns a truncated version of [quote1] that excludes [quote2]. For example, ``` `file.txt' - `.txt'``` resolves to ``` `file'```.

If [quote2] is not equal to the right-most part of [quote1], then only [quote1] is returned. As an example of this, the combination ``` `' - `xyz'``` returns the empty quote, ``` `'```.

### Multiplication

One quote can also be "multiplied" into another, where the combination `[quote1] * [quote2]` returns a version of [quote1] with [quote2] inserted after each character. For instance ``` `abc' * `xy'``` results in ``` `axybxycxy'```.

### Division

The inverse of quote multiplication is quote division. That is, the combination ``` `axybxycxy' / `xy'``` returns ``` `abc' ```. If [quote2] is not a sub-quote of [quote1], then only [quote1] is returned.

#### Exercise:

> Predict the result of ``` `abc' / `xy' * `xy'```.

> Solution: By operator precedence, the combination ``` `xy' * `xy'``` is considered first, resulting in ``` `xxyyxy'```. The problem translates to ``` `abc' / `xxyyxy'```, resulting in simply ``` `abc'```.

...

## Quote Comparison and Logic

Quotes can be compared using the same operators that apply to numbers, following the same precedence.

The equivalency operator, denoted by a single "equal" symbol ( `=` ), tests for equivalency between two quotes. If the left- and right-arguments are equal, the returned result is `1`. Non-equal arguments return `0`. In contrast to numerical comparison, the result of quote comparison is not formatted as a number. As stand-alone symbols, `1` and `0` are considered "words" until "touched" by an operator.

The logical AND, along with logical OR, also apply to quotes. Any non-empty inputs are considered "on", and an empty-input is considered "off". Like the equivalency operator, the logical operators, as applied to quotes, return a `1` for the affirmative case, and `0` otherwise.

***

# Guide: Output Formatting

Sxript output is passed through a final formatting step before entering the environment. Most notably, quotes lose their bracketing characters, i.e. ``` ` ``` and ` ' ` vanish. This also applies to embedded quotes, so ``` `cows say `moo''``` flattens to `cows say moo`.

## Escape Character

When the backslash character ( `\` ), or *escape character* appears in any output, the character to the right receives special treatment.

The most obvious need for the escape character is for including the backtick ( ``` ` ``` ) or apostrophe ( ` ' ` ) in a quote. This is achieved using respective combinations ``` \` ```, and ``` \' ```.

Tabs and returns are handled by the following:
* `\t` becomes ASCII-9  (Tab)
* `\n` becomes ASCII-10 (LF)
* `\r` becomes ASCII-13 (CR)
* `\\` becomes ` \ ` after all other formatting takes place.

### Carriage Return

Note that the role of ASCII-13, i.e. the Carriage Return, behaves differently per implementation. Through JavaScript, the quote ``` `hello\rthere'``` is broken apart at ``` `hello'```, and ``` `there'``` is printed on a new line. Meanwhile, the QB64 and C++ terminal implementations return ` `thereo'`, because the cursor returns to the left-most position without starting a new line.

***

# Guide: Code Blocks

Sxript expressions can be chained together in a linear sequence, and sent for evaluation as a *code block*, or simply, "block".

## Block Anatomy

A code block begins with the word `block`, followed by a set of curly braces enclosed in parentheses, as in `({})`. Inside this structure, we place any number of valid expressions, separated by the colon symbol ( `:` ). At least one expression must be prefixed with the word `print_`, with the underscore. All together, a code block may look like:

```
sub({
  1+1:
  2+2:
  print_3+3
})
```
Note that the use of spaces, tabs, and new lines is entirely optional. The code block above is immediately condensed to `sub({1+1:2+2:print_3+3})` before proceeding.

## Block Evaluation

When evaluated, the expressions in a code block are resolved in left-to-right order. The *only* output of the code block, however, is whatever follows `print_`. (This is much like the "return" aspect of C-family functions.) For the example on hand, the code block will first evaluate `1+1`, followed by `2+2`, and finally `3+3`. The *only* output carried away from the code block is what follows `print_`, i.e. `+6.0`.

#### Exercise:

> Predict the result of: 
```
block({
  print_1+1:
  2+2:
  print_3+3
})
```
> Solution: This code block stacks two outputs, namely `+2.0` and `+6.0`. Of course, these are situated as an expression of their own, namely `+2.0+6.0`, which evaluates to `+8.0`.

...

## Comments

One may wonder why a code block may contain certain expressions that are not used in constructing output. Indeed, we may replace the expression `2+2` in the above with a quote, serving the role of a *comment*:

```
block({
  print_1+1:
  `Comments are just quotes':
  print_3+3
})
```
Note that comments must obey all of the "usual" rules for quote placement. (Comments are lines of code.)

## Block Embedding

Code blocks may nest within code blocks to make calculations more organized. If the output of a code block is matched to its surroundings, evaluation continues without a hitch. For example, the following code returns a value of `+10.0` (be sure to puzzle this out):

```
block({
  print_
  4 +
  block({
    `Inner code block':
    print_1+1:
    print_2+2
  }):
  `Outer block':
})
```

Note again that the use of spaces, indentation, and new lines (outside of quotes) is entirely for clarity.

***

# Guide: Procedural Subsystem

Several "procedural" keywords are used for "jumping around" expressions inside  a code block. All at once, these are `do`, `loop`, `goto_`, `anchor_`, and `if_`. Procedural statements may *only* mingle within their own code block. An embedded code block is unaware of what the parent block is doing with procedural statements, and vice-versa.

## do ... loop

The `do` ... `loop` structure is a mechanism for iterative evaluation. The "body" of the loop is any expression(s) contained between `do` and `loop`. The number of iterations is defined by the number that directly precedes the `do` statement. For instance, the following code block contains a loop that is iterated five times:

```
block({
  print_`Hello w' + :
  5:
  do:
    print_`o' + :
  loop:
  print_`rld!'
})
```
#### Exercise:

> Predict the result of the above code block.

> Solution: The output is constructed from: ``` `Hello w'+`o'+`o'+`o'+`o'+`o'+`rld!'  ```, resulting in ``` `Hello wooooorld!'```.

...

### Nested Loops

Multiple `do` ... `loop` structures can exist in the same code block, with nesting being no exception.

#### Exercise:

> Predict the result of the following code block:

```
block({
  3:
  do:
    2:
    do:
      4:
      do:
        print_1:
      loop:
    loop:
  loop:
})
```

> Solution: The `print_` statement is embedded in all three `do` ... `loop` structures. Multiplying the number of iterations, we find 3 * 2 * 4 = 24. Thus, the output is 24 copies of the `1`, namely `111111111111111111111111`.

...

## anchor ... goto

Within a code block, we may define an *anchor* point, much like a label or line label, for which control may be passed. This achieved using `anchor_`, followed by a unique word to denote the anchor name. Anchors are used in conjunction with the `goto_` statement followed by the anchor name - this is the classic GOTO scenario that we love to hate. 

The following spaghetti code illustrates the use of `anchor_` and `goto_`. After all of the skipping around, the output of this block is `134`:

```
block({
   print_1:
    goto_a:
  anchor_b:
   print_2:
  anchor_a:
   print_3:
    goto_c:
    goto_b:
  anchor_c:
   print_4
})
```