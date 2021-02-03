# Guide: Procedural Subsystem

Several "procedural" keywords, or *statements* are used for "jumping around" expressions inside  a code block. All at once, these are `do`, `loop`, `goto_`, `anchor_`, and `if_`. Procedural statements may *only* mingle within their own code block. An embedded code block is unaware of what the parent block is doing with procedural statements, and vice-versa.

## 1/3) do ... loop

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

## 2/3) anchor ... goto

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

## 3/3) if ... goto












