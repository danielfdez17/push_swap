#!/bin/sh

# ! This script is used to test the functionality of the project.
# ! It runs a series of tests and outputs the results.

# ? Utils
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;36m'
ORANGE='\033[0;33m'
NC='\033[0m' # ? No Color
WARNING=$YELLOW'[WARNING]'
INFO=$BLUE'[INFO]'
OK=$GREEN'[OK]'
ERROR=$RED'[KO]'
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

clear
log_warning "Making sure ./push_swap and ./checker are up to date"
make bonus

generate_numbers() {
	if [ -z "$1" ]; then
		max=100
	else
		max=$1
	fi
	seq -$max $max | shuf | head -n $max | tr "\n" " "
	# shuf -i 1-$max -n $max | tr "\n" " "
}

test_n() {
	n=$1
	limit=$2
	ok_iterations=0
	bad_iterations=0
	ok_checker=0
	ko_checker=0
	total_moves=0
	max_moves=0
	min_moves=999999
	log_info "Running $iterations iterations with $n numbers..."
	echo $YELLOW"MOVEMENTS \t| IS SORTED \t| GENERATED NUMBERS" $NC
	for i in $(seq 1 $iterations); do
		numbers=$(generate_numbers $n)
		moves=$(echo $numbers | xargs ./push_swap | wc -l)
		checker_result=$(echo $numbers | xargs ./push_swap | ./checker $numbers)
		max_moves=$((moves > max_moves ? moves : max_moves))
		min_moves=$((moves < min_moves ? moves : min_moves))
		if [ $checker_result = "OK" ]; then
			checker_result="$OK OK $NC"
			ok_checker=$((ok_checker + 1))
		else
			checker_result="$ERROR KO $NC"
			ko_checker=$((ko_checker + 1))
		fi
		total_moves=$((total_moves + moves))
		# ? Check if the number of moves is greater than the limit
		if [ $moves -gt $limit ]; then
			log_error "$moves moves\t| $checker_result\t|$BLUE numbers: $numbers $NC"
			bad_iterations=$((bad_iterations + 1))
		else
			log_ok "$moves moves\t| $checker_result\t|$BLUE numbers: $numbers $NC"
			ok_iterations=$((ok_iterations + 1))
		fi
	done
	percentage_ok=$(awk "BEGIN {printf \"%.2f\", ($ok_iterations/$iterations)*100}")
	percentage_ko=$(awk "BEGIN {printf \"%.2f\", ($bad_iterations/$iterations)*100}")
	checker_percentage_ok=$(awk "BEGIN {printf \"%.2f\", ($ok_checker/$iterations)*100}")
	checker_percentage_ko=$(awk "BEGIN {printf \"%.2f\", ($ko_checker/$iterations)*100}")
	log_info "Summary for $n numbers in $iterations iterations."
	log_info "=========PUSH_SWAP========="
	log_info "$GREEN$percentage_ok% OK$NC, $RED$percentage_ko% KO"
	log_info "=========CHECKER========="
	log_info "$GREEN$checker_percentage_ok% OK$NC, $RED$checker_percentage_ko% KO"
	log_info "=========STATISTICS========="
	log_info "Average moves: $(awk "BEGIN {printf \"%.2f\", $total_moves/$iterations}")"
	log_info "Max moves: $max_moves; Max moves allowed: $limit"
	log_info "Min moves: $min_moves"
}

start() {
	# ? Check if at least 2 integer arguments were provided
	if [ $n -le 5 ]; then
		test_n $n 12
	elif [ $n -le 100 ]; then
		test_n $n 700
	elif [ $n -le 500 ]; then
		test_n $n 5500
	else
		test_n $n $n
	fi
}

# ? Check if ./push_swap exists
if [ ! -f "./push_swap" ]; then
	log_error "Error: ./push_swap not found. Please compile the project first."
	exit 1
fi

# ? Check if the first argument is provided, if not set it to 100
if [ -z $1 ]; then
	iterations=100
else
	iterations=$1
fi

# ? Check if the second argument is provided, if not set it to 100
if [ -z $2 ]; then
	n=100
else
	n=$2
fi

start