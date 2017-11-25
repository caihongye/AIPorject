import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

public class ChessBoard {

    public int widthPix;
    public int heightPix;

    public int rowNum;
    public int colNum;
    public boolean isEnd;

    public int rowPix;
    public int colPix;

    public ChessMan[][]chessMan;

    //testdata
    int count;

    ChessBoard(int width_pix, int height_pix, int row_num, int col_num) {

        chessMan = new ChessMan[row_num][col_num];
        for (int i = 0; i < row_num; i++) {
            for (int j = 0; j < col_num; j++) {
                chessMan[i][j] = new ChessMan();
            }
        }


        this.widthPix = width_pix;
        this.heightPix = height_pix;
        this.rowNum = row_num;
        this.colNum = col_num;
        rowPix = height_pix / (row_num + 1);
        colPix = width_pix / (col_num + 1);
        isEnd = false;

        count = 0;
    }

    public int DrawChess(int x, int y, Color color,int tag) {
        System.out.println(tag+" place x:"+x+",y: "+y);
        chessMan[y][x].tag=tag;
        chessMan[y][x].color=color;
        int result=CheckWin(x,y);
        if(result!=0){
            isEnd=true;
            return result;
        }
        return 0;
    }

    public int CheckWin(int x,int y){

        //check
        int winTag=1;
        for(int i=1;i<5;i++){
            int compareX=x-i;
            int compareY=y-i;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        for(int i=1;i<5;i++){
            int compareX=x+i;
            int compareY=y+i;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        if(winTag>=5){
            System.out.println(chessMan[y][x].tag+" win");
            return chessMan[y][x].tag;
        }

        //check
        winTag=1;
        for(int i=1;i<5;i++){
            int compareX=x-i;
            int compareY=y+i;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        for(int i=1;i<5;i++){
            int compareX=x+i;
            int compareY=y-i;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        if(winTag>=5){
            System.out.println(chessMan[y][x].tag+" win");
            return chessMan[y][x].tag;
        }


        //check
        winTag=1;
        for(int i=1;i<5;i++){
            int compareX=x-i;
            int compareY=y;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        for(int i=1;i<5;i++){
            int compareX=x+i;
            int compareY=y;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        if(winTag>=5){
            System.out.println(chessMan[y][x].tag+" win");
            return chessMan[y][x].tag;
        }

        //check
        winTag=1;
        for(int i=1;i<5;i++){
            int compareX=x;
            int compareY=y-i;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        for(int i=1;i<5;i++){
            int compareX=x;
            int compareY=y+i;
            if(compareX>=colNum||compareX<0||compareY>=rowNum||compareY<0){
                break;
            }
            if(chessMan[compareY][compareX].tag==chessMan[y][x].tag){
                winTag++;
            }
            else {
                break;
            };
        }
        if(winTag>=5){
            System.out.println(chessMan[y][x].tag+" win");
            return chessMan[y][x].tag;
        }
        return 0;
    }

}
