# Guide: User-Defined Functions

A *user-defined function*, also known as a UDF, allows the programmer to create reusable structures that depend on arguments, much like language primitives.

## The `func` Primitive

Functions are defined using the `func` primitive, having prototype `func(name,occult)=name`. Analogous to [variable](docs/Variables.md) definition, the `func` primitive connects `name` to a piece of occulted code called the *function body*. In the same way that most primitives require arguments, user-defined functions may also depend on arguments.

## Zero-Argument Function

A trivial use of the `func` primitive defines a function that takes no arguments. In this case, the user-defined function simply stores a *value*, illustrated in the following:

> `func(a,{1+1})`

In the above, the function name `a` is associated with `{1+1}`. When evaluated, the result of the above is simply `a`, signaling that `a` is defined properly.

Functions are "retrieved", or *called*, using the same notation used for primitives. When called, the occulted code is "unlocked", and the content is free for evaluation. For the example on hand, the expression `a()` returns `+2.0`.

## One-Argument Functions

 A *one-argument* function requires one input. For example, consider the function:

> `func(b,{[x]+2*[x]})`

In the above, the `func` primitive associates the name `b` with `{[x]+2*[x]}`. Inside the function body, symbol `[x]`, is called the *parameter*. The parameter may appear more than once within the function body, but the parameter must *always* be named `[x]`.

To make use of the function `b`, we first decide which argument to "send to" the function. Choosing an argument of `1`, we would write:

> `b(1)`

When evaluated, the argument `1` replaces the parameter `[x]` inside the function body, producing the intermediate step `1+2*1`, resulting in `+3.0`.

By the rules of [operator overloading](docs/Operator-Overloading.md), the function `b` as defined can handle string arguments as well:

> ``` b(`hello ')```

The above evaluates to `hello hello hello `.

## Multiple-Argument Functions

All single-argument functions use `[x]` as the parameter in the function body. All two-argument functions use `[x]` and `[y]`. This pattern continues up to six arguments, i.e. the symbols reserved inside functions are:

> `[x]`, `[y]`, `[z]`, `[t]`, `[u]`, `[v]`

After six arguments, we run out of reserved letters. Formally however, the *only* argument needed is `[x]`. Multiple data elements can be stored in a vector, which is considered a single argument, acceded by `[x]` within the function body. Most cases call for functions of one to three arguments, thus `[x]`, `[y]`, and `[z]` tend to appear most commonly in functions.

## Functions and Scope

The whole apparatus of state, scope, and environment that applies to variables also applies to functions.

## Pure Functions vs. Impure Functions

A *pure function* is one that (i) does not modify its environment, and (ii) produces the same output for a given input. On the other hand, an *impure function* either (i) has an effect on its environment, and/or (ii) gives a different output for the same input.

