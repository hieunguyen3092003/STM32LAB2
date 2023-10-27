/*
 * SoftwareTimer.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#include <SoftwareTimer.h>

int timer1Counter = 0;
int timer1Flag = 0;
//ex5 variables
int hour = 15, minute = 8, second = 50;
//ex5 variables
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

//EX9
int timer3Counter = 0;
int timer3Flag = 0;

void setTimer3(int duration){
	timer3Counter = duration;
	timer3Flag = 1;
}
void timerRun3(){
	if (timer3Counter > 0){
		timer3Counter--;
		if (timer3Counter <= 0){
			timer3Flag = 1;
		}
	}
}
