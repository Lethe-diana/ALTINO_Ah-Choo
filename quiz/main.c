#include <stdio.h>
#include "Altino.h"

void one()
{
    int num=0;
    int speed=200;
    Open(szPort);
    while(1)
    {
        scanf("%d",&num);
        if(num==3)
            break;
        else if(num==1)
        {
            Go(200,200);
        }
        else if(num==2)
        {
            Go(0,0);
        }
        else if(num==4)
        {
            scanf("%d",&speed);
            Go(speed,speed);
        }

    }
    Close();
}
void two()
{
    char num=0;

    Open(szPort);
    while(1)
    {
        scanf("%c",&num);
        if(num=='d')
        {
            Steering(3);
            Go(300,300);
        }
        else if(num=='w')
        {
            Steering(2);
            Go(300,300);
        }
        else if(num=='a')
        {
            Steering(1);
            Go(300,300);

        }
        else if(num=='x')
        {
            Steering(2);
            Go(-300,-300);

        }

    }
    Close();

}

void three()
{
    int c =1;

    Open(szPort);
    while(1)
    {
        SensorData data;
        SensorData irdata;
        data=Sensor(1);
        irdata=Sensor(10);
        printf("%d\n",data.CDSSensor);

        if(data.CDSSensor>200)
        {
            Display(NULL);

            if(c==1)
            {
                Go(300,300);
                delay(3200);

                Steering(3);
                Go(270,270);
                delay(2000);
                Steering(2);
                c=2;
            }
            else if(c==2)
            {
                Go(270,270);
                if(irdata.IRSensor[1]>10&&irdata.IRSensor[0]>10&&irdata.IRSensor[2]>10)
                {
                    Go(0,0);
                    LED(0xccff);
                    Sound(60);
                    delay(2000);
                    Sound(0);
                    break;
                }
            }
        }
        else
        {
            Go(0,0);
            Display('A');
        }

    }
    Close();
}

int main()
{
   //one();
   //two();
   three();
}
