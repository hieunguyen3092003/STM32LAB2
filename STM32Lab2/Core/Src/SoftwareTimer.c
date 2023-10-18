/*
 * SoftwareTimer.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#include <SoftwareTimer.h>

int timer1Flag = 0;
int timer1Counter = 0;
int seg7Counter;
int seg7Buffer;

void setTimer1(int duration){
	timer1Counter = duration;
	timer1Flag = 1;
}

void timerRun(){
	if (timer1Counter > 0){
		timer1Counter--;
		if(timer1Counter <= 0){
			timer1Flag = 1;
		}
	}
}
