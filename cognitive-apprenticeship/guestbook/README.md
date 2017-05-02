# Guestbook CA

## Setup project
- generate a project with gradle
- add starter dependencies:
```
  compile("org.springframework.boot:spring-boot-starter-web")
  compile("org.springframework.boot:spring-boot-starter-thymeleaf")
```
- create a mainapp:
```java
@SpringBootApplication
public class MainApp {
  public static void main(String[] args) {
    SpringApplication.run(MainApp.class, args);
  }
}
```
- create a simple controller with one endpoint and a template
- print out a hello world
- run & check
- add devtools dependency
- rerun
- change sg in the template
- rebuild the template file and check the changes without rerunning the bootRun task

## Add a counter
- Add an `int count = 0;` to the controller
- extend the endpoint with modelandview and pass the count to the model:
```java
@RequestMapping("")
public ModelAndView index(ModelAndView m) {
  m.setViewName("index");
  m.addObject("count", count);
  return m;
}
```
- add another endpoint:
```java
@RequestMapping("/hit")
public String hitit() {
  count++;
  return "redirect:/";
}
```
- add a link to the index template:
```html
<!doctype html>
<html xmlns:th="http://www.w3.org/1999/xhtml">
    <body>
        <h1>Hitted: <span th:text="${count}"></span></h1>
        <a href="/hit">HITIT2</a>
    </body>
</html>
```

## Change the link to form button
```html
<form action="/hit">
    <input type="submit" value="HITIT">
</form>
```
- check the error, sg about xml parsing, notice that the input field is not closed
- correct it, rebuild, check

## Add input fields to the form
```html
<form action="/hit" th:object="${entry}">
    Name: <input type="text" th:field="*{name}" />
    Message: <input type="text" th:field="*{message}" />
    <input type="submit" value="HITIT" />
</form>
```

## Create the entry model and extend the endpoint by printing it out
- Entry model: name, message, getters, setters, toString
- hit endpoint:
```java
@RequestMapping("/hit")
public String hitit(Entry entry) {
  count++;
  System.out.println(entry);
  return "redirect:/";
}
```

## Extend controller to store entries
- initialize an entry list
- add the entry to it
- show the size of it on the template

## Pass entries to the modelandview and show it
```html
<table>
  <tbody>
    <tr th:each="e : ${entries}">
      <td th:text="${e.getName()}">name</td>
      <td th:text="${e.getMessage()}">message</td>
    </tr>
  </tbody>
</table>
```
