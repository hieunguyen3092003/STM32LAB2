/*
 * SoftwareTimer.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#include <SoftwareTimer.h>

int timer1Counter = 0;
int timer1Flag = 0;

void setTimer1(int duration){
	timer1Counter = duration;
	timer1Flag = 0;
}

void timerRun(){
	if (timer1Counter > 0){
		timer1Counter--;
		if (timer1Counter <= 0){
			timer1Flag = 1;
		}
	}
}

// ex 4
int timer2Counter = 0;
int timer2Flag = 0;

void setTimer2(int duration){
	timer2Counter = duration;
	timer2Flag = 1;
}
void timerRun2(){
	if (timer2Counter > 0){
		timer2Counter--;
		if (timer2Counter <= 0){
			timer2Flag = 1;
		}
	}
}
