public class CountRules {
    //public static
    public static int LEVEL1=1;
    public static int LEVEL2=2;
    public static int LEVEL3=5;
    public static int LEVEL4=10;
    public static int LEVEL5=50;
    public static int LEVEL6=100;
    public static int LEVEL7=1000;
    public static int LEVEL8=10000;
    public static int LEVEL9=1000000;
    public static int LEVEL10=999999999;
    public static RunAction[] RULES;
    CountRules(){

        //周围为空对位置等级为1
        ActionNode[] an1={new ActionNode(0,-4,ActionNode.EMPTY),new ActionNode(0,-3,ActionNode.EMPTY),
                new ActionNode(0,-2,ActionNode.EMPTY),new ActionNode(0,-1,ActionNode.EMPTY),
                new ActionNode(0,4,ActionNode.EMPTY),new ActionNode(0,3,ActionNode.EMPTY),
                new ActionNode(0,2,ActionNode.EMPTY),new ActionNode(0,1,ActionNode.EMPTY),
        };

        //周围有一个敌方棋子等级位3
        ActionNode[] an2={new ActionNode(-1,0,ActionNode.ENEMY)};
        ActionNode[] an3={new ActionNode(0,-1,ActionNode.ENEMY)};
        ActionNode[] an4={new ActionNode(1,0,ActionNode.ENEMY)};
        ActionNode[] an5={new ActionNode(0,1,ActionNode.ENEMY)};

        //周围有敌方连续两个棋子等级为4
        ActionNode[] an6={new ActionNode(0,-3,ActionNode.EMPTY),new ActionNode(0,-2,ActionNode.ENEMY),new ActionNode(0,-1,ActionNode.ENEMY)};
        ActionNode[] an7={new ActionNode(0,3,ActionNode.EMPTY),new ActionNode(0,2,ActionNode.ENEMY),new ActionNode(0,1,ActionNode.ENEMY)};
        ActionNode[] an8={new ActionNode(-3,0,ActionNode.EMPTY),new ActionNode(-2,0,ActionNode.ENEMY),new ActionNode(-1,0,ActionNode.ENEMY)};
        ActionNode[] an9={new ActionNode(3,0,ActionNode.EMPTY),new ActionNode(2,0,ActionNode.ENEMY),new ActionNode(1,0,ActionNode.ENEMY)};
        ActionNode[] an10={new ActionNode(-3,-3,ActionNode.EMPTY),new ActionNode(-2,-2,ActionNode.ENEMY),new ActionNode(-1,-1,ActionNode.ENEMY)};
        ActionNode[] an11={new ActionNode(3,3,ActionNode.EMPTY),new ActionNode(2,2,ActionNode.ENEMY),new ActionNode(1,1,ActionNode.ENEMY)};
        ActionNode[] an12={new ActionNode(-3,3,ActionNode.EMPTY),new ActionNode(-2,2,ActionNode.ENEMY),new ActionNode(-1,1,ActionNode.ENEMY)};
        ActionNode[] an13={new ActionNode(3,-3,ActionNode.EMPTY),new ActionNode(2,-2,ActionNode.ENEMY),new ActionNode(1,-1,ActionNode.ENEMY)};

        //周围有敌方连续3个棋子等级为7
        ActionNode[] an14={new ActionNode(0,-4,ActionNode.EMPTY),new ActionNode(0,-3,ActionNode.ENEMY),new ActionNode(0,-2,ActionNode.ENEMY),new ActionNode(0,-1,ActionNode.ENEMY)};
        ActionNode[] an15={new ActionNode(0,4,ActionNode.EMPTY),new ActionNode(0,3,ActionNode.ENEMY),new ActionNode(0,2,ActionNode.ENEMY),new ActionNode(0,1,ActionNode.ENEMY)};
        ActionNode[] an16={new ActionNode(-4,0,ActionNode.EMPTY),new ActionNode(-3,0,ActionNode.ENEMY),new ActionNode(-2,0,ActionNode.ENEMY),new ActionNode(-1,0,ActionNode.ENEMY)};
        ActionNode[] an17={new ActionNode(4,0,ActionNode.EMPTY),new ActionNode(3,0,ActionNode.ENEMY),new ActionNode(2,0,ActionNode.ENEMY),new ActionNode(1,0,ActionNode.ENEMY)};
        ActionNode[] an18={new ActionNode(-4,-4,ActionNode.EMPTY),new ActionNode(-3,-3,ActionNode.ENEMY),new ActionNode(-2,-2,ActionNode.ENEMY),new ActionNode(-1,-1,ActionNode.ENEMY)};
        ActionNode[] an19={new ActionNode(4,4,ActionNode.EMPTY),new ActionNode(3,3,ActionNode.ENEMY),new ActionNode(2,2,ActionNode.ENEMY),new ActionNode(1,1,ActionNode.ENEMY)};
        ActionNode[] an20={new ActionNode(-4,4,ActionNode.EMPTY),new ActionNode(-3,3,ActionNode.ENEMY),new ActionNode(-2,2,ActionNode.ENEMY),new ActionNode(-1,1,ActionNode.ENEMY)};
        ActionNode[] an21={new ActionNode(4,-4,ActionNode.EMPTY),new ActionNode(3,-3,ActionNode.ENEMY),new ActionNode(2,-2,ActionNode.ENEMY),new ActionNode(1,-1,ActionNode.ENEMY)};


        ActionNode[] an58={new ActionNode(0,1,ActionNode.ENEMY),new ActionNode(0,-2,ActionNode.ENEMY),new ActionNode(0,-1,ActionNode.ENEMY)};
        ActionNode[] an59={new ActionNode(0,1,ActionNode.ENEMY),new ActionNode(0,2,ActionNode.ENEMY),new ActionNode(0,-1,ActionNode.ENEMY)};
        ActionNode[] an60={new ActionNode(0,1,ActionNode.ENEMY),new ActionNode(0,2,ActionNode.ENEMY),new ActionNode(0,3,ActionNode.ENEMY)};

        ActionNode[] an61={new ActionNode(1,0,ActionNode.ENEMY),new ActionNode(-2,0,ActionNode.ENEMY),new ActionNode(-1,0,ActionNode.ENEMY)};
        ActionNode[] an62={new ActionNode(1,0,ActionNode.ENEMY),new ActionNode(2,0,ActionNode.ENEMY),new ActionNode(-1,0,ActionNode.ENEMY)};
        ActionNode[] an63={new ActionNode(1,0,ActionNode.ENEMY),new ActionNode(2,0,ActionNode.ENEMY),new ActionNode(3,0,ActionNode.ENEMY)};


        ActionNode[] an64={new ActionNode(1,1,ActionNode.ENEMY),new ActionNode(-2,-2,ActionNode.ENEMY),new ActionNode(-1,-1,ActionNode.ENEMY)};
        ActionNode[] an65={new ActionNode(1,1,ActionNode.ENEMY),new ActionNode(2,2,ActionNode.ENEMY),new ActionNode(-1,-1,ActionNode.ENEMY)};
        ActionNode[] an66={new ActionNode(1,1,ActionNode.ENEMY),new ActionNode(2,2,ActionNode.ENEMY),new ActionNode(3,3,ActionNode.ENEMY)};


        ActionNode[] an67={new ActionNode(1,-1,ActionNode.ENEMY),new ActionNode(-2,2,ActionNode.ENEMY),new ActionNode(-1,1,ActionNode.ENEMY)};
        ActionNode[] an68={new ActionNode(1,-1,ActionNode.ENEMY),new ActionNode(2,-2,ActionNode.ENEMY),new ActionNode(-1,1,ActionNode.ENEMY)};
        ActionNode[] an69={new ActionNode(1,-1,ActionNode.ENEMY),new ActionNode(2,-2,ActionNode.ENEMY),new ActionNode(3,-3,ActionNode.ENEMY)};

        //我方能构成5个棋子等级为10
        ActionNode[] an22={new ActionNode(0,-4,ActionNode.SELF),new ActionNode(0,-3,ActionNode.SELF),new ActionNode(0,-2,ActionNode.SELF),new ActionNode(0,-1,ActionNode.SELF)};
        ActionNode[] an23={new ActionNode(0,-3,ActionNode.SELF),new ActionNode(0,-2,ActionNode.SELF),new ActionNode(0,-1,ActionNode.SELF),new ActionNode(0,1,ActionNode.SELF)};
        ActionNode[] an24={new ActionNode(0,-2,ActionNode.SELF),new ActionNode(0,-1,ActionNode.SELF),new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,2,ActionNode.SELF)};
        ActionNode[] an25={new ActionNode(0,-1,ActionNode.SELF),new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,2,ActionNode.SELF),new ActionNode(0,3,ActionNode.SELF)};
        ActionNode[] an26={new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,2,ActionNode.SELF),new ActionNode(0,3,ActionNode.SELF),new ActionNode(0,4,ActionNode.SELF)};

        ActionNode[] an27={new ActionNode(-4,0,ActionNode.SELF),new ActionNode(-3,0,ActionNode.SELF),new ActionNode(-2,0,ActionNode.SELF),new ActionNode(-1,0,ActionNode.SELF)};
        ActionNode[] an28={new ActionNode(-3,0,ActionNode.SELF),new ActionNode(-2,0,ActionNode.SELF),new ActionNode(-1,0,ActionNode.SELF),new ActionNode(1,0,ActionNode.SELF)};
        ActionNode[] an29={new ActionNode(-2,0,ActionNode.SELF),new ActionNode(-1,0,ActionNode.SELF),new ActionNode(1,0,ActionNode.SELF),new ActionNode(2,0,ActionNode.SELF)};
        ActionNode[] an30={new ActionNode(-1,0,ActionNode.SELF),new ActionNode(1,0,ActionNode.SELF),new ActionNode(2,0,ActionNode.SELF),new ActionNode(3,0,ActionNode.SELF)};
        ActionNode[] an31={new ActionNode(1,0,ActionNode.SELF),new ActionNode(2,0,ActionNode.SELF),new ActionNode(3,0,ActionNode.SELF),new ActionNode(4,0,ActionNode.SELF)};

        ActionNode[] an32={new ActionNode(-4,-4,ActionNode.SELF),new ActionNode(-3,-3,ActionNode.SELF),new ActionNode(-2,-2,ActionNode.SELF),new ActionNode(-1,-1,ActionNode.SELF)};
        ActionNode[] an33={new ActionNode(-3,-3,ActionNode.SELF),new ActionNode(-2,-2,ActionNode.SELF),new ActionNode(-1,-1,ActionNode.SELF),new ActionNode(1,1,ActionNode.SELF)};
        ActionNode[] an34={new ActionNode(-2,-2,ActionNode.SELF),new ActionNode(-1,-1,ActionNode.SELF),new ActionNode(1,1,ActionNode.SELF),new ActionNode(2,2,ActionNode.SELF)};
        ActionNode[] an35={new ActionNode(-1,-1,ActionNode.SELF),new ActionNode(1,1,ActionNode.SELF),new ActionNode(2,2,ActionNode.SELF),new ActionNode(3,3,ActionNode.SELF)};
        ActionNode[] an36={new ActionNode(1,1,ActionNode.SELF),new ActionNode(2,2,ActionNode.SELF),new ActionNode(3,3,ActionNode.SELF),new ActionNode(4,4,ActionNode.SELF)};

        ActionNode[] an37={new ActionNode(-4,4,ActionNode.SELF),new ActionNode(-3,3,ActionNode.SELF),new ActionNode(-2,2,ActionNode.SELF),new ActionNode(-1,1,ActionNode.SELF)};
        ActionNode[] an38={new ActionNode(-3,3,ActionNode.SELF),new ActionNode(-2,2,ActionNode.SELF),new ActionNode(-1,1,ActionNode.SELF),new ActionNode(1,-1,ActionNode.SELF)};
        ActionNode[] an39={new ActionNode(-2,2,ActionNode.SELF),new ActionNode(-1,1,ActionNode.SELF),new ActionNode(1,-1,ActionNode.SELF),new ActionNode(2,-2,ActionNode.SELF)};
        ActionNode[] an40={new ActionNode(-1,1,ActionNode.SELF),new ActionNode(1,-1,ActionNode.SELF),new ActionNode(2,-2,ActionNode.SELF),new ActionNode(3,-3,ActionNode.SELF)};
        ActionNode[] an41={new ActionNode(1,-1,ActionNode.SELF),new ActionNode(2,-2,ActionNode.SELF),new ActionNode(3,-3,ActionNode.SELF),new ActionNode(4,-4,ActionNode.SELF)};

        //敌方已经有4个,等级为9
        ActionNode[] an42={new ActionNode(0,-4,ActionNode.ENEMY),new ActionNode(0,-3,ActionNode.ENEMY),new ActionNode(0,-2,ActionNode.ENEMY),new ActionNode(0,-1,ActionNode.ENEMY)};
        ActionNode[] an43={new ActionNode(0,4,ActionNode.ENEMY),new ActionNode(0,3,ActionNode.ENEMY),new ActionNode(0,2,ActionNode.ENEMY),new ActionNode(0,1,ActionNode.ENEMY)};
        ActionNode[] an44={new ActionNode(-4,0,ActionNode.ENEMY),new ActionNode(-3,0,ActionNode.ENEMY),new ActionNode(-2,0,ActionNode.ENEMY),new ActionNode(-1,0,ActionNode.ENEMY)};
        ActionNode[] an45={new ActionNode(4,0,ActionNode.ENEMY),new ActionNode(3,0,ActionNode.ENEMY),new ActionNode(2,0,ActionNode.ENEMY),new ActionNode(1,0,ActionNode.ENEMY)};
        ActionNode[] an46={new ActionNode(-4,-4,ActionNode.ENEMY),new ActionNode(-3,-3,ActionNode.ENEMY),new ActionNode(-2,-2,ActionNode.ENEMY),new ActionNode(-1,-1,ActionNode.ENEMY)};
        ActionNode[] an47={new ActionNode(4,4,ActionNode.ENEMY),new ActionNode(3,3,ActionNode.ENEMY),new ActionNode(2,2,ActionNode.ENEMY),new ActionNode(1,1,ActionNode.ENEMY)};
        ActionNode[] an48={new ActionNode(-4,4,ActionNode.ENEMY),new ActionNode(-3,3,ActionNode.ENEMY),new ActionNode(-2,2,ActionNode.ENEMY),new ActionNode(-1,1,ActionNode.ENEMY)};
        ActionNode[] an49={new ActionNode(4,-4,ActionNode.ENEMY),new ActionNode(3,-3,ActionNode.ENEMY),new ActionNode(2,-2,ActionNode.ENEMY),new ActionNode(1,-1,ActionNode.ENEMY)};

        //进攻规则，判断可以三个棋子并且两路无子，等级为5
        ActionNode[] an50={new ActionNode(-1,-1,ActionNode.EMPTY),new ActionNode(1,1,ActionNode.SELF),new ActionNode(2,2,ActionNode.SELF),new ActionNode(3,3,ActionNode.EMPTY)};
        ActionNode[] an51={new ActionNode(-1,-1,ActionNode.SELF),new ActionNode(-2,-2,ActionNode.SELF),new ActionNode(-3,-3,ActionNode.EMPTY),new ActionNode(1,1,ActionNode.EMPTY)};

        ActionNode[] an52={new ActionNode(0,-1,ActionNode.EMPTY),new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,2,ActionNode.SELF),new ActionNode(0,3,ActionNode.EMPTY)};
        ActionNode[] an53={new ActionNode(0,3,ActionNode.EMPTY),new ActionNode(0,2,ActionNode.SELF),new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,-1,ActionNode.EMPTY)};

        ActionNode[] an54={new ActionNode(-1,0,ActionNode.SELF),new ActionNode(-2,0,ActionNode.SELF),new ActionNode(-3,0,ActionNode.EMPTY),new ActionNode(1,0,ActionNode.EMPTY)};
        ActionNode[] an55={new ActionNode(3,0,ActionNode.EMPTY),new ActionNode(2,0,ActionNode.SELF),new ActionNode(1,0,ActionNode.SELF),new ActionNode(-1,0,ActionNode.EMPTY)};

        ActionNode[] an56={new ActionNode(1,-1,ActionNode.EMPTY),new ActionNode(-1,1,ActionNode.SELF),new ActionNode(-2,2,ActionNode.SELF),new ActionNode(-3,3,ActionNode.EMPTY)};
        ActionNode[] an57={new ActionNode(-1,1,ActionNode.EMPTY),new ActionNode(1,-1,ActionNode.SELF),new ActionNode(2,-2,ActionNode.SELF),new ActionNode(3,-3,ActionNode.EMPTY)};

        //进攻规则
        ActionNode[] an70={new ActionNode(-1,-1,ActionNode.EMPTY),new ActionNode(1,1,ActionNode.SELF),new ActionNode(2,2,ActionNode.SELF),new ActionNode(3,3,ActionNode.SELF),new ActionNode(4,4,ActionNode.EMPTY)};
        ActionNode[] an71={new ActionNode(-1,-1,ActionNode.SELF),new ActionNode(-2,-2,ActionNode.SELF),new ActionNode(-3,-3,ActionNode.SELF),new ActionNode(-4,-4,ActionNode.EMPTY),new ActionNode(1,1,ActionNode.EMPTY)};

        ActionNode[] an72={new ActionNode(0,-1,ActionNode.EMPTY),new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,2,ActionNode.SELF),new ActionNode(0,3,ActionNode.SELF),new ActionNode(0,4,ActionNode.EMPTY)};
        ActionNode[] an73={new ActionNode(0,4,ActionNode.EMPTY),new ActionNode(0,3,ActionNode.SELF),new ActionNode(0,2,ActionNode.SELF),new ActionNode(0,1,ActionNode.SELF),new ActionNode(0,-1,ActionNode.EMPTY)};

        ActionNode[] an74={new ActionNode(-1,0,ActionNode.SELF),new ActionNode(-2,0,ActionNode.SELF),new ActionNode(-3,0,ActionNode.SELF),new ActionNode(-4,0,ActionNode.EMPTY),new ActionNode(1,0,ActionNode.EMPTY)};
        ActionNode[] an75={new ActionNode(4,0,ActionNode.EMPTY),new ActionNode(3,0,ActionNode.SELF),new ActionNode(2,0,ActionNode.SELF),new ActionNode(1,0,ActionNode.SELF),new ActionNode(-1,0,ActionNode.EMPTY)};

        ActionNode[] an76={new ActionNode(1,-1,ActionNode.EMPTY),new ActionNode(-1,1,ActionNode.SELF),new ActionNode(-2,2,ActionNode.SELF),new ActionNode(-3,3,ActionNode.SELF),new ActionNode(-4,4,ActionNode.EMPTY)};
        ActionNode[] an77={new ActionNode(-1,1,ActionNode.EMPTY),new ActionNode(1,-1,ActionNode.SELF),new ActionNode(2,-2,ActionNode.SELF),new ActionNode(3,-3,ActionNode.SELF),new ActionNode(4,-4,ActionNode.EMPTY)};


        RunAction[] runActions={
                new RunAction(an1,LEVEL1),
                new RunAction(an2,LEVEL3),
                new RunAction(an3,LEVEL3),
                new RunAction(an4,LEVEL3),
                new RunAction(an5,LEVEL3),
                new RunAction(an6,LEVEL4),
                new RunAction(an7,LEVEL4),
                new RunAction(an8,LEVEL4),
                new RunAction(an9,LEVEL4),
                new RunAction(an10,LEVEL4),
                new RunAction(an11,LEVEL4),
                new RunAction(an12,LEVEL4),
                new RunAction(an13,LEVEL4),
                new RunAction(an14,LEVEL7),
                new RunAction(an15,LEVEL7),
                new RunAction(an16,LEVEL7),
                new RunAction(an17,LEVEL7),
                new RunAction(an18,LEVEL7),
                new RunAction(an19,LEVEL7),
                new RunAction(an20,LEVEL7),
                new RunAction(an21,LEVEL7),
                new RunAction(an22,LEVEL10),
                new RunAction(an23,LEVEL10),
                new RunAction(an24,LEVEL10),
                new RunAction(an25,LEVEL10),
                new RunAction(an26,LEVEL10),
                new RunAction(an27,LEVEL10),
                new RunAction(an28,LEVEL10),
                new RunAction(an29,LEVEL10),
                new RunAction(an30,LEVEL10),
                new RunAction(an31,LEVEL10),
                new RunAction(an32,LEVEL10),
                new RunAction(an33,LEVEL10),
                new RunAction(an34,LEVEL10),
                new RunAction(an35,LEVEL10),
                new RunAction(an36,LEVEL10),
                new RunAction(an37,LEVEL10),
                new RunAction(an38,LEVEL10),
                new RunAction(an39,LEVEL10),
                new RunAction(an40,LEVEL10),
                new RunAction(an41,LEVEL10),
                new RunAction(an42,LEVEL9),
                new RunAction(an43,LEVEL9),
                new RunAction(an44,LEVEL9),
                new RunAction(an45,LEVEL9),
                new RunAction(an46,LEVEL9),
                new RunAction(an47,LEVEL9),
                new RunAction(an48,LEVEL9),
                new RunAction(an49,LEVEL9),
                new RunAction(an50,LEVEL5),
                new RunAction(an51,LEVEL5),
                new RunAction(an52,LEVEL5),
                new RunAction(an53,LEVEL5),
                new RunAction(an54,LEVEL5),
                new RunAction(an55,LEVEL5),
                new RunAction(an56,LEVEL5),
                new RunAction(an57,LEVEL5),
                new RunAction(an58,LEVEL7),
                new RunAction(an59,LEVEL7),
                new RunAction(an60,LEVEL7),
                new RunAction(an61,LEVEL7),
                new RunAction(an62,LEVEL7),
                new RunAction(an63,LEVEL7),
                new RunAction(an64,LEVEL7),
                new RunAction(an65,LEVEL7),
                new RunAction(an66,LEVEL7),
                new RunAction(an67,LEVEL7),
                new RunAction(an68,LEVEL7),
                new RunAction(an69,LEVEL7),
                new RunAction(an70,LEVEL8),
                new RunAction(an71,LEVEL8),
                new RunAction(an72,LEVEL8),
                new RunAction(an73,LEVEL8),
                new RunAction(an74,LEVEL8),
                new RunAction(an75,LEVEL8),
                new RunAction(an76,LEVEL8),
                new RunAction(an77,LEVEL8)
        };
        RULES=runActions;
        System.out.println("weight:"+RULES[0].weight);
    }
}
