#include <stdio.h>
#include <stdlib.h>
#include "Altino.h"

int main()
{
    SensorData data;
    int ir1,ir2,ir3,ir4,ir5,ir6;
    Open(szPort);

    while(1)
    {
        ir1=0;ir2=0;ir3=0;ir4=0;ir5=0;ir6=0;
        data = Sensor(10);
        ir1 = data.IRSensor[0];
        ir2 = data.IRSensor[1];
        ir3 = data.IRSensor[2];
        ir4 = data.IRSensor[3];
        ir5 = data.IRSensor[4];
        ir6 = data.IRSensor[5];

        printf("%d\t%d\t%d\n",ir2,ir4,ir5);
        if(ir2 > 15 && ir1 > 15 && ir3 > 15)
        {
            if(ir4>ir5)//left
            {
                printf("\t\t\t\t%d\t%d\t%d\n",ir2,ir4,ir5);
                DisplayLine(0x1f,0x1f,0x18,0x18,0x18,0x7e,0x3c,0x18);
                Go(-350,-350);
                delay(1550);
                Steering(1);
                Go(430,430);
                delay(1950);
                Steering(2);
            }
            else if(ir4<ir5)//right
            {
                printf("%d\t%d\t%d\n",ir2,ir4,ir5);
                DisplayLine(0x18,0x3c,0x7e,0x18,0x18,0x18,0x1f,0x1f);
                Go(-350,-350);
                delay(1550);
                Steering(3);
                Go(430,430);
                delay(1950);
                Steering(2);
            }
            else
            {
                DisplayLine(0,0,0,0,0,0,0,0);
                break;
            }
        }
        else
        {
            DisplayLine(0x10,0x30,0x7f,0xff,0xff,0x7f,0x30,0x10);
            Go(280,280);
            Steering(2);
        }
        data = Sensor(0);
    }

    Go(0,0);
    Close();
    return 0;
}
