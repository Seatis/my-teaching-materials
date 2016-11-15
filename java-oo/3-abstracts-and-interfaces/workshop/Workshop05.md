#Workshop05 - Comparator/Comparable
Comparing 2 elements using OO differs from what we would do with primitives.  Of course, it's easy to see that 2 < 3 or that 15==15.  But what happens when its a collection of LCD TVs on sale on argep.hu?

Let's first refresh, what do we know about sorting lists?

Sort the following list.

```java
List<String> tvModels= new ArrayList<String>();

tvModels.add("Samsung S19E200BW");
tvModels.add("LG 19MB35D");
tvModels.add("NEC MultiSync EA193Mi");
tvModels.add("Asus VE198S");

//do something here

//write the output now

```
*_hints_ *
- if it's not compiling for you, did you remember *psvm*?
- remember to *import* the right library?

We should get the following:-
```
Model 1 : Asus VE198S
Model 2 : LG 19MB35D
Model 3 : NEC MultiSync EA193Mi
Model 4 : Samsung S19E200BW
```

## What when we're working with *Objects*
So let's create a class of tvModels (as we now know something about OO).

+ fields
  - String name
  - String size // this is going to be the screen size
  - int rtV4M // rating from 1 to 9 as to teh Value-for-Money
+ constructor `public Model(String name, String size, int rtV4M)`
+ toString "%s - %s diagonal (%d)" for name, size and rtV4M.

And let's do the following.  We cannot use collection, but sort does work:-

```java
import java.util.*;

public class App {

    public static void main(String[] args) {

        Model[] model = new Model[4];
        model[0]= new Model("Samsung S19E200BW", "19", 5);
        model[1]= new Model("LG 19MB35D", "18", 2);
        model[2]= new Model("NEC MultiSync EA193Mi", "18",8);
        model[3]= new Model("Asus VE198S", "17", 6);

        Arrays.sort(model);

        for( Model i: model) {
            System.out.println(i.toString());
        }
    }
}
```

You should get an error.

```
Exception in thread "main" java.lang.ClassCastException: Model cannot be cast to java.lang.Comparable
	at java.util.ComparableTimSort.countRunAndMakeAscending(ComparableTimSort.java:320)
	at java.util.ComparableTimSort.sort(ComparableTimSort.java:188)
	at java.util.Arrays.sort(Arrays.java:1246)
	at App.main(App.java:13)
...
```

*What's the problem?*

To sort Objects, you have to implement the _Comparable_ interface and then override the _compareTo()_ method.  

How? Look up the `implements Comparable<T>`.

You'll see that you need to both amend the header of the Class, and add a method `compareTo()`.

```java
public class .... {

...
  public int compareTo (Model compareModel) { 
  ...
  }
}
```

Now when `sort` runs, it has a means to compute a ranking of the items it's comparing.

When this works, you should get the following output.

```
LG 19MB35D - 18 diagonal (2)
Samsung S19E200BW - 19 diagonal (5)
Asus VE198S - 17 diagonal (6)
NEC MultiSync EA193Mi - 18 diagonal (8)
```

## Use a `Comparator`
Google the following `class implements Comparable<T>`.  

This is another way that the comparison can be done.  Adding this will give you some alternatives to just the 1 sort.

Note that you'll keep the `compareTo()` function, but you'll also add a `Comparator<>` static method; this will allow you to chose to sort by say the name.

This is a trickier bit of code... You can try to figure it out with Google, or peek below.

> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *
> *

```java
    public static Comparator<Model> ModelNameComparator = new Comparator<Model>() {
        public int compare (Model model1, Model model2) {
            String left = model1.getName().toUpperCase();
            String right = model2.getName().toUpperCase();
            return left.compareTo(right);
        }
    };
```

You'll need to modify the `sort` to now reference the new `ModelNameComparator`.

The output should be 
```
Asus VE198S - 17 diagonal (6)
LG 19MB35D - 18 diagonal (2)
NEC MultiSync EA193Mi - 18 diagonal (8)
Samsung S19E200BW - 19 diagonal (5)
```

## Finally 
Implement one last comparator, a `ModelSizeComparator`, you should get the following:

```
Now by ModelSize Comparator
Asus VE198S - 17 diagonal (6)
LG 19MB35D - 18 diagonal (2)
NEC MultiSync EA193Mi - 18 diagonal (8)
Samsung S19E200BW - 19 diagonal (5)
```
## Closing observations
You'll notice that you don't get an option of Ascending or Descending.  To do that you have to implement a separate function and just reverse comparing from left to right, to right to left.





