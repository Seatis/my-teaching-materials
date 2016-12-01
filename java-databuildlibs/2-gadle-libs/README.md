# Data & Build & Libs
*Manage project build and dependencies with Gradle Build Tool. Get to know a little two useful java library.*

## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Gradle Basics (EP1)](https://www.youtube.com/watch?v=vxKN2VSqTMg&t=595s)|21:26 (-59s)|
|[Gradle Dependencies and Configurations (EP2)](https://www.youtube.com/watch?v=7alCuE7cNVQ)|21:12|
|[Create Gradle project in IntelliJ](https://www.youtube.com/watch?v=3Euo6xzCwY4)|4:19|
|[Quick start Joda-Time](http://www.joda.org/joda-time/quickstart.html)||


### Optional
| Material | Time |
|:-------- |-----:|
|[Gradle Custom Tasks (EP3)](https://www.youtube.com/watch?v=g56O_HeefBE)|29:53|
|[Introduction to Google Guava](http://zetcode.com/articles/guava/)||
|[Overview of Guava](https://www.youtube.com/watch?v=MFEJll-wU7Q)|55:56|
|[Introducing the Java Time API in JDK 8 (Advanced)](https://www.youtube.com/watch?v=CtD9B9TU_cY)|58:37|
      
## Workshop

### New Gradle project
*Create new Gradle project in IntelliJ as tutorial.*
- New project (Gradle, Java)
- Group id: hu.greenfox, Artifact id: jodatime
- Check auto-import and create directories for empty content roots options
- Project name: jodatime
- Copy sources from git repo to src folder of your project
- Gradle setting:
      - You need java plugin.
      - Use maven central repository.
      - You are going to use newest stable versions of "guava", "joda-time", "slf4j-log4j12" and "junit" java libraries. Add these to gradle dependencies.
      - (We use Java/JDK 1.7)
- Create .gitignore file and roles
- Build and run BirthdayWithJavaUtilDate.java
- Run TestJavaUtilDate.java unit test.
- If both java files compilable and runnable please commit your code and this task is done.

### Birthday Calculator with Java Util Date

- Open BirthdayWithJavaUtilDate class from date package and implement the empty methods of BirthdayCalculator interface. Please use simple java util date only.
- Run, try and correct your program.
- Run unit tests of TestJavaUtilBirthdayCalculator.
- Improve your program as long as all tests run well.

### Birthday Calculator with Joda-Time

- Open BirthdayWithJodaTime class from date package and implement the empty methods of BirthdayCalculator interface. You should use Joda-Time library now.
- Run, try and correct your program.
- Run unit tests of TestJodaTimeBirthdayCalculator.
- Improve your program as long as all tests run well.

### Handy Guava tools

- Open GuavaTasks from guava package class and implement the missing part of constructor and empty methods acording to TODOs. You must use Google Common Utility libraries (Guava) for your solutions
- Run, try and correct your program.
- Run unit tests of TestGuavaTasks.
- Improve your program as long as all tests run well.
