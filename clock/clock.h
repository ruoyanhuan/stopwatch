#ifndef _CLOCK_H_
#define _CLOCK_H_

#include <dos.h>
#include <conio.h>
#include "MultiKey.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define programsize 400

#define START 1
#define BREAK 0
#define ENTER KEY_ENTER
#define BACKSPACE KEY_BACKSPACE
#define SPACE KEY_SPACE

typedef struct TIME_STD			//标准时间，即带分，带秒
{
	int t_f;
	double t_m;
}TIME_STD;
/*更改0x1c软中断 每次调用使他令计时器TIME自增1*/

void far interrupt NewClock();	//新时间中断
void InstallClock();
void ShutDownClock();
void Break_Clock();			//暂停
void Stop_Clock();			//停止
void Start_Clock();
double GetClock();				//获取游戏进行的时间，返回为单位为秒
void ftoa(double fn, int prec, char *s);
void clock(int left, int up);
void Init_TS(TIME_STD *std);
void TtoS(double T, TIME_STD* std);
double StoT(TIME_STD std);
void Install();
void ShutDown();

#endif // !_CLOCK_H_

