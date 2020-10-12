class Othello extends Main {
    int row, col;
    int count=8;
    char playerX = 'X';
    char playerO = 'O';
    char[][] board = new char[count][count];
    char turn;
    char empty=32;
    int []countTable = new int[count];

    void ClearBoard(){
        for (row=0; row<count; row++){
            for (col=0; col<count; col++){
                board[col][row]=empty;
            }
        }
    }

    void PrintBoard(){
        int i, j;
        System.out.println(" 01234567 ");
        for(i=0; i<count; i++){
            System.out.print(i);
            for(j=0; j<count; j++){
                System.out.print(board[j][i]);
            }
            System.out.println();
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
        int totalCount=0;

        //arah atas = 0
        x=xp;
        y=yp-1;
        countTable[0]=0;
        while(y>=0){
            if (board[y][x]==empty){
                countTable[0]=0;
                break;
            }
            else if (board[y][x]==turn){
                break;
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
        while (x<count){
            if (board[y][x]==empty){
                countTable[1]=0;
                break;
            }
            else if (board[y][x]==turn){
                break;
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
        while (y<count){
            if (board[y][x]==empty){
                countTable[2]=0;
                break;
            }
            else if (board[y][x]==turn){
                break;
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
        while (x>=0){
            if (board[y][x]==empty){
                countTable[3]=0;
                break;
            }
            else if (board[y][x]==turn){
                break;
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
            }
            else if (board[y][x]==turn){
                break;
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
            }
            else if(board[y][x]==turn){
                break;
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
            }
            else if(board[y][x]==turn){
                break;
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
            }
            else if(board[y][x]==turn){
                break;
            }
            else{
                x--;
                y++;
                countTable[7]++;
            }
        }
        for(int i=0; i<4; i++){
            totalCount+=countTable[i];
        }
        return totalCount;
    }
    void ChangeColor(int xp, int yp){
        int x,y;
        //atas=0
        x=xp;
        y=yp-1;
        for (int i=0; i<countTable[0]; i++){
            board[y][x]=turn;
        }
        //arah kanan = 1
        x=xp+1;
        y=yp;
        for (int i=0; i<countTable[1]; i++){
            board[y][x]=turn;
        }
        //arah bawah = 2
        x=xp;
        y=yp+1;
        for (int i=0; i<countTable[2]; i++){
            board[y][x]=turn;
        }
        //arah kiri = 3
        x=xp-1;
        y=yp;
        for (int i=0; i<countTable[3]; i++){
            board[y][x]=turn;
        }
        //atas kiri = 4
        x=xp-1;
        y=yp-1;
        for (int i=0; i<countTable[4]; i++){
            board[y][x]=turn;
        }
        //atas kanan = 5
        x=xp+1;
        y=yp-1;
        for (int i=0; i<countTable[5]; i++){
            board[y][x]=turn;
        }
        //bawah kanan = 6
        x=xp+1;
        y=yp+1;
        for (int i=0; i<countTable[6]; i++){
            board[y][x]=turn;
        }
        //bawah kiri = 7
        x=xp-1;
        y=yp+1;
        for (int i=0; i<countTable[7]; i++){
            board[y][x]=turn;
        }
    }

}
