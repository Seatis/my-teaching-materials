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
|[Java 8 Date and Time](https://www.youtube.com/watch?v=nvluJ9yf4ho)|11:22|



### Optional
(Some deeper concepts of how gradle and java 8 date and time work)

| Material | Time |
|:-------- |-----:|
|[Gradle Basics (EP1)](https://www.youtube.com/watch?v=vxKN2VSqTMg&t=361s)|21:26|
|[Gradle Dependencies and Configurations (EP2)](https://www.youtube.com/watch?v=7alCuE7cNVQ&t=1110s)|21:12|
|[Gradle Custom Tasks (EP3)](https://www.youtube.com/watch?v=g56O_HeefBE&t=664s)|29:54|
|[Java 8 Date and Time Melbourne conf](https://www.youtube.com/watch?v=daCUA17yWw4)|24:05|
|[Java 8 Date and Time reading](http://www.oracle.com/technetwork/articles/java/jf14-date-time-2125367.html)|reading|
|[Package java.time](https://docs.oracle.com/javase/8/docs/api/java/time/package-summary.html)|reading|


## Material Review
- gradle
- dependencies
- build.gradle
- groovy
- gradle wrapper
- `LocalDateTime`
- `now();`

### Optional
- gradle tasks
- apply plugin
- artifacts
- jar file

## Workshop

### Exercises

 - [Lottery filter](lottery-filter/java.md)
 - [Yoda Speak]()
 - [Weather checker](weather-checker/java.md)
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

### Example code for [retrofit](http://square.github.io/retrofit/)

```java
public interface GitHubService {
  @GET("users/{user}/repos")
  Call<ResponseBody> listRepos(@Path("user") String user);
}
```

```java
public static void main(String[] args) {
  Retrofit retrofit = new Retrofit.Builder()
    .baseUrl("https://api.github.com/")
    .build();

  GitHubService service = retrofit.create(GitHubService.class);

  Call<ResponseBody> repos = service.listRepos("octocat");

  System.out.println(repos.execute().body().string());
}
```
