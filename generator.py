import random
import sys


def grn(min_val, max_val):
	if min_val > max_val:
		min_val, max_val = max_val, min_val
	# sample the inclusive range so negatives work correctly
	nums = random.sample(range(min_val, max_val + 1), max_val - min_val + 1)
	print(*nums)


def main(min_val, max_val):
	"""Main entry: takes min and max as parameters and prints the random list."""
	grn(min_val, max_val)


if __name__ == "__main__":
	if len(sys.argv) != 3:
		print("Usage: generator.py MIN MAX")
		sys.exit(1)
	try:
		min_val = int(sys.argv[1])
		max_val = int(sys.argv[2])
	except ValueError:
		print("MIN and MAX must be integers")
		sys.exit(1)
	main(min_val, max_val)
