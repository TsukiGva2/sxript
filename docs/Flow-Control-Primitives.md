# Guide: Flow-Control Primitives

## The `iff` Primitive

The `iff` primitive, obeying the prototype `iff(condition,occult1,occult2)=z`, is a *conditional* primitive. In the prototype, `condition` is a placeholder for any Sxript expression. If the condition reduces to anything numerically equivalent to `+1.0`, the `occult1` code is "accessed" and evaluated. If the `condition` is not met, then control passes into `occult2`. Neither `occult1` nor `occult2` may be empty.

The `iff` primitive is much *unlike* its cousin `if_`, part of the [Procedural Subsystem](Procedural-Subsystem.md).

#### Trivial Use

A trivial use case for the `iff` primitive would be `iff(1,{a},{b})`, whose condition of `1` is clearly equivalent to `+1.0`, and returns `a`. Similarly, `iff(0,{a},{b})` fails the condition check, and returns `b`.

#### Typical Use

The structures `occult1` and `occult2` must each be equivalent to a single expression, which means neither contain multiple statements. For instance, `iff([condition],{a:b:c},{d:e:f})` is undefined, and certainly *wrong*. In order to "properly" achieve this, we must employ [Code Blocks](Code-Blocks.md) as follows:

```
iff([condition],{
  block({
    a:b:print_c
  })
},{
  block({
    d:e:print_f
  })
})
```

If the condition check passes, then the output of the above is `c`. Otherwise, the output is `f`.

### Nesting

Conditions and blocks can also be nested as a way to build complexity:

```
iff(1,{
  block({
    print_iff(0,{`cat'},{`dog'})
  })
},{
  block({
    d:e:print_f
  })
})
```
## The `for` Primitive

The `for` primitive, obeying the prototype `iff(<j,ji,jf,dj>,occult)=z`, sets up a count-controlled loop. The "body" of the loop occurs as an occulted structure. The leading term is a vector that contains the looping conditions.

### The Iteration Variable

The number of `for`-loop iterations is governed by a number `j`, beginning at some initial value `ji`, ending at some final value `jf`, incrementing by `dj` after each iteration. This so-called *iteration variable* `j`, which need ne labeled `j` necessarily, can be accessed within the loop as a *symbol*. That is, value of `j`, as a *formatted* number, is represented by `[j]`. Any expressions in the loop body that contain `[j]` have "access" to this value.

Note that the symbol `[j]` can be replaced with (nearly) any other, however the following symbols are reserved and should not be used inside the `for` primitive:

> `[x]`, `[y]`, `[z]`, `[t]`, `[u]`, `[v]`

#### Trivial Use

A trivial use case for the `for` primitive would be `for(<i,0,9,1>,{a})`, which outputs the word `a` ten times.

#### Typical Use

An example of a `for` loop that references its own iteration variable may occur as `for(<k,0,4,1>,{[k]})`. Such an expression translates to `+0.0+1.0+2.0+3.0+4.0`, resulting in `+10.0`. Of course, we can slip the "unformat" primitive around the iteration variable to prevent the summation effect. That is, `for(<k,0,4,1>,{unf([k])})` results in `01234`.

### Nesting

The `for`-primitive can be nested within other structures, and by the same token, the body of the `for` loop can contain nested structures. This also means that the iteration variable (`[i]`, `[k]`, etc.) can be accessed within the nested structures.

#### Loop Nesting

A simple example of nested `for`-loops is the following:

```
for(<i,1,4,1>,{
  for(<j,1,[i],1>,{
    unf([j])
  })
  \n
})
```

The "outer" loop, having iteration variable `i`, is executed four times. This loop contains an "inner" loop, which iterates a variable `j` starts at `1`, and ends at the present value of `i`, represented by `[i]`. The nested expression `unf([j])` reports a clean representation of `[j]`. The inner loop is followed by a line break. The output of the above is:

```
1
12
123
1234
```
#### Block Nesting

A more complex use of the `for` primitive requires multiple expressions within the loop body. Modifying the example above somewhat, we may come up with:

```
for(<i,1,4,1>,{
  block({
    print_[i] \n:
    print_
    for(<j,1,[i],1>,{
      block({
        print_for(<k,[j],[i],1>,{unf([k])}) \t:
        print_unf([j]) \n
      })
    })
  })
})
```

Looking closely at the expressions following `print_`, we predict a somewhat-organized structure of formatted numbers and unformatted numbers, looking somewhat like:

```
+1.0
1       1
+2.0
12      1
2       2
+3.0
123     1
23      2
3       3
+4.0
1234    1
234     2
34      3
4       4
```
