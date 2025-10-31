import random


def generate_random_numbers(min_val, max_val):
	"""Return a randomly shuffled list of integers from min_val to max_val inclusive."""
	if min_val > max_val:
		min_val, max_val = max_val, min_val
	return random.sample(range(min_val, max_val + 1), k=(max_val - min_val + 1))

def main(min_val, max_val):
	"""Main entry: takes min and max as parameters and returns the random list."""
	return generate_random_numbers(min_val, max_val)

if __name__ == "__main__":
	numbers = main(0, 10)
	print(" ".join(map(str, numbers)))
