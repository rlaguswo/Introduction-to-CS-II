Name: Hyunjae Kim
ONID: kimh6
Section: CS162 001 U 2020
Assignment4, due 08/14/2020

Description: This program is about linked list, and has several functions which is using linked list. You can add some element or sort the list. Even you can count prime numbers in the list.

Instruction:

1)Compile the program
  1>make clean
  2>make
  
 2) Run the program
   ./driver
   
 3) When you run the program, the only thing which you have to do is just pressing enter. First, the program will show you the length of the list, and the elements of the list, which is empty. 
     Then the program will ask you to press the enter. Then it will go to the next function which is push front. It will add some elements to the front of the list, then it will show you. After that it will ask you to press enter.
     Then the program will go to the next function print back, and it  will add some element to the back of the list. Then it will show you. Then you can press enter in order to go to the next step.
     The program will add some elements to the specific index of the list, and then it will show you the result. Then you can press enter in order to go to next step.
     The program will sort the list as ascending order, and if you go to the next step, the program will sort the list as descending order. Finally, the program will count the numbers of prime number in the list.
     If the program doesn't print out expected result, the program will print out the message that the test is fail. However, if the program prints out the expected result, the program will print out the message that test is success.
     
 4)Limitation
   I can't find the limitation of the program, but I think that there will be limitation in the program.
   
5) lgorithm and Complexity
   1> sort_ascending()
	    Algorithm: 1. Compute the midpoint of each of the sub-list.
		            2. Recursively sort two sublists of n/2 elements each as ascending order.
					   3. Merge n elements of the list.
		Runtime complexity: O(nlog(n))
	    
	  2> sort_descending()
	    Algorithm: 1. Compute the midpoint of each of the sub-list.
		            2. Recursively sort two sublists of n/2 elements each as descending order.
					   3. Merge n elements of the list
       Runtime complexity: O(nlog(n))
	    
	  3> count_primt(const Linked_List& list)
	    Algorithm: 1.First set the count as 0.
		            2. Iterate the loop untill the node points NULL.
						3. In the loop first set the flag as 0, and the m as the half of the value of the node.
						4. If the value of node is 1, set the flag as 1.
						5. Iterate the loop which is dividing the value of node by 2 ~ m.
						6. In the loop, if the mod is 0, set the flag as 1, and break the loop.
						7. After the loop, if the flag is 0, then increment the count.
						8. When the loop which iterates until the node is pointing to NULL is end, return the count.  
		Runtime complexity: O(n)*O(x) (x is the number of nodes in the list  which can change)
	   
