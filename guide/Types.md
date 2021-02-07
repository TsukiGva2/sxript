# Guide: Types

Here all data structures that occur in Sxript code are classified into `types`. We also introduce the `type` primitive, a one-argument function that estimates the type of its input. Prototyped by `type(x)=quote`, we see that `type` sends its output as a quote.

## Numbers

*Numbers* fall into two categories, (i) unformatted numbers, and (ii) formatted numbers. Each of these fall qualify as the *number type*.

### Unformatted Numbers

Unformatted numbers carry as little information as they can, i.e. `1`, `-7.5`, etc. As a whole set, unformatted numbers consist of the following elements: `-.0987654321`

Left "untouched", unformatted numbers remain as they are. For example, the  vector `<1,-2,7.5>`, simply evaluates to itself, as would any of its components.

### Formatted Numbers

If an unformatted number is "touched" by an operator however, the operation results in a formatted number, always containing a sign and a decimal (the above set gains a `+`). Taking our example vector and simply adding zero according to `0 + <1,-2,7.5>`, the end result is `<+1.0,-2.0,+7.5>`.

### The *Unformat* Primitive

A sure way to convert an unformatted number to a formatted number is to add zero. For instance, `3+0` yields `+3.0`. To go back the other way, the "unformat" primitive, prototyped by `unf(formatted)=formatted`, does the job. The `unf` primitive won't remove any necessary information from a number. That is, `unf(-3.5)` yields `-3.5`, whereas `unf(+5.0)` yields plain `5`.

### Using Type(number)