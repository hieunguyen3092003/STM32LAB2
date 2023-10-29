/*
 * SoftwareTimer.h
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_
//extern ex5 variables
extern int hour, minute, second;

extern int timer1Flag;
void setTimer1(int duration);

void timerRun();

extern timer2Flag;
void setTimer2(int duration);
void timerRun2();

//ex9:
extern int timer3Flag;
void setTimer3(int duration);
void timerRun3();

#endif /* INC_SOFTWARETIMER_H_ */
