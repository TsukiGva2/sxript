# Guide: Introduction to Primitives

## Built-in Functions

Apart from operators, a second class of "prime movers" in the Sxript language are called *primitives*. A primitive translates to a "built-in function", where a function is a mechanism that transforms input into output. In the most general sense, a function is usually denoted `f`, and its input is labeled `[i]`. The construction `f([i])` results in an output value `[o]` that depends on, but is generally different from `[i]`.

## Prototype Notation

Let us introduce the "quote length" primitive, which we *prototype* as `len(quote)=number`. A prototype is a way of writing a function so that the name, input, and output appears symbolically. The above prototype tells is that the `len` primitive takes takes `quote` as input, and then delivers `number` as an output. As the name implies, the "quote length" primitive simply reports the number of characters in a string.

#### Length of a Quote

As simple example of the "quote length" primitive, the expression ```len(`hello')``` simplifies to `5`. To extend this slightly, the expression ```len(`hello ' + `world')``` simplifies to `11`. The inner contents of the parentheses are evaluated before `len` notices.

## Primitive Overloading

 Recall that several operators, such as the subtraction operator ( `-` ), behave a certain when applied to numbers, whereas the same operator behaves differently when applied to quotes. By analogy to operator overloading, certain primitives can be overloaded, exhibiting analogous behavior.

 ### Length of a Vector

Continuing our discussion of the `len` primitive, it turns out that `len()` can also wrap around a vector, obeying the prototype `len(vector)=number`. In this case, `len` returns the number of elements in the vector. For instance, `len(<a,b,c,d,e>)` returns `5` as the input vector contains five elements.

 ### Number of Occulted Statements

The `len` primitive can also count the number of statements inside occulted code, obeying the prototype `len(occult)=number`. For instance, `len({a:b:c:d:e})` returns `5` there are five occulted statements.

 ### Length of a Number

Yet another use of the `len` is for determining the overall length of a number, as if it were a quote. Note however that `len` also counts the sign and the decimal point, if present. For example, `len(5)` is simply `1`, whereas `len(3+3)` simplifies to `len(+6.0)`, simplifying to `4`.

### Length of a Word

Any *word* is any chain of one or more characters without bracketing symbols such as parentheses, quotes ( ``` ` ' ```), angle brackets ( `< >` ), curvy braces ( `{ }` ), etc. The `len` primitive also measures the number of characters in a given word. The subtlety here is that no (unprotected) whitespace exists in a word. As a consequence, an expression such as ```len(a b c d e )``` is contensed to `len(abcde)`, simplifying to `5`, whereas ```len(`a b e d e ')``` simplifies to `10`.

#### Exercise:

> Of the two prototypes not specified above, write them below.

> Solution: Length of a number: `len(number)=number`, Length of a word: `len(word)=number`

## The `prim(x)` Notation

Certain language primitives, with `len` being a prime example, are able to receive more than one type of input. For example, `len` measures the length of a quote, the number of elements in a vector, the number of statements within occulted code, etc. While the input in each case varies, the output of `len` is always a number. A succinct way to express the `len` prototype is therefore `len(x)=number`, where `x` stands for any valid input.

## Arguments

The formal name for the piece of data sent to a function is an *argument*. For example, in the expression ``` len(`hello world')```, the argument is the quote ``` `hello world'```. For a more general example, the "length" prototype `len(x)=number` has an argument represented by `x`.

When a primitive requires multiple arguments, we traditionally represent the first argument with `x`, the second with `y`, and so on. Such a prototype may look like `prim(x,y)=result`, where `result` represents the output.