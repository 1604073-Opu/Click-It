#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
main()
{
    initwindow(1366,768);
    int x,y,point,pointx,over,i;
    float xx,yy;
top:
    cleardevice();
    point=0;
    pointx=0;
    over=0;
    settextstyle(4,0,5);
    outtextxy(300,200,"CLICK IT");
    outtextxy(300,300,"Play");
    line(0,300,1366,300);
    line(0,350,1366,350);
    outtextxy(300,400,"Quit");
    line(0,400,1366,400);
    line(0,450,1366,450);
    delay(500);
    if(ismouseclick(513)==1)
    {
        yy=mousey();
        if(yy>=300&&yy<=350)
        {
            cleardevice();
            clearmouseclick(513);
            delay(500);
            for(i=1; ; i++)
            {
                if(over>=5)
                {
                    break;
                }
                if(point>pointx)
                {
                    pointx=point;
                }
                char p[]="Point";
                sprintf(p,"%d",pointx);
                settextstyle(4,0,5);
                outtextxy(10,10,"POINT:");
                outtextxy(250,10,p);
                char o[]="MISS";
                sprintf(o,"%d",over);
                outtextxy(1000,10,"MISS:");
                outtextxy(1220,10,o);
                xx=-1;
                yy=-1;
restart:
                x=rand()%1000;
                y=rand()%1000;
                if(y>700||y<100)
                {
                    goto restart;
                }
                setcolor(RED);
                setfillstyle(SOLID_FILL,RED);
                circle(x,y,10);
                floodfill(x,y,RED);
                int time;
                time=1600-(i*4);
                if(time<900)
                {
                    time=900;
                }
                delay(time);
                int remark=ismouseclick(513);
                if(remark==1)
                {
                    xx=mousex();
                    yy=mousey();
                }
                clearmouseclick(513);
                if((xx>=x-10&&xx<=x+10)&&(yy>=y-10&&yy<=y+10))
                {
                    point++;
                }
                else
                {
                    over++;
                }
                cleardevice();
            }
click:
            cleardevice();
            char p[]="p";
            settextstyle(4,0,6);
            outtextxy(200,200,"GAME OVER");
            outtextxy(500,500,"POINT:");
            sprintf(p,"%d",point);
            outtextxy(775,500,p);
            delay(500);
            if(ismouseclick(513)==1)
            {
                clearmouseclick(513);
                goto top;
            }
            else
            {
                clearmouseclick(513);
                goto click;
            }
        }
        else if(yy>=400&&yy<=450)
        {
            return 0;
        }
        else
        {
            clearmouseclick(513);
            goto top;
        }
    }
    else
    {
        clearmouseclick(513);
        goto top;
    }
}
