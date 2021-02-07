# Guide: Vectors (Lists)

A *vector* is a structure for keeping separate pieces of data in a linear list, somewhat like an array. 

## Vector Anatomy

A vector is enclosed by left- ( `<` ) and right-angle-brackets ( `>` ). The formal name for "piece of data" in a vector is an *element*. Each element is separated by a comma ( `,` ).

For example, the following vectors containing mixtures of numbers, quotes, and other "words' are each valid:

``` <1,2,+3.0,4,`Computer`>```

``` <a,b,c,d,e>```

``` <1,`Keyboard',3.14,`Toyota'>```

A vector may also contain an embedded vector (or several) among its elements:

```
<1,2,3,<a,b,c,d,e,f>,<4,5,6>>
```
## Vector Nomenclature

### Matrix

If each element in vector is itself a vector with the a constant number of elements, this is loosely called a *matrix*. Think of a matrix as being a "rectangular" list of lists.

```
<
  <a,b,c>,
  <d,e,f>,
  <g,h,i>
>
```

### Super-List

Any generalization of a matrix is called a *super-list*. For instance, the following embedding of vectors is perfectly valid:

```
<
  <a,b,3>,
  <d,<e,f,7>,h>,
  <i,`jello',
    <k,`l',m,
      <o,15,`"quick"'>
    >,
    r,s,`truck'
  >
>
```

Note that the use of spaces, tabs, and line breaks is entirely optional. Such an input is flattened to 

```<<a,b,c>,<d,<e,f,g>,h>,<i,j,<k,l,m,<o,p,q>>,r,s,t>>```

before evaluation.

## Vector Operators

### Definition

The relationship between vectors and operators is best introduced formally: A vector shall be symbolized as `[v]`, having `N` elements, where the `j`th element of `[v]` is given by `elem([v],j)`, and `j` is an integer between `1` and `N`, inclusive. If `[v1]` and `[v2]` are two vectors with the same number of elements `N`, then, for any operator `[op]`, the expression `[v1] [op] [v2]`, yields a new vector `[v3]`, also of `N` elements, where the `j`th element in `[v3]` is given by `elem([v1],j) [op] elem([v1],j)`.

### Examples

#### Numeric

The expression `<1,2,3>+<4,5,6>` is translated to `<1+4,2+5,3+6>`, which of course simplifies to `<+5.0,+7.0,+9.0>`. The addition ( `+` ) operator between the vectors can be replaced with any valid operator.

#### Quote

This construction also works for quotes. Jumping right to an interesting example, a vector ```<`hello', ` ', `world'>``` multiplied by another vector ```<`!',`?',`##'>```, yields the exotic result: ```<`h!e!l!l!o!',` ?',`w##o##r##l##d##'>```.

#### Super-List

Operators are are also clearly defined for two super-lists of the same structure. For instance, the expression

```
<
  <1,2>,
  <3,<9,0>,`Toyota '>
>

+

<
  <6,7>,
  <8,<9,10>,`Camry'>
>
```

yields the result `<<+7.0,+9.0>,<+11.0,<+18.0,+10.0>,Toyota Camry>>`.