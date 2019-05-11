#include<GL/glut.h>
#include<stdio.h>

int A[21][21]= 
{ {1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,1},
{1,0,0,0,0,0,1,0,1,1,0,1,1,0,1,0,0,0,0,0,1},
{1,0,1,1,1,0,1,0,0,1,1,1,0,0,1,0,1,1,1,0,1},
{1,0,1,1,1,0,1,0,0,1,0,1,1,0,1,0,1,1,1,0,1},
{1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1},
{1,0,0,0,0,0,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1},
{1,1,1,1,1,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1},
{0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0},
{1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,1,1},
{1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,0,1,0,0,1},
{0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,0,0,0,1,1,0},
{0,1,0,1,1,0,0,1,1,1,1,0,1,0,0,0,1,0,1,1,0},
{0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,1,1,0,1,1,1,0,1,0,0,1},
{1,1,1,1,1,1,1,0,0,0,0,1,1,1,0,1,1,1,1,1,0},
{1,0,0,0,0,0,1,0,1,1,0,1,0,1,1,1,0,0,1,0,1},
{1,0,1,1,1,0,1,0,0,0,1,1,1,1,1,1,1,0,0,1,1},
{1,0,1,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0},
{1,0,1,1,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,1,1},
{1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1},
{1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,0,1,1,1,1} };




void drawBlock(int i, int j)
{
	int xmin, ymin, xmax, ymax;
	xmin = (20 + (i * 20));
	ymin = (20 + (j * 20));
	xmax = xmin + 20;
	ymax = ymin + 20;
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_POLYGON);
	glVertex2f(xmin, ymin);
	glVertex2f(xmin, ymax);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymin);
	glEnd();
	glFlush();
}


void initArray()
{

}

void drawQR()
{
	int i, j;
	for (i = 0; i < 21; i++)
	{
		for (j = 0; j < 21; j++)
		{
			if (A[i][j] == 1)
			{
				drawBlock(i, j);
			}
		}	
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, 460, 0, 460);
	drawQR();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Draw Rectangle");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutMainLoop();
}