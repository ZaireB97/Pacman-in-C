#include <stdio.h> //required header for input/output function such as printf and scanf
#include <stdlib.h> //required header for c commands like rand()







void gameBoard(char board[20][20]) //prints the pacman board that is 7 by 7 in dimension
//the game board will be stored in a 2-dimensional array
{
	int i, j; //intialize i(which will be the length of the board(considering that the down is the length)) and intialize j(which is the width(the across))
	printf("\n\n"); //prints two lines after the previous printed statement
	for(i = 0 ;i<=19;i++) //creates 7 new lines for the board length
	{
		for(j = 0;j<=19;j++) //creates 7 character on the board for every line, therefore the board has 49 characters in total
		{
			printf("%c", board[i][j]); //prints the two dimensional array
		}
		printf("\n"); //prints a line after the board
	}
}

int validMove(char board[20][20], int x, int y, char c)
//checks to see if users move is a vaild move
{
	if(c=='a') //looks at when user inputs 'a' left move
	{
		if(board[x][y-1]=='.') 
		/*looks at the position on the same length but one left of the pacman's current position to see if it has '.'(which would make the move vaild)*/
		{
			board[x][y-1]='P'; //moves the pacman over to the left 
			board[x][y]=' '; //replaces the pacman's previous space with a space
			return 1;
			//returns true and lets the program continue; if this was a zero or didn't exist the program would think the move is invalild and end the game
		}
		else 
			return 0; 
			//returns that the input was false and an invaild move
	}
	if(c=='s') 
	//looks at when user inputs 's' down move
	{
		if(board[x+1][y]=='.') 
		//looks at the position on the length one down but same width of the pacman's current position to see if it has '.'(which would make the move vaild)
		{
			board[x+1][y]='P'; 
			//moves the pacman down one
			board[x][y]=' '; 
			//replaces the pacman's previous space with a space
			return 1;  
			//returns true and lets the program continue; if this was a zero or didn't exist the program would think the move is invaild and end the game
		}
		else
			return 0; //returns that the input was false and an invaild move
	}
	if(c=='d') 
	//looks at when user inputs 'd' right move
	{
		if(board[x][y+1]=='.') 
		//looks at the position on the same length but one to the right of the pacman's current position to see if it has '.'(which would make the move vaild)
		{
			board[x][y+1]='P'; 
			//moves the pacman right one
			board[x][y]=' '; 
			//replaces the pacman's previous space with a space
			return 1;  
			//returns true and lets the program continue; if this was a zero or didn't exist the program would think the move is invaild and end the game
		}
		else
			return 0; 
			//returns that the input was false and an invaild move
	}
	if(c=='w') //looks at when user inputs 'w' up move
	{
		if(board[x-1][y]=='.') 
		//looks at the position on the length one up but on the same width of the pacman's current position to see if it has '.'(which would make the move vaild)
		{
			board[x-1][y]='P'; 
			//moves the pacman right one
			board[x][y]=' '; 
			return 1; 
			//returns true and lets the program continue; if this was a zero or didn't exist the program would think the move is invaild and end the game
		}
		else
			return 0; 
			//returns that the input was false and an invaild move
	}
	return 0; 
	//function must return something since it is an integer; also ends the code if the user input is notone of the following 
	//'w','a','s','d' or if the move is invaild
}


//main function
int main()
{
	int score;

	//char board[20][20]; //intializes board as two dimensional array
	int steps = 324, eaten = 324; //intailize the number of move for the PacMan and the number of characters the pacman can eat
	int x, y; //intializes position of length and width of the pacman
	char c; //variable for user input to control the game
	int lower = 1, upper = 18; //ranges for the number of avaible spots that the ghost can be randomized to
	int gx, gy;
	int gx2, gy2;//variable for the ghost's length position and width position
	int i, j,g ;



	//x = (rand() % (upper-lower + 1)) + lower; //randomizes position of the pacman on the length side within the range
	//y = (rand() % (upper-lower + 1)) + lower; //randomizes position of the pacman on the width side within the range

	gx = (rand() % (upper-lower + 1)) + lower; //randomizes position of the ghost on the length side within the range 
	gy = (rand() % (upper-lower + 1)) + lower; //randomizes position of the ghost on the length side within the range 

	gx2 = (rand() % (upper-lower + 1)) + lower; //randomizes position of the ghost on the length side within the range
	gy2 = (rand() % (upper-lower + 1)) + lower; //randomizes position of the ghost on the length side within the range
	
	char board[20][20] =  {{'&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','&','&','&','.','.','.','.','.','.','.','.','.','.','&','&','&','.','&'},
						  {'&','.','&','&','&','.','.','.','.','.','.','.','.','.','.','&','&','&','.','&'},
						  {'&','.','&','&','&','.','.','.','.','.','.','.','.','.','.','&','&','&','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','&','&','&','&','&','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','&','&','&','&','&','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','&','&','&','&','&','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','.','&','&','&','.','.','.','.','.','.','.','.','.','.','&','&','&','.','&'},
						  {'&','.','&','&','&','.','.','.','.','.','.','.','.','.','.','&','&','&','.','&'},
						  {'&','.','&','&','&','.','.','.','.','.','.','.','.','.','.','&','&','&','.','&'},
						  {'&','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','.','&'},
						  {'&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&','&'}};
	board[13][16] = 'P';

	//print board
	printf("\nLets play Dungeons\n\n"); //prints this statement to start the game

	printf("\nRules of the Game: \n"); //prints the statment
	printf("1) Eat all the ‘.’ to win the game\n"); //prints the statment
	printf("2) Don't land on a ghost '&' or you lose the game\n"); //prints the statment
	printf("3) Borders '#' make you lose the game immediately\n"); //prints the statment


	gameBoard(board); //prints the PacMan board for the user using the intialized variables

	printf("%40s","SCORE = 0");

	score = 0;

	while(steps>0) //does the following steps when the step(move) of the pacman are greater than 0
	{
		printf("\n\na: move left\ns: move down\nd: move right\nw: move up\n\nEnter your move: "); //print statment for how the user can control the game
		scanf(" %c", &c); //get move from player

		//call move
		switch(c)
		{
			case 'a': //when user input is a
				if(validMove(board,x,y,c)==1) //looks if the vaild move is true
				{
					y-=1; //moves new position one to the left by subtracting one to the width position
					steps--; //decrements the steps by 1 each time
					eaten--; //decrements the eaten by 1 each time
					gameBoard(board); //prints the new game board
					score += 1;
					printf("%40s = %d","SCORE",score);
				}
				else
				{
					printf("\nInvalid move\n"); //prints when vaild move is false
					printf("\n\nYou lost the game!!!\n\n"); //prints
					return 0; //terminates the game
				}
				break; //jumps back to the beginning of the while loop

			//move down
			case 's': //when user input is s
				if(validMove(board,x,y,c)==1)//looks if the vaild move is true
				{
					x+=1; //moves new position one to down by adding one to the length position
					steps--; //decrements the steps by 1 each time
					eaten--; //decrements the eaten by 1 each time
					gameBoard(board); //prints the new game board
					score += 1;
					printf("%40s = %d","SCORE",score);
				}
				else
				{
					printf("\nInvalid move\n"); //prints when vaild move is false
					printf("\n\nYou lost the game!!!\n\n"); //prints
					return 0;//terminates the game
				}
				break;

			//move right
			case 'd': //when user input is d
				if(validMove(board,x,y,c)==1) //looks if the vaild move is true
				{
					y+=1; //moves new position one to down by adding one to the width position
					steps--; //decrements the steps by 1 each time
					eaten--; //decrements the eaten by 1 each time
					gameBoard(board); //prints the new game board
					score += 1;
					printf("%40s = %d","SCORE",score);
				}
				else
				{
					printf("\nInvalid move\n"); //prints when vaild move is false
					printf("\n\nYou lost the game!!!\n\n"); //prints
					return 0; //terminates the game
				}
				break;

			//move up
			case 'w': //when user input is w
				if(validMove(board,x,y,c)==1) //looks if the vaild move is true
				{
					x-=1; //moves new position one to the left by subtracting one to the length position
					steps--; //decrements the steps by 1 each time
					eaten--; //decrements the eaten by 1 each time
					gameBoard(board); //prints the new game board
					score += 1;
					printf("%40s = %d","SCORE",score);
				}
				else
				{
					printf("\nInvalid move\n"); //prints when vaild move is false
					printf("\n\nYou lost the game!!!\n\n"); //prints
					return 0; //terminates the game
					
				}	
				break;
			default: //when an input is entered that is not one of the cases 
				break; //jump back to beginning of the while loop
		}
	}
	//print results
	if(eaten==0) //when they are no more eaten pieces left the game is won
	{
		printf("\n\nYou won the game!!!\n\n"); // prints the win statement
	}
	else //when there are more game pieces left or the move is invaild the game is lost
	{
		printf("\n\nYou lost the game!!!\n\n"); // prints the lost statement
	}
  	return 1;
}
