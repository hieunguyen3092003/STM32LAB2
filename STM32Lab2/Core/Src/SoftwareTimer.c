/*
 * SoftwareTimer.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#include <SoftwareTimer.h>

int Timer1Counter = 0;
int Timer1Flag = 0;

void SetTimer1(int duration){
	Timer1Counter = duration;
	Timer1Flag = 0;
}
void TimerRun(){
	if (Timer1Counter > 0){
		Timer1Counter--;
		if (Timer1Counter <= 0){
			Timer1Flag = 1;
		}
	}
}

