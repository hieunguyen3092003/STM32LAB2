/*
 * SoftwareTimer.h
 *
 *  Created on: Oct 5, 2023
 *      Author: hieun
 */

#ifndef INC_SOFTWARETIMER_H_
#define INC_SOFTWARETIMER_H_

extern int timer1Flag;
extern int seg7Counter;
extern int seg7Buffer;

void setTimer1(int duration);
void timerRun();

#endif /* INC_SOFTWARETIMER_H_ */
