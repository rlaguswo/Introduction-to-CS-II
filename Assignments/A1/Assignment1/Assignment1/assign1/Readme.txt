	opening_functions(f1,f2,argv[1],argv[2]);
	if(!f1.is_open() || !f2.is_open()){
Name: Hyunjae Kim
ONID: kimh6
Section:CS162-001-U2020
Assignment 1,due 07/05/2020,23:59

Discription:
This program is about wizard school. There are students and teachers and head master int the school. The wizard school got a lot of new spell books, and if the user enters the right id and password, the user can see the books. However, if the user's id is student, the user cannot see the books when the book have spells which effect is poison or death. Teachers and Head master can see the books contained spell which effect is poison and death. The user can sort the book by pages, sort the spells by effect, and sort the books by average success rate. If the user's id is student, the book which contains poison or death spell cannot be displayed. When the user fails the login over three times, the program will just quit by itself. Becareful of that! When the user is using program, the user can print the information to screen and store to text file either  existed or created, and the user can quit the program when the program offers choices.

Instructions:
1)Compile the program with
	first, you have to type 'make clean'
	second, you have to type 'make'
2)Run the program with
	./run_wizard <wizard_info> <spellbooks_info>
3)You will strat the program by typing your id and password. The allowd attepts to you is only three times. If you type invalid id or invalid password over three times, the program will end by itself.To be specific, if you type valid id and invalid password, or invalid id and valid password, the program will end itself. When you made it to login the program, There are three choices you can choose.                  
Please enter your id: 190199                                       
Please enter your password: abcde                                          
Incorrect id or password.
Please enter your id: 190199
Please enter your password: scardude99
Incorrect id or password.
Please enter your id: 190199
Please enter your password: asdf
Incorrect id or password.

<When the user fails to login three times>


Please enter your id: 190199
Please enter your password: wizbiz101
Welcome Dumbledore
ID: 190199
Status: Headmaster
Beard Length: 9000
Which option would you like to choose?
1.Sort spellbooks by number of pages
2.Group spells by their effect
3.Sort spellbooks by average success rate
4.Quit
Your Choice:
<When the user success to login>

There will be four choices if you login the program. The program will detect your id wheter it is student id or not. Then the program will decide to hide the informaion,spells with death or poison effect. 
The program will infinitely iterate unless you press the quit button. 

4)Limitations
The program can detect invalid id or invalid password. However, the program cannot detect some invalid id. For instace, the program cannot detect the input '190199a'(190199 is a valid id in the text file). It reads the input as a valid id.iMoreover,in the case of sorting spells by effect, if you chose to append the information to the file, it will be success to append the information to the file, but it has blank lines between the information. If you make a typo when you try to append the information to the file, it will create a file, but cannot certain that the information is appended. For instance, if you type 'a' when you are trying to append the information to the file, it creates a file 'a'. 
