# Command Line Calculator
*Create a bigger program*

## Objectives
 - Read and interpret user stories
 - Create a bigger project


## Materials & Resources

- [string.h](https://www.tutorialspoint.com/c_standard_library/string_h.htm)

## Workshop
This is a quite long project, at first read the whole specification. Try to figure out what kind of error handling technique would fit for each operation. Try to make a concept in your head about how you will implement the application. Work with floating point numbers and convert it if necessary. Take care of the spaces between the operator and operands.

### Basics (mandatory) tasks
- [+](#)
- [-](#)
- [*](#)
- [/](#)
- [% (modulus)](#)
- [power](https://en.wikipedia.org/wiki/Exponentiation)
- [extracting the root (square root)](#)
- [logarithm](https://en.wikipedia.org/wiki/Logarithm)
- [hex to bin converter](#)
- [bin to hex converter](#)
- [dec to bin converter](#)
- [bin to dec converter](#)
- [hex to dec converter](#)
- [dec to hex converter](#)
- [error handling](#)

### Advanced tasks
- [decimal to binary conversion](http://www.wikihow.com/Convert-from-Decimal-to-Binary)
- [binary to decimal conversion](http://www.wikihow.com/Convert-from-Binary-to-Decimal)
- [nth roots](https://en.wikipedia.org/wiki/Nth_root)

### Print usage
 - At application startup the following message should be shown:

```
	CLI Calculator
====================================
usage: [number] [operation] [number]
Commands:
 +		summation
 -		subtraction
 *		multiplication
 /		division
 % 		division with remainder
 ^		squaring
 <		square root
 log		logarithm
 binto		binary to hex or dec
 hexto		hexadecimal to bin or dec
 decto		decimal to bin or hex
 ====================================
 exit	exiting from the program
 clear	clear the screen
 help	print usage
 ====================================
 Hit enter to start!
 ====================================
 ```

### +

For example the content is:

```
3 + 2 = 5

```

### -


For example the content is:

```
3 - 2 = 1

```

### *

For example the content is:

```
3 * 2 = 6

```

### /

For example the content is:

```
6 / 2 = 3

```

### ^

For example the content is:

```
3 ^ 2 = 9

```

### <

For example the content is:

```
2 < 4 = 2

```

### %

For example the content is:

```
3 % 2 = 1

```

### binto, hexto, decto
```
0110 binto 10 = 6
```
or
```
aa hexto 10 = 170
```
or
```
13 decto 2 = 1101
```

### error handling

For example the content is:

```
5 / 0 = Division by zero is undefined.
```
if you give incorrect operators (alphabetic characters), you should see:
```
a + b = Invalid operands.
```
if you leave out spaces, or use an unknown operator, like @, you should get:
```
5 + @
Invalid command
Hit enter to continue.
```


### logarithm

For example the content is:

```
2log8 = 3

```

### roots

For example the content is:

```
2 < 9 = 3

```


## Solution
[Solution]()
