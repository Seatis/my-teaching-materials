# Interview questions Workshop

## General
- What is a design pattern?
- Design patterns - What is the ... pattern?
    - Singleton
    - Factory
    - Builder
    - Prototype
    - Adapter
    - Iterator
    - MVC
    - Chaining
- In an integer array, there is 1 to 100 number, out of one is duplicate, how to find?
- What is the difference between Stack and Queue data structure?
- What is binary search tree?
- What is a Link?
- What is a LAN?
- What are the layers of the OSI reference model?
- What is data encapsulation?
- What is DoS?
- What are MAC addresses?
- What is DHCP?
- What is Ping?
- What is IPv6?

## General Java
- What is JVM? Why is Java called the ‘Platform Independent Programming Language’?
- What is the Difference between JDK and JRE?
- What are the Data Types supported by Java? What is Autoboxing and Unboxing ?
- What is Constructors, Constructor Overloading in Java and Copy-Constructor?
- What is the difference between Throw and Throws in Java Exception Handling?
- Does Java support multiple inheritance ?
- What are pass by reference and pass by value ?
- What are the basic interfaces of Java Collections Framework ?
- What is difference between Array and ArrayList ? When will you use Array over ArrayList ?
- What's the difference between an ArrayList and a LinkedList?
- How can you use Comparator and Comparable?
- What is JDBC ?

## Java Tricks Questions
- Can you override a private or static method in Java?
- What will happen if you put return statement or System.exit () on try or catch block? Will finally block execute?
- What do the expression 1.0 / 0.0 will return? will it throw Exception? any compile time error?
- Does Java support multiple inheritances?
- What is the issue with following implementation of compareTo() method in Java
```java
private int id;

public int compareTo(Object o){
   Employee emp = (Employee) o;
   return this.id - e.id;
}
```
- What is the difference between String, StringBuffer and StringBuilder in Java?
- How many objects are created here?
```java
String s = new String("abc");
```
- What is the difference between final, finalize and finally?
- How does Garbage Collection prevent a Java application from going out of memory?
- `int a = 1L;` Won’t compile and `int b = 0; b += 1L;` compiles fine. Why?
- Is Empty .java file name a valid source file name?
- What is the default value of the local variables?
- Can you use this() and super() both in a constructor?
- What's the difference between method Overloading and Overriding?
- Is it possible to instantiate an abstract class?
- Is it possible to instantiate an interface?
- What is the return type of this method?
```java
public abstract int[] foo(int[] arg)[][][][][][][][][][][];
```

### What's get printed out?
```java
public class Test {
  public static void main(String[] args) {
    System.out.println(Math.min(Double.MIN_VALUE, 0.0d));
  }
}
```

```java
public class Test {
  public static void main(String[] args) throws Exception {
    char[] chars = new char[] {'\u0097'};
    String str = new String(chars);
    byte[] bytes = str.getBytes(); System.out.println(Arrays.toString(bytes));
  }
}
```

```java
final double d = 1 / 2;
System.out.println(d);
```

```java
final List<Integer> list = new ArrayList<>();

list.add(1);
list.add(2);
list.add(3);

list.remove(2);
System.out.println(list);
```

```java
public class Test
{
    public static void main(String[] args)
    {
        Integer a = 1000, b = 1000;
        System.out.println(a == b);

        Integer c = 100, d = 100;
        System.out.println(c == d);
    }
}
```

```java
public static void main() {
  int x = 1;
  methodTwo(x);
  System.out.println(x);
}

public static void methodTwo(int i) {
  i++;
}
```

### Java WAT

```java
Object o = true ? 'a' : new Float(1);
System.out.println(o);
System.out.println(o.getClass());
```

```java
int[] a = { , };
System.out.println(a.length);
```

```java
public class Foo {
    public static String wat(String arg) {
        return arg + arg;
    }
}

Foo myFoo = null;
System.out.println(myFoo.wat("wat"));
```

```java
System.out.println("a.b.c".replace(".", "/"));
System.out.println("a.b.c".replaceAll(".", "/"));
```
