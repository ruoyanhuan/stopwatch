#include "MultiKey.h"
#include "clock.h"
#include <graphics.h>
#include <string.h>

void main()
{
	int  Flag=BREAK;
	double T;
	char a[10];
	int gd=VGA,gm=VGAHI;
	InstallKeyboard();
	InstallClock();
	initgraph(&gd,&gm,"c:\\borlandc\\bgi");
	outtextxy(300,10,"0.00");
	while(1)
	{
		if(KeyPress(KEY_ENTER))
		{
			if(Flag==BREAK)
			{
				Start_Clock();
				Flag=START;
			}
		}
		else if(KeyPress(KEY_SPACE))
		{
			if(Flag==START)
			{
				Break_Clock();
			}	Flag=BREAK;
		}
		else if(KeyPress(KEY_BACKSPACE))
		{
			Stop_Clock();
			cleardevice();
			outtextxy(300,10,"0.00");
			Flag=BREAK;
		}
		if(Flag==START)
		{
			clock(100,100);
			delay(30);
		}
		if(KeyPress(KEY_LQUOTE))
			break;
	}
	ShutDownKeyboard();
	ShutDownClock();
}