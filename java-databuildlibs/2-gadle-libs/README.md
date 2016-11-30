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

# New Gradle project
*Create new Gradle project in IntelliJ as tutorial.*
- New project (Gradle, Java)
- Group id: hu.greenfox, Artifact id: jodatime
- Check auto-import and create directories for empty content roots options
- Project name: jodatime
- Copy sources from git repo to src folder of your project
- Gradle setting:
-     You need java plugin.
-     Use maven central repositiry.
-     You are going to use newest stable versions of "guava", "joda-time", "slf4j-log4j12" and "junit" java libraries. Add these to gradle dependencies.
-     (We use Java/JDK 1.7)
- Build and run BirthdayWithJavaUtilDate.java
- Run TestJavaUtilDate.java unit test.
- If both java files compilable and runnable this task is done.

# Birthday Calculator with Java Util Date
