# Styleguide for C


## 1) Indentation
- The whole idea behind indentation is to clearly **define where a block of control starts and ends**.
- **Tabs are 4 characters long**. It's a golden mean, because 8-character indentations makes the code move too far to the right. Identations with less than 4 characters, the code is not enough proportioned.

- The preferred way to ease multiple indentation levels in a switch statement is to align the switch and its subordinate case labels in the same column instead of double-indenting the case labels. E.g.:
```
switch (suffix) {
case 'G':
case 'g':
	mem <<= 30;
    break;
case 'M':
case 'm':
    mem <<= 20;
    break;
case 'K':
case 'k':
    mem <<= 10;
    /* fall through */
default:
    break;
}
```
- Don’t put multiple statements on a single line unless you have something to hide:
```
if (condition) do_this;
    do_something_everytime;
```
- Don’t put multiple assignments on a single line either. Avoid tricky expressions.

- Outside of comments, documentation spaces are never used for indentation, and the above example is deliberately broken.

- Get a decent editor and don’t leave whitespace at the end of lines.

## 2) Breaking long lines and strings
Coding style is all about readability and maintainability using commonly available tools.

The limit on the **length of lines is 80 columns** and this is a strongly preferred limit.

Statements **longer than 80 columns** will be **broken into sensible chunks**, unless exceeding 80 columns significantly increases readability and does not hide information. Descendants are always substantially shorter than the parent and are placed substantially to the right. The same applies to function headers with a long argument list. However, never break user-visible strings such as printk messages, because that breaks the ability to grep for them.

## 3) Placing Braces and Spaces
The other issue that always comes up in C styling is the placement of braces. Unlike the indent size, there are few technical reasons to choose one placement strategy over the other, but the preferred way, as shown to us by the prophets Kernighan and Ritchie, is to **put the opening brace last on the line, and put the closing brace first**, thusly:
```
if (x is true) {
	we do y
}
```

- **This applies to all non-function statement blocks** (if, switch, for, while, do). E.g.:
```
switch (action) {
case KOBJ_ADD:
    return "add";
case KOBJ_REMOVE:
    return "remove";
case KOBJ_CHANGE:
    return "change";
default:
    return NULL;
}
```
- However, there is **one special case**, namely **functions**: they have the **opening brace at the beginning of the next line**, thus:
```
int function(int x)
{
    body of function
}
```
Some people may see that this is **inconsistent, but** all right-thinking people know that **functions are special** (e.g you can’t nest them in C).

Note that the closing brace is empty on a line of its own, except in the cases where it is followed by a continuation of the same statement, ie a while in a do-statement or an else in an if-statement, like this:

```
do {
    body of do-loop
} while (condition);
```
and
```
if (x == y) {
    ..
} else if (x > y) {
    ...
} else {
    ....
}
```
Also, note that this brace-placement also **minimizes the number of empty (or almost empty) lines**, without any loss of readability. Thus, as the supply of new-lines on your screen is not a renewable resource (think 25-line terminal screens here), you have more empty lines to put comments on.

Do not unnecessarily use braces where a single statement will do.
```
if (condition)
	action();
```

and

```
if (condition)
    do_this();
else
    do_that();
```
This does not apply if only one branch of a conditional statement is a single statement; in the latter case use braces in both branches:
```
if (condition) {
    do_this();
    do_that();
} else {
    otherwise();
}
```

### 3.1) Spaces
This styleguide for use of spaces depends mostly on function-vs-keyword usage. **Use a space after (most) keywords**. The notable **exceptions are sizeof**, **typeof**, which look somewhat like functions (and are usually **used with parentheses**, although they are not required in the language, as in: sizeof info after struct fileinfo info; is declared).

- So **use a space after** these keywords:
```
if, switch, case, for, do, while
```

- but not with:
```
sizeof, typeof
```

- For example:
```
s = sizeof(struct file);
```

- **Do not add spaces around (inside) parenthesized expressions**. This example is bad:
```
s = sizeof( struct file );
```

When declaring pointer data or a function that returns a pointer type, the preferred use of ``` * ``` is adjacent to the data name or function name and not adjacent to the type name. Examples:

```
char *linux_banner;
unsigned long long memparse(char *ptr, char **retptr);
char *match_strdup(substring_t *s);
```

- Use **one space around** (on each side of) most **binary and ternary operators**, such as any of these:
```
=  +  -  <  >  *  /  %  |  &  ^  <=  >=  ==  !=  ?  :
```
Let's see an example:
```
int a = 5;
int b = 6;
int c = a + b;
```
- but **no space after unary operators**:
```
&  *  +  -  ~  !  sizeof  typeof  defined
```
Let's see an example:
```
int a = -8;
```
- **no space before the postfix** and **after the prefix increment & decrement** unary **operators**:
```
++  --
```

- and **no space around the ``` . ``` and ``` -> ```  structure member operators**.:
```
struct mystruct.datamember = 5;
```

**Do not leave trailing whitespace at the ends of lines**. Some editors with smart indentation will insert whitespace at the beginning of new lines as appropriate, so you can start typing the next line of code right away. However, some such editors do not remove the whitespace if you end up not putting a line of code there, such as if you leave a blank line. As a result, you end up with lines containing trailing whitespace.

Git will warn you about patches that introduce trailing whitespace, and can optionally strip the trailing whitespace for you; however, if applying a series of patches, this may make later patches in the series fail by changing their context lines.

## 4) Naming
C is a Spartan language, and so should your naming be. C programmers do not use cute names like ThisVariableIsATemporaryCounter. A C programmer would call that variable tmp, which is much easier to write, and not the least more difficult to understand.

- However, **descriptive names for global variables are a must**. To call a global function foo is a shooting offense. Your variable names should look like: ```my_variable``` (use pronouncable and descriptive names). **Don't use too much global variables**, but if needed, give them descriptive names, as do global functions. If you have a function that counts the number of active users, **you should call that count_active_users() or similar, you should not call it cntusr()**.

- Encoding the type of a function into the name (so-called Hungarian notation) is brain damaged - the compiler knows the types anyway and can check those, and it only confuses the programmer.

- **Local variable names should be short, and to the point**. If you have some random integer loop counter, it should probably be called i. Calling it **loop_counter is non-productive**, if there is no chance of it being mis-understood. Similarly, tmp can be just about any type of variable that is used to hold a temporary value.

If you are afraid to mix up your local variable names, you have another problem, which is called the function-growth-hormone-imbalance syndrome. See chapter 5 (Functions).

## 5) Functions
- Functions should be **short** and sweet, and **do just one thing and do that well without having any side effect**. They should **fit on one or two screenfuls of text** (the ISO/ANSI screen size is 80x24, as we all know).

- The maximum length of a function is inversely proportional to the complexity and indentation level of that function. So, **if you have a conceptually simple function that is just one long (but simple) case-statement**, where you have to do lots of small things for a lot of different cases, **it’s OK to have a longer function**.

- However, if you have a complex function, and you suspect that a less-than-gifted first-year high-school student might not even understand what the function is all about, you should adhere to the maximum limits all the more closely. **Use helper functions with descriptive names** (you can ask the compiler to in-line them if you think it’s performance-critical, and it will probably do a better job of it than you would have done).

- Another measure of the function is the **number of local variables**. They **shouldn’t exceed 5-10**, or you’re doing something wrong. **Re-think** the function, and **split it into smaller pieces**. A human brain can generally easily keep track of about 7 different things, anything more and it gets confused. You know you’re brilliant, but maybe you’d like to understand what you did 2 weeks from now.

- In function **prototypes, include parameter names with their data types**. Although this is not required by the C language, it is preferred in this styleguide because it is a simple way to add **valuable information for the reader**.

## 6) Centralized exiting of functions
Albeit deprecated by some people, the equivalent of the goto statement is used frequently by compilers in form of the unconditional jump instruction.

The **goto statement comes in handy when a function exits from multiple locations** and some common work such as cleanup has to be done. If there is no cleanup needed then just return directly.

But be careful with goto. **Choose label names which say what the goto does or why the goto exists**. An example of a good name could be out_free_buffer: if the goto frees buffer. Avoid using names like err1: and err2:, as you would have to renumber them if you ever add or remove exit paths, and they make correctness difficult to verify anyway.

The rationale for using gotos is: unconditional statements are easier to understand and follow nesting is reduced errors by not updating individual exit points when making modifications are prevented
saves the compiler work to optimize redundant code away.

```
int fun(int a)
{
	int result = 0;
	char *buffer;

	buffer = kmalloc(SIZE, GFP_KERNEL);
	if (!buffer)
		return -ENOMEM;

		if (condition1) {
			while (loop1) {
				...
			}
			result = 1;
			goto out_free_buffer;
        }
        ...
	out_free_buffer:
		kfree(buffer);
		return result;
}
```

## 7) Function return values and names
Functions can return values of many different kinds, and one of the most common is a value indicating **whether the function succeeded or failed**. Such a value can be represented as an error-code integer (0 : failure, non-zero : success).

- It's also a generally accepted custom, if you **return with an enumeration**, because it's very expressive.

- If the name of a function is an action or an imperative command, the function should return an error-code integer. If the name is a predicate, the function should return a "succeeded" value.

- For example, add work is a command, and the add_work() function returns **0** for success or **-EBUSY** (an enum) for failure.

- **Functions whose return value is the actual result of a computation**, rather than an indication of whether the computation succeeded, are not subject to this rule. Generally **they indicate failure by returning some out-of-range result**. Typical examples would be functions that return pointers; they use NULL or the ERR_PTR mechanism to report failure.

- If you have **more than 3 arguments**, rather pack them into a **structure**. The practical reason for this: it's not easy to keep the right sequence of parameters in mind.

- **Don't use output parameters** without special reason.

- **Don't use fairly deep nested loops and conditionals (maximum 3 level)** within one function. Rather split up your function, and use helper-functions instead. But consider that, too much calls on an embedded platform may cause problems with regard to memory.
- Lastly, a frequent question: **Returning from a function first** or coding the **main part in if** statement?:
Let's compare the 2 alternatives and try to guess, which one is preffered:
```
void some_function(char some_condition)
{
    if (some_condition) {
        // Do Something: it can be very-very long...
    }
}
```
and
```
void some_function(char some_condition)
{
    if (!someCondition)
        return;

    // Do Something
}
```
Well people usually code with the first one since that is the way our brain works while coding, although the 2nd one takes care of any error handling right away and it's easier to read.

So it's recommended to **get invalid cases out of the way first, either simply exiting or calling an error handler function, then add the "real" body of the function**. It's easier to read and see through what the function does.

## 8) Data structures
- Structure provides a way to store multiple variables of similar or different types under one umbrella. This makes information more packaged and program more modular as different variables referring to different values can be accessed through a single structure object.

- Your struct should look like this:
```
struct car {
	enum car_type type;
	double km;
	double gas;
};
```
and use this way:
```
struct car var_car = {TESLA, 1500.25, 80.75};
```

- unions and bitfields are very similar to structs. Use them the same way.

## 9) Typedefs
Typedefs are **useful element** of the C language, especially when making a library, but **be careful** with them!

Please don’t use things like vps_t. It’s a mistake to use typedef for pointers. When you see a
```
vps_t a;
```
in the source, what does it mean? In contrast, if it says
```
struct virtual_container *a;
```
you can actually tell what a is.

Another bad practice to typedef an array:
```
typedef char type_24_bit[3];
```
The resulting type is an array type, but users of it won't see that it's an array type. If used as a function argument, it will be passed by reference, not by value, and the sizeof for it will then be wrong.

Lots of people think that typedefs help readability. Not always. They are useful only for:

**1) Clear integer types**, where the abstraction helps avoid confusion whether it is int or long.
- u8/u16/u32 are perfectly fine typedefs.

**2) Data structures**. It's useful when you write a function that takes a struct as a pointer or return a custom type.
Compare the 2 below examples, one wich uses typedef (and mark that the ```_t``` ending in the type name, refering to the fact that this is a type), and one wich doesn't.
```
typedef struct {
	//data members
} student_t;

typedef struct {
	//data members
} grade_t;

grade_t get_worst_grade_subjet(student_t *student)
{
	...
}
```
and
```
struct student {
	//data members
}

struct grade {
	//data members
}

struck grade get_worst_grade_subjet(struct student *student)
{
	...
}
```

**3) Enums**. You can use typedefs in the same way:
```
typedef enum {MATH, HISTORY, ENGLISH, SCIENCE} subject_t;
```

## 10) Commenting
Comments are good, but there is also a danger of over-commenting. **Never** try to **explain how your code works** in a comment: it’s much better to write the code so that the working is obvious, and it’s a waste of time to explain badly written code.

Generally, you want your comments to **tell WHAT your code does, NOT HOW**. Also, try to **avoid putting comments inside a function body**: if the function is so complex that you need to separately comment parts of it, you should probably **go back to chapter 5** for a while. You can make small comments to note or warn about something particularly clever (or ugly), but try to avoid excess. Instead, **put the comments at the head of the function**, telling people what it does, and possibly why it does it.

The preferred style for long (multi-line) comments is:
```
/*
 * This is the preferred style for multi-line
 * comments in the Linux kernel source code.
 * Please use it consistently.
 *
 * Description:  A column of asterisks on the left side,
 * with beginning and ending almost-blank lines.
 */
```
It’s also **important to comment data, whether they are basic types or derived types**. To this end, use just one data declaration per line (no commas for multiple data declarations). This leaves you room for a small comment on each item, explaining its use.

## 11) Macros and Enums
- Names of macros defining constants and labels in enums are capitalized. They are especially **useful on embedded platforms**, because they don't use any memory when running.
```
#define CONSTANT 0x12345
```
- **Enums** are preferred when defining **several related constants**.
```
enum weekday {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY};
```
- Capitalized macro names are appreciated but **macros resembling functions may be named in lower case**.
- Generally, inline functions are preferable to macros **resembling functions**.
- Macros with multiple statements should be **enclosed in a do - while block**:
```
#define macrofun(a, b, c)				\
	do {								\
		if (a == 5)						\
			do_this(b, c);				\
	} while (0)
```
**Things to avoid when using macros:**
- macros that **affect control flow** is a very bad idea. It looks like a function call but exits the calling function; don’t break the internal parsers of those who will read the code.:
```
#define FOO(x)							\
	do {								\
		if (blah(x) < 0)				\
			return -EBUGGERED;			\
	} while (0)
```
- macros that **depend on having a local variable with a magic name** (might look like a good thing, but it’s confusing as hell when one reads the code and it’s prone to breakage from seemingly innocent changes.):
```
#define FOO(val) bar(index, val)
```
- macros with arguments that are used as left-values: FOO(x) = y; will bite you if somebody e.g. turns FOO into an inline function.
- **forgetting about precedence**: macros defining constants using expressions must enclose the expression in parentheses. Beware of similar issues with macros using parameters.
```
#define CONSTANT 0x4000
#define CONSTEXP (CONSTANT | 3)
```
- namespace collisions when defining local variables in macros resembling functions:
```
#define FOO(x)							\
({										\
	typeof(x) ret;						\
	ret = calc_ret(x);					\
	(ret);								\
})
```
ret is a common name for a local variable - __foo_ret is less likely to collide with an existing variable.
- and lastly you could still have some kind of type safety problems with macros. Use inline functions instead:
```
void func_test() __attribute__((always_inline));
```
- Since they are functions so **type of arguments is checked by the compiler** whether they are correct or not.
- They can include multiple lines of **code without trailing backlashes.**
- Inline functions have their **own scope for variables and they can return a value.**
- **Debugging code is easy** in case of Inline functions as compared to macros.

## 12) Conditional Compilation
Conditional compilation is very useful when building a library. E.g. you want a portable driver pack for a lot of different AVR microcontroller family, but:
- Wherever possible, **don’t use preprocessor conditionals (#if, #ifdef) in .c files**; doing so makes code harder to read and logic harder to follow. **Instead, use such conditionals in a header file defining functions** for use in those .c files, providing no-op stub versions in the #else case, and then call those functions unconditionally from .c files. The compiler will avoid generating any code for the stub calls, producing identical results, but the logic will remain easy to follow.

- Prefer to **compile out entire functions, rather than portions of functions or portions of expressions**. Rather than putting an ifdef in an expression, factor out part or all of the expression into a separate helper function and apply the conditional to that function.

- If you have a function or variable which may potentially go unused in a particular configuration, and the compiler would warn about its definition going unused, mark the definition as __maybe_unused rather than wrapping it in a preprocessor conditional. (However, if a function or variable always goes unused, delete it.)

- The compiler will constant-fold the conditional away, and include or exclude the block of code just as with an #ifdef, so this will not add any runtime overhead. However, this approach still allows the C compiler to see the code inside the block, and check it for correctness (syntax, types, symbol references, etc). Thus, you still have to use an #ifdef if the code inside the block references symbols that will not exist if the condition is not met.

- **At the end of any non-trivial #if or #ifdef block** (more than a few lines), place a **comment after the #endif on the same line**, noting the conditional expression used. For instance:
```
#ifdef CONFIG_SOMETHING
...
#endif /* CONFIG_SOMETHING */
>>>>>>> new-c-styleguide
