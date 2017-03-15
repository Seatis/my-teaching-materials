public class Car {

    //Add something here to create a car
    int sizeEngine;
    String color;
    int kmOdometer;
    String tyCar;

    public Car(){
        sizeEngine = 1600;
        color = "red";
    }

    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.tyCar = "Mazda";
        myCar.kmOdometer = 12312;

        Car myCar2 = new Car();
        myCar2.tyCar = "Ford";
        myCar2.color= "silver";
        myCar2.sizeEngine= 2500;
        myCar2.kmOdometer=152312;

        Car myCar3 = new Car();
        myCar3.tyCar = "Beamer";
        myCar3.color= "green";
        myCar3.sizeEngine= 2800;
        myCar3.kmOdometer=42521;

        System.out.printf("This %s is %s, has %d cc engine and clocked %d km's\n",
                myCar.tyCar, myCar.color,myCar.sizeEngine, myCar.kmOdometer);

        System.out.printf("This %s is %s, has %d cc engine and clocked %d km's\n",
                myCar2.tyCar, myCar2.color,myCar2.sizeEngine, myCar2.kmOdometer);

        System.out.printf("This %s is %s, has %d cc engine and clocked %d km's\n",
                myCar3.tyCar, myCar3.color,myCar3.sizeEngine, myCar3.kmOdometer);

    }
}