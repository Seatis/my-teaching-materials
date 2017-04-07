public class Car {

    private static int countCar = -1;

    //Add something here to create a car
    private int sizeEngine;
    private String color;
    private int kmOdometer;
    private String tyCar;

    public static int getCount() {
        return countCar;
    }

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
        countCar++;
    }

}