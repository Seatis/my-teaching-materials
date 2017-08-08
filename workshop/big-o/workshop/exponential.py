import time

# Let's play with exponential calculation
#
# - Can you find the largest fibonacci number your computer can handle?
# - Count the number of operations that the fibonacci function performs, display it too

def fibonacci (number):
    if (number <= 1):
        return number
    return fibonacci(number - 2) + fibonacci(number - 1)

nth_item = 10

start = time.process_time()

result = fibonacci( nth_item )

elapsed_time = time.process_time() - start

print( "The #{} fibonacci number is {} and it took {} sec to calculate".format( nth_item, result, elapsed_time ) )
