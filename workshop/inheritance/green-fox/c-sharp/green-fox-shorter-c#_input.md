# Test input
```c#
ArrayList people = new ArrayList();

Person mark = new Person("Mark", 46, "male");
people.Add(mark);
Person jane = new Person();
people.Add(jane);
Student john = new Student("John Doe", 20, "male", "BME");
people.Add(john);
Student student = new Student();
people.Add(student);
Mentor gandhi = new Mentor("Gandhi", 148, "male", "senior");
people.Add(gandhi);
Mentor mentor = new Mentor();
people.Add(mentor);
Sponsor sponsor = new Sponsor();
Sponsor elon = new Sponsor("Elon Musk", 46, "male", "SpaceX");

student.SkipDays(3);

for (int i = 0; i < 5; i++) {
	elon.Hire();
}
for (int i = 0; i < 3; i++) {
	sponsor.Hire();
}

for(Person person : people) {
	person.Introduce();
	person.GetGoal();
}
```
