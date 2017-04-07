# File manipulation exercises

## Materials & Resources

| Material | Time |
|:---------|-----:|
| [Python Programming Tutorial - 23 - How to Read and Write Files](https://www.youtube.com/watch?v=YV6qm6erphk) | 6:26 |
| [Python Programming Tutorial - 21 - Modules](https://www.youtube.com/watch?v=WN4A6iJOUns) | 5:44 |
| [Python Programming Tutorial - You are the only Exception](https://www.youtube.com/watch?v=1cCU0owdiR4) | 11:40 |
| [General introduction to modules](http://pymbook.readthedocs.org/en/latest/modules.html) | - |
| [General introduction to file handling / IO](http://pymbook.readthedocs.org/en/latest/file.html) | - |

## Material review

 - `open()` and parameters `r, w, a`
 - `close()`
 - `write()`
 - `read()`, `readline()` and `readlines()`
 - `module` and `submodule`
 - `import`
 - `from`
 - `help()`
 - `os` library
 - [`requests` module](http://pymbook.readthedocs.io/en/latest/modules.html#requests-module)
 - Compile time error
 - Runtime error
 - Syntax error
 - Semantic error
 - `try`
 - exception
 - `except`
 - exception types
 - `finally`

## Workshop

### Exceptions

```python
divisor = input()

result = 12 / divisor # If the input value for divisor was 0 the program breaks
print(result) # The program doesn't reach this line if the input was 0
```

The result if the input value was zero:

```
Traceback (most recent call last):
  File "div.py", line 3, in <module>
    result = 12 / divisor
ZeroDivisionError: integer division or modulo by zero
```

Handle the exception:

```python
divisor = input()

try: # Prevents the program breaking when attempting dividing by zero
    result = 12 / divisor # If the input value for divisor was 0 it stops the try block
    print(result) # The program doesn't reach this line if the input was 0
except ZeroDivisionError:
    print("Can't divide by zero!") # This line only runs if the input was 0
```

#### Exercises

 - [01 - divide_by_zero.py](divide-by-zero/divide_by_zero.py)


### Reading files

```python
my_file = open("file-name.txt", "r")
```

4 different ways of reading:

```python
# reads the entire file as a string
print(my_file.read())

# reads a line from the file
print(my_file.readline())

# reads all lines as a list
print(my_file.readlines())

# loops through on each of the lines of the file
for line in my_file:
    print(line.rstrip()) # rstrip() removes the newline character from the line 
```

```python
file_name = "file-name.txt"
try:
    f = open(file_name, "r")
except IOError:
    print("cannot open", file_name)
```

#### Exercises

 - [02 - print_each_line.py](print-each-line/print_each_line.py)
 - [03 - count_lines.py](count-lines/count_lines.py)

### Writing files

```python
my_file = open("file-name.txt", "w")
my_file.write("Apple") # Wirtes the string "Apple" to the file
```

#### Exercises

 - [04 - write_single_line.py](write-single-line/write_single_line.py)
 - [05 - write_multiple_lines.py](write-multiple-lines/write_multiple_lines.py)
 - [06 - copy_file.py](copy-file/copy_file.py)

### Decryption

#### Exercises

 - [07 - doubled.py](decrypt-doubled/doubled.py) | [duplicated-chars.txt](decrypt-doubled/duplicated-chars.txt)
 - [08 - reversed_lines.py](decrypt-reversed-lines/reversed_lines.py) | [reversed-lines.txt](decrypt-reversed-lines/reversed-lines.txt)
 - [09 - reversed_order.py](decrypt-reversed-order/reversed_order.py) | [reversed-order.txt](decrypt-reversed-order/reversed-order.txt)

### Optional Hard Exercises

 - [10 - encoded_lines.py](decrypt-encoded/encoded_lines.py) | [encoded-lines.txt](decrypt-encoded/encoded-lines.txt)
 - [11 - lottery.py](lottery/lottery.py) | [otos.csv](lottery/otos.csv)

