#include <windows.h>
#include "glut.h"
#include <math.h>


void text(float x, float y, float z, void *font, char *string);

void Display(void)
{
	glClearColor(0.3, 0.5, 0.7, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//	glRotated(0.4, 1, 1, 1);      //движ. само
	//	glPushMatrix();
	//	gluLookAt(x, y, z,  x-sin(angleX / 180 * pi),y+tan(angleY / 180 * pi), z-cos(angleX / 180 * pi), 0, 1, 0);
	//	glTranslatef(0,0,0);

	glColor3d(1, 0, 0.5);

	//	text(0,0,0,GLUT_BITMAP_TIMES_ROMAN_24,"ouyui");

	glutSolidTorus(20, 50, 16, 16);
	glPopMatrix();

	glFinish();
	glutSwapBuffers();
	glutPostRedisplay();
}


void Keyboard(unsigned char Key, int X, int Y)
{
	if (Key == 27) exit(30);
}


void Keyboard_s(int Key, int X, int Y)
{
	if (Key == GLUT_KEY_UP) glRotated(5.0, 1.0, 0.0, 0.0);
	if (Key == GLUT_KEY_RIGHT) glRotated(-5.0, 0.0, 1.0, 0.0);
	if (Key == GLUT_KEY_LEFT) glRotated(5.0, 0.0, 1.0, 0.0);
	if (Key == GLUT_KEY_DOWN) glRotated(-5.0, 1.0, 0.0, 0.0);
	if (Key == GLUT_KEY_END) glRotated(5.0, 0.0, 0.0, 1.0);
}


/*
void Keyboard_s(int Key, int X, int Y)
{
const float speed = 5;

switch (Key)
{
case 'w':  x += -sin(angleX / 180 * pi) * speed;
//cords.at(1) += tan(angleY / 180 * pi) * speed;
z += -cos(angleX / 180 * pi) * speed;
break;
case 'a':  x += sin((angleX - 90) / 180 * pi) * speed;
x += cos((angleX - 90) / 180 * pi) * speed;
break;
case 's': x += sin(angleX / 180 * pi) * speed;
//cords.at(1) += -tan(angleY / 180 * pi) * speed;
y += cos(angleX / 180 * pi) * speed;
break;
case 'd': x += sin((angleX + 90) / 180 * pi) * speed;
x += cos((angleX + 90) / 180 * pi) * speed;
break;
}
}
*/


void layts()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);

	float light0_direction[] = { 100.0, 0.0, 100.0, 1.0 }; //точечное освещение
	glLightfv(GL_LIGHT0, GL_POSITION, light0_direction);

	gluLookAt(-5, 0, -50,      //где камера      //зависет от glOrtho
		0, 0, 0,            //куда смотрит
		0, 5, 0);           //вверх 

}


void text(float x, float y, float z, void *font, char *string)
{
	char *c;
	glRasterPos3f(x, y, z);
	for (c = string; *c != '\0'; c++) glutBitmapCharacter(font, *c);
}


void main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("мяу");
	//	glEnable(GL_DEPTH);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);

	layts();                                                 //свет

	glutDisplayFunc(Display);

	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(Keyboard_s);
	//	glutReshapeFunc(Reshape);
	glutFullScreen();
	glutIdleFunc(Display);


	glutMainLoop();
}