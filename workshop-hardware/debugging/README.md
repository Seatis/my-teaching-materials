# What is wrong with the code?!

## Objectives
- learn how to troubleshoot others code

## Materials & Resources
### Environment
  - Make sure that Code::Blocks is installed on your machine
    - For installation instructons see the syllabus

### Training

#### C programming language

| Material | Duration |
|:---------|-----:|
| [Debugger in Code::Blocks](https://www.youtube.com/watch?v=Jab1qj_QR8s) | 9:20 |
|[wiki](http://wiki.codeblocks.org/index.php/Debugging_with_Code::Blocks)|-|

*note: you are not going to use all of the functions that the wiki page is talking about*

```
#include <stdio.h>
#include <stdint.h>

int summation(int a, int b){

    return a + b;
}

int subtraction(int a, int b){

    return a - b;
}

int multiplication(int a, int b){

    return a * b;
}

int division(int a, int b){

    return a / b;
}

int main()
{
    int choice = 0;
    int num_1 = 0;
    int num_2 = 0;

    int num_1_watcher = 0;
    int num_2_watcher = 0;

    printf("Hello this is a calculator!\n");
    printf("Please add two number (hit enter between them):\n");
    scanf("%d %d", &num_1, &num_2);

    num_1_watcher = &num_1;
    num_2_watcher = &num_2;

	printf("Please choose from the following options:\n\n");
	printf("\tpress 1 for summation\n");
	printf("\tpress 2 for subtraction\n");
	printf("\tpress 3 for multiplication\n");
	printf("\tpress 4 for division\n");
	printf("\tpress 9 to exit the program\n");

    while(choice != 9){
        scanf("%d", &choice);

        switch(choice){
        case 1:
            printf("%d + %d = %d\n",num_1, num_2, summation(num_1, num_2));
            continue;
        case 2:
            printf("%d - %d = %d\n",num_1, num_2, subtraction(num_1, num_2));
            continue;
        case 3:
            printf("%d * %d = %d\n",num_1, num_2, multiplication(num_1, num_2));
            continue;
        case 4:
            printf("%d / %d = %d\n",num_1, num_2, division(num_1, num_2));
            continue;
        case 9:
            printf("program is over\n");
            continue;
        default:
            printf("wrong user input, you have played your only one chance you son of a bit*h!\n");
            continue;
        }
    }

	return 0;
}

```

Get familiar with the code above. This is a working program, this will be representative during the material review. Run it a few times. Maybe you can change the code to understand it better. 

## Workshop
Look at the codes below! They are not working properly. Can you help us to find
the problems and correct them?

- [Number printer](workshop/number_printer.c)
- [Square checker](workshop/square_checker.c)
- [To binary](workshop/to_binary.c)
- [Guess game](workshop/guess-game.c)
- [Palindrome](workshop/palindrome.c)
- [Palindrome search](workshop/palindrome-search.c)
- [ToDo app](workshop/todo-app.c)

## Individual Workshop Review
Please follow the styleguide: [Our C styleguide](https://github.com/greenfox-academy/teaching-materials/blob/master/styleguide/c.md)

 - Is the directory structure and the name of the files correct?
 - Are the includes placed on the top of the files?
 - Is the indentation good in each file?
 - Is there unnecessary code?
 - Can you find unnecessary code in comments?
 - Is there unnecessary code duplication?
 - Are there unnecessary empty blocks?
 - Can you spot unused variables?
 - Is the commit message meaningful?

## Solutions
[Solutions](https://github.com/greenfox-academy/teaching-materials/tree/master/workshop/hardware/solutions/debugging)
