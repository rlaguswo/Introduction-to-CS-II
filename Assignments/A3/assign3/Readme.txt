Name: Hyunjae Kim
ONID: kimh6
Section: CS162 001 U 2020
Assignment3, due 08/02/2020

Description:
Welcome to Zoo Tycoon! You can manage the zoo by buying animals, selling animals, or curing animals! You can be the winner of the zoo! Enjoy the program!

Instructions:

1)Compile the program
	1> make clean
	2>make 
2)Run the program: ./driver

3) When you start the program, the program will offer the choices. The choices are buying an animal, selling an animal, curing an animal, going to next month, and quiting the program. In each month, the user only can choose one specie, and buy up to two animals. Furthermore, the user cannot sell the animal if there is no animal in the zoo. The user is allowed to sell up to one animal in each month. Moreover, every month, there will be sepcial evnets in the zoo. The animal got sick, and the animal gets babies. Moreover, there is a zoo boom which the total attendance and the cost of the food for animals are doubled.

The user can cure the animal, but if the user has not enough money, then the sick animal will die. 

The user starts the program with $50000 in the user's bank account, and the cost for feeding animals and buying animals will be deducted from the bank account. The user will earn profits which is depending on the number of animals, the specie of the animal, and the total attendance of the zoo which is determined by the number of animals every month. The profit which is earned every month will be added to the user's bank account. Finally, the user can iterate the program infinitely unless the user wants to quit the program. 

If the user's bank account is less than 0, the program will inform the user that the game is over, and end the program.

When the amount of money in bank account is less than 0, and if the sum of the revenue and the amount of money in bank account is more than 0, then this is not bankrupt. However, if the sum of the revenue and the amount of money in bank account is less than 0, then this is bankrupt. If the bankrupt occurs, the program will end the program.

At the first month of the zoo, there will be no special events because there is no animals. After the first month, the program will print out the special events.  

If the animal got sick and there is not enough money to cure the animal, the program will try to cure the animal, but the animal will die. 

4)Limitation
The zoo boom occurs so frequently that it is easy to win the zoo tycoon.
There's some conditional jump in the program.

5)Extra Credit
When the amount of money in the user's bank account is more than $500000, the program will infrom the user that the user is the winner. And the program will offer the program screen to the user. It is up to user's mind to quit the program or not.