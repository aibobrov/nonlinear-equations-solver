#include "plottingGraph.h"
#include "defines.h"

void key(unsigned char c, int x, int y){
	if (c == 27) { // key == 'ESC'
		exit(0);
	}
}

void reshape(int w, int h){
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void drawCoordinateLines(double x1, double x2, double y1, double y2){
	glBegin(GL_LINES);
	
	glVertex2d(0, y1); // Oy
	glVertex2d(0, y2);
	glVertex2d(0, y2); // Oy arrows
	glVertex2d(-0.15, y2 - 0.7);
	glVertex2d(0, y2);
	glVertex2d(0.15, y2 - 0.7);
	for (long long y = (long long) y1; y <= (long long) y2 - 1; y++) {
		glVertex2d(0.05, y);
		glVertex2d(-0.05, y);
	}
	
	glVertex2d(x1, 0); // Ox
	glVertex2d(x2, 0);
	glVertex2d(x2, 0); // Ox arrows
	glVertex2d(x2 - 0.7, 0.15);
	glVertex2d(x2, 0);
	glVertex2d(x2 - 0.7, -0.15);
	
	for (long long x = (long long) x1 + 1; x <= (long long) x2 - 1; x++) {
		glVertex2d(x, 0.1);
		glVertex2d(x, -0.1);
	}
	glEnd();
	glColor3f(0, 0, 1);
	for (long long y = (long long) y1; y <= (long long) y2 - 1; y++) { // Oy numbers
		if (!y)
			continue;
		string number = to_string(y);
		if (y > 0) {
			if (y >= 10)
				glRasterPos2d(-0.6, y - 0.1);
			else
				glRasterPos2d(-0.4, y - 0.1);
		} else {
			if (y <= -10)
				glRasterPos2d(-0.9, y - 0.1);
			else
				glRasterPos2d(-0.6, y - 0.1);
		}
		for (int i = 0; i < number.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, number[i]);
		}
	}
	for (long long x = (long long) x1; x <= (long long) x2 - 1; x++) { // Ox numbers
		if (!x)
			continue;
		string number = to_string(x);
		if (x > 0) {
			if (x >= 10)
				glRasterPos2d(x - 0.2, -0.7);
			else
				glRasterPos2d(x - 0.15, -0.7);
		} else {
			if (x <= -10)
				glRasterPos2d(x - 0.5, -0.7);
			else
				glRasterPos2d(x - 0.3, -0.7);
		}
		for (int i = 0; i < number.size(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_8_BY_13, number[i]);
		}
	}
	glRasterPos2d(-0.3, -0.6); // (0)
	glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '0');
}

void draw(double x1, double x2, double y1, double y2, int N){
	
	double dx = 1.0 / N;
	glPushMatrix();
	double scale = MIN(1.0 / (x2 - x1), 1.0 / (y2 - y1));
	glScalef(scale, scale, 1.0);
	glTranslatef(-x1, -x1, 0.0);
	glColor3f(0, 0, 0); // black line coordinate
	drawCoordinateLines(x1, x2, y1, y2);
	
	glColor3f(1, 0, 0); // red graph
	
	glBegin(GL_LINE_STRIP);
	
	for (double x = x1; x < x2; x += dx) {
		if ((expression.Eval(&x) > y2 + 10 || expression.Eval(&x) < y1 - 10) && x < x2) {
			glEnd();
			while ((expression.Eval(&x) > y2 + 10 || expression.Eval(&x) < y1 - 10) && x < x2) {
				x += dx;
			}
			glBegin(GL_LINE_STRIP);
		}
		double y = expression.Eval(&x);
		if (!expression.EvalError()) {
			glVertex2d(x, y);
		}
	}
	glEnd();
	glPopMatrix();
}

void redraw(){
	glClearColor(1, 1, 1, 1); // white
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	draw(-20, 20, -20, 20, 100);
	glutSwapBuffers();
}

void windowStart(int argc, char **argv, const char *titleOfWindow){
	//инициализация экрана
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(1280, 720);
	glutCreateWindow(titleOfWindow);
	glLineWidth(1.0);
	glEnable(GL_LINE_SMOOTH);
	
	//инициализация функций для построения
	glutDisplayFunc(redraw);
	glutKeyboardFunc(key);
	glutReshapeFunc(reshape);
}