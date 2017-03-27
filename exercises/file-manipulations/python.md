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
 - compile time error
 - runtime error
 - syntactic error
 - semantic error
 - try
 - exception
 - except
 - exception types
 - finally

## Workshop

### I/O

```python
my_file = open("file_name.txt", "r")
```

4 different ways of reading:

```python
my_file.read()

my_file.readline()

my_file.readlines()

for line in my_file:
      print(line.rstrip())
```
<!--
### Useful string methods
```python
split()

" ".join()

my_list[start:end:step]

ord('a')

chr(97)
```
-->

### Decryption
#### Exercises
 - [Doubled](decrypt_function_doubled/crypto_1dup.py) | [duplicated-chars.txt](decrypt_function_doubled/duplicated-chars.txt)
 - [Reversed Lines](decrypt_function_reversed_lines/crypto_2revlines.py) | [reversed-lines.txt](decrypt_function_reversed_lines/reversed-lines.txt)
 - [Reversed Order](decrypt_function_reversed_order/crypto_3revorder.py) | [reversed-order.txt](decrypt_function_reversed_order/reversed-order.txt)
 - [Encoded Lines](decrypt_function_encoded_lines/crypto_4encoded.py) | [encoded-lines.txt](decrypt_function_encoded_lines/encoded-lines.txt)


### Exceptions
```python
try:
    f = open(arg, 'r')
except IOError:
    print('cannot open', arg)
```

#### Exercises
- [Divide by 0](exceptions/divide_by_0/divide-by-0.py)
- [No file](exceptions/file_not_exists/file_not_exists.py)

### Optional
 - [Lotto.java](read_lotto_csv/lottery.py) | [otos.csv](read_lotto_csv/otos.csv)
