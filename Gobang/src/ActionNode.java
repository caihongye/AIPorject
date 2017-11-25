public class ActionNode {
    public static int SELF=1;
    public static int ENEMY=2;
    public static int EMPTY=3;

    public int moveX;
    public int moveY;
    public int chessType;
    ActionNode(int m_x,int m_y,int is_self){
        moveX=m_x;
        moveY=m_y;
        chessType=is_self;
    }
}
