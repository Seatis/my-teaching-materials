public class Car {

    //Add something here to create a Car
    private int sizeEngine;
    private String color;
    private int kmOdometer;
    private String tyCar;

    public int getSizeEngine() {
        return sizeEngine;
    }

    public void setSizeEngine(int sizeEngine) {
        this.sizeEngine = sizeEngine;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getKmOdometer() {
        return kmOdometer;
    }

    public void setKmOdometer(int kmOdometer) {
        this.kmOdometer = kmOdometer;
    }

    public String getTyCar() {
        return tyCar;
    }

    public void setTyCar(String tyCar) {
        this.tyCar = tyCar;
    }

    public Car(){
        sizeEngine = 1600;
        color = "red";
    }

}

public class Workshop01 {

    public static void main(String[] args) {
        Car myCar = new Car();
        myCar.setTyCar("Mazda");
        myCar.setKmOdometer (12312);

        
        Car myCar2 = new Car();
        myCar2.setTyCar("Ford");
        myCar2.setColor("silver");
        myCar2.setSizeEngine( 2500);
        myCar2.setKmOdometer(152312);

        Car myCar3 = new Car();
        myCar3.setTyCar ("Beamer");
        myCar3.setColor("green");
        myCar3.setKmOdometer(2800);
        myCar3.setKmOdometer(42521);

        System.out.printf("This %s is %s, has %d cc engine and clocked %d km's\n",
                myCar.getTyCar(), myCar.getColor(),myCar.getSizeEngine(), myCar.getKmOdometer());

        System.out.printf("This %s is %s, has %d cc engine and clocked %d km's\n",
                myCar2.getTyCar(), myCar2.getColor(),myCar2.getSizeEngine(), myCar2.getKmOdometer());

        System.out.printf("This %s is %s, has %d cc engine and clocked %d km's\n",
                myCar3.getTyCar(), myCar3.getColor(),myCar3.getSizeEngine(), myCar3.getKmOdometer());

    }

}
