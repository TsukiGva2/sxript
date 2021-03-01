# Guide: Scope and Subprograms

## State

The `let` primitive, which allows values to be stored and recalled, is a double-edged sword: we gain the benefit of storing and re-using variables, however we have to make sure that variables do not cause "unwanted side effects" in code that follows their definition.

Whenever a variable is defined or changed, the *state* program is modified. That is, once the expression `let(a,1)` is evaluated, any subsequent mention of the variable name as a symbol, namely `[a]`, will have an effect on the program.

## Scope

 Consider the following code block:

```
block({
  let(a,1):

  block({
    let(b,2):
    let(a,[a]+[b]):
    print_()
  }):

  print_<[a],[b]>
})
```

In the above, we let the variable `a` stores the value `1`, and control is passed to a code block. Inside the block, variable `b` stores the values `2`, and `a` is overwritten to contain `+3.0`. After the block, the values of `a` and `b` are recalled and outputted using `print_<[a],[b]>`, which results in `<+3.0,2>`. Despite the nested code block containing (re)definitions of `a` and `b`, it naturally follows that each variable is "visible" outside of the nested block.

Two or more variables that are mutually accessible to each other are said to exist in the same *scope*. Flipping back through this guide, all programs so far written have been of the same scope.

## The `sub` Primitive

The notion of "scope" invokes the question of whether a variable may be *inaccessible* to another, an idea called *private scope*. In our case, we may imagine a modification to the above code block that "protects" the outer program from whatever is happening inside the nested code block. Indeed, the `sub` primitive, which replaces `block` in the above, achieves just this:

```
block({
  let(a,1):

  sub({
    let(b,2):
    let(a,[a]+[b]):
    print_()
  }):

  print_<[a],[b]>
})
```

The `sub` primitive, short for "subprogram", behaves *exactly* like the `block` primitive, except the outer program has total amnesia with respect to the inner calculations. That is, the *only* effect that *sub* has on a program is whatever is carried away by the `print_` statement.

Evaluating the above code block results in `<1,[b]>`. Note that this output is completely independent of the edits to `a` and `b` within the subprogram.

The above code block can be modified again to make use of the subprogram calculation, namely by sending the output `[a]` to a variable `c` as shown:

```
block({
  let(a,1):

  let(c,
    sub({
      let(b,2):
      let(a,[a]+[b]):
      print_[a]
    })
  ):

  print_<[a],[b],[c]>
})
```

The output of the above is `<1,[b],+3.0>`. Outside of the subprogram, `a` still stores `1`, and `b` is still undefined. Meanwhile, `c` stores `+3.0`.

## Environment

When the `sub` primitive is used, the "outer program" is formally called the *environment*. All variables from the environment are accessible to the subprogram, but this is a one-way relationship. Expressions in the environment cannot access variables within a subprogram.

When the sub program is completed, the *only* effect on the state of the program is whatever is carried off by the `print_` statement.
