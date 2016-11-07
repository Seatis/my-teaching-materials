# Module 03 #5 Exceptions (`try, catch &amp; finally`) and File Input/Output (IKO)
If anything can go wrong, it will.   Programming is not exempt and exceptions come in all sorts of ways:-
- the data entered or received is of a type that isn't expected
- the location for data is wrong
- an unexpected event or condition occurs.

We don't always anticipate every situation, and machines (like people) don't always behave as anticipated.

Fortunately, we have ways to handle errors.  One is to code defensively.  That is, ensure the error cannot occur by inserting code that  checks the data that the program is about to handle.  Another is to code in fallbacks.  These say, *if something goes wrong, do this to recover*.

I/O (which standards for Input/Output) addresses how we work with *streams* of data.  Data might be streamed from a source (like YouTube), the disk drive; perhaps a device monitoring items on a conveyor belt.  

And we have combined these topics here as I/O is one place where you cannot always predict what might be happen and therefore must be ready for Exceptions.  

## Objectives
 - What are the Exceptions and how to handle them using try-catch-finally
 - How to write and read a text file from java

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Exceptions (Bana.06)](https://www.youtube.com/watch?v=EWj60p8esD0)|15:42|
|[File Class (first part using files Bana.31)](https://www.youtube.com/watch?v=o9F73FU2vzs) - ignore the JFrame around 10m00|12:17|
|[Read & Write Files (Bana.32)](https://www.youtube.com/watch?v=D_WDuwnaobg) - this shows a little bit of Object Orientation (OO); pay attention to printWriter and getInfo|14:31|

Bana talks about OO which we will get into; for the moment though, focus on the methods of reading and writing data.  

### Optional
As opposed to ASCII (or encoded) data, we can also get *binary* data such as images.  These are sometimes referred to as *blobs* and in a database as *varbinary*.

| Material | Time |
|:-------- |-----:|
|[Read & Write Binary Streams](https://www.youtube.com/watch?v=X81XIVaMWCQ)|13:58|


## Material Review
- Structure of Exception Handling
  - `throws` keyword
  - `try` - `catch`
  - `try` - `catch` - `finally`
  - catch order/specificity
    - catch(IOException e) - what the "e" is
    - catch to catch to (final) catch, eg.
    ```
    catch(FileNotFoundException e) {
    }
    catch(IOException e) {
    }
    catch(Exception e) {
    }
    ```
- Libraries
  - java.lang.RuntimeException
  - java.lang.Exception
    - getMessage()
- File I/O
  - java.io.&lowast; import
  - File
    - exists()
    - getCanonicalPath()
    - canRead()
    - canWrite()
    - getName()
    - isDirectory()
    - isFile()
    - isHidden()
    - getParent()
    - lastModified()
    - length()
    - renameTo()
    - delete()
    - listFiles()
    - mkdir()
    - createNewFile()
    - getCanonicalPath()
    - list() - will put the list of files in a directory in a String[]
  - PrintWriter
  - BufferedWriter
  - FileWriter
  - BufferedReader
  - FileReader
  - Exceptions
    - ArithmeticException
    - ClassNotFound
    - IllegalArgumentException
    - IndexOutOfBounds
    - InputMismatchException
    - FileNotFoundException
    - IOException
    - IndexOutOfBoundsException

### Optional
Binary data read/write

## Workshops
### Exceptions
In these exercises work on catching the basic exceptions and then determining what to do.

#### Exercise
- [m04d05w01.java](workshop/Workshop01.java) - a simple situation
- [m04d05w02.java](workshop/Workshop02.java) - more complexity
- [m04d05w03.java](workshop/Workshop03.java) - what to do at the end
- [m04d05w04.java](workshop/Workshop04.java) - programming defensively

### File I/O
Search for a particular file in a directory; then read input in, write stuff out.

#### Exercise
- [m04d05w11.java](workshop/Workshop11.java) - scan directory
- [m04d05w12.java](workshop/Workshop12.java) - read input
- [m04d05w13.java](workshop/Workshop13.java) - write output
- [m04d05w14.java](workshop/Workshop14.java) - merge 2 files
- [m04d05w15.java](workshop/Workshop15.java) - handle missing file
- [m04d05w16.java](workshop/Workshop16.java) - handle a data exception

## Individual Workshop Review
Neatness counts in coding.

Please be sure you're well acquainted with the guidelines on coding: [GreenFox Academy's Java Styleguide](../../styleguide/java.md)

Key questions to consider:
- Are the directory structure and the names of the files correct?
- Are the includes placed at the top of the file?
- Does the code follow the right level of indentation?
- Are all of the brackets positioned correctly?
- Are the whitespaces where they should be; and not where they shouldn't?
- Is the code *pithy* (meaning to the point, not superfluous or un-necessary)?
  - Not using extra variables (unless needed to understand the logic)
  - Not confusingly or overly commented
  - Does the computation instead of repeating stuff (aka *code duplication*)?
  - Does not contain empty blocks
  - Non repetitive and where needing to repeat a block instead, carved out to a function?
- Are there un-used variables - added during development but later made surplus to requirements through simplification?
- Is the commentary in the code at the right level?
  - Can one deduce the purpose of a block from the variable naming combined with the explanation
  - Are there *Watch outs* warnings just in case somebody later maintains the code and needs to beware of something tricky (or not obvious)?
- Are the data types used right for the purpose
- Is the "commit message" meaningful?
- Do the names conform to the Styleguide?
    - Classes: UpperCamelCase
    - variables: lowerCamelCase
    - functions: lowerCamelCase(paramsLowerCase)
