# Guide: Output Formatting

Sxript output is passed through a final formatting step before entering the environment. Most notably, quotes lose their bracketing characters, i.e. ``` ` ``` and ` ' ` vanish. This also applies to embedded quotes, so ``` `cows say `moo''``` flattens to `cows say moo`.

## Escape Character

When the backslash character ( `\` ), or *escape character* appears in any output, the character to the right receives special treatment.

The most obvious need for the escape character is for including the backtick ( ``` ` ``` ) or apostrophe ( ` ' ` ) in a quote. This is achieved using respective combinations ``` \` ```, and ``` \' ```.

Tabs and returns are handled by the following:
* `\t` becomes ASCII-9  (Tab)
* `\n` becomes ASCII-10 (LF)
* `\r` becomes ASCII-13 (CR)
* `\\` becomes ` \ ` after all other formatting takes place.

### Carriage Return

Note that the role of ASCII-13, i.e. the Carriage Return, behaves differently per implementation. Through JavaScript, the quote ``` `hello\rthere'``` is broken apart at ``` `hello'```, and ``` `there'``` is printed on a new line. Meanwhile, the QB64 and C++ terminal implementations return ``` `thereo'```, because the cursor returns to the left-most position without starting a new line.