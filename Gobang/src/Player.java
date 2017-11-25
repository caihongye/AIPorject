import java.awt.*;

public class Player {
    public int tag;
    public Color color;
    private int row;
    private int col;
    private int[][] weightMap;
    private int placeX;
    private int placeY;
    private ChessBoard chessBoard;
    Player(int _tag,Color _color,ChessBoard _chessBoard){
        tag=_tag;
        color=_color;
        chessBoard=_chessBoard;
        row=chessBoard.rowNum;
        col=chessBoard.colNum;
        weightMap=new int[row][col];
    }

    public ChessPos PlaceChess(){

        int maxWeight=0;
        placeX=0;
        placeY=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(chessBoard.chessMan[i][j].tag!=0){
                    continue;
                }
                weightMap[i][j]=CountValue(j,i);
                if(weightMap[i][j]>maxWeight){
                    maxWeight=weightMap[i][j];
                    placeX=j;
                    placeY=i;
                }
            }
        }

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                System.out.print(weightMap[i][j]+" ");
            }
            System.out.println("");
        }
        weightMap[placeY][placeX]=0;
        return new ChessPos(placeX,placeY);
    }

    public int CountValue(int x,int y){
        int w=0;
        for(int i=0;i<CountRules.RULES.length;i++){
            RunAction runAction=CountRules.RULES[i];
            for(int j=0;j<runAction.actionNodes.length;j++){
                int m_x=x+runAction.actionNodes[j].moveX;
                int m_y=y+runAction.actionNodes[j].moveY;
                //System.out.println("action x:"+runAction.actionNodes[j].moveX+",y:"+runAction.actionNodes[j].moveY+"|"+
                //        "m_x:"+m_x+",m_y:"+m_y+"|"+"x:"+x+",y:"+y+"|tag:"+tag+"|aimtag:"+chessBoard.chessMan[m_y][m_x].tag);
                if(m_x>=chessBoard.colNum||m_x<0||m_y>=chessBoard.rowNum||m_y<0){
                    break;
                }
                if((runAction.actionNodes[j].chessType==ActionNode.SELF)&&(chessBoard.chessMan[m_y][m_x].tag!=tag)) {
                    break;
                }
                if((runAction.actionNodes[j].chessType==ActionNode.EMPTY)&&(chessBoard.chessMan[m_y][m_x].tag!=0)){
                    break;
                }
                if((runAction.actionNodes[j].chessType==ActionNode.ENEMY)&&((chessBoard.chessMan[m_y][m_x].tag==tag)||(chessBoard.chessMan[m_y][m_x].tag==0))){
                    break;
                }
                if(j==runAction.actionNodes.length-1){
                    w+=runAction.weight;
                    break;
                }
            }
        }
        return w;
    }
}
