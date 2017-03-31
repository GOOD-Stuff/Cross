# Cross
This is a simple game - 'tic tac toe' for the family chip Zynq-7000.

# WHAT WORKS 

In this time exist singleplayer mode

# TODO

Add multiplayer;

Write normal tactic for computer;

# HOW TO PLAY

First of all, you must to compile this project by your cross-compiler, and after send into board.

After run application, you will see this menu. 


  	"_________________________________" 
  
	"|---------- Cross 0.1v ----------|"
	
	"|------------ Menu --------------|"
	
	"|------- 1) Singleplayer --------|"
	
	"|------- 2) Multiplayer  --------|" 
	
	"|------- 3) How to play? --------|" 
	
	"|---  anything) Exit outside  ---|" 
	
	"|________________________________|"
	
	"You choose: "

In single game, for doing your turn, you must to insert "X" or "x" and position in range from 0 to 2.

Example:

`"Your turn X 1 1" or "Your turn x 2 0"`

For reset game, you must to insert "R" and position in range from 0 to 2. After this, game will restart.

Example: 

`"Your turn R 0 1"`

And for exit from game, you must to insert "E".

Example:

`"Your turn E"	
"I was glad to see you. Goodbye!"`
