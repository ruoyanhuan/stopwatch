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

typedef struct TIME_STD			//��׼ʱ�䣬�����֣�����
{
	int t_f;
	double t_m;
}TIME_STD;
/*����0x1c���ж� ÿ�ε���ʹ�����ʱ��TIME����1*/

void far interrupt NewClock();	//��ʱ���ж�
void InstallClock();
void ShutDownClock();
void Break_Clock();			//��ͣ
void Stop_Clock();			//ֹͣ
void Start_Clock();
double GetClock();				//��ȡ��Ϸ���е�ʱ�䣬����Ϊ��λΪ��
void ftoa(double fn, int prec, char *s);
void clock(int left, int up);
void Init_TS(TIME_STD *std);
void TtoS(double T, TIME_STD* std);
double StoT(TIME_STD std);
void Install();
void ShutDown();

#endif // !_CLOCK_H_

