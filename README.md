*This project has been created as part of the 42 curriculum by danfern3*

# **Description**

This project consists of sorting a random integer sequence in the fewest movements possible.

The available movements are

|Movement|Key|Description|
|:---:|:---:|:---|
|swap a|**sa**|Swap the first 2 elements at the top of stack ***a***. Do nothing if there is only one element or none|
|swap b|**sb**|Swap the first 2 elements at the top of stack ***b***. Do nothing if there is only one element or none|
|---|**ss**|**sa** and **sb** at the same time|
|push a|**pa**|Take the first element at the top of ***b*** and put it at the top of ***a***. Do nothing if ***b*** is empty|
|push b|**pb**|Take the first element at the top of ***a*** and put it at the top of ***b***. Do nothing if ***a*** is empty|
|rotate a|**ra**|Shift up all elements of stack ***a*** by 1. The first element becomes the last one|
|rotate b|**rb**|Shift up all elements of stack ***b*** by 1. The first element becomes the last one|
|---|**rr**|**ra** and **rb** at the same time|
|reverse rotate a|**rra**|Shift down all elements of stack ***a*** by 1. The last element becomes the first one|
|reverse rotate b|**rrb**|Shift down all elements of stack ***b*** by 1. The last element becomes the first one|
|---|**rrr**|**rra** and **rrb** at the same time|
# **Benchmarks**
## Minimal project validation
- **100 numbers in under 1100 operations** and **500 numbers in under 8500 operations**.
- **100 numbers in under 700 operations** and **500 numbers in under 11500 operations**.
- **100 number in under 1300 operations** and **500 numbers in under 5500 operations**.

## Maximum project validation
- Sort **100 random numbers in fewer than 700 operations**.
- Sort **500 random numbers in no more than 5500 operations**.
# **Instructions**

## Clone the project and build it

```bash
git clone --recursive https://github.com/danielfdez17/push_swap.git && cd push_swap
```

> [!warning] If you have issues cloning the submodules, run `git config --global url."https://github.com/".insteadOf "git@github.com:"`
## Choose the compilation mode

### Build for fast execution
```bash
make all || make bonus
```

> [!info] Note: by default it's built for speed, so you can omit the BUILD_TYPE param
### Build for debugging
```bash
make all BUILD_TYPE=debug || make bonus BUILD_TYPE=debug
```

## Choose the algorithm

### Bucket sort
```bash
make all || make all SORT_ALGO=0
```

```bash
make bonus || make bonus SORT_ALGO=0
```

> [!info] Note: by default bucket sort is chosen 
### Radix sort
```bash
make all SORT_ALGO=1
```

```bash
make bonus SORT_ALGO=1
```

### Selection sort
```bash
make all SORT_ALGO=2
```

```bash
make bonus SORT_ALGO=2
```

## Tester

#### `push_swap_tester.sh`

There is a `push_swap_tester.sh` to benchmark the sorting algorithm.

1. Give the appropriate permissions to the tester: `chmod +x push_swap_tester.sh`
2. Execute the tester with at least two integer parameters: `bash ./scripts/42/push_swap/push_swap_tester.sh 100 10`. If it does not work, try: `sh ./scripts/42/push_swap/push_swap_tester.sh 100 10`
    - The first parameter indicates the number of times `./push_swap` will be called
    - The second parameter indicates the random number range
    - From the third parameter onwards, values are ignored

#### `single_test.sh`

There is also another test to check whether the random integer sequence is sorted using the output of the `push_swap` program.

1. Give the appropriate permissions to the tester: `chmod +x ./scripts/42/push_swap/single_test.sh`
2. Execute the tester with at least one integer sequence parameter: `./scripts/42/push_swap/single_test.sh 45 -100 95 0`. If it does not work, try: `sh ./scripts/42/push_swap/single_test.sh 45 -100 95 0`
    - The first parameter indicates the integer sequence to be sorted
    - From the second parameter on, values are ignored

# **Resources**

### Use of AI
- To check the syntax of the project files (source, headers, and docs files)
- To help me refactor the programs' compilation
- To help me achieve bucket sort best move calcs

### Useful links
- https://www.programiz.com/dsa/bucket-sort
