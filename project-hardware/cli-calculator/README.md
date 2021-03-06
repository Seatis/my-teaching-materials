# Command Line Calculator
*Create a bigger program*

## Objectives
 - Read and interpret user stories
 - Create a bigger project


## Materials & Resources

- [string.h](https://www.tutorialspoint.com/c_standard_library/string_h.htm)

## Workshop
This is a quite long project, at first read the whole specification. Try to figure out what kind of error handling technique would fit for each operation. Try to make a concept in your head about how you will implement the application. Work with floating point numbers and convert it if necessary. Take care of the spaces between the operator and operands. The result should be seen on the same row, where the operands are. For this you get a [little bit of help](#help-for-the-positioning).

### Basics (mandatory) tasks
- [+](#user-content-summation)
- [-](#user-content-subtraction)
- [*](#user-content-multiplication)
- [/](#user-content-division)
- [%](#user-content-division-with-remainder)
- [squaring](#user-content-squaring)
- [square root](#user-content-square-root)
- [logarithm](#user-content-logarithm)
- [binary to](#user-content-binto)
- [hexadecimal to](#user-content-hexto)
- [decimal to](#user-content-decto)
- [error handling](#user-content-error-handling)

### Advanced tasks

Implement a function to calculate the [`n`th roots.](https://en.wikipedia.org/wiki/Nth_root)

### Print usage
 - At application startup the following message should be shown:

```
	CLI Calculator
====================================
usage: [number] [operation] [number]
Commands:

 +	summation
 -	subtraction
 *	multiplication
 /	division
 %	division with remainder
 ^	squaring
 <	square root
 log	logarithm
 binto	binary to hex or dec
 hexto	hexadecimal to bin or dec
 decto	decimal to bin or hex
 ====================================
 exit	exiting from the program
 clear	clear the screen
 help	print usage
 ====================================
 Hit enter to start!
 ====================================
 ```

### summation

For example the content is:

```
3 + 2 = 5
```

### subtraction


For example the content is:

```
3 - 2 = 1
```

### multiplication

For example the content is:

```
3 * 2 = 6
```

### division

For example the content is:

```
6 / 2 = 3
```

### squaring

For example the content is:

```
3 ^ 2 = 9
```

### square root

For example the content is:

```
2 < 4 = 2
```

### division with remainder

For example the content is:

```
3 % 2 = 1
```

### logarithm

For example the content is:

```
2log8 = 3
```


### binto

For example the content is:

```
0110 binto 10 = 6
```

### hexto

For example the content is:

```
aa hexto 10 = 170
```

### decto

For example the content is:

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
---
### help for the positioning

Some help for the positioning of the cursor in order to see the result in the same row as the operands in Windows (you have to include Windows.h):
```
COORD coord = {0,0};
void set_cursor_pos(int x, int y)
{
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
```

positioning the console cursor in Linux or OSX:
```
void set_cursor_pos(int x, int y)
{
	printf("\033[%d;%dH", y+1, x+1);
}
```


## Solution
[Solution](#)
