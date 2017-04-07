/* 
 * The Circle class models a circle with a radius and color.
 */
public class Circle {    // Save as "Circle.java"
   // The public constants
   public static final double DEFAULT_RADIUS = 8.8;
   public static final String DEFAULT_COLOR  = "red";
   
   // The private instance variables
   private double radius;
   private String color;
   
   // The (overloaded) constructors
   public Circle() {                   // 1st (default) Constructor
      this.radius = DEFAULT_RADIUS;
      this.color  = DEFAULT_COLOR;
   }
   public Circle(double radius) {      // 2nd Constructor
      this.radius = radius;
      this.color = DEFAULT_COLOR;
   }
   public Circle(double radius, String color) { // 3rd Constructor
      this.radius = radius;
      this.color = color;
   }
   
   // The public getters and setters for the private variables
   public double getRadius() {
      return this.radius;
   }
   public void setRadius(double radius) {
      this.radius = radius;
   }
   public String getColor() {
      return this.color;
   }
   public void setColor(String color) {
      this.color = color;
   }
 
   // The toString() returns a String description of this instance
   public String toString() {
      return "Circle[radius=" + radius + ", color=" + color + "]";
   }
 
   // Return the area of this Circle
   public double getArea() {
      return radius * radius * Math.PI;
   }
 
   // Return the circumference of this Circle
   public double getCircumference() {
      return 2.0 * radius * Math.PI;
   }
}