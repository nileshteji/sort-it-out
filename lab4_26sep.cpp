#include <math.h>
#include <GL/glut.h>

struct Point {
	GLint x;
	GLint y;
};

struct Color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
};

void init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 400, 0, 400);
}

Color getPixelColor(GLint x, GLint y) {
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	return color;
}

void setPixelColor(GLint x, GLint y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
	glFlush();
}

void floodFill(GLint x, GLint y, Color oldColor, Color newColor) {
	Color color;
	color = getPixelColor(x, y);

	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		setPixelColor(x, y, newColor);
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	return;
}

void onMouseClick(int button, int state, int x, int y)
{
	Color newColor = {1.0f, 0.5f, 0.7f};
	Color oldColor = {0.5f, 0.5f, 0.6f};

	floodFill(320, 240, oldColor, newColor);
}

void draw_polygon() {
	/*
		glBegin(GL_LINE_LOOP);//start drawing a line loop
		//glColor3f(0.0,1.0,0.0);
      glVertex3f(60.0f,10.0f,0.0f);//left of window
      glVertex3f(60.0f,60.0f,0.0f);//right of window
      glVertex3f(10.0f,60.0f,0.0f);//top of window
      glVertex3f(10.0f,10.0f,0.0f);///bottom of widnow
    glEnd();
    glFlush();    */
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.5f,1.0f);
            glVertex2i(100,100);
            glVertex2i(20,20);
            glVertex2i(100,20);
            glVertex2i(20,100);
        glEnd();
        glFlush();
 	}


void display(void) {
	

	glClear(GL_COLOR_BUFFER_BIT);
	
		draw_polygon();
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("FLOOD FILL");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(onMouseClick);
	glutMainLoop();
	return 0;
}
