# Guide: Boundary Fusion

## Definition

If two "chunks" of occulted code occur in sequence with no separating character, i.e. `{abc}{def}`, the inner boundary symbols `}{` disappear entirely, resulting in `{abcdef}`. This is called *boundary fusion*, and is only defined for occulted code. Other bracketed structures, such as quotes and vectors, do not bear this notion.

## Standard Application

Now we employ a curious combination of variable retrieval and boundary fusion. To motivate this, consider the following code block, in where we intend to "inject" the symbol `[a]` into in occulted code structure:

```
block({
  let(a,2):
  print_{1+[a]+3}
})
```

Not surprisingly, the above simply outputs `{1+[a]+3}` as the occulting symbols block `[a]` from being replaced by its content, `2`. However, we can step toward the desired result using  boundary fusion to "close and reopen" the occulted structure as follows:

```
block({
  let(a,2):
  print_{1+}[a]{+3}
})
```

The above code block results in `{1+}2{+3}`, which is a good sign. Recall that the `occult` primitive can be used to wrap its argument in curvy brackets ( `{ }` ), which we promptly set around `[a]`:

```
block({
  let(a,2):
  print_{1+}occult([a]){+3}
})
```

The above produces the result intermediate result `{1+}{2}{+3}`, which reduces to `{1+2+3}` by the boundary fusion rule, satisfying the original intention.

## Occult-Embedding Combination

The combination

> `{... }occult(x){ ...}`

allows `x` to be evaluated directly, as it excluded from the occulted structure. Immediately afterward, the `occult` primitive wraps `x` accordingly, and simplifies to 

> `{... }{x}{ ...}`

which, by boundary fusion, simplifies again to:

> `{... x ...}`

The structure `}occult(x){` shall be called the *occult-embedding combination*, which penetrates one layer of occulting symbols ( `{ }` ).

### Double-Embedded Combination

 To penetrate two occult layers, the modified combination `}}occult(occult(x)){{` replaces the previous one. Modifying the above example, the two-layer combination applies in the following code block, which outputs `{1+2+3}`:

```
block({
  let(a,2):
  print_block({print_{1+ }}occult(occult([a])){{ +3}})
})
```

### Triple-Embedded Combination

Naturally, the combination needed to penetrate three occult layers must be `}}}occult(occult(occult(x))){{{`, as illustrated in the following:

```
block({
  let(a,`yes'):
  print_{iff(1,{ }}}occult(occult(occult([a]))){{{ },{`no'})}
})
```

The output of the above reads `{iff(1,{yes},{no})}`.