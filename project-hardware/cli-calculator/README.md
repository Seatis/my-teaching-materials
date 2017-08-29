# Command Line Calculator
*Create a bigger program*

## Objectives
 - Read and interpret user stories
 - Create a bigger project


## Materials & Resources

- [string.h](https://www.tutorialspoint.com/c_standard_library/string_h.htm)

## Workshop
This is a quite long project, at first read the whole specification. Try to figure out what kind of error handling technique would fit for each operation. Try to make a concept in your head about how you will implement the application. Work with floating point numbers and convert it if necessary. Take care of the spaces between the operator and operands. The result should be seen on the same row, where the operands are. For this you get a little bit of [help](#help).

### Basics (mandatory) tasks
- [+](#+)
- [-](#-)
- [*](#*)
- [/](#/)
- [%](#%)
- [^](#^)
- [<](#<)
- [log](#logarithm)
- [binto](#binto)
- [hexto](#binto)
- [decto](#binto)
- [error handling](#error-handling)

### Advanced tasks
- [nth roots](https://en.wikipedia.org/wiki/Nth_root)

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

### logarithm

For example the content is:

```
2log8 = 3

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
---

### help
positioning the console cursor in Windows:
```
void set_cursor_pos(int x_pos, int y_pos)
{
   COORD coord;

   coord.X = x_pos;
   coord.Y = y_pos;

   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
```

positioning the console cursor in Linux:
```
void set_cursor_pos(int x_pos, int y_pos)
{
   printf("\033[%d;%dH", y_pos+1, x_pos+1);
}
```


## Solution
[Solution]()
