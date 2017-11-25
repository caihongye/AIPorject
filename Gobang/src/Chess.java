import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

class Chess extends JPanel
{

    ChessBoard chessBoard;

    Player p1;

    //testdata
    //int count;

    Chess(ChessBoard _chessBoard) {
        chessBoard=_chessBoard;
        p1=new Player(3,Color.BLACK,chessBoard);
        //count = 0;
        this.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {

            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseReleased(MouseEvent e) {
                if(chessBoard.isEnd){
                    return;
                }
                System.out.println(e.getX() + "|" + e.getY());
                int x = (e.getX() - chessBoard.colPix / 2) / chessBoard.colPix;
                int y = (e.getY() - chessBoard.rowPix / 2) / chessBoard.rowPix;
                System.out.println("place chess= x:"+x + ",y:" + y);
                if(x>=chessBoard.colNum||y>=chessBoard.rowNum){
                    System.out.println("draw out");
                    return;
                }
                if(chessBoard.chessMan[y][x].tag!=0){
                    System.out.println("has draw");
                    return;
                }

                if(e.isControlDown()){
                    System.out.println("control down");
                    System.out.println(p1.CountValue(x,y));
                    return;
                }

                //count++;
                DrawChess(x, y, Color.WHITE,1);
                if(chessBoard.isEnd){
                    return;
                }
                ChessPos ans=p1.PlaceChess();
                int result=chessBoard.DrawChess(ans.x,ans.y,Color.BLACK,3);
                if(result!=0){
                    chessBoard.isEnd=true;
                    Graphics g = getGraphics();
                    g.setColor(Color.BLACK);
                    g.setFont(new Font("TimesRoman", Font.BOLD, 50));
                    g.drawString("Player "+result+" Win!",50,chessBoard.heightPix+50);
                }
                paintComponent(getGraphics());

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });
    }

    public void paintComponent( Graphics g )
    {
        g.setColor(Color.GRAY);
        for (int i = 1; i < chessBoard.rowNum+2; i++) {
            g.drawLine(chessBoard.rowPix * i, 0, chessBoard.rowPix * i, chessBoard.heightPix);

        }
        for (int i = 1; i < chessBoard.colNum+2; i++) {
            g.drawLine(0, chessBoard.colPix * i, chessBoard.widthPix, chessBoard.colPix * i);

        }
        System.out.println("paintComponent start");

        for(int i=0;i<chessBoard.rowNum;i++){
            for(int j=0;j<chessBoard.colNum;j++){
                if(chessBoard.chessMan[i][j].tag==0){
                    continue;
                }
                g.setColor(chessBoard.chessMan[i][j].color);
                g.fillOval(j * chessBoard.colPix + chessBoard.colPix / 2, i * chessBoard.rowPix + chessBoard.rowPix / 2,
                        chessBoard.colPix, chessBoard.rowPix);
            }
        }
    }


    public void DrawChess(int x, int y, Color color,int tag) {
        Graphics g = getGraphics();
        /*
        Graphics2D g2 = (Graphics2D) g;
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2.setPaint(color);
        g2.fillOval(x * colPix + colPix / 2, y * rowPix + rowPix / 2, colPix, rowPix);
        */
        chessBoard.chessMan[y][x].tag=tag;
        chessBoard.chessMan[y][x].color=color;
        int result=chessBoard.CheckWin(x,y);
        if(result!=0){
            chessBoard.isEnd=true;
            g.setColor(Color.BLACK);
            g.setFont(new Font("TimesRoman", Font.BOLD, 50));
            g.drawString("Player "+result+" Win!",50,chessBoard.heightPix+50);
        }
        System.out.println( chessBoard.chessMan[y][x].tag);
        paintComponent(getGraphics());
    }


}
