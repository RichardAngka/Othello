#include<stdio.h>
#include<conio.h>
char empty=32;
#define count 8

int row, col, xInput, yInput;
char playerX = 'X';
char playerO = 'O';
char board[count][count];
char turn;
int countTable[count];

void ClearBoard(){
	for(row=0; row<count; row++){
		for(col=0; col<count; col++){
			board[col][row]=empty;
		}
	}
}

void PrintBoard(){
	int i,j;
	printf(" 01234567\n");
	for(i=0; i<count; i++){
		printf("%i", i);
		for(j=0; j<count; j++){
			printf("%c", board[j][i]);
		}
		puts(""); //sama kek System.out.println();
	} 
}

void NewBoard(){
	ClearBoard();
	board[3][3]=playerX;
	board[4][4]=playerX;
	board[3][4]=playerO;
	board[4][3]=playerO;
}

int CalculateGained(int xp, int yp){
	int x,y;
	bool canLoop;
	int totalCount=0;
	//arah atas=0
	x=xp;
	y=yp-1;	
	countTable[0]=0;
	//canLoop =(y>=0);
	while (y>=0){
		if (board[y][x]==empty){
			countTable[0]=0;
			break;
			//canLoop=false;
		}
		else if (board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			y--;
			countTable[0]++;
		}
	}
	//arah kanan = 1
	x=xp+1;
	y=yp;
	countTable[1]=0;
	//canLoop=(x<count);
	while (x<count){
		if (board[y][x]==empty){
			countTable[1]=0;
			break;
			//canLoop=false;
		}
		else if (board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			x++;
			countTable[1]++;
		}
	}
	//arah bawah = 2 
	x=xp;
	y=yp+1;
	countTable[2]=0;
	//canLoop=(y<count);
	while (y<count){
		if (board[y][x]==empty){
			countTable[2]=0;
			break;
			//canLoop=false;
		}
		else if (board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			y++;
			countTable[2]++;
		}
	}
	//arah kiri = 3 
	x=xp-1;
	y=yp;
	countTable[3]=0;
	//canLoop=(x>=0);
	while (x>=0){
		if (board[y][x]==empty){
			countTable[3]=0;
			break;
			//canLoop=false;
		}
		else if (board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			x--;
			countTable[3]++;
		}
	}
	//atas kiri = 4
	x=xp-1;
	y=yp-1;
	countTable[4]=0;
	while(y>=0 && x>=0){
		if(board[y][x]==empty){
			countTable[4]=0;
			break;
			//canLoop=false;
		}
		else if (board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			x--;
			y--;
			countTable[4]++;
		}
	}
	//atas kanan=5
	x=xp+1;
	y=yp-1;
	countTable[5]=0;
	while(y>=0 && x<count){
		if (board[y][x]==empty){
			countTable[5]=0;
			break;
			//canLoop=false;
		}
		else if(board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			x++;
			y--;
			countTable[5]++;
		}
	}
	//bawah kanan=6
	x=xp+1;
	y=yp+1;
	countTable[6]=0;
	while(y<count && x<count){
		if (board[y][x]==empty){
			countTable[6]=0;
			break;
			//canLoop=false;
		}
		else if(board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			x++;
			y++;
			countTable[6]++;
		}
	}
	//bawah kiri=7
	x=xp-1;
	y=yp+1;
	countTable[7]=0;
	while(y<count && x>=0){
		if (board[y][x]==empty){
			countTable[7]=0;
			break;
			//canLoop=false;
		}
		else if(board[y][x]==turn){
			break;
			//canLoop=false;
		}
		else{
			x--;
			y++;
			countTable[7]++;
		}
	}
	totalCount=0;
	for(int i=0; i<4; i++){
		totalCount+=countTable[i];
	}
	return totalCount;
}

int ChangeColor(int xp,int yp){
	int x,y;
	//atas=0
	x=xp;
	y=yp-1;
	for (int i=0; i<countTable[0]; i++){
		board[y][x]=turn;
		//y--;
	}
	//arah kanan = 1
	x=xp+1;
	y=yp;
	for (int i=0; i<countTable[1]; i++){
		board[y][x]=turn;
		//x++;
	}
	//arah bawah = 2 
	x=xp;
	y=yp+1;
	for (int i=0; i<countTable[2]; i++){
		board[y][x]=turn;
		//y++;
	}
	//arah kiri = 3 
	x=xp-1;
	y=yp;
	for (int i=0; i<countTable[3]; i++){
		board[y][x]=turn;
		//x--;
	}
	//atas kiri = 4
	x=xp-1;
	y=yp-1;
	for (int i=0; i<countTable[4]; i++){
		board[y][x]=turn;
		//x--;
		//y--;
	}
	//atas kanan = 5
	x=xp+1;
	y=yp-1;
	for (int i=0; i<countTable[5]; i++){
		board[y][x]=turn;
		//x++;
		//y--;
	}
	//bawah kanan = 6
	x=xp+1;
	y=yp+1;
	for (int i=0; i<countTable[6]; i++){
		board[y][x]=turn;
		//x++;
		//y++;
	}
	//bawah kiri = 7
	x=xp-1;
	y=yp+1;
	for (int i=0; i<countTable[7]; i++){
		board[y][x]=turn;
		//x--;
		//y++;
	}
}

int main(){
	NewBoard();
	turn=playerX;
	//clrscr();
	puts("");
	do{
		//clrscr();
		PrintBoard();
		printf("%c\n", "Player", turn, ":");
		printf("Please enter row: ");
		scanf("%i", &yInput);
		printf("Please enter col: ");
		scanf("%i", &xInput);
		if(((xInput>=0) && (xInput<count)) && ((yInput>=0) && (yInput<count))){
			if (board[yInput][xInput]>0){
				if (CalculateGained(xInput,yInput)>0){
					board[yInput][xInput]=turn;
					ChangeColor(xInput, yInput);
					if (turn==playerX){
						turn=playerO;
					}
					else{
						turn=playerX;
					}
				}
			}
		}
	}
	while((xInput<count) && (yInput<count));
	
}
