import java.util.Scanner;

public class Main {
    public static void main(String[]args){
        int xInput, yInput;
        int count=8;
        char[][]board = new char[count][count];
        char empty=32;
        int []countTable = new int[count];
        int gameType;

        Scanner scanner = new Scanner(System.in);
        Othello game = new Othello();
        game.NewBoard();
        game.turn=game.playerX;
        System.out.println("Othello Game Prototype using Greedy Method");
        System.out.println();
        System.out.println("Press 1 for Human vs Greedy Computer");
        System.out.println("Press 2 for Human vs Human");
        System.out.println("Please Enter Your Choice");
        gameType = scanner.nextInt();

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
                        game.CountPlayer();
                        if(game.countEmpty>0) {
                            if (gameType == 2) {
                                if (game.turn == game.playerX) {
                                    game.turn = game.playerO;
                                }
                                else {
                                    game.turn = game.playerX;
                                }
                            }
                            else if(gameType==1){
                                game.turn = game.playerO;
                                game.ComputerPlay();
                            }
                        }
                    }
                }
            }
            scanner.nextLine();
        }
        while((xInput<count) && (yInput<count) && (game.countEmpty>0));
        scanner.close();

        if(game.countX>game.countO){
            System.out.println("Player" + game.playerX + "wins");
        }
        else if(game.countX<game.countO){
            System.out.println("Player" + game.playerO + "wins");
        }
        else{
            System.out.println("A Draw Game");
        }
    }
}
