# Guide: Operator Overloading

As we've seen, the "basic" operators, namely `+ - & /`, are able to be cleanly used between sets of numbers, quotes, and vectors. In this sense, such operators are called *overloaded*. Certain operations can be "very overloaded", allowing the left- and right- arguments are of unequal type.

## Number-Quote Mixing

### Number-Quote Concatenation

The addition operator can join a number to a quote, or similarly, join a quote to a number. In each case, the result is a quote. For instance, ```3 + `apple' ``` results in ``` `3apple' ```, and ``` `orange' + 4 ``` results in ``` `orange4' ```.

### Number-Quote Multiplication

A quote can be duplicated `N` times by multiplying an the integer `N` into either side side of the quote. For example, ``` 4 * `hello' ``` results in ``` `hellohellohellohello'```, and so too does ``` `hello' * 4```.

## Vectors and Overloading

The "mixing rules" for numbers and quotes extend to vectors. In symbolic notation: Suppose `[a]` is a number or a quote, and `[v]` is a vector having `N` elements represented by `elem([v],j)`, where any `elem([v],j)` is a number, quote, or vector, and `j` is an index between `1` and `N`, inclusive. Introducing an operator `[op]` such that `[a] [op] elem([v],j)` is clearly defined for all `N` elements, it follows that the operation `[a] [op] [v]` results in a vector `[r]`, of `N` elements, where `elem([r],j)` equals `[a] [op] elem([v],j)` for all `j`.

By the same token, the commuted operation `[v] [op] [a]` results in a vector having elements `elem([v],j) [op] [a]`.

### Examples

The operation ``` `abc' * <1,2,`xyz'>``` simply distributes ``` `abc'``` onto `1`, then `2`, and finally ``` `xyz'```. The individual results are enclosed into a vector of three elements, ``` <`abc',`abcabc',`axyzbxyzcxyz'> ```.

For a more practical but mundane example, the following expression adds ``` `.txt'``` to a vector of bare "filenames": ``` <`file1',`file2',`file3'> + `.txt'```