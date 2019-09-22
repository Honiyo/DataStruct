#include "mainwindow.h"
#include <string.h>
#include "time.h"
#include "windows.h"
#include "ui_mainwindow.h"
/*
 * 本代码是以系统时间为种子数，产生随机数，作为事发路段的起始点
 * 再以系统时间为种子数，随机产生事发事故等级，有1,2,3个等级
 * 图上的点代表城市或者高速路入出口，并显示标号以及是否拥有救援物资，以及救援物资级数
 * 最后以红色显示最短的前期救援，绿色显示最短的后期救援路径
 * 代码完成时间2019年6月28日
*/

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    const QString str="D:/QT/untitled/1.txt";  //文件包含点的坐标信息
    const QString str1="D:/QT/untitled/2.txt";  //文件包含点与点之间的相连关系
    g.input0(str);
    g.input1(str1);
    painter.setPen(QPen(QColor(0,0,0),2,Qt::SolidLine));//设置的画点轮廓颜色
    for(int j=0;j<g.NumOfVertices();j++)  //以下是在有直接相连路径的两点间画出一条黑色直线
        for(int i=0;i<g.NumOfVertices();i++)
        {
            if(g.Edge[j][i]>0&&g.Edge[j][i]<g.maxWeight)
            {
                painter.setPen(QPen(QColor(0,0,0),2,Qt::SolidLine));
                painter.drawLine(g.VerticesList[j].x+10,g.VerticesList[j].y+10,g.VerticesList[i].x+10,g.VerticesList[i].y+10);
                painter.setFont(QFont("consloas",10));
                painter.setPen(QPen(QColor(70,130,180),2,Qt::SolidLine));//设置权值数字的颜色
                int x=((g.VerticesList[i].x+10)+(g.VerticesList[j].x+10))/2; //权值数据的坐标
                int y=((g.VerticesList[i].y+10)+(g.VerticesList[j].y+10))/2;
                QPoint xy(x-10,y+10);
                painter.drawText(xy,QString::number(g.Edge[j][i]));//在该线条上标注出权值
            }
        }
    painter.setPen(QPen(QColor(0,0,0),2,Qt::SolidLine));
    for(int i=0;i<g.NumOfVertices();i++)//以下为画出点信息
    {
        painter.setFont(QFont("Consolas",10));
        painter.drawEllipse(g.VerticesList[i].x,g.VerticesList[i].y,20,20);
        QPoint tc(g.VerticesList[i].x+5,g.VerticesList[i].y+14); //点坐标
        painter.drawText(tc,QString::number(g.VerticesList[i].name));//标注点的标号
        if(g.VerticesList[i].flag==1)//有一级救援物资
        {
            painter.setBrush(QBrush(QColor(255,255,255)));//以白色作为填充点的颜色
            painter.drawText(g.VerticesList[i].x+3,g.VerticesList[i].y-6,QStringLiteral("1"));//显示有标记1，下同
        }
        else if(g.VerticesList[i].flag==2)//有2级救援物资
        {
            painter.setBrush(QBrush(QColor(255,255,255)));
            painter.drawText(g.VerticesList[i].x+3,g.VerticesList[i].y-6,QStringLiteral("2"));
        }
        else if(g.VerticesList[i].flag==3)//有3级救援物资
        {
            painter.setBrush(QBrush(QColor(255,255,255)));
            painter.drawText(g.VerticesList[i].x+3,g.VerticesList[i].y-6,QStringLiteral("3"));
        }

    }

    if (flagbutton==1) {//当点击按钮时，flagbutton标记为1，执行以下代码
        int a,b; //a代表事故路段的入口，b代表事故路段的出口
        SYSTEMTIME sys;  // 系统时间作为种子数
        GetLocalTime(&sys);
        double t1=sys.wMilliseconds*1000+sys.wSecond+sys.wMinute*60+sys.wHour*360;
        srand(t1);
        int flag=rand()%3+1;  //事故等级
        S<int,double,Node> s;  //S类为模板类，包含求单元最短路径的函数，int代表城市标号，double代表权值，
                               //Node为自定义类，包含位置pos和dist数值，方便在求单源最短路径中最小堆的调整
        double t2=sys.wMilliseconds*1000+sys.wSecond+sys.wMinute*60+sys.wHour*360+1;
        srand(t2);
        a=rand()%66;  //事故路段的入口位置标号
        double t3=sys.wMilliseconds*1000+sys.wSecond+sys.wMinute*60+sys.wHour*360+3;
        srand(t3);
        b=rand()%66;   //事故路段的出口位置标号
        while(g.Edge[a][b]==g.maxWeight||g.Edge[a][b]==0){
            b=rand()%66;   //当产生的出口标号与入口标号没有直接相连路径时，重新产生
                           //以保证事故是发生在一个固定的区域内
        }
        ui->textEdit_3->clear();
        ui->textEdit_3->setText(QString::number(flag));
        painter.setPen(QPen(QColor(0,0,0),0,Qt::SolidLine));
        painter.setBrush(QBrush(QColor(255,0,0,120)));//事故路段的入口以红色表示
        painter.drawEllipse(g.VerticesList[a].x,g.VerticesList[a].y,20,20);
        painter.setBrush(QBrush(QColor(0,255,0,120)));//事故路段的出口以绿色表示
        painter.drawEllipse(g.VerticesList[b].x,g.VerticesList[b].y,20,20);
        double d1[100],d2[100],weight1=0,weight2=0;
        int p1[100],*shortpath1,p2[100],*shortpath2,count1,count2;

        s.ShortestPath0(g,a,d1,p1,m1);//用S类的对象求点a到所有其它点的单源最短路径，并将路径存储在p1里
                                      //将a到所有点的最短路径的权值存在d1里  下同
        shortpath1=printShortestPath(g,a,d1,p1,flag,weight1,count1);
        //该函数是求事故等级为flag，所有点中到a点具有最短距离的路径信息，并将权值存在weight1里，返回一个存有最短路径信息的数组，下同
        s.ShortestPath0(g,b,d2,p2,m2);
        shortpath2=printShortestPath(g,b,d2,p2,flag,weight2,count2);

        int i=0,x1[50],y1[50],x2[50],y2[50],j=0,k; //循环变量i，j，k
                                                //数据坐标存储数组x1，x2，y1，y2
        for(i=0;i<=count1;i++)  //将到a点的最短路径中点的坐标存储在数组里
        {
            x1[i]=g.VerticesList[shortpath1[i]].x;
            y1[i]=g.VerticesList[shortpath1[i]].y;
             //cout<<g.getValue(shortpath1[i])<<" ";
        }
        //cout<<endl;
        x1[i]=(g.VerticesList[a].x+g.VerticesList[b].x)/2; //在a，b两点的中点处画一个圆，表示事故发生点
        y1[i]=(g.VerticesList[a].y+g.VerticesList[b].y)/2;
         painter.setBrush(QBrush(QColor(255,255,0)));
         painter.drawEllipse(x1[i]+5,y1[i]+5,10,10);


        for(j=0;j<=count2;j++)  //将b点到其他点的最短路径中点的坐标存储在数组里
        {
            x2[j]=g.VerticesList[shortpath2[j]].x;
            y2[j]=g.VerticesList[shortpath2[j]].y;
            //cout<<g.getValue(shortpath2[j])<<" ";
        }
        //cout<<endl;
        x2[j]=(g.VerticesList[b].x+g.VerticesList[a].x)/2;  //同为表示事故发生点
        y2[j]=(g.VerticesList[b].y+g.VerticesList[a].y)/2;

        QString str1="pre-rescue:\n";
        painter.setPen(QPen(QColor(255,0,0),2,Qt::SolidLine));
        for(k=0;k<i;k++){
            if(k==i-1) //该if——else结构为拼接信息，输出在界面的文本框内
                str1+=QString::number(g.getValue(shortpath1[k]))+" "+QString::number(0)+" "+QString::number(g.getWeight(a,b)/2)+"\n";
            else
                str1+=QString::number(g.getValue(shortpath1[k]))+" "+QString::number(g.getValue(shortpath1[k+1]))+" "+QString::number(g.Edge[shortpath1[k]][shortpath1[k+1]])+"\n";
            //以下是在路径上画出箭头，表示路线走向
            QPoint q1(x1[k]+7,y1[k]+7);
            QPoint q2(x1[k+1]+7,y1[k+1]+7);
            float x1 = q1.x();         //lastPoint 起点
            float y1 = q1.y();
            float x2 = q2.x();           //endPoint 终点
            float y2 = q2.y();
            float l = 10.0;                   //箭头的那长度
            float a = 0.5;                       //箭头与线段角度
            float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
            float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
            float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
            float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
            painter.drawLine(x2,y2,x3,y3);
            painter.drawLine(x2,y2,x4,y4);
            painter.drawLine(q1,q2);
        }
        weight1+=g.getWeight(a,b)/2; //获取前期救援的路径长度
        str1+="total:"+QString::number(weight1)+"\n";
        ui->textEdit->clear();
        ui->textEdit->setText(str1); //文本框显示输出

        //同上，是拼接后期救援的路径信息，并描绘
        QString str2="post-rescue:\n";
        painter.setPen(QPen(QColor(0,255,0),2,Qt::SolidLine));
        for(k=j;k>0;k--){
            if(k==j)
                str2+=QString::number(0)+" "+QString::number(g.getValue(shortpath2[k-1]))+" "+QString::number(g.getWeight(a,b)/2)+"\n";
            else
                str2+=QString::number(g.getValue(shortpath2[k]))+" "+QString::number(g.getValue(shortpath2[k-1]))+" "+QString::number(g.Edge[shortpath2[k]][shortpath2[k-1]])+"\n";
           // painter.drawLine(QLineF(QPoint(x2[k]+15,y2[k]+15),QPoint(x2[k-1]+15,y2[k-1]+15)));
            QPoint q1(x2[k]+14,y2[k]+14);
            QPoint q2(x2[k-1]+14,y2[k-1]+14);
            float x1 = q1.x();         //lastPoint 起点
            float y1 = q1.y();
            float x2 = q2.x();           //endPoint 终点
            float y2 = q2.y();
            float l = 10.0;                   //箭头的那长度
            float a = 0.7;                       //箭头与线段角度
            float x3 = x2 - l * cos(atan2((y2 - y1) , (x2 - x1)) - a);
            float y3 = y2 - l * sin(atan2((y2 - y1) , (x2 - x1)) - a);
            float x4 = x2 - l * sin(atan2((x2 - x1) , (y2 - y1)) - a);
            float y4 = y2 - l * cos(atan2((x2 - x1) , (y2 - y1)) - a);
            painter.drawLine(x2,y2,x3,y3);
            painter.drawLine(x2,y2,x4,y4);
            painter.drawLine(q1,q2);
        }
        weight2+=g.getWeight(a,b)/2; //获取后期救援的路径长度
        str2+="total:"+QString::number(weight2)+"\n";
        ui->textEdit_2->clear();
        ui->textEdit_2->setText(str2); //文本框显示输出
        flagbutton=0; //在点击一下按钮后，执行该代码后，标记变量变为0
    }

}




void MainWindow::on_pushButton_2_clicked()
{
    flagbutton=1;
    update(); //刷新图
}

