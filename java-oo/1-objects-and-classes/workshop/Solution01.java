public class Car {

    //Add something here to create a car
    int sizeEngine;
    String color;

    public Car(){
        this.sizeEngine = 1600;
        this.color = "red";
    }

    public static void main(String[] args) {
        Car myCar = new Car();
        System.out.printf("Just got a new Car, it's %s and has a %d cc Engine!\n",
                "puke", 1 // replace this stuff with the way we get those attributes about myCar
        );
        System.out.printf("Just got a new Car, it's %s and has a %d cc Engine!\n",
                myCar.color, myCar.sizeEngine // replace this stuff with the way we get those attributes about myCar
        );

    }
}