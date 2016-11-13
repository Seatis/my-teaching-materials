Extend the `Car` class alternative Constructors `method()`'s.

Setting the object with individual instructions is a pain().  We'd like to have alternatives.  So, if some values are not given, do 1 thing else another.  

We want to call the following method 

```
	Car myCar05 = new Car("Opel", "white", 1400, 25);
        Car myCar06 = new Car("VW", "grey"); // defaults to 1600 cc, 10 kms
        Car myCar07 = new Car(1100, 15); // defaults to a red Mazda
```

And then print.

```
This Mazda is red, has 1600 cc engine and clocked 12327 km's.
This Ford is silver, has 2500 cc engine and clocked 152312 km's.
This Beamer is green, has 2800 cc engine and clocked 42521 km's.
This Opel is white, has 1400 cc engine and clocked 25 km's;
This VW is is grey, has 1600 cc engine and clocked 10 km's;
This Mazda is red, has 1100 cc engine and cloced 15 km's;
```


