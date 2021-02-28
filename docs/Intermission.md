# Guide: Intermission

By this point, it's becoming evident that certain tasks can be approached from more than one direction, and the number of directions will only grow from here. Meanwhile we've covered enough ground to write programs that *approach* being useful. Here we explore a few "toy" programs that demonstrate various features discussed so far, without introducing any major language features.

## Vectors and `for` Loops

Vectors `<a,b,c,d,...>` are easily typed when the number of elements is reasonable, however situations often arise in which vectors are "systematic" enough to be created with a `for` loop.

### Numerical Elements

If a vector is to have purely numerical content, its elements may be composed by referencing the iteration variable. Building the case slowly, begin with `for(<i,1,10,1>,{unf([i])})`, which would return `12345678910` if evaluated. By inserting the vector separator symbol just after the `unf([i])`-structure, namely `for(<i,1,10,1>,{unf([i]),})`, the output becomes `1,2,3,4,5,6,7,8,9,10,`. Such an output is not well-defined. To assure the output is a vector, wrap the whole expression in ( `<>` ) to write `<for(<i,1,10,1>,{unf([i]),})>` which simplifies to `<1,2,3,4,5,6,7,8,9,10,>`. The empty element at the end is eliminated with the `smooth` primitive. Finally then, we have that `smooth(<for(<i,1,10,1>,{unf([i]),})>)` produces the clean result `<1,2,3,4,5,6,7,8,9,10>`.

If such a vector needs to have negative elements, we have (at least) two options. Since arithmetic operations distribute into vectors such that `-1 * <1,2,3,4,5>` simplifies to  `<-1.0,-2.0,-3.0,-4.0,-5.0>`, it should follow that `-1 * smooth(<for(<i,1,5,1>,{unf([i]),})>)` produces the same result. Instead, we may reference `-1*[i]` in the original expression to write `smooth(<for(<i,1,5,1>,{-1*[i],})>)`, producing the same result yet again.

## Condensing Vectors

For a vector `<a,b,c,d,e>`, one way to produce the word `abcde`, is to use the `reduce` primitive with `join` as an argument, namely `reduce(join,<a,b,c,d,e>)`. Alternatively, the same result is attained using a `for` loop to print the components in succession: `for(<i,1,5,1>,{elem(<a,b,c,d,e>,[i])})`

## Block Evaluation with `apply`

Here we demonstrate multiple "programs" existing as elements of a vector, where evaluation is triggered with the `apply` primitive with `block` as the first argument:

```
apply(block,<
  {
    print_\n `hello ' + :
    print_`world' \n
  },
  {
    print_
    (for(<j,1,3,1>,{[j]})) \n
  },
  {
    print_
    smooth(<for(<j,1,10,1>,{
      iff(([j]%2)=0,{unf([j]),},{()})
    })>) \n
  },
  {
    print_
    smooth(<for(<j,1,10,1>,{
      iff(([j]%2)=0,{()},{unf([j]),})
    })>) \n
  }
>)
```

Output:

```
<
hello world
,+6.0
,<2,4,6,8,10>
,<1,3,5,7,9>
>
```

## Nesting Occulted Code

Consider the following code block:

```
block({
  print_{print_1:print_2+2}
})

```

Due to the `print_` statement outputting an occulted expression, the result of the above is simply `{print_3:print_2+2}`. Note though, that this is exactly compatible with the body of a code block. It must follow that if we wrap the *whole* code block with yet another `block` primitive, the inner content can be evaluated.

```
block(
  block({
    print_{print_3:print_2+2}
  })
)
```

The intermediate output of the above is `{print_3:print_2+2}`, which simplifies to `+7.0`.

## ASCII Tables

### Mini Table

A a sample of the ASCII table can be produced with a `for` loop as follows:

```
for(<i,97,122,1>,{
  block({
    print_quote(unf([i])) + ` ':
    print_quote(chr([i])):
    print_\t
  })
})
```

Output:

```
97 a	98 b	99 c	100 d	101 e	102 f	103 g	104 h	105 i	106 j	107 k	108 l	109 m	110 n	111 o	112 p	113 q	114 r	115 s	116 t	117 u	118 v	119 w	120 x	121 y	122 z	
```

### Partial Table

Of course, many ASCII characters are special to Sxript syntax. To produce a more complete table, we make use of the procedural subsystem and the escape character ( `\` ):

```
for(<i,32,126,1>,{
  block({
    print_quote(unf([i])) + ` ':
    if_[i]=39  @ascii39:
    if_[i]=40  @ascii40:
    if_[i]=41  @ascii41:
    if_[i]=44  @ascii44:
    if_[i]=60  @ascii60:
    if_[i]=62  @ascii62:
    if_[i]=91  @ascii91:
    if_[i]=92  @ascii92:
    if_[i]=93  @ascii93:
    if_[i]=96  @ascii96:
    if_[i]=123 @ascii123:
    if_[i]=125 @ascii125:
    goto_normal:
    anchor_ascii39 :print_\'   :goto_exit:
    anchor_ascii40 :print_\(   :goto_exit:
    anchor_ascii44 :print_\,   :goto_exit:
    anchor_ascii41 :print_\)   :goto_exit:
    anchor_ascii60 :print_\<   :goto_exit:
    anchor_ascii62 :print_\>   :goto_exit:
    anchor_ascii91 :print_\[   :goto_exit:
    anchor_ascii92 :print_\\{\}:goto_exit:
    anchor_ascii93 :print_\]   :goto_exit:
    anchor_ascii96 :print_\`   :goto_exit:
    anchor_ascii123:print_\{   :goto_exit:
    anchor_ascii125:print_\}   :goto_exit:
    anchor_normal:
    print_quote(chr([i])):
    anchor_exit:
    print_\t
  })
})
```

Output:

```
32  	33 !	34 "	35 #	36 $	37 %	38 &	39 '	40 (	41 )	42 *	43 +	44 ,	45 -	46 .	47 /	48 0	49 1	50 2	51 3	52 4	53 5	54 6	55 7	56 8	57 9	58 :	59 ;	60 <	61 =	62 >	63 ?	64 @	65 A	66 B	67 C	68 D	69 E	70 F	71 G	72 H	73 I	74 J	75 K	76 L	77 M	78 N	79 O	80 P	81 Q	82 R	83 S	84 T	85 U	86 V	87 W	88 X	89 Y	90 Z	91 [	92 \	93 ]	94 ^	95 _	96 `	97 a	98 b	99 c	100 d	101 e	102 f	103 g	104 h	105 i	106 j	107 k	108 l	109 m	110 n	111 o	112 p	113 q	114 r	115 s	116 t	117 u	118 v	119 w	120 x	121 y	122 z	123 {	124 |	125 }	126 ~	
```