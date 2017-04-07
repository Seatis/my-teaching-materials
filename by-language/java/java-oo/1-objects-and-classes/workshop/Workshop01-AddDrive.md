Extend the `Car` class with `method()`.

Taking the `getter`/`setter` concept to the next level, we can now offer *other* means to manipulate data associated with the class.  In this situation, we want to change the odometer each time somebody drives the car.

As from before, you now are adding stuff in both Workshop01 (to the main) as well as the class.

We want to call the following method 

	Car.drive(15); // drive the specific car 15 kms, sends out the message "brrrm, just drove around town 15 clicks
        System.out.printf("The %s %s odometer now shows %d", //you know the drill

When the "car" drives, we get a message:-
- for <20 km, "brrm, ZY just drove around town x clicks."
- for <50 km, "brrm, screech, brrm, screech; ZY commuted x clicks."
- else "whee, ZY x clicks."

```
The brrm, the red Mazda just drove around town 15 clicks.
This Mazda is red, has 1600 cc engine and clocked 12327 km's.
This Ford is silver, has 2500 cc engine and clocked 152312 km's.
This Beamer is green, has 2800 cc engine and clocked 42521 km's.
```

At your discretion, test out the Beamer doing 49 km and Ford doing 1200.

