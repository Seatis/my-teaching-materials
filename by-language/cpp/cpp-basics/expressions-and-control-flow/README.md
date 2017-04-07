# Expressions and Control flow
*Meet the base elements of the C++ language by implementing small programs*

## Objectives
 - Understanding the Compiler
 - Using basic types
 - Creating and reading expressions
 - Declaring and definind variables
 - Using variables and mutate values
 - Understanding conditionals
 - Using while and for loops
 - Casting Types

## Materials & Resources
### Environment
 - Install Eclipse IDE C/C++ on your system!
	- http://www.eclipse.org/downloads/packages/eclipse-ide-cc-developers/lunasr1
 - Windows help for installing:
	- https://www.youtube.com/watch?v=TXbuATMlVNY

### Training
| Material | Time |
|:---------|-----:|
| [Works, Compilers, Linkers, IDE's](https://www.youtube.com/watch?v=twodd1KFfGk) | 8:03 |
| [Hello World!!!](https://www.youtube.com/watch?v=e840YAaK620) | 9:20 |
| [Understanding Variables](https://www.youtube.com/watch?v=tkPjecc0ViY) | 11:15 |
| [Constants, Variables, Data types, Keywords](https://www.youtube.com/watch?v=z600MQdQ9lg) | 7:26 |
| [Creating and Using Variables](https://www.youtube.com/watch?v=5kjOhtniLOs) | 8:19 |
| [Console Output with Cout](https://www.youtube.com/watch?v=c7foOFAYqbk) | 5:19 |
| [Cin for Receiving User, Console Input](https://www.youtube.com/watch?v=lW_ZT_OZD1A) | 6:03 |
| [Comments](https://www.youtube.com/watch?v=uT0c5X1kvq4) | 8:24 |
| [Arithmetic Operators](https://www.youtube.com/watch?v=RKNgEgm_DP8) | 5:38 |
| [Increment and Decrement Operators](https://www.youtube.com/watch?v=kwkZpSc6g7Q) | 7:39 |
| [Modulus, Short-Hand Operators](https://www.youtube.com/watch?v=fy4hJWctkNc) | 5:13 |
| [IF ELSE](https://www.youtube.com/watch?v=rPyn7kGHZzA) | 8:26 |
| [Nested IF ELSE and IF ELSEIF](https://www.youtube.com/watch?v=oMrt_87aW-U) | 5:31 |
| [Logical and Comparison Operators](https://www.youtube.com/watch?v=HLv2gVg6Xtc) | 13:18 |
| [Ternary Operator (Conditional Operator)](https://www.youtube.com/watch?v=-QVc_fGSJAw) | 4:44 |
| [While Loop](https://www.youtube.com/watch?v=kcd2FAxC5Ms) | 5:24 |
| [Do While Loop](https://www.youtube.com/watch?v=IqKweotABQI) | 5:46 |
| [For Loop](https://www.youtube.com/watch?v=dNmdkIu0qww) | 7:36 |

### Optional
*If you've got time and/or want to dig deeper, consider the following:*

| Material | Time |
|:---------|-----:|
| [Operators](https://www.tutorialspoint.com/cplusplus/cpp_operators.htm) | |

## Material Review
 - constant, variable, datatype, keyword
 - int, float, char, bool
 - `cin >>` and `cout <<`
 - `//`, `/* .. */`
 - `--i`/`++i` and `i--`/`i++`
 - `+`, `-`, `*`, `/`, `%`
 - `+=`, `-=`, `*=`, `/=`
 - `==`, `>`, `>=`, `<`, `<=`, `!=`
 - `&&`, `||`, `!`
 - if statement
 - nested if statement
 - `?:` ternary operator
 - while loop
 - do while loop
 - for loop

## Workshop

### Hello World
```c_cpp
cout << "Hello World!" << endl;
```

### Numbers
```c_cpp
1
0
123
-1
1.1
1.0

1 + 1
2 - 1
3 * 4
1 / 2
1 / 0
1 % 2
(1 + 3) * 4
```

### Variables
```c_cpp
int a = 1;
int a;
a = a + 1;
a += 1;
```

#### Excercises
 - [01.cpp](workshop/01.cpp)
 - [02.cpp](workshop/02.cpp)
 - [03.cpp](workshop/03.cpp)
 - [04.cpp](workshop/04.cpp)
 - [05.cpp](workshop/05.cpp)
 - [06.cpp](workshop/06.cpp)


### Boolean
```c_cpp
a == 2
True
False
1 < 2
1 > 2
1 == 2
1 != 2
True || False
True && False
!True
```

#### Excercises
 - [07.cpp](workshop/07.cpp)
 - [08.cpp](workshop/08.cpp)
 - [09.cpp](workshop/09.cpp)
 - [10.cpp](workshop/10.cpp)
 - [11.cpp](workshop/11.cpp)

### Strings
```c_cpp
#include <string>
string txt = "alma";
string txt;
txt = "alma" + "fa";
```

#### Excercises
 - [12.cpp](workshop/12.cpp)
 - [13.cpp](workshop/13.cpp)
 - [14.cpp](workshop/14.cpp)

### If
```c_cpp
	if (a == 2) {
	cout << a << endl;
	}

	if (a < 16) {
	cout << a + 1 << endl;
	}
	else if ( a <= 40) {
	cout << a - 1 << endl;
	}
	else {
	cout << a << endl;
	}

	if (a <= 40) {
		if (a < 16) {
		cout << a + 1 << endl;
		}
		else {
		cout << a - 1 << endl;
	}
	else {
	cout << a << endl;
	}
```

#### Excercises
 - [15.cpp](workshop/15.cpp)
 - [16.cpp](workshop/16.cpp)
 - [17.cpp](workshop/17.cpp)
 - [18.cpp](workshop/18.cpp)
 - [19.cpp](workshop/19.cpp)
 - [20.cpp](workshop/20.cpp)
 - [21.cpp](workshop/21.cpp)
 - [22.cpp](workshop/22.cpp)


### While / Do - While / For
```c_cpp
int a = 0;
while (a < 5) {
    a += 1;
    cout << a << endl;
}

do {
    a += 1;
    cout << a << endl;
} while (a < 5);

for (a = 0; a < 5; a++) {
    cout << a << endl;
}
```

#### Excercises
Please do the excercises with while && do-while && for
 - [23.cpp](workshop/23.cpp)
 - [24.cpp](workshop/24.cpp)
 - [25.cpp](workshop/25.cpp)
 - [26.cpp](workshop/26.cpp)
 - [27.cpp](workshop/27.cpp)
 - [28.cpp](workshop/28.cpp)
 - [29.cpp](workshop/29.cpp)

## Individual Workshop Review
Please follow the styleguide: [Our C++ styleguide](../../styleguide/cpp.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes palced on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?

