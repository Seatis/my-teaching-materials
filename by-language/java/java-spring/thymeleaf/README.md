# Thymeleaf, Models, Views
*Subtitle*

![Html everywhere](html_everywhere.jpg)


## Materials & Resources

### Training
| Material | Time |
|:-------- |-----:|
|[Introduction to Thymeleaf (Broadleaf)](https://www.youtube.com/watch?v=GNteuJDo1KA&t=374) - focus on the section "Introduction to Thymeleaf", you can keep watching the "Intermediate" Chapter, but this is just to get the basic concepts (@27m00).|38:00|
| [Getting started with the Standard dialects in 5 minutes](http://www.thymeleaf.org/doc/articles/standarddialect5minutes.html)| 5:34 |
| [Introduction to Using Thymeleaf in Spring](http://www.baeldung.com/thymeleaf-in-spring-mvc) | 7:00 |
| [Spring Forms with Thymeleaf](http://www.thymeleaf.org/doc/tutorials/2.1/thymeleafspring.html#creating-a-form) | 8:42 |
| [Spring RequestMapping](http://www.baeldung.com/spring-requestmapping) | 7:26 |
| [Handling Form Submission](https://spring.io/guides/gs/handling-form-submission/) | 6:59 |


### Optional
| Material | Time |
|:-------- |-----:|
| [Using Thymeleaf (From Paragraph 3 to 7)](http://www.thymeleaf.org/doc/tutorials/2.1/usingthymeleaf.html) | 35:00 |
| [Illustration of Thymeleaf with MVC (RomanianCoder)](https://www.youtube.com/watch?v=Aiqf0X7dlw0&t=454s) - this shows some sample code using the annotations to the html and how such is backed with Java code.  We'll do more on MVC and beans later.|26:20|

## Material Review
- @Controller
- @RequestMapping
- @RequestParam
  - required
- @PathVariable
- @ModelAttribute
- Model
- xmlns:th="http://www.thymeleaf.org"
HTML insertions
- `${...}` : Variable expressions.
  - `${session.user.name}` = OGNL (Open Graph Notation Language)
- `*{...}` : Selection expressions - used to replace one item for another, eg. a parent
- `#{...}` : Message (i18n) expressions - found in the properties file - *not critical for course*
- `@{...}` : Link (URL) expressions.
- `~{...}` : Fragment expressions. - *not critical for course*

- extensions
  - `th:text` - will replace the text
  - `th:attrib` 
  - `th:utext`
  - `th:each` - `<li th:each= "book : ${books}>" iterating book which can be used beneath, for each item in the list books
  - `th:insert`
  - `th:replace`
  - `th:with`
  - `th:unless`
- operators
  - use of `?`
    - to supply a default value ( `(value) ?: (defaultvalue)`)
	- for if then (`(if) ? (then)`)
	- for ternary (`(if) ? (then) : (else)`)
  - `__` - preprocessor - eg `#{selection.__${sel.code}__}` where `{sel.code}` = "ALL" becomes `#{select.ALL}` before evaluating
	

## Workshop

### Thymeleaf Exercises

Solve all the exercises from Exercise 1 to 13 on http://itutorial.thymeleaf.org/

### Hello Templates

- Create a new Spring project using Spring initializer (add Spring MVC and Thymeleaf)
- Create a new package called com.greenfoxacademy in src/main/java
- Create a `HelloController` class and add a new action to this controller which is mapped to `/helloWorld`
- Add a new param called `name` to the action which is not required and its default is "Thymeleaf"
- Create a new template which body will be `<h1>Hello Thymeleaf</h1>` or `<h1>Hello {name}</>` if `name` is specified
- Extend the following and add the current date and time to the template

### Todos

- Extend the previous project and add a Todo (id:int, title:String, isUrgent:Boolean, isDone:Boolean) class
- Create a new controller called `TodoController` which maps to `/todo` (hint: @RequestMapping to Controller?)
- Add a new action which maps to `/` and `/list` to the previous controller
- Add [TodoService.java](workshop/TodoService.java) to the project (don't forget to specify the package)
- Add the following to the `TodoController` class:

  ```
  private TodoService todoService;

  @Autowired
  public TodoController(TodoService todoService){
    this.todoService = todoService;
  }
  ```
- Use `getTodos()` from `TodoService` to get all the Todos
- Create a new template in the `src/main/resources/templates/todo` folder and in its html body display the `todos` list (hint: `th:each`, `ul`)

### Extend Listing

- Extend the previous listing action with a parameter (querystring) for listing the active todos (parameter name can be `active`; active means !isDone)

### Todo Details View

- Extend the previous project and add a todo detail action and view
- On the detail page show the following attributes:
  - id
  - title
  - isUrgent (checkbox, disabled)
  - isDone (checkbox, disabled)
- It has to be accessible from an url like this: `http://localhost/todo/details/1` (1 is the id of the Todo)

### Create a Link

- Extend the previous project and create a link from the `list` page to the `details` page for every Todo

### Create an "Add New Todo" Page

- Extend the previous project and add a create todo view and action (hint: you need two different actions(GET, POST))
- After the user submitted the form and the Todo is saved then redirect to the `list` page
- Add a link to the `list` page which redirects to the `add new todo` page

#Links
- [Parent - Java Spring](../README.md)
- [Prior - Intro, Boot, HelloWorld](../intro-to-spring/README.md)
- [Next - Beans, Config](../ioc-bean/README.md)
