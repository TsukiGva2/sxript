# Guide: Index of Types

Here all data structures that occur in Sxript code are classified into `types`. 

## Review of Types

### Numbers

*Numbers* fall into two categories, (i) unformatted numbers, and (ii) formatted numbers. Each of these fall qualify as the *number type*.

#### Unformatted Numbers

Unformatted numbers carry as little information as they can, i.e. `1`, `-7.5`, etc. As a whole set, unformatted numbers consist of the following elements: `-.0987654321`

Left "untouched", unformatted numbers remain as they are. For example, the  vector `<1,-2,7.5>`, simply evaluates to itself, as would any of its components.

#### Formatted Numbers

If an unformatted number is "touched" by an operator however, the operation results in a formatted number, always containing a sign and a decimal (the above set gains a `+`). Taking our example vector and simply adding zero according to `0 + <1,-2,7.5>`, the end result is `<+1.0,-2.0,+7.5>`.

#### The *Unformat* Primitive

A sure way to convert an unformatted number to a formatted number is to add zero. For instance, `3+0` yields `+3.0`. To go back the other way, the "unformat" primitive, prototyped by `unf(formatted)=formatted`, does the job. The `unf` primitive won't remove any necessary information from a number. That is, `unf(-3.5)` yields `-3.5`, whereas `unf(+5.0)` yields plain `5`.

### Quotes

*Quotes* are any characters enclosed by the back-tick symbol ( ``` ` ``` ) on the left, and the apostrophe ( `'` ) on the right. See [Quotes (Strings)](guide/Quotes-Strings.md) for an introduction. 

### Vectors

A *vector* is any structure enclosed by left- ( `<` ) and right-angle-brackets ( `>` ). See [Vectors (Lists)](guide/Vectors-Lists.md) for an introduction.

### Occulted Code

*Occulted* code is any content enclosed by left- ( `{` ) and right-curly-brackets ( `}` ). See [Parentheses and Layering](guide/Parentheses-and-Layering.md) for an introduction.

### Symbols

A *symbol* is any structure enclosed by left- ( `[` ) and right-square-brackets ( `]` ). Symbols and their applications have not yet been introduced.

### Words

A *word*, first mentioned in [Parentheses and Layering](guide/Parentheses-and-Layering.md), is a catch-all term for anything not classified above. Conspicuously absent is a type for "function" or and type for "primitive". For instance, the characters `len`, in isolation, still constitute a word, even though we know it's a primitive (function). The same applies to *most* operators in isolation.

## The `type` Primitive

The `type` primitive, prototyped by `type(x)=quote`, is a one-argument function that estimates the type of its input. The precise job of `type` is to examine the *first* character in `x`, whatever it may be, and compare that character to the bracketing characters ( ``` ` < { [ ``` ... ) for the types listed above. For detecting numbers, `type` scans for all digits `0`-`9`, along with signs ( `+`, `-` ) and the decimal ( `.` ).

### Examples

The following expressions return ``` `number' ```.

> `type(1)`

> `type(2*3)`

> `type(-+)`

> `type(7hello)`

The following expressions return ``` `quote'```.

> ``` type(`hello')```

> ``` type(`hello' + `world')```

> ``` type(`')```

The following expressions return ``` `vector'```.

> `type(<a,b,c>)`

> `type(<{a:b},{c:d},{e:f}>)`

> `type(<>)`

The following expressions return ``` `occult'```.

> `type({a:b:c})`

> `type({<a,b>:<c,d>:<e,f>})`

> `type({})`

The following expressions return ``` `symbol'```.

> `type([a])`

> `type([])`

The following expressions return ``` `word'```.

> `type(hello)`

> `type(len)`

> `type(*)`

Finally, the special case of the empty argument, namely `type()`, returns ``` `paren'```.