# Guide: Variables

Now we meet the *variable*, a means for storing and recalling information. A variable fundamentally consists of two things: (i) a variable name, and (ii) the stored content.

## Storage: the `let` Primitive

Variable storage is achieved using the `let` primitive, having prototype `let(name,x)=x`. The `name` argument is interpreted as a `word` (i.e. not a `quote`, see [Index of Types](docs/Type-Index.md)). The `name` argument can be more-or-less anything, however the following symbols are reserved and should not be used as a name:

> `[x]`, `[y]`, `[z]`, `[t]`, `[u]`, `[v]`

The "content" argument, represented by `x`, is any valid Sxript expression. Being embedded within the `let` primitive, note that `x` is evaluated before storage takes place. The output of the `let` prototype is the literal content `x`.

To illustrate, the expression `let(a,1+1)` is first reduced to `let(a,+2.0)`, and then the value `+2.0` is attached to the name `a`. The output of `let(a,1+1)` is precisely `+2.0`.

Meanwhile, content can be "protected" by occulting the `x`-argument. That is, `let(b,{1+1})` stores and outputs `{1+1}`.

### Corollaries

Since the output of the `let` primitive is the content `x`, it follows that `let` can be used in-line with compatible operations. For instance, `4+let(a,3)` outputs `+7.0`, after storing `3` in the name `a`.

As an "ordinary" primitive, `let` can be embedded within other primitives, including itself. For instance, `let(b,4+let(a,3))` will store `3` in `a`, simplifying to `let(b,+7.0)`.

## Retrieval: `[name]=x`

After the `len` primitive is used to store content `x`, its literal value is recovered by enclosing the variable name within square brackets, forming a `symbol` type. Then, any instance of `[name]` in the expression is replaced by `x`.

Continuing the examples above, the expression `[b]+[a]` simplifies to `+7.0+3`, resulting in `+10.0`.

### Rules for `[name]=x` Retrieval

There are two chief rules for so-called `[name]=x` retrieval in an expression:

* Replacement occurs *before* any operators, primitives, or parenthesized sub-expressions are evaluated.
* Replacement does *not* occur within occulted structures ( `{ }` ).

## Illustration

Consider the simple code block:

```
block({
  let(a,2+2):
  print_[a]+(3+3)
})
```

Since whitespace and indentation is ignored, let us follow in step and write the above as `block({let(a,2+2):print_[a]+(3+3)})`. The body of the code block contains two lines, evaluated in sequence (see [Procedural Subsystem](docs/Procedural-Subsystem.md)). After the first line is evaluated, the code block simplifies to `block({+4.0:print_[a]+(3+3)})`, where the value `+4.0` is now stored with the name `a`.

With the first line finished, control passes to the `print_` statement, evaluated in steps. Note that variable replacement `[a]` -> `+4.0` takes place before the parenthesized quantity `(3+3)` is evaluated, so the original statement `print_[a]+(3+3)` simplifies to `print_+4.0+(3+3)`, finally resulting in `+10.0`.

## Variable Mutation

When it comes to changing the value stored in a variable, there is no "edit" primitive, nor are there any specialized operators `++`, `+=`, `=+`, etc. Instead, we simply use `let` again, with the variable content represented by a symbol in the second argument. For example, the following code block stores `1` in the variable `a`, and then stores `+2.0` in the same variable:

```
block({
  let(a,1):
  print_let(a,[a]+1)
})
```

## Storing Occulted Code

Consider the following code block:

```
block({
  let(a,{let(b,3):print_2+[b]}):
  print_[a]
})
```

In the above, we store the occulted code `{let(b,3):print_2+[b]}` in a variable `a`, and then the `print_` statement simply outputs the occulted code as-is. Of course, this can itself be evaluated if we wrap the *whole* code block within another `block` primitive, the above becomes:

```
block(
  block({
    let(a,{let(b,3):print_2+[b]}):
    print_[a]
  })
)
```

The final output of the above is `+5.0`. Note also that two variables `a` and `b` are still defined.