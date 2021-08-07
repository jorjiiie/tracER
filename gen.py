import math
import random

random.seed(69)

NUM_TRIALS = 5000000
worst_case = 0
total_tries = 0 
for i in range(NUM_TRIALS):
	tries = 0
	while True:
		x = random.random() * 2 - 1
		y = random.random() * 2 - 1
		z = random.random()
		tries += 1
		if (x**2 + y ** 2 + z ** 2) <= 1:
			total_tries += tries
			if (tries > worst_case):
				worst_case = tries	
			break

print(total_tries/NUM_TRIALS,worst_case)