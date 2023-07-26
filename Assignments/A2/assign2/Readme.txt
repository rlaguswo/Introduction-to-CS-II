Name: Hyunjae Kim
ONID: kimh6
Section: CS162 001 U2020
Assignment2, due 07/19/2020

Description:
Welcome to go fish game! You can play go fish card game with computer. Play the go fish card game with the computer and be the winner of the game! Hope you to be the winner of the game! Enjoy the game!

Instructions:

1)Compile the program
	1> make clean
	2>make
2)Run the program
	Debug mode) ./Driver true
	Normal mode) ./Driver false
3) You start the game with computer. First of all, the computer and the player will have 7cards from the deck when the game starts. Each player asks the rank to other player and if the opponent says "go fish" then the player has to take one card from the deck. If the player has four cards with same rank, then the player book will be incremented. The game processes until there is no card on the deck. The winner is the player who has the most books. The player can start the game again, or quit the game. 

(Normal mode)
___________________________________________________________
        computer
Books: 0
Hand: < > < > < > < > < > < > < >

        Deck

        Player
Books: 0
Hand: <4> <K> <8> <6> <5> <9> <7>

___________________________________________________________________
Enter the rank of the card you wish to request:

(Debug mode)
___________________________________________________________
        computer
Books: 0
Hand: <3> <Q> <5> <4> <6> <9> <7>

        Deck

        Player
Books: 0
Hand: <J> <K> <2> <8> <J> <10> <3>

___________________________________________________________________
Enter the rank of the card you wish to request:

(Caution: when you are going to enter the rank in the program you have to make sure that the input is different from the rank in the screen)

Input manual
: (rank in screen- actual input)
(2-0), (3-1), (4-2), (5-3), (6-4), (7-5). (8-6), (9-7), (10-8), (J-9), (Q-10), (K-11), (A-12)

The game will process, and at the end of the game, the program will ask you to quit the game or not.
If you want to continue the game, press 1 and if you want to quit the game, press 2.

___________________________________________________________
        computer
Books: 10
Hand:

        Deck

        Player
Books: 3
Hand:

___________________________________________________________________
Computer win
Enter 1 to play again or 2 to exist:

If you want to say go fish, you can type 111. Then the computer will accept that you said go fish, but if you lie to computer, the computer will say "no cheating", and take the asked ranks you have.
___________________________________________________________________
Computer asks for a: J
You are going to give (type rank_number/111:go fish): 111
No Cheating!
You give Computer 1: J
___________________________________________________________________

The game will flow like the aforementioned information. At the end of the game, the program will inform you who is the winner.
___________________________________________________________
        computer
Books: 9
Hand:

        Deck

        Player
Books: 4
Hand:

___________________________________________________________________
Computer win



4) Limitations:
-If the user puts the wrong input, the program cannot check that error. It asks rank 2 to the computer.
-When the user has to enter the rank in the screen, the user has to put different value. (See the pairs above.)

5)Extra Credit:
-The computer asks the rank which is the last component of the hand array instead of randomly asking the rank to the player when the program is normal mode.

