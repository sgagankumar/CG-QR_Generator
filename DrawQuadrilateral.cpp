#include<GL/glut.h>
void drawRectangle(float xmin, float ymin, float xmax, float ymax)
{
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

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
	drawRectangle(-250.0, -250.0, 250.0, 250.0);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Draw Rectangle");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(display);
	glutMainLoop();
}