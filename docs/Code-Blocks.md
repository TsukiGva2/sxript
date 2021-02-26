# Guide: Code Blocks

Sxript expressions can be chained together in a linear sequence, and sent for evaluation as a *code block*, or simply, "block".

## Block Anatomy

A code block begins with the word `block`, followed by a set of curvy braces enclosed in parentheses, as in `({})`. Inside this structure, we place any number of valid expressions, separated by the colon symbol ( `:` ). At least one expression must be prefixed with the word `print_`, with the underscore. All together, a code block may look like:

```
block({
  1+1:
  2+2:
  print_3+3
})
```

## Whitespace

The use of spaces, tabs, and line breaks is entirely optional. For instance, the code block above is immediately flattented to `sub({1+1:2+2:print_3+3})` before evaluation.

## Block Evaluation

When evaluated, the expressions in a code block are resolved in left-to-right order. The output of the code block, however, is strictly limited to expressions following `print_`. (This is much like the "return" aspect of C-family functions.) A code block is "erased" after evaluation, and the surviving output is whatever followed `print_`.

For the example on hand, the code block will first evaluate `1+1`, followed by `2+2`, and finally `3+3`. The *only* output carried away from the code block is what follows `print_`, i.e. `+6.0`.

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

Code blocks may nest within code blocks to keep calculations organized. If the output of a code block is matched to its surroundings, evaluation continues without a hitch. For example, the following code returns a value of `+10.0` (be sure to puzzle this out):

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