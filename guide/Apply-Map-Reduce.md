# Guide: Apply, Map, Reduce

Here we introduce three powerful primitives that apply to vectors: `apply`, `map`, and `reduce`.

## Apply

The `apply` primitive applies a function to each element in a vector and returns the result. Writing the prototype `apply(f(x),vector)=vector`, note that the input vector and the returned vector have the same number of elements, and the function `f(x)` depends on a single argument.

In symbolic notation, the `apply` primitive applies function `f([x])` to each of the `N` elements in vector `[v]` to produce the result:

> `<f(elem([v],1)), f(elem([v],2)), ..., f(elem([v],N-1)), f(elem([v],N))>`

### Examples

| Expression | Result
|---|---|
| `apply(cos,<1,2,3>)` | `<.5403023058681398,-.4161468365471424,-.9899924966004454>`
| `apply(identity,<a,b,c,d,e>)` | `<a,b,c,d,e>`
| ``` apply(len,<`dog',`cat',`mouse'>) ``` | `<3,3,5>`
| `apply(rand,<1,2,3>)` | `<.8627438545227051,.954358458518982,2.44416081905365>` (typical)
| `apply(sqrt,<9,16,25,121>)` | `<3,4,5,11>`
| |

## Map







