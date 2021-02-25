# Guide: Variables

Now we meet the *variable*, a means for storing and recalling information. A variable fundamentally consists of two things: (i) a variable name, and (ii) the stored content.

## Storage: the `let` Primitive

Variable storage is achieved using the `let` primitive, having prototype `let(name,x)=x`. The `name` argument is interpreted as a `word` (i.e. not a `quote`, see [Index of Types](docs/Type-Index.md)). The `name` argument can be more-or-less anything, however the following symbols are reserved and should not be used as a name:

> `[x]`, `[y]`, `[z]`, `[t]`, `[u]`, `[v]`

The "content" argument, represented by `x`, is any valid Sxript expression. Being embedded within the `let` primitive, note that `x` is evaluated before the storage takes place.

## Retrieval: 



block({
  let(a,5):
  print_{{{{{
    {a}
  }}}}}
})
