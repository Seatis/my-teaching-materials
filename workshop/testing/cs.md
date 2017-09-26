# Testing
*Trust, but verify.* - Ronald Reagan in speaking to Mikhail Gorbachev about an arms control treaty.

When coding, we start with the best intentions of covering all the eventualities.  But sometimes we miss things or our code evolves and no longer does what it was intended.

Several languages have a concept of automated testing.  These are separate collections from the code base which can be called (and stored with the project).

Testing generally involves running a method to see that such returns expected results.  As the testing grows in complexity, the testing system also has to have the means to impose logic.  For example, pre-fill some data, reset something, handle "exceptions" as the code is expected to complain/refuse to operate.

## Materials & Resources

### Material
| Material | Time |
|:-------- |-----:|
|[C# Tutorial - How to create NUnit Test | FoxLearn](https://www.youtube.com/watch?v=f2NrKazjWes)|4:16|
|[NUNIT](https://www.youtube.com/watch?v=ogIJHX-HcYs)|17:10|
|[Test-Driven Developement](https://www.youtube.com/watch?v=dWayn0QsJr8)|11:11|
|[TDD Basics with C#](https://www.youtube.com/watch?v=l4xhTq4qmC0)|23:27|


### Optional
| Material | Time |
|:-------- |-----:|
|[TDD: Don't Turn Off Your Brain](https://www.youtube.com/watch?v=6OQyv6CFbPo)|18:23|
|[MSTest Attributes as nUnit Attributes](https://blogs.msdn.microsoft.com/nnaderi/2007/02/01/comparing-the-mstest-and-nunit-frameworks/)|text|


## Material Review
- `[TestFixture]`
- `[Test]`, `[SetUp]`, `[TearDown]`
- `[Values()]`
- `Assert.AreEqual()`, `Assert.False()`, `Assert.True()`

## Workshop

### Class
```csharp
public class MessageUtil 
{
    private string message;

    public MessageUtil(string message) 
    {
        this.message = message;
    }

    public string PrintMessage() 
    {
        Console.Writeline(message);
        return message;
    }   
}  
```

### Test Case Class
```csharp
[TestFixture]
public class MessageUtilTests 
{
    [Test]
    public void PrintMessageTest() 
    {
        //arrange
        string message = "Hello World";
        var messageUtil = new MessageUtil(message);

        //act
        string output = messageUtil.PrintMessage();

        //assert
        Assert.AreEqual(message, output);
    }
}
```

## Exercises
- [Apples](apples/cs.md)
- [Sum](sum/cs.md)
- [Anagram](anagram/anagram.md)
- [Count Letters](count-letters/count-letters.md)
- [Fibonacci](fibonacci/fibonacci.md)
- [Extension](extension/cs.md)
- [Sharpie](sharpie/cs.md)
- [Animal](animal/animal.md)
- [Cows and Bulls](cows-and-bulls/cows-and-bulls.md)