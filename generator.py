import random


def grn(min_val, max_val):
	nums = random.sample(range(500),500)
	print(*nums)

# def generate_random_numbers(min_val, max_val):
# 	"""Return a randomly shuffled list of unique integers from min_val to max_val inclusive."""
# 	if min_val > max_val:
# 		min_val, max_val = max_val, min_val
# 	nums = list(range(min_val, max_val + 1))
# 	random.shuffle(nums)
# 	return nums

def main(min_val, max_val):
	"""Main entry: takes min and max as parameters and returns the random list."""
	grn(min_val, max_val)
	# return generate_random_numbers(min_val, max_val)

if __name__ == "__main__":
	numbers = main(0, 500)
	# print(" ".join(map(str, numbers)))
