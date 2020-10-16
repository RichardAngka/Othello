#include <stdio.h>
#include <conio.h>
#define Count 8

int	 GameType, row, col, yInput, xInput, Counter[Count], CountO, CountX,  xC, yC,  CountEmpty, AICount[Count][Count];
char Board[Count][Count], PlayerX = 'X', PlayerO = 'O', Turn, empty = ' ';

void ClearBoard(){
	for (row = 0; row<Count; row++){
		for (col = 0; col<Count; col++){
			Board[row][col]= empty;
		}
	}
}

void NewBoard(){
	ClearBoard;
	Board[3][3] = PlayerX;
	Board[4][4] = PlayerX;
	Board[3][4] = PlayerO;
	Board[4][3] = PlayerO;
}

void PrintBoard(){
	puts("  01234567");
	for (row = 0; row<Count; row++){
		printf("%i ", row);
		for (col = 0; col<Count; col++){
			printf("%c", Board[row][col]);
		}
		puts("");
	}
}

int CalculateGained(int yInput, int xInput){
	int TotalCount = 0, x, y, i;

	//Top (0)
	x = xInput;
	y = yInput-1;
	Counter[0] = 0;
	while (true){
		if (Board[y][x]== Turn)break;
		else if (!Board[y][x] || y<0){
			Counter[0] = 0;
			break;
		}
		else{
			Counter[0]++;
			y--;
		}
	}

	//Right (1)
	x = xInput+1;
	y = yInput;
	Counter[1] = 0;
	while (true){
		if (Board[y][x]== Turn)break;
		else if (!Board[y][x] || x>=Count){
			Counter[1] = 0;
			break;
		}
		else{
			Counter[1]++;
			x++;
		}
	}

	//Bottom (2)
	x = xInput;
	y = yInput+1;
	Counter[2] = 0;
	while (true){
		if (Board[y][x]== Turn)break;
		else if (!Board[y][x] || y>=Count){
			Counter[2] = 0;
			break;
		}
		else{
			Counter[2]++;
			y++;
		}
	}

	//Left (3)
	x = xInput-1;
	y = yInput;
	Counter[3] = 0;
	while (true){
		if (Board[y][x]== Turn)break;
		else if (!Board[y][x] || x<0){
			Counter[3] = 0;
			break;
		}
		else{
			Counter[3]++;
			x--;
		}
	}

	//Top Right (4)
	x = xInput+1;
	y = yInput-1;
	Counter[4] = 0;
	while (true){
		if (Board[y][x]== Turn) break;
		else if (!Board[y][x] || x>=Count || y<0){
			Counter[4] = 0;
			break;
		}
		else{
			Counter[4]++;
			x++;
			y--;
		}
	}

	//Bottom Right (5)
	x = xInput+1;
	y = yInput+1;
	Counter[5] = 0;
	while (true){
		if (Board[y][x]== Turn) break;
		else if (!Board[y][x] || x>=Count || y>=Count){
			Counter[5] = 0;
			break;
		}
		else{
			Counter[5]++;
			x++;
			y++;
		}
	}

	//Bottom Left (6)
	x = xInput-1;
	y = yInput+1;
	Counter[6] = 0;
	while (true){
		if (Board[y][x]== Turn) break;
		else if (!Board[y][x] || x<0 || y>=Count){
			Counter[6] = 0;
			break;
		}
		else{
			Counter[6]++;
			x--;
			y++;
		}
	}
	//Top Left (7)
	x = xInput-1;
	y = yInput-1;
	while (true){
		if (Board[y][x]== Turn)break;
		else if (!Board[y][x] || x<0 || y<0){
			Counter[7] = 0;
			break;
		}
		else{
			Counter[7]++;
			x--;
			y--;
		}
	}

	for (i = 0; i<Count; i++)
		TotalCount+=Counter[i];

	return TotalCount;
}

void ChangeColor(int yInput, int xInput){ //pert 7
	int x, y, i;

	//Top (0)
	x = xInput;
	y = yInput-1;
	for (i = 0; i < Counter[0]; i++){
		Board[y][x] = Turn;
		y-=1;
	}

	//Right (1)
	x = xInput+1;
	y = yInput;
	for (i = 0; i < Counter[1]; i++){
		Board[y][x] = Turn;
		x+=1;
	}
	//Bottom (2)
	x = xInput;
	y = yInput+1;
	for (i = 0; i < Counter[2]; i++){
		Board[y][x] = Turn;
		y+=1;
	}
	//Left (3)
	x = xInput-1;
	y = yInput;
	for (i = 0; i < Counter[3]; i++){
		Board[y][x] = Turn;
		x-=1;
	}
	//Top Right (4)
	x = xInput+1;
	y = yInput-1;
	for (i = 0; i < Counter[4]; i++){
		Board[y][x] = Turn;
		x+=1;
		y-=1;
	}
	//Bottom Right (5)
	x = xInput+1;
	y = yInput+1;
	for (i = 0; i < Counter[5]; i++){ 
		Board[y][x] = Turn;
		x+=1;
		y+=1;
	}
	//Bottom Left (6)
	x = xInput-1;
	y = yInput+1;
	for (i = 0; i < Counter[6]; i++){
		Board[y][x] = Turn;
		x-=1;
		y+=1;
	}
	//Top Left (7)
	x = xInput-1;
	y = yInput-1;
	for (i = 0; i < Counter[7]; i++){
		Board[y][x] = Turn;
		x-=1;
		y-=1;
	}
}

void CountPlayer(){
	int i, j;
	CountEmpty = 0;
	CountO = 0;
	CountX = 0;
	
	for (i = 0; i<Count; i++){
		for (j = 0; j<Count; j++){
			if (Board[i][j] == PlayerO) CountO++;
			else if (Board[i][j] == PlayerX) CountX++;
			else CountEmpty++;
		}
	}
}

void ComputerCount(){
	int x, y, GreedyMax = 0;
	for (y = 0; y<Count; y++){
		for (x = 0; x<Count; x++){
			if (!Board[y][x])
				if (GreedyMax<CalculateGained(y, x)){
					GreedyMax = CalculateGained(y, x);
					xC = x;
					yC = y;
				}
		}
	}
}

void SuccessfulInput(){
	Board[yInput][xInput] = Turn;
	ChangeColor(yInput, xInput);
	CountPlayer();
	if (Turn == PlayerX) Turn = PlayerO;
	else Turn = PlayerX;
}

void ComputerPlay(){
	PrintBoard();
	printf("Press any key for computer to play\n");
	getch();
	ComputerCount();
	Board[yC][xC] = Turn;
	CalculateGained(yC, xC);
	ChangeColor(yC, xC);
	Turn = PlayerX;
	CountPlayer();	
}

void DecideWinner(){
	if (CountX > CountO)
		puts("Player X wins");
	else if (CountX < CountO)
		puts("Player O wins");
	else 
		puts("Draw");	
}

void main(){

	puts("Othelo Game Prototype using greedy method");
	printf("Press 1 for human vs greedy computer\nPress 2 for human vs human\n");
	printf("Please enter your choice: ");
	scanf("%i", &GameType);
	NewBoard(); //create new board
	Turn = PlayerX;
	do{
		PrintBoard();
		printf("Player %c's turn\n\n", Turn);
		printf("Please enter row : "); scanf("%i", &yInput);
		printf("Please enter col : "); scanf("%i", &xInput);
		
		if (!Board[yInput][xInput]){
			if (CalculateGained(yInput, xInput)>0){
				SuccessfulInput();
				clrscr();
				if (CountEmpty>0){
					if (GameType==1){
						ComputerPlay();
					}	
				}
			}
		}
	}while (yInput<Count && xInput<Count && CountEmpty>0);
	DecideWinner();
}
