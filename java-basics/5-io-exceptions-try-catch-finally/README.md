# Module 03 #5 - Exceptions, File I/O, try-catch-finally

Exceptions helps to handle ...
I/O (Input/Output) discusses how one stores and retrieves streams of data ...
try-catch-finally used to handle exceptions

## Materials & Resources
| Material | Time |
|:-------- |-----:|
|[Exceptions](https://www.youtube.com/watch?v=EWj60p8esD0)|15:42|
|[File Class](https://www.youtube.com/watch?v=o9F73FU2vzs)|12:17|
|[Read & Write Files](https://www.youtube.com/watch?v=D_WDuwnaobg)|14:31|


### Optional
*How to read/write binary data*

| Material | Time |
|:-------- |-----:|
|[Read & Write Binary Streams](https://www.youtube.com/watch?v=X81XIVaMWCQ)|13:58|


## Assignment Review
- Exceptions
  - java.lang.RuntimeException
  - java.lang.Exception
    - getMessage()
  - ArithmeticException
  - IndexOutOfBoundsException
  - `throws` keyword
  - try - catch
  - try - catch - finally
  - catch order/specificity
- File I/O
  - java.io.*
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
  - PrintWriter
  - BufferedWriter
  - FileWriter
  - BufferedReader
  - FileReader
  - FileNotFoundException
  - IOException

### Optional

Binary data read/write

## Workshops

### Exceptions

- [Workshop18.java](workshop/Workshop18.java)


### File I/O

- [Workshop01.java](workshop/Workshop01.java)


### try-catch-finally

- [Workshop13.java](workshop/Workshop13.java)


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
