# Serialization, Regular Expressions
[Description of serialization and regex]

## Objectives
 - How to Serialize/Deserialize objects

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Serialization Part 1](https://www.youtube.com/watch?v=6MisF1sxBTo)|9:24|
|[Serialization Part 2](https://www.youtube.com/watch?v=FCRwbIXTFyk)|9:48|
|[Serialization Part 3](https://www.youtube.com/watch?v=q_g7VYoA4sg)|7:50|

### Optional
*How to use Regular Expressions in Java*

| Material | Time |
|:-------- |-----:|
|[Regex](https://www.youtube.com/watch?v=s_PfopWcMwI)|19:27|

## Material Review
- Serialization
  - Serializable interface
  - ObjectOutputStream
    - writeObject()
  - FileOutputStream
  - ObjectInputStream
    - readObject()
  - ObjectOutputStream

### Optional
- Regular Expressions
  - Pattern
    - compile()
  - Matcher
    - find()
    - group()
  - String.replaceAll(String regex, String replacement)
  - String.replaceFirst(String regex, String replacement)

## Workshop
### Serialization

#### Exercise
- [Workshop18.java](workshop/Workshop18.java)

### Regular Expression

#### Exercise
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
