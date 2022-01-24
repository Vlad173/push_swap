# push_swap (school 21)

### Project finished (125%)

The purpose of this project is to create sorting algorithm.

<img src="https://user-images.githubusercontent.com/71993796/150856328-0a045e27-cfe3-427c-ba52-5a621ff469f3.gif" width="500" />

# Rules
- There are 2 stacks:
    - the stack **a** contains a random amount of negative and/or positive numbers
which cannot be duplicated.
    - **b** is empty
- The goal is to sort in ascending order numbers into stack **a** using a minimum of operations
-  To do this you have the following operations at your disposal:
    - sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
    - sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
    - ss : sa and sb at the same time.
    - pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
    - pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
    - ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
    - rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
    - rr : ra and rb at the same time.
    - rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
    - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
    - rrr : rra and rrb at the same time.

You can find more informaton about the task [here](https://github.com/Vlad173/school21/blob/master/subjects/push_swap.pdf)

## Brief explanation of my algorithm

* Step 1: Find the max, min and median value in the A and push everything except them into stack B.
* Step 2: Sort stack A.
* Step 3: Find X in B, which will require a minimum of operations to push it into A without breaking the sorting order.
* Step 4: Push X into stack A.
* Step 5: If stack B is not empty go to step 3.
* Step 6: Shift all the elements of stack A to sort it completely

## Visualization 

![Jan-24-2022 23-00-20](https://user-images.githubusercontent.com/71993796/150855662-438524f1-8f66-4fe9-ba99-215c7ec36cad.gif)

## Benchmarks

To test my push_swap I used this [tester](https://github.com/lmalki-h/push_swap_tester)

Result of solving 1000 cases with 100 numbers:

<img src="https://user-images.githubusercontent.com/71993796/150852700-2e437063-cc76-4258-89f9-e3d78cd7ab0c.png" width="600" />

Result of solving 100 cases with 500 numbers:

<img src="https://user-images.githubusercontent.com/71993796/150853493-321c79ff-2d66-4c40-835c-66c3762c2e9a.png" width="600" />

Feel free to clone and test this algorithm :)
