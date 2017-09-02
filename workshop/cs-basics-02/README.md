# C# Basics II
*Introduction to Entity Framework and Unit Testing in C#*

## Materials & Resources
### Resources
Preparation:
- Install MySQL for your computer - you'll need to have admin rights to your pc;
- [MySQL Community Server](https://dev.mysql.com/downloads/mysql/)
- Add MySQL Workbench

### Materials
| Material | Time |
|:---------|-----:|
| [Nuget Package Manager](https://www.youtube.com/watch?v=F8sx49NdCNk) | 5:35 |
| [Entity Framework from Scratch](https://www.youtube.com/watch?v=ZX7_12fwQLU) | 27:56 |
| [Unit Testing in C#](https://msdn.microsoft.com/en-us/library/hh694602.aspx) | Text |

### Optional
| Material | Time |
|:---------|-----:|
| [C# Unit Testing](https://www.youtube.com/watch?v=8YFZBNFm0OM) | 59:01 |

## Material Review
 - NuGet
 - Test Class
 - Test Method
 - Test Initialize
 - ExpectedException
 - Entity Framework
   - Database-First
   - Code-First
   - (Model-First)

## Workshop

### Testing
```cs
[TestMethod]  
public void Withdraw_ValidAmount_ChangesBalance()  
{  
    // arrange  
    double currentBalance = 10.0;  
    double withdrawal = 1.0;  
    double expected = 9.0;  
    var account = new CheckingAccount("JohnDoe", currentBalance);  
    // act  
    account.Withdraw(withdrawal);  
    double actual = account.Balance;  
    // assert  
    Assert.AreEqual(expected, actual);  
}  
  
[TestMethod]  
[ExpectedException(typeof(ArgumentException))]  
public void Withdraw_AmountMoreThanBalance_Throws()  
{  
    // arrange  
    var account = new CheckingAccount("John Doe", 10.0);  
    // act  
    account.Withdraw(20.0);  
    // assert is handled by the ExpectedException  
}  
```
- [Anagram](../testing/anagram/anagram.md)
- [Count Letters](../testing/count-letters/count-letters.md)
- [Fibonacci](../testing/fibonacci/fibonacci.md)
- [Animal](../testing/animal/animal.md)
- [Cows and Bulls](../testing/cows-and-bulls/cows-and-bulls.md)

### Database
- [TODO App](./workshop/todo.md)