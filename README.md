*This project has been created as part of the 42 curriculum by danfern3*

# **Description**

This project consists of sorting a random integer sequence in the less amount of movements as possible.

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

# **Instructions**

Clone the project and build it

```bash
git clone https://github.com/danielfdez17/push_swap.git && cd push_swap && make bonus
```

## Testers

#### `tester.sh`

There is a `tester.sh` to benchmark the sorting algorithm.

1. Give the appropiate permissions to the tester: `chmod +x tester.sh`
2. Execute the tester with at least integer params: `./tester.sh 100 10`. If it does not work, try with: `sh tester.sh 100 10`
    - The first param indicates the number of times the ./push_swap will be called
    - The second param indicates the random generated number
    - From the third param on, they will be dismissed

#### `single_test.sh`

There is also another test to check only if the random integer sequence is sorted with the output of the `push_swap` program.

1. Give the appropiate permissions to the tester: `chmod +x single_test.sh`
2. Execute the tester with at least integer params: `./single_test.sh "45 -100 95 0"`. If it does not work, try with: `sh single_test.sh "45 -100 95 0"`
    - The only first param indicates the integer sequence to be sorted
    - From the second param on, they will be dismissed

# **Resources**

### Use of AI
- To check the syntax of the project files (source, headers, and docs files)
- To help me 

### Useful links
- https://www.programiz.com/dsa/bucket-sort