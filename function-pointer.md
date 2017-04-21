Function Pointer Exercise
=========================

Overview
--------

This is an exercise meant to give you an opportunity to use function pointers.

There are other ways to solve this problem, but I want to see function
pointer used.

I want to see a program that reads a text document line-by-line, parses out
the instructions, works out the right order to do them in, and executes them,
printing the correct answer at the end.

Detailed Specification
----------------------

Starting from 0, perform instructions in order until you run out of
instructions, and then print the result.

The structure of the input is:

<pre>
1 add 4
3 subtract 3
2 multiply 6
4 add -3
</pre>

The first word is always a positive integer, starting from 1.

The second word is "add", "subtract" or "multiply".

The third word is an integer that may be negative.

The words are all separated by one space.

Hints
-----

### fscanf

fscanf (see `man 3 fscanf`) is a useful function for parsing instructions in
that format.

### operation function signatures

Every operation has the exact same function signature:
<pre>
int operation(int current_num, int applied_num)
</pre>
(where it takes current_num as the number before it performs the operation,
applied_num as the number to apply to the operation, and returns the number
after performing the operation)

### structs

I would recommend storing the parsed information in a struct, e.g.
<pre>
struct operation
{
  unsigned int pos;
  int (*operation)(int, int);
  int operand;
};
</pre>

### sorting

You will need to store these operations in an array and sort them to perform
them in the correct order.

I recommend using qsort (see `man 3 qsort`).

Qsort takes a function pointer as an argument. The comparison function will
probably look something like:

<pre>
int operator_comparator(const void *first_arg, const void *second_arg)
{
  struct operation *first = first_arg; //   convert the void pointer to a
  struct operation *second = second_arg; // struct operation pointer.

  // This is a bit intricate, the comparator expects a negative result when
  // the first arg is LESS than the second, a positive result when the first
  // arg is GREATER than the second, and zero when they're equal.
  // First minus second happens to match this criteria.
  return first->pos - second->pos;
}
</pre>

If it comes out in the wrong order, just switch the way round you compare
things, I rarely get it right the first time.

### Helpful reading

http://www.cprogramming.com/tutorial/function-pointers.html has examples of
using function pointers in general, and qsort in particular.

You might find http://www.cprogramming.com/tutorial/lesson7.html useful, too,
if you're having difficulty with structs.
