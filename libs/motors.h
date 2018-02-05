
#ifndef MOTORS_H
#define MOTORS_H

#include "mbed.h"
#include "qei.h"
#include "pid.h"

#define PERIOD_REFRESH 0.001f
#define PERIOD_PWM 0.000033f
#define MIN_DUTY 0.05f
#define MAX_DUTY 0.50f

#define DIR_STOP 0
#define DIR_FORWARD 1
#define DIR_BACKWARD 2
#define DIR_BREAK 3

#define min(x, y) ((x)<(y) ? (x) : (y))

class Motor {
	public:
		Motor(PwmOut*, DigitalOut*, DigitalOut*, Timer*);
		~Motor();
	protected:
		void SetPwm(float, int*);
		void SetDirection(unsigned char, int*);
	private:
		float _duty;
		unsigned short _dir;
		PwmOut* _pwm;
		DigitalOut* _dir0;
		DigitalOut* _dir1;
		Timer* _timer;
};

class Block {
	public:
		Block(Motor*, Qei*, Pid*, Ticker*);
		~Block();
		float GetSpeed();
		void SetSpeed(float);
	private:
		void Refresh();
		_SPspeed;
		_PVspeed;
		Motor* _motor;
		Qei* _qei;
		Pid* _pid;
		Ticker* _ticker;

};


#endif
