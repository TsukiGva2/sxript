# Guide: Quotes (Strings)

Strings, henceforth called *quotes*, are always enclosed by the back-tick symbol ( ``` ` ``` ) on the left, and the apostrophe ( ` ' ` ) on the right. The double-quote symbol ( ` " ` ) is not reserved. For example, ``` `horse' ``` is a valid quote, and so too is ``` `aB"1e3"cD'```.

Quotes can embed within quotes, meaning, for instance, ``` `cows say `moo''```, is a perfectly valid quote.

The range of allowed characters is dependent on the host environment. Terminal implementations tend to only resolve ASCII characters, whereas JavaScript implementations extend to allows Unicode characters in quotes.

## Quote Operations

Quotes can be manipulated using (some of) the same operators that apply to numbers. Allowed operators `* / + -` follow the same precedence as their mathematical counterparts.

### Concatenation

Much as one would expect, quotes are concatenated with the plus ( `+` ) operator, for instance ``` `apple' + `juice' ``` becomes ``` `applejuice' ```.

### Subtraction

If `[quote2]` exactly matches the rightmost characters of `[quote1]`, then the combination `[quote1] - [quote2]` returns a truncated version of [quote1] that excludes [quote2]. For example, ``` `file.txt' - `.txt'``` resolves to ``` `file'```.

If `[quote2]` is not equal to the right-most part of `[quote1]`, then only `[quote1]` is returned. As an example of this, the combination ``` `' - `xyz'``` returns the empty quote, ``` `'```.

### Multiplication

One quote can also be "multiplied" into another, where the combination `[quote1] * [quote2]` returns a version of `[quote1]` with `[quote2]` inserted after each character. For instance ``` `abc' * `xy'``` results in ``` `axybxycxy'```.

### Division

The inverse of quote multiplication is quote division. That is, the combination ``` `axybxycxy' / `xy'``` returns ``` `abc' ```. If `[quote2]` is not a sub-quote of `[quote1]`, then only `[quote1]` is returned.

#### Exercise:

> Predict the result of ``` `abc' / `xy' * `xy'```.

> Solution: By operator precedence, the combination ``` `xy' * `xy'``` is considered first, resulting in ``` `xxyyxy'```. The problem translates to ``` `abc' / `xxyyxy'```, resulting in simply ``` `abc'```.

## Quote Comparison and Logic

Quotes can be compared using the same operators that apply to numbers, following the same precedence.

The equivalency operator, denoted by a single "equal" symbol ( `=` ), tests for equivalency between two quotes. If the left- and right-arguments are equal, the returned result is `1`. Non-equal arguments return `0`. In contrast to numerical comparison, the result of quote comparison is not formatted as a number. As stand-alone symbols, `1` and `0` are considered "words" until "touched" by an operator.

The logical AND, along with logical OR, also apply to quotes. Any non-empty inputs are considered "on", and an empty-input is considered "off". Like the equivalency operator, the logical operators, as applied to quotes, return a `1` for the affirmative case, and `0` otherwise.