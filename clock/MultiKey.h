

#ifndef _MULTIKEY_H_
#define _MULTIKEY_H_


#define KEY_A 0x1E
#define KEY_B 0x30
#define KEY_C 0x2e
#define KEY_D 0x20
#define KEY_E 0x12
#define KEY_F 0x21
#define KEY_G 0x22
#define KEY_H 0x23
#define KEY_I 0x17
#define KEY_J 0x24
#define KEY_K 0x25
#define KEY_L 0x26
#define KEY_M 0x32
#define KEY_N 0x31
#define KEY_O 0x18
#define KEY_P 0x19
#define KEY_Q 0x10
#define KEY_R 0x13
#define KEY_S 0x1f
#define KEY_T 0x14
#define KEY_U 0x16
#define KEY_V 0x2f
#define KEY_W 0x11
#define KEY_X 0x2d
#define KEY_Y 0x15
#define KEY_Z 0x2c
#define KEY_1 0x02
#define KEY_2 0x03
#define KEY_3 0x04
#define KEY_4 0x05
#define KEY_5 0x06
#define KEY_6 0x07
#define KEY_7 0x08
#define KEY_8 0x09
#define KEY_9 0x0a
#define KEY_0 0x0b
#define KEY_DASH 0x0c /* _- */
#define KEY_EQUAL 0x0d /* += */
#define KEY_LBRACKET 0x1a /* {[ */
#define KEY_RBRACKET 0x1b /* }] */
#define KEY_SEMICOLON 0x27 /* :; */
#define KEY_RQUOTE 0x28 /* "' */
#define KEY_LQUOTE 0x29 /* ~` */
#define KEY_PERIOD 0x33 /* >. */
#define KEY_COMMA 0x34 /* <, */
#define KEY_SLASH 0x35 /* ?/ */
#define KEY_BACKSLASH 0x2b /* |\ */
#define KEY_F1 0x3b
#define KEY_F2 0x3c
#define KEY_F3 0x3d
#define KEY_F4 0x3e
#define KEY_F5 0x3f
#define KEY_F6 0x40
#define KEY_F7 0x41
#define KEY_F8 0x42
#define KEY_F9 0x43
#define KEY_F10 0x44
#define KEY_ESC 0x01
#define KEY_BACKSPACE 0x0e
#define KEY_TAB 0x0f
#define KEY_ENTER 0x1c
#define KEY_CONTROL 0x1d
#define KEY_LSHIFT 0x2a
#define KEY_RSHIFT 0x36
#define KEY_PRTSC 0x37
#define KEY_ALT 0x38
#define KEY_SPACE 0x39
#define KEY_CAPSLOCK 0x3a
#define KEY_NUMLOCK 0x45
#define KEY_SCROLLLOCK 0x46
#define KEY_HOME 0x47
#define KEY_UP 0x48
#define KEY_PGUP 0x49
#define KEY_MINUS 0x4a
#define KEY_LEFT 0x4b
#define KEY_CENTER 0x4c
#define KEY_RIGHT 0x4d
#define KEY_PLUS 0x4e
#define KEY_END 0x4f
#define KEY_DOWN 0x50
#define KEY_PGDOWN 0x51
#define KEY_INS 0x52
#define KEY_DEL 0x53

/**********************************************************
Function：      ShutDownKeyboard

Description：   恢复9H之前的中断函数

Input：      None
Output：     None
Return：     None
Others：     None
**********************************************************/
void ShutDownKeyboard(void); 

/**********************************************************
Function：      NewInt9

Description：   新的中断函数

Input：      None
Output：     None
Return：     None
Others：     None
**********************************************************/                   
void far interrupt NewInt9(void);              

/**********************************************************
Function：      InstallKeyboard

Description：   将新中断写入向量表，并保存旧的中断

Input：      None
Output：     None
Return：     None
Others：     None
**********************************************************/ 
void InstallKeyboard(void);                     

/**********************************************************
Function：      GetKey

Description：   检测给定按键是否按下过

Input：      int ScanCode         给定按键键值，见文件开头的宏定义  

Output：     None
Return：     None
Others：     None
**********************************************************/ 
int GetKey(int ScanCode);                      

/**********************************************************
Function：     KeyPress

Description：   检测给定按键当前是否处于按下状态

Input：      int ScanCode         给定按键键值，见文件开头的宏定义  

Output：     None
Return：     None
Others：     None
**********************************************************/ 
int KeyPress(int ScanCode);                    


#endif
