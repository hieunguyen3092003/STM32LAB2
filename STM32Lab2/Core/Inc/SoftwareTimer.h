/*
 * SoftwareTimer.h
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timer1Flag;
//Ex1
extern int sevenSegBuffer;
extern int sevenSegFlag;

//example
void setTimer1(int duration);
void timerRun();

//ex1 function
void sevenSegSetTimer(int duration);
void sevenSegRun();

#endif /* INC_SOFTWARETIMER_H_ */
