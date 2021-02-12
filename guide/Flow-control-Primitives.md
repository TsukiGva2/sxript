# Guide: Flow-Control Primitives

## The `iff` Primitive

The `iff` primitive, obeying the prototype `iff(condition,occult1,occult2)=z`, is a *conditional* primitive. In the prototype, `condition` is a placeholder for any Sxript expression. If the condition reduces to anything numerically equivalent to `+1.0`, the `occult1` code is "accessed" and evaluated. If the `condition` is not met, then control passes into `occult2`. Neither `occult1` nor `occult2` may be empty.

The `iff` primitive is much *unlike* its cousin `if_`, part of the [Procedural Subsystem](Procedural-Subsystem.md).

### Basic Use

A trivial use case for the `iff` primitive may appear as `iff(1,{a},{b})`, whose condition of `1` is clearly equivalent to `+1.0`, and returns `a`. Similarly, `iff(0,{a},{b})` fails the condition check, and returns `b`.

### Advanced Use

The structures `occult1` and `occult2` must each be equivalent to a single expression, which means neither contain multiple statements. In other words `iff([condition],{a:b:c},{d:e:f})` is undefined, and certainly *wrong*. In order to "properly" achieve this, we must employ [Code Blocks](Code-Blocks.md) as follows:

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
