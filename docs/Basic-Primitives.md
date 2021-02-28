# Guide: Basic Primitives

## Numeric: Basic Primitives

In the following, `x` and `y` are numbers.

| Prototype | Description
|---|---
| `abs(x)=number` | Removes sign information from number `x`.
| `atan(x)=number` | Returns trigonometric arc-tangent of `x`.
| `cos(x)=number` | Returns trigonometric cosine of `x` (argument in radians).
| `greater(x,y)=number` | Returns `1` if `x` is greater than `y`. Returns `0` otherwise.
| `int(x)=number`  | Converts `x` to an integer.
| `ln(x)=number`  | Returns natural logarithm of `x`.
| `rand(x)=number` | Returns a random number between `0` and `x`. (Impure Function!)
| `sgn(x)=number`  | Returns `1` if `x` is positive, `-1` if negative, `0` if neither.
| `sin(x)=number` | Returns trigonometric sine of `x` (argument in radians).
| `sqrt(x)=number` | Returns the square root of `x`.
| `tan(x)=number` | Returns trigonometric tangent of `x` (argument in radians).
| `unf(x)=number` | Converts `x` to formatted number.

## Quotes: Basic Primitives

In the following, `x` is a quote, `n` is a number, and `z` is arbitrary.

| Prototype | Description
|---|---
| `asc(x)=number` | Returns the ASCII code of character `x`.
| `chr(x)=quote` | Returns the character corresponding to ASCII code `x`.
| `instr(x,y)=number` | Returns `n` if quote `x` contains quote `y` starting at position `n`. Returns zero otherwise
| `lcase(x)=quote` | Replaces all uppercase characters in `x` to lowercase.
| `left(x,n)=quote` | Returns a sub-quote of the left-most `n` characters from quote `x`.
| `len(x)=number` | Returns the number of characters in quote `x`.
| `mid(x,n1,n2)=quote` | Returns a sub-quote of length `n2` starting at position `n1` in quote `x`.
| `quote(x)=quote` | Encloses `x` in quotation bracketing symbols ( ``` ` ``` and `'` ).
| `right(x,n)=quote` | Returns a sub-quote of the right-most `n` characters from quote `x`.
| `ucase(x)=quote` | Replaces all lowercase characters in `x` to uppercase.
| `unquote(x)=z` | Removes quote bracketing symbols ( ``` ` ``` and `'` ) from `x`.

## Vectors: Basic Primitives

In the following, `x` and `y` are vectors, `n` is a number, and `z` is arbitrary.

| Prototype | Description
|---|---
| `column(x,n)=vector` | Returns the `n`th column of matrix `x` as a vector.
| `elem(x,n)=z` | Returns the `n`th element from vector `x`.
| `left(x,n)=vector` | Returns a sub-vector of the left-most `n` elements from vector `x`.
| `len(x)=number` | Returns the number of elements in vector `x`.
| `mid(x,n1,n2)=vector` | Returns a sub-vector with `n2` elements starting at position `n1` in vector `x`.
| `replace(x,n,z)=vector` | Returns a vector with element with content `z` placed at position `n`.
| `right(x,n)=vector` | Returns a sub-vector of the right-most `n` elements from vector `x`.
| `smooth(x)=vector` | Removes all empty elements from vector `x` and returns the result.
| `stack(x,y)=vector` | Appends `x` onto `y` and returns the result.
| `unvector(x)=z` | Removes vector bracketing symbols ( `<` and `>` ) from `x`.
| `vector(x)=vector` | Encloses `x` in vector bracketing symbols ( `<` and `>` ).

## Occult: Basic Primitives

In the following, `x` and `y` are vectors, `n` is a number, and `z` is arbitrary.

| Prototype | Description
|---|---
| `elem(x,n)=z` | Returns the `n`th element from occulted structure `x`.
| `left(x,n)=occult` | Returns a sub-structure of the left-most `n` elements from occulted structure `x`.
| `len(x)=number` | Returns the number of elements in occulted structure `x`.
| `mid(x,n1,n2)=occult` | Returns a sub-structure with `n2` elements starting at position `n1` in occulted structure `x`.
| `occult(x)=occult` | Encloses `x` in occulting symbols ( `{` and `}` ).
| `replace(x,n,z)=occult` | Returns an occulted structure with element with content `z` placed at position `n`.
| `right(x,n)=occult` | Returns a sub-structure of the right-most `n` elements from occulted structure `x`.
| `smooth(x)=occult` | Removes all empty elements from occulted structure `x` and returns the result.
| `stack(x,y)=occult` | Appends `x` onto `y` and returns the result.
| `unoccult(x)=z` | Removes occult bracketing symbols ( `{` and `}` ) from `x`.

## Time-Keeping Primitives

The following primitives take no argument.

| Prototype | Description
|---|---
| `date()=quote` | Returns the system date.
| `time()=quote` | Returns the system time.

## The `identity` Primitive

One special primitive that does absolutely nothing with its argument is called the `identity`, having prototype `identity(x)=x`, which simply re-sends its input as output. The `identity` primitive has no profound implications.

| Prototype | Description
|---|---
| `identity(z)=z` | Returns `z`.

## The `join` Primitive

Another second special primitive takes *two* arguments and simply joins them together as if typed beside each other, represented by `join(x,y)=xy`.

| Prototype | Description
|---|---
| `join(w,z)=wz` | Returns `wz`.
