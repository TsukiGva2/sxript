# Guide: Apply, Map, Reduce

Here we introduce three powerful primitives that apply to vectors: `apply`, `map`, and `reduce`. Each of these invoke the notion of a *collection-controlled loop*.

## Apply

The `apply` primitive applies a one-argument function to each element in a vector, and returns the result. Writing the prototype `apply(f(x),vector)=vector`, note that the input vector and the returned vector have the same number of elements, and the function `f(x)` depends on a single argument.

Expanding this, the `apply` primitive applies function `f([x])` to each of the `N` elements `[vj]` in vector `[v]` to produce:

> `<f([v1]), f([v2]), ..., f(vN-1]), f([vN])>`

### Examples

| Expression | Result
|---|---
| `apply(cos,<1,2,3>)` | `<.5403023058681398,-.4161468365471424,-.9899924966004454>`
| `apply(identity,<a,b,c,d,e>)` | `<a,b,c,d,e>`
| ``` apply(len,<`dog',`cat',`mouse'>) ``` | `<3,3,5>`
| `apply(rand,<1,2,3>)` | `<.8627438545227051,.954358458518982,2.44416081905365>` (varies)
| `apply(sqrt,<9,16,25,121>)` | `<3,4,5,11>`

## Map

The `map` primitive applies a two-argument function to equal-indexed pairs of elements within two vectors of equal length, returning a vector of the same length. The `map` prototype is written `map(vector,f(x,y),vector)=vector`.

In more detail, the `map` primitive applies a function `f([x],[y])` to each of the `N` corresponding elements `[vj]`, `[wj]` in two vectors `[v]`, `[w]` to produce:

> `<f([v1],[w1], f([v2],[w2], ..., f([vN-1],[wN-1]), f([vN],[wN])>`

### Examples

| Expression | Result
|---|---
| `map(<10,5,3>,greater,<6,5,4>)` | `<1,0,0>`
| `map(<1,3,4>,join,0+<1,2,3>)` | `<+2.0,+5.0,+7.0>`
| `map(map(<1,2,3>,join,<+,*,->),join,<7,8,9>)` | `<+8.0,+16.0,-6.0>`
| ``` map(<`dog',`cat',`mouse'>,instr,<`o',`z',`u'>) ``` | `<2,0,3>`
| `map(<<a,b,c>,<d,e,f>,<g,h,i>>,left,<1,2,3>)` | `<<a>,<d,e>,<g,h,i>>`

## Reduce

The `reduce` primitive uses a two-argument function `f(x,y)` to collapse a vector `[v]` to a single value `[r]`. The `reduce` prototype is written `reduce(f(x,y),vector)=z`, where `z` is some structure within the range of `f(x,y)`, and is calculated according to:

> `f(...(f(f(f([v1],[v2]),[v3]),[v4])...),[vN])`

### Examples

| Expression | Interpretation | Result
|---|---|---
| `reduce(join,<a,b,c>)` | `join(join(a,b),c)` | `abc`
| `reduce(greater,<4,3,0>)` | `greater(greater(4,3),0)` | `1`
| `reduce(join,4*<1,2,3>)` | `join(join(+4.0,+8.0),+12.0)` | `+24.0`
| `reduce(join,<5*,4*,3*,2*,1>)` | `join(join(join(join(5*,4*),3*),2*),1)` | `+120.0`

### Examples, cont'd.

| Expression | Result
|---|---
| ``` reduce(join,map(<`dog',`cat',`mouse'>+` ',join,<+,+,>))``` | ``` `dog cat mouse ' ``` 
