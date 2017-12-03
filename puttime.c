#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Altino.h"
#include<time.h>

#define speed 270

int main()
{
    char ch=0;
    int state=0;
    SensorData data;
                            //<2>
	double time_cal;		// process ���� clock����, ���������� clock���� ���̸�  ���� �ð��� ����
	time_t start, end;		// process ����, �շ����� ������ clock�� ���Խ�ų ����

    Open(szPort);
							//<3>
	start = clock();		// ���۽� clock ����


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
            if(kbhit())
            {
                Steering(2);
                Go(0,0);
                break;
            }
    }
	end = clock();

    time_cal = (double)(end - start) / CLK_TCK;
	printf("\n\nWe Spent %f Clock Time", time_cal);
    Close();
    delay(3000);
    return 0;
}

