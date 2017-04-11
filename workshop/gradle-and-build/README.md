# Gradle and Build

## Materials & Resources

## Material Review

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
