import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        int xInput, yInput;
        int count=8;
        char[][]board = new char[count][count];
        char empty=32;
        int []countTable = new int[count];

        Scanner scanner = new Scanner(System.in);
        Othello game = new Othello();
        game.NewBoard();
        game.turn=game.playerX;
        do{
            game.PrintBoard();
            System.out.println("Player " + game.turn + ": ");
            System.out.println("Please enter row: ");
            yInput = scanner.nextInt();
            System.out.println("Please enter col: ");
            xInput = scanner.nextInt();
            if(((xInput>=0) && (xInput<count)) && ((yInput>=0) && (yInput<count))){
                if (game.board[yInput][xInput]>0){
                    if ((game.CalculateGained(xInput,yInput))>0){
                        game.board[yInput][xInput]=game.turn;
                        game.ChangeColor(xInput, yInput);
                        if (game.turn==game.playerX){
                            game.turn=game.playerO;
                        }
                        else{
                            game.turn=game.playerX;
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
