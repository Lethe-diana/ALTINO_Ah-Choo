#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Altino.h"

#define speed 270

int main()
{
    char ch=0;
    int state=0;
    SensorData data;

    Open(szPort);

    Steering(2);
    while(1)
    {
        data=Sensor(10);

        printf("%d %d %d %d %d\n",data.IRSensor[0], data.IRSensor[1], data.IRSensor[2],data.IRSensor[3], data.IRSensor[4]);

            if(data.IRSensor[0]>20 && data.IRSensor[2]>20)
            {
                if(data.IRSensor[1]>30)
                {
                    if(data.IRSensor[3]<data.IRSensor[4])
                    {
                        Steering(1);
                    }
                    else
                    {
                        Steering(3);
                    }

                    Go(-speed,-speed);
                }
                else
                {
                    Steering(2);
                    Go(speed,speed);
                }


            }
            else if(data.IRSensor[0]>20 && data.IRSensor[2]<=20)
            {
                if(data.IRSensor[1]>30)
                {
                    Steering(1);
                    Go(-speed,-speed);
                }
                else
                {
                    Steering(3);
                    Go(speed,speed);
                }
            }
            else if(data.IRSensor[0]<=20 && data.IRSensor[2]>20)
            {

                if(data.IRSensor[1]>30)
                {
                    Steering(3);
                    Go(-speed,-speed);
                }
                else
                {
                    Steering(1);
                    Go(speed,speed);
                }
            }
            else
            {
                Steering(2);
                if(data.IRSensor[1]>30)
                {
                    Go(-speed,-speed);
                }
                else
                    Go(speed,speed);

            }
    }

    Close();
    return 0;
}
