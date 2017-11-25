import javax.swing.*;
import java.awt.*;

public class Gobang {
    public static void main(String[] args) {
        ChessBoard chessBoard=new ChessBoard(480,480,15,15);
        Chess chess = new Chess(chessBoard);
        JFrame application = new JFrame(" 五子棋");
        application.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        application.setBackground(new Color(210, 210, 134));
        application.add(chess);
        application.setSize(480, 550);
        application.setVisible(true);
        CountRules cr=new CountRules();
    }
}
