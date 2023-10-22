/*
 * SoftwareTimer.c
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#include <SoftwareTimer.h>

int timer1Flag = 0;
int timer1Counter = 0;

//Ex1
int sevenSegFlag = 0;
int sevenSegBuffer = 0;
int sevenSegCounter = 0;

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
//Ex1 function
void sevenSegSetTimer(int duration){
	sevenSegCounter = duration;
	sevenSegFlag = 1;
}

void sevenSegRun(){
	if(sevenSegCounter > 0) {
		sevenSegCounter--;
		if(sevenSegCounter <= 0){
			sevenSegFlag = 1;
		}
	}
}

