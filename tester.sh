#!/bin/sh

# This script is used to test the functionality of the project.
# It runs a series of tests and outputs the results.

# ? Utils
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
ORANGE='\033[0;33m'
NC='\033[0m' # No Color
WARNING=$YELLOW'[WARNING]'
INFO=$BLUE'[INFO]'
OK=$GREEN'[OK]'
ERROR=$RED'[ERROR]'
TODO=$ORANGE'[TODO]'

log_info() {
	echo $INFO "$1" $NC
}

log_ok() {
	echo $OK "$1" $NC
}

log_error() {
	echo $ERROR "$1" $NC
}

log_warning() {
	echo $WARNING "$1" $NC
}

log_todo() {
	echo $TODO "$1" $NC
}

make all --no-print-directory
# make re --no-print-directory

generate_numbers() {
	if [ -z "$1" ]; then
		max=100
	fi
	max=$1
	shuf -i 1-$max -n $max | tr "\n" " "
}

push_swap() {
	# numbers=$(generate_numbers $1)
	# if [ -z "$2" ]; then
	# 	echo $numbers
	# fi
	# log_info "Testing with $1 numbers..."
	movs=$(generate_numbers $1 | xargs ./push_swap | wc -l)
	# log_ok "Number of moves: $movs"
	echo $movs
}

test() {
	log_info "Running tests..."
	push_swap 6
	push_swap 10
	push_swap 100
}

if [ -z "$1" ]; then
	log_warning "No argument provided. Defaulting to 100."
	read -p "Enter the number of iterations (default: 100): " iterations
	if [ -z "$iterations" ]; then
		iterations=100
	fi
else
	iterations=$1
fi

total_iterations=$iterations
ok_iterations=0
bad_iterations=0
log_info "Running $iterations iterations with 6 numbers..."
for i in $(seq 1 $iterations); do
	moves=$(push_swap 6)
	# Check if the number of moves is greater than 12
	if [ $moves -gt 12 ]; then
		# log_error "Iteration $i: $moves moves (exceeds 12)"
		bad_iterations=$((bad_iterations + 1))
	else
		# log_ok "Iteration $i: $moves moves"
		ok_iterations=$((ok_iterations + 1))
	fi
done
percentage=$(awk "BEGIN {printf \"%.2f\", ($ok_iterations/$total_iterations)*100}")
log_ok "$percentage% iterations passed"
percentage=$(awk "BEGIN {printf \"%.2f\", ($bad_iterations/$total_iterations)*100}")
log_error "$percentage% iterations failed"


# push_swap 10
# push_swap 100