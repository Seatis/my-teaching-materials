# Testing
*Trust, but verify.* - Ronald Reagan in speaking to Mikhail Gorbachev about an arms control treaty.

When coding, we start with the best intentions of covering all the eventualities.  But sometimes we miss things or our code evolves and no longer does what it was intended.

Several languages have a concept of automated testing.  These are separate collections from the code base which can be called (and stored with the project).

Testing generally involves running a method to see that such returns expected results.  As the testing grows in complexity, the testing system also has to have the means to impose logic.  For example, pre-fill some data, reset something, handle "exceptions" as the code is expected to complain/refuse to operate.

## Materials & Resources
| Material | Time |
|:---------|-----:|
| [Understanding Unit Testing](https://jeffknupp.com/blog/2013/12/09/improve-your-python-understanding-unit-testing) | 15-30 min reading |
| [Unittest - Getting Started - video](https://www.youtube.com/watch?v=0Keq3E2bbeE) | 5:07 |
| [Testing Your Code](http://docs.python-guide.org/en/latest/writing/tests/) Just focus on the general rules of testing | 5 min reading |
| [Beginning Test-Driven Development in Python](http://code.tutsplus.com/tutorials/beginning-test-driven-development-in-python--net-30137) | 30 -45 min reading |


## Material Review
- Unit Testing
- Assertions
    - equals
    - true or false
    - in
    - not
    - raise
- What should you test?
- How should you name your test?
- What is TDD?

## Workshop

```python
import unittest

class TestStringMethods(unittest.TestCase):

    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)

if __name__ == '__main__':
    unittest.main()
```

### The Big Testing

#### Setting up environment
- create a file named as `your_name_work.py`, and work in that file
- create the following methods in that file
- create a `your_name_test.py` where these methods are tested

### Exercises
- [Apples](apples/python.md)
- [Sum](sum/python.md)
- [Anagram](anagram/anagram.md)
- [Count Letters](count-letters/count-letters.md)
- [Fibonacci](fibonacci/fibonacci.md)
- [Extension](extension/extension.md)
- [Sharpie](sharpie/python.md)
- [Animal](animal/animal.md)
- [Cows and Bulls](cows-and-bulls/cows-and-bulls.md)