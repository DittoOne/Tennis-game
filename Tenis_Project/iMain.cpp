#include "iGraphics.h"

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
int box_x = 87;
int box_y = 10;
double box_x1 = 153;
double box_y1 = 370;
double box_width1 = 100;
double box_height1 = 20;
int box_width = 100;
int box_height = 20;
double ball_x = 200;
double ball_y = 200;
double ball_r = 10;
int index1;
int score = 0;
double dx = 5;
double dy = 7;
void iDraw()
{
	iClear();


	iSetColor(255, 0, 0);
	iFilledRectangle(box_x, box_y, box_width1, box_height1);

	iSetColor(0, 255, 0);
	iFilledRectangle(0, 200, 400, 5);

	iSetColor(0, 255, 0);
	iCircle(200, 200, 50);

	iSetColor(0, 255, 0);
	iLine(390, 0, 390, 400);

	iSetColor(0, 255, 0);
	iLine(10, 0, 10, 400);

	iSetColor(0, 255, 0);
	iLine(0, 390, 400, 390);

	iSetColor(0, 255, 0);
	iLine(0, 10, 400, 10);

	iSetColor(255, 0, 0);
	iFilledRectangle(box_x1, box_y1, box_width, box_height);

	iSetColor(255, 255, 0);
	iFilledCircle(ball_x, ball_y, ball_r);

	iText(300, 360, "2p score: ");
	iText(300, 40, "1p score: ");

	iSetColor(0, 255, 255);
	iText(5, 360, "use 'a' & 'd' to move for 2p");

	iSetColor(0, 255, 255);
	iText(5, 40, "use mouse to move for 1p");

	if (ball_y  < 0 || ball_y + (2 * ball_r) > 400){
		score++;

		iPauseTimer(index1);
		iSetColor(255, 0, 255);
		iText(150, 240, "GAME OVER", GLUT_BITMAP_TIMES_ROMAN_24);
		iSetColor(255, 255, 0);
		iText(170, 220, "press 'home' to resume", GLUT_BITMAP_TIMES_ROMAN_10);

	}

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

	printf("mx =%d my =%d\n", mx, my);
}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

	if (box_x >= 0 && (box_x + box_width) < 600)
		box_x = mx;


	printf("mx =%d my =%d\n", mx, my);
}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (box_x >= 0)
			box_x -= 20;

	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		if ((box_x + box_width) < 600)
			box_x += 20;
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'a')
	{


		if (box_x1 - (box_width1 / 2) > 0)
			box_x1 -= 50;
	}
	if (key == 'd')
	{

		if ((box_x1 + box_width1) < 400)
			box_x1 += 50;
	}
	if (key == 'p')
	{
		iPauseTimer(index1);
	}


}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{
		
	}

	if (key == GLUT_KEY_HOME)
	{
		iResumeTimer(index1);
		ball_x = 200;
		ball_y = 200;
	}
	if (key == GLUT_KEY_F3)
	{
		
	}


}

void ballChange(){
	ball_x += dx;
	ball_y += dy;

	if (ball_x + (2 * ball_r) > 400 || ball_x   < 0)
	{

		dx = -dx;

	}

	if (ball_y > box_y1 && (ball_x >= box_x1 && ball_x <= box_x1 + box_width1) || (ball_y < box_y + box_height && (ball_x >= box_x&&ball_x <= box_x + box_width)))
	{
		dy = -dy;

	}

}

void ballfast(){
	dx = dx + 1;
	dy = dy + 1;
}
int main()
{
	index1 = iSetTimer(37, ballChange);
	//iSetTimer(5000, ballfast);
	///srand((unsigned)time(NULL));
	iInitialize(400, 400, "Project Title");

	///updated see the documentations
	iStart();
	return 0;
}