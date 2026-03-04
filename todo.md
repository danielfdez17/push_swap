- [x] Script to test and benchmark my push_swap
- [x] Update the Makefile as transcendence/mini-baas/Dylan's Makefiles
- [x] Update parser to split every argument the program receives. This will make the program handle strange inputs like:
	* ./push_swap 1 2 4 -1 -29
	* ./push_swap "1 2 4 -1 -29"
	* ./push_swap "1" "2 4 -1 -29" 0 "23   19"
