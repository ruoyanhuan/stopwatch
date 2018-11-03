#include "clock.h"
#include <graphics.h>

/*����0x1c���жϣ�ÿ�ε���ʹ��ʱ������1*/

unsigned long int TIME = 0;
unsigned long int CLOCK = 0;		//���ڼ�¼��Ϸʱ��
void interrupt far(*OldClock)();  //��ʱ���ж�

void interrupt NewClock()	//��ʱ���ж�
{
	TIME += 1;
}

//����ʱ���жϣ�����������
void InstallClock()
{
	disable();
	OldClock = getvect(0x1c);
	setvect(0x1c, NewClock);
	enable();
}

//��ԭʱ���жϣ�����������
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

void Break_Clock()			//��ͣ
{
	CLOCK = TIME;
}

void Stop_Clock()			//ֹͣ
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

//�Ǳ�׼ʱ��ת������׼ʱ��
void TtoS(double T, TIME_STD* std)
{
		while (T >= 60)
		{
			T -= 60;
			std->t_f += 1;
		}
	std->t_m = T;
}

//��׼ʱ��ת�����Ǳ�׼ʱ��
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

//����ʼʱ���ã������ж�
void Install()
{
	InstallKeyboard();
	InstallClock();
}

//�������ʱ���ã���ԭ�ж�
void ShutDown()
{
	ShutDownClock();
	ShutDownKeyboard();
}

//�ڵ�ǰλ����ʾʱ��
void clock(int left, int up)
{
	double T;		//ʱ�����T
	TIME_STD std;		//����
	char Ta[10];	//ʱ���ַ���Ta
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
	outtextxy(left+16, up, Ta);			//8x8����
}