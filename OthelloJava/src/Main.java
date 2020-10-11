import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        int yInput, xInput;
        char playerX = 'X';
        char playerO = 'O';
        char turn = playerX;
        int count=8;
        char[][] board = new char[count][count];

        Scanner scanner = new Scanner(System.in);
        Othello game = new Othello();
        game.NewBoard();
        do{
            game.PrintBoard();
            System.out.println("Player " + turn + ": ");
            System.out.println("Please enter row: ");
            yInput = scanner.nextInt();
            System.out.println("Please enter col: ");
            xInput = scanner.nextInt();
            if(((xInput>=0) && (xInput<count)) && ((yInput>=0) && (yInput<count))){
                if (board[yInput][xInput]>0){
                    if (game.CalculateGained(xInput,yInput)>0){
                        board[yInput][xInput]=turn;
                        game.ChangeColor(xInput, yInput);
                        if (turn==playerX){
                            turn=playerO;
                        }
                        else{
                            turn=playerX;
                        }
                    }
                }
            }
            scanner.nextLine();
        }
        while((xInput<count) && (yInput<count));
        scanner.close();
    }
}
