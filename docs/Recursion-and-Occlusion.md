# Recursion and Occlusion

Sxript expressions readily admit parentheses ( `()` ) for embedding an expression within an expression. In a given input string, the *deepest-and-left-most* set matching parentheses, if the pair exists, contains a "sub-expression". Once isolated, the sub-expression is sent for evaluation, returning as a number, quote, or other structure. This result is inserted into the working string in place of the sub-expression, without the parentheses. This behavior repeats until all sub-expressions are simplified.

## Evaluation of Alphanumeric Expressions

The role of parentheses in numeric and quote expressions is analogous to their role in elementary algebra. Taking a trivial example from arithmetic, the expression `(4-1)/(4-2)` simplifies to `+3.0/+2.0`, and once again to `+1.5`. We may "refactor" the expression to look more complicated, as in `(4-(3-2))/(4-2)`, to yield the same result.

The notion of "evaluate the deepest-and-left-most first" extends to sub-expressions containing quotes, and also to cases mixing numbers and quotes.

## Evaluation within Vectors

By default, the elements in a vector are evaluated in left-to-right order, starting with element `1` and ending at element `N`. However, the "deepest and left-most sub-expression" rule always applies, meaning the most-embedded sub-expression *in the whole vector* is always simplified first.

## Occulted Code

Now we come to an important definition. Any content contained in curvy braces ( `{}` ) is called *occulted* code, or occulted expressions, considered as a single piece of data. Occulted expressions, whether they contain parentheses or not, are invisible to the evaluation mechanism.

### Occulted Code in Blocks

The simplest use of occulted code occurs in a code block, where the form `block({a:b:c})` contains the occulted structure `{a:b:c}`. Each *element* of occulted code is separated by the colon symbol ( `:` ).

The special form `block()` opens (or "un-occults") the contents for evaluation. Control is passed inside the code block, and the entire `block({a:b:c})` expression simplifies to whatever is carried off by `print_` statement(s) contained in `{a:b:c}`.
