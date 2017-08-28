import time

# This is a simple demonstration on how to measure execution time
# Try changing num_of_iterations to see how it affects running time

# Which O would it be?

c = 0
num_of_iterations = 500000
start = time.process_time()

for i in range( num_of_iterations ):
    c += 1

elapsed_time = time.process_time() - start

print(elapsed_time)
