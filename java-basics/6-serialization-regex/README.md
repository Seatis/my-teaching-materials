# Serialization, Regular Expressions
Serialization is an approach to transmitting data between processes.  While in a program, you can have variables that hold your data.  These have nice, discrete boundaries.  For example A=10, B=2 and C=Joe.  But if you need to transmit data between processes it gets more complicated.  

The first complication is that you need to know where one piece of data ends and another begins.  If we just put A, B and C (above) together, we'd get 102Joe.  We could have a separate file that says 2 characters for A, 1 for B and the rest is C.  But that's not very flexible.  What if later, we have an A that is 100?

While databases have defined "columns", when communicating between processes (especially over the internet), we need another method to do such.  Enter the concept of *serialisation*.  Serialisation is a way to mark the beginning and endings; and also name what each packet of data is.  In fact, *serialisation* can also identify data relationships.  For example, this is an `Invoice`, and here are the `Invoice`'s 2 `Billing Rows`.

You are already acquainted with this.  Think of HTML and CSS.  They are both examples of serialisation.  For example &lt;div&gt; marks a lexical group which can contain other &lt;div&gt;s, &lt;p&gt;s, &lt;span&gt;s etc.  &lt;article&gt; for example, tells a Search Engine that what follows is text to be indexed for searches as opposed to &lt;h1&gt; which is just a section title in the document (and therefore probably less likely to answer a googler's question.  And &lt;div&gt can have direct value such the element's value which can be a long piece of text as well as attributes that appear inside the angled brackets.

Putting data into this format is aptly call *serialization* and returning it to data variables conversely is called *deserialisation*.

Now to do this could be involved.  Fortunately though, most modern programming languages have libraries that do all the heavy lifting  for us. (Though you'd be amazed at the number of people who still attempt to do it the old, long hand method - with incredible results; and not to name names, but TNT (as of 2016) still hasn't figured it out.)

Also in this `day` we can optionally look at Regex.  Regex offers ways to scan texts for patterns.  These are useful, for example, in validating postcodes, phone numbers, email addresses, etc.  From time-to-time you'll find knowing a little Regex well worth your while.  All you'll need to do is Google a particular pattern, find it and then use it to validate some data input (e.g. Brazilian Postcodes) rather than you having to research and then handcode such (again, I'm drawing on some *recent* experience).

## Objectives
- How to Serialize/Deserialize objects
- Introduce Regex

## Materials & Resources

| Material | Time |
|:-------- |-----:|
|[Concepts behind Serialization (POSCH.01)](https://www.youtube.com/watch?v=6MisF1sxBTo) - converting data into and out of transmittable forms.|9:24|
|[Serialization - a worked example (POSCH.02)](https://www.youtube.com/watch?v=FCRwbIXTFyk)|9:48|
|[Deserialization - a worked example (POSCH.03)](https://www.youtube.com/watch?v=q_g7VYoA4sg)|7:50|

### Optional
*How to use Regular Expressions in Java.*
|[Regex - How to use Regular Expressions (in Java)](https://www.youtube.com/watch?v=s_PfopWcMwI)|19:27|
|[Add Maven library to a IDEA project](https://www.jetbrains.com/help/idea/2016.2/downloading-libraries-from-maven-repositories.html)|0:50|
|[Gson API docs](https://google.github.io/gson/apidocs/com/google/gson/Gson.html)|1:00|

## Material Review
- Serialization
  - Serializable interface
  - ObjectOutputStream
    - writeObject()
  - FileOutputStream
  - ObjectInputStream
    - readObject()
  - ObjectOutputStream
- Gson (serialize to JSON)
  - JSON
  - toJson()
  - fromJson()

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
- [Workshop01.java](workshop/Workshop01.java)
- [Workshop02.java](workshop/Workshop02.java)
- [Workshop03.java](workshop/Workshop03.java)
- [Workshop04.java](workshop/Workshop04.java)

### Regular Expression
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
