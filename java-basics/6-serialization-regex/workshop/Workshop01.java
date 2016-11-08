public static class Workshop01 {
  public static void main(String... args){
    Person person = new Person("John Doe", 23);
    // Serialize "person" to a file which has the following name: "person.ser"

  }
}

class Person implements Serializable {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return name + "-" + age;
    }
}
