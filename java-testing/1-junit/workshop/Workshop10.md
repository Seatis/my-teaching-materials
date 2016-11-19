# Workshop10 - Using @Before and @After

Add to your main the following classes and ensure that they execute accordingly in your testing

```java
		    public static void onceExecutedBeforeAll() {
		        System.out.println("@BeforeClass: onceExecutedBeforeAll");
		    }
		 
		    public void executedBeforeEach() {
		        WordToolbox W = new WordToolbox("Muppets");
		        System.out.println("@Before: executedBeforeEach");
		    }

		    public static void onceExecutedAfterAll() {
		        System.out.println("@AfterClass: onceAfterAll");
		    }
		 
		    public void executedAfterEach() {
			W = null;
		        System.out.println("@After: executedAfterEach");
		    }

```

Expectations are something like this (not tested yet).

```	 
@BeforeClass: onceExecutedBeforeAll
@Before: executedBeforeEach
@Test: testwhatever
@After: executedAfterEach
@Before: executedBeforeEach
@Test: testwhatever
@After: executedAfterEach
@AfterClass: onceAfterAll
```