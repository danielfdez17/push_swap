#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

/**
 * Executes a move on the stacks a and b based on the input string @param move.
 * The function compares the input string with the possible moves
 * (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) and performs
 * the corresponding operation on the stacks. If the input string
 * does not match any of the valid moves, the function returns false,
 * indicating an invalid move. Otherwise, 
 * it returns true after executing the move.
 * @param a The first stack to perform the move on
 * @param b The second stack to perform the move on
 * @param move The string representing the move to be executed
 * @return true if the move is valid and executed, false otherwise
 */
bool	execute_move(t_stack *a, t_stack *b, char *move);

/**
 * Reads moves from the standard input and executes them on the stacks a and b.
 * The function continuously reads lines from the standard input until
 * there are no more lines to read. For each line read, it calls the
 * execute_move function to perform the corresponding move on the stacks.
 * If an invalid move is encountered, it prints an error message
 * to the standard error and stops reading further moves.
 * @param a The first stack to perform the moves on
 * @param b The second stack to perform the moves on
 */
void	read_moves(t_stack *a, t_stack *b);

#endif // CHECKER_BONUS_H