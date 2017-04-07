# Solution to Workshop05 - Comparable

# Initial exercise
```java
import java.util.*;

public class App {

    public static void main(String[] args) {


        ArrayList<String> tvModels= new ArrayList<String>();
        tvModels.add("Samsung S19E200BW");
        tvModels.add("LG 19MB35D");
        tvModels.add("NEC MultiSync EA193Mi");
        tvModels.add("Asus VE198S");

        Collections.sort(tvModels);

        int i=0;
        for(String temp: tvModels){
            System.out.println("Model " + ++i + " : " + temp);
        }

    }


}
```
public class Model {

    private String name;
    private String size; // this is going to be the screen size
    private int    rtV4M; // rating from 1 to 9 as to Value-for-Money

    public Model(String name, String size, int rtV4M) {
        this.name = name;
        this.size = size;
        this.rtV4M = rtV4M;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public int getRtV4M() {
        return rtV4M;
    }

    public void setRtV4M(int rtV4M) {
        this.rtV4M = rtV4M;
    }

    public String toString () {
        return String.format("%s - %s diagonal (%d)", this.name, this.size, this.rtV4M);
    }

}

```

Then we tried this

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

Which failed.  Then we extended the class, adding 

```java
public class Model implements Comparable<Model> { 
...
    public int compareTo (Model compareModel) {
        int comparison = ((Model) compareModel).getRtV4M();
        return this.rtV4M - comparison;
    }
}
```

# Adding the comparator
*alt-Enter, and added java.util.Comparator, 

```java
import java.util.Comparator;

public class Model implements Comparable<Model>{

    private String name;
    private String size; // this is going to be the screen size
    private int    rtV4M; // rating from 1 to 9 as to Value-for-Money

    public Model(String name, String size, int rtV4M) {
        this.name = name;
        this.size = size;
        this.rtV4M = rtV4M;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public int getRtV4M() {
        return rtV4M;
    }

    public void setRtV4M(int rtV4M) {
        this.rtV4M = rtV4M;
    }

    public String toString () {
        return String.format("%s - %s diagonal (%d)", this.name, this.size, this.rtV4M);
    }

    public int compareTo (Model compareModel) {
        int comparison = ((Model) compareModel).getRtV4M();
        return this.rtV4M - comparison;
    }

    public static Comparator<Model> ModelNameComparator = new Comparator<Model>() {
        public int compare (Model model1, Model model2) {
            String left = model1.getName().toUpperCase();
            String right = model2.getName().toUpperCase();
            return left.compareTo(right);
        }
    };

}
```

And the App changed as follows:

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

        System.out.println("Now by ModelName Comparator");
        Arrays.sort(model, Model.ModelNameComparator);

        for( Model i: model) {
            System.out.println(i.toString());
        }


    }
}
```

The final step

```java
import java.util.Comparator;

public class Model implements Comparable<Model>{

    private String name;
    private String size; // this is going to be the screen size
    private int    rtV4M; // rating from 1 to 9 as to Value-for-Money

    public Model(String name, String size, int rtV4M) {
        this.name = name;
        this.size = size;
        this.rtV4M = rtV4M;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSize() {
        return size;
    }

    public void setSize(String size) {
        this.size = size;
    }

    public int getRtV4M() {
        return rtV4M;
    }

    public void setRtV4M(int rtV4M) {
        this.rtV4M = rtV4M;
    }

    public String toString () {
        return String.format("%s - %s diagonal (%d)", this.name, this.size, this.rtV4M);
    }

    public int compareTo (Model compareModel) {
        int comparison = ((Model) compareModel).getRtV4M();
        return this.rtV4M - comparison;
    }

    public static Comparator<Model> ModelNameComparator = new Comparator<Model>() {
        public int compare (Model model1, Model model2) {
            String left = model1.getName().toUpperCase();
            String right = model2.getName().toUpperCase();
            return left.compareTo(right);
        }
    };

    public static Comparator<Model> ModelSizeComparator = new Comparator<Model>() {
        public int compare (Model model1, Model model2) {
            String left = model1.getSize().toUpperCase();
            String right = model2.getSize().toUpperCase();
            return left.compareTo(right);
        }
    };

}

```

And the App changes.


```
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

        System.out.println("\nNow by ModelName Comparator");
        Arrays.sort(model, Model.ModelNameComparator);

        for( Model i: model) {
            System.out.println(i.toString());
        }

        System.out.println("\nNow by ModelSize Comparator");
        Arrays.sort(model, Model.ModelSizeComparator);

        for( Model i: model) {
            System.out.println(i.toString());
        }



    }
}
```

