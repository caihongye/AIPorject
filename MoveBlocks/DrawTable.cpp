//
// Created by chy on 17-10-21.
//

#include "DrawTable.h"

DrawTable::DrawTable(string filename){
    this->filename=filename;

    head="<style>\nbody{margin:0;padding:0;}\nul,li,dl,dd,dt,p{margin:0;padding:0;}\nul,li{list-style:none;}\n\n.histogram-container{position:relative;margin-left:60px;margin-top:10px;margin-bottom:25px;}\n.histogram-bg-line{border:#999 solid;border-width:0 1px 1px 1px;border-right-color:#eee;overflow:hidden;width:10000px;}\n.histogram-bg-line ul{overflow:hidden;border:#eee solid;border-width:1px 0 0 0;}\n.histogram-bg-line li{float:left;width:100px;/*根据.histogram-bg-line下的ul里面li标签的个数来控制比例*/overflow:hidden;}\n\n.histogram-content{position:absolute;left:0px;top:0;width:99%;height:100%;}\n.histogram-content ul{height:100%;}\n.histogram-content li{float:left;height:100%;width:100px;/*根据直方图的个数来控制这个width比例*/text-align:center;position:relative;}\n.histogram-box{position:relative;display:inline-block;height:100%;width:20px;}\n.histogram-content li a{position:absolute;bottom:0;right:0;display:block;width:20px;}\n.histogram-content li .name{position:absolute;bottom:-20px;left:0px;white-space:nowrap;display:inline-block;width:100%;font-size:12px;}\n.histogram-y{position:absolute;left:-60px;top:-10px;font:12px/1.8 verdana,arial;}\n.histogram-y li{text-align:right;width:55px;padding-right:5px;color:#333;}\n.histogram-bg-line li div,.histogram-y li{height:60px;/*控制单元格的高度及百分比的高度，使百分数与线条对齐*/}\n </style>\n\n\n\n <div class=\"histogram-container\" id=\"histogram-container\">\n <div class=\"histogram-bg-line\">\n <ul>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n </ul>\n <ul>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n </ul>\n <ul>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n </ul>\n <ul>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n </ul>\n <ul>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n <li><div></div></li>\n </ul>\n </div>\n <!--柱状条-->\n <div class=\"histogram-content\">\n <ul>\n ";

    end="</div>";
}


bool DrawTable::Draw() {
    ofstream outfile;
    outfile.open(filename, ios::out | ios::trunc );

    string buf=head;

    for(int i=0;i<itemNum;i++){
        char temp_precent[64];
        char temp_height[64];
        int height_precent=item[i].height*100/yMax;
        sprintf(temp_precent,"%d",height_precent);
        sprintf(temp_height,"%lld",item[i].height);
        cout<<temp_height<<endl;
        buf=buf+"<li>\n<span class=\"histogram-box\"><a style=\"height:"+temp_precent+"%;background:gray;\" title=\""+temp_height+"\"></a></span>\n<span class=\"name\">"+item[i].itemName+"</span>\n</li>";
    }

    buf=buf+"</div><div class=\"histogram-y\">\n<ul>";
    for(int i=0;i<6;i++){
        char temp[64];
        sprintf(temp,"%lld",yMax*(5-i)/5);
        buf=buf+"<li>"+temp+"</li>";
    }


    buf=buf+"</ul></div>";

    buf=buf+end;
    outfile.write(buf.c_str(),buf.size());

    outfile.close();
}
