# Guide: Procedural Subsystem

Several "procedural" keywords, or *statements* are used for "jumping around" expressions inside  a code block. All at once, these are `do`, `loop`, `goto_`, `anchor_`, and `if_`. Procedural statements may *only* mingle within their own code block. An embedded code block is unaware of what the parent block is doing with procedural statements, and vice-versa.

## 1/3) do ... loop

The `do` ... `loop` structure is a mechanism for iterative evaluation, formally called a *count-controlled loop*. The "body" of the loop is any expression(s) contained between `do` and `loop`. The number of iterations is defined by the number that directly precedes the `do` statement. For instance, the following code block contains a loop that is iterated five times:

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

> Solution: The output is constructed from ``` `Hello w'+`o'+`o'+`o'+`o'+`o'+`rld!'  ```, resulting in ``` `Hello wooooorld!'```.

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
> Solution: The `print_` statement is embedded in all three `do` ... `loop` structures. Multiplying the number of iterations, we find 3 * 2 * 4 = 24. Thus, the output is 24 copies of the "word" `1`, namely `111111111111111111111111`.

#### Exercise:

> In the above code block, replace `1` with `+1`. What is the new output?

> The output is constructed from `+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1`, resulting in `+24.0`.

## 2/3) anchor ... goto

Within a code block, we may define an *anchor* point, much like a line label, for which control may be passed. This achieved using `anchor_`, followed by a unique word to denote the anchor name. Anchors are used in conjunction with the `goto_` statement followed by the anchor name - this is the classic GOTO scenario that we love to hate. 

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

## 3/3) if ... @

A second means of jumping to an anchor point is the "conditional if" structure:

> `if_ condition @name`

The so-called `condition` is a placeholder for any Sxript expression. If the condition reduces to anything numerically equivalent to `+1.0`, then control is passed to the anchor called `name`. Otherwise, control is passed to the next line, if any. For instance, in the following code block, the statement `if_ 1 @a` detects a `1` between the underscore ( `_` ) and the `@`-symbol, always returning `true`.

```
block({
  if_ 1 @a:
  print_`not '+:
  anchor_a:
  print_`true'
})
```

By changing the condition away from `1`, for instance `if_ 3 @a`, then the output of the code block is `not true`.

This apparatus is the rat material for setting up a *condition-controlled loop*.

## Remark

The procedural subsystem is the *only* means of writing multi-lined programs in Sxript, and the set of commands detailed here is the *entire* set. You will not be impinged upon by more underscored procedural commands later on.

Using few keywords, it is still possible to write an enormous code block wired with many loops, anchors, and goto statements. Before long, such a spaghetti-code program becomes difficult to follow, let alone improve or repurpose. This practice is of course discouraged in all languages, with Sxript being no exception.