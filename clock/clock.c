#include "clock.h"
#include <graphics.h>

/*更改0x1c软中断，每次调用使计时器自增1*/

unsigned long int TIME = 0;
unsigned long int CLOCK = 0;		//用于记录游戏时间
void interrupt far(*OldClock)();  //旧时间中断

void interrupt NewClock()	//新时间中断
{
	TIME += 1;
}

//更改时间中断，不单独调用
void InstallClock()
{
	disable();
	OldClock = getvect(0x1c);
	setvect(0x1c, NewClock);
	enable();
}

//还原时间中断，不单独调用
void ShutDownClock()
{
	disable();
	setvect(0x1c, OldClock);
	enable();
}

void Start_Clock()
{
	TIME = CLOCK;
}

void Break_Clock()			//暂停
{
	CLOCK = TIME;
}

void Stop_Clock()			//停止
{
	TIME = 0;
	CLOCK = 0;
}

double GetClock()
{
	CLOCK = TIME;
	return CLOCK / 18.2;
}

void ftoa(double fn, int prec, char *s)
{
	int ival, fval, pow;
	ival = (int)fn;

	for (pow = 1; prec > 0; prec--)
		pow *= 10;

	fval = (int)((fn - ival) * pow);

	if (fn < 0)
		*s++ = '-';

	itoa(abs(ival), s, 10);
	while (*s)
		s++;

	if (fval != 0)
	{
		*s++ = '.';
		itoa(abs(fval), s, 10);
	}
}

void Init_TS(TIME_STD *std)
{
	std->t_f = 0;
	std->t_m = 0;
}

//非标准时间转换至标准时间
void TtoS(double T, TIME_STD* std)
{
		while (T >= 60)
		{
			T -= 60;
			std->t_f += 1;
		}
	std->t_m = T;
}

//标准时间转换至非标准时间
double StoT(TIME_STD std)
{
	double T = 0;
	while (std.t_f >= 1)
	{
		T += 60;
		std.t_f -= 1;
	}
	T += std.t_m;
	return T;
}

//程序开始时调用，更改中断
void Install()
{
	InstallKeyboard();
	InstallClock();
}

//程序结束时调用，还原中断
void ShutDown()
{
	ShutDownClock();
	ShutDownKeyboard();
}

//在当前位置显示时间
void clock(int left, int up)
{
	double T;		//时间变量T
	TIME_STD std;		//分钟
	char Ta[10];	//时间字符串Ta
	T = GetClock();
	Init_TS(&std);
	TtoS(T, &std);
	itoa(std.t_f,Ta,10);
	setfillstyle(1, BLACK);
	bar(left, up, left + 80, up + 10);
	setcolor(WHITE);
	outtextxy(left, up, Ta);
	outtextxy(left + 8, up, ".");
	ftoa(std.t_m, 2, Ta);
	outtextxy(left+16, up, Ta);			//8x8点阵
}