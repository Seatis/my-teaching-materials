# Gradle and Build
Gradle is an advanced general purpose build management system that supports the automatic download and configuration of dependencies or other libraries.

## Materials & Resources

| Material | Time |
|:-------- |-----:|
|[Why Gradle](https://www.youtube.com/watch?v=VOUmY4_hPeM)| until 00:50|
|[Getting started with Gradle](https://www.youtube.com/watch?v=wN8bFn9Yp8Q)|7:13|
|[Gradle intro and some Groovy](https://www.youtube.com/watch?v=mPpncYETnTg&t=319s)|until 11:06|
|[Gradle Wrapper](https://www.youtube.com/watch?v=wbuwoVbCwAk)|8:08|
|[Gradle in IntelliJ](https://www.youtube.com/watch?v=3Euo6xzCwY4)|4:19|

### Optional
(Some deeper concepts of how gradle works)

| Material | Time |
|:-------- |-----:|
|[Gradle Basics (EP1)](https://www.youtube.com/watch?v=vxKN2VSqTMg&t=361s)|21:26|
|[Gradle Dependencies and Configurations (EP2)](https://www.youtube.com/watch?v=7alCuE7cNVQ&t=1110s)|21:12|
|[Gradle Custom Tasks (EP3)](https://www.youtube.com/watch?v=g56O_HeefBE&t=664s)|29:54|

## Material Review
- gradle
- dependencies
- build.gradle
- groovy
- gradle wrapper
- artifacts

### Optional
- gradle tasks
- apply plugin
- jar file



## Workshop

### Example code for [jopt-simple](http://pholser.github.io/jopt-simple/examples.html)

```java
public static void main(String[] args) {
  OptionParser parser = new OptionParser();
  parser.accepts("l");
  parser.accepts("a").withRequiredArg();
  OptionSet options = parser.parse(args);

  if (options.has("a")) {
    System.out.println("`-a` was given with the argument " + options.valueOf("a"));
  }

  if (options.has("l")) {
    System.out.println("`-l` was given with the no additional information.");
  }
}
```

### Example code for [opencsv](http://opencsv.sourceforge.net/)

```java
CSVReader reader = new CSVReader(new FileReader("data.csv"), ';');
List<String[]> lines = reader.readAll();
CSVWriter writer = new CSVWriter(new FileWriter("copydata.csv"), ';', CSVWriter.NO_QUOTE_CHARACTER);
writer.writeAll(lines);
writer.close();
```

 - [Lottery filter](lottery-filter/java.md)
