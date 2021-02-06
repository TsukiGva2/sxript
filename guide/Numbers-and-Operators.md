# Guide: Numbers and Operators

## Numerical Operators

Numerical expressions are defined as one-character operators ` ! ^ * / % + - ` embedded between a pair of base-ten numbers (or rarely, one number) to produce a numerical result of double precision. Operators are treated in strict descending order as listed: no two operators are of equal precedence. The result of a numerical operation is always prefixed with a sign, `+` or `-`, and suffixed with a decimal remainder, even if `.0`. Expressions containing multiple operators are evaluated recursively.

## Operator Reduction

Before any numerical operations are considered, all input passes through an operator reduction filter, which reduces things like `+++` to a single `+`, and so on. Occurrences of `-+` are interpreted as `-`, making inputs such as `3-+3` evaluate to `+0.0`, as expected. Occurrences of a "double negative" `--` are interpreted as a single positive `+`.

## Duality of the Negative Sign

Following the (unfortunate) convention of traditional notation, the negative sign ( `-` ) plays a dual rule in numerical expressions. Apart from acting as the subtraction operator, the same symbol is used to denote stand-alone negative numbers, such as `-3.5`, in where no "operation" takes place at all.

Sxript adopts a convention where the negative sign prefers to bind to numbers (like an electron) to make them negative, instead of going between numbers to act as a subtraction operator.

#### Exercise:

> Predict the result of `0-3^2`.

> Solution: By operator precedence, the power operator ( `^` ) is regarded first, which triggers a "search" for numbers surrounding the operator. On the right, we have `2`, whereas on the left, the operator captures `-3`. This means `-3*-3` is treated as a stand-alone problem, solved by `+9.0`. The original expression becomes `0+9.0`, simplifying to `+9.0`.

#### Exercise:

> Predict the result of `0--3^2`.

> Solution: By operator reduction, the expression reduces to `0+3^2` before any numerical operations take place. The expression becomes `0+9.0`, simplifying to `+9.0`.

## Numerical Comparison and Logic

The equivalency operator, denoted by a single "equal" symbol ( `=` ), tests for equivalency between two numbers. If the left- and right-arguments are numerically equal, the returned result is `+1.0`. Non-equal arguments return `+0.0`.

The logical AND, along with logical OR, are represented by the ampersand ( `&` ) and vertical slash ( `|` ), respectively. Any non-zero inputs are considered "on", and a zero-input is considered "off". Like the equivalency operator, the logical operators, as applied to numbers, return a `+1.0` for the affirmative case, and `+0.0` otherwise.

## Remark

There is no operator notation for "less than" ( `<` ) and "greater than" ( `>` ), because the angle bracket symbols are reserved for vectors. To perform such comparisons, we'll soon meet the `greater(x,y)` function.