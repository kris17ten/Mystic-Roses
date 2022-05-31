// #include loads up library files, the order can matter
// generally load glut.h last
#include <stdio.h>  // this library is for standard input and output
#include <stdlib.h>
#include "glut.h"// this library is for glut the OpenGL Utility Toolkit
#include <math.h> //for rotation and math-y stuff

int counter = 0;

// this is the initialisation function, called once only
void init2() {

	glClearColor(0.0, 0.0, 0.0, 0.0); // set what colour you want the background to be
	glMatrixMode(GL_PROJECTION); // set the matrix mode, we will look at this later
								 // set the projection window size in x an y. Window will then
								 // be mapped to the window created in the main function
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

void draw2() {
	const int NUMBEROFPOINTS = 18;
	//initialize point array
	//double ptAX[NUMBEROFPOINTS] = { (rand() % 150) };
	//double ptAY[NUMBEROFPOINTS] = {0};
	double ptAX[80] = { (20 + rand() % 150) };
	double ptAY[80] = { 0 };

	int pts = (int)(10 + (rand() % 30));
	//degree of rotation
	double degree = ((360.0/pts)/180.0) * 3.1415926;

	//find other points
	for (int i = 1; i < pts; i++) {
		double pt[2] = {
			(ptAX[i - 1] * cos(degree)) - (ptAY[i - 1] * sin(degree)),
			(ptAX[i - 1] * sin(degree)) + (ptAY[i - 1] * cos(degree))
		};
		ptAX[i] = pt[0];
		ptAY[i] = pt[1];
	}

	//drawing
	glBegin(GL_LINES);
	glLineWidth(2.0);
	//glColor3f(((counter+1) % 2), ((counter+11) % 2), ((counter+29) % 2));
	glColor3f((float)(rand() % 2), (float)(rand() % 2), (float)(rand() % 2));
	for (int a = 0; a < pts; a++) {
		for (int b = 0; b < pts; b++) {
			//glColor3f((float)(rand() % 2), (float)(rand() % 2), (float)(rand() % 2));
			glVertex2d(ptAX[a], ptAY[a]);
			glVertex2d(ptAX[b], ptAY[b]);
		}
	}
	glEnd();
}

void draw3() {
	const int NUMBEROFPOINTS = 40;
	//initialize point array
	double ptAX[NUMBEROFPOINTS] = { (rand() % 150) };
	//double ptAX[NUMBEROFPOINTS] = { 100 };
	double ptAY[NUMBEROFPOINTS] = { 0 };

	//degree of rotation
	double degree = (360.0 / NUMBEROFPOINTS);

	//find other points
	for (int i = 1; i < NUMBEROFPOINTS; i++) {
		double pt[2] = {
			(ptAX[i - 1] * cos(degree)) - (ptAY[i - 1] * sin(degree)),
			(ptAX[i - 1] * sin(degree)) + (ptAY[i - 1] * cos(degree))
		};
		ptAX[i] = pt[0];
		ptAY[i] = pt[1];
	}

	//drawing
	glBegin(GL_LINE_STRIP);
	glLineWidth(2.0);
	//glColor3f(((counter+1) % 2), ((counter+11) % 2), ((counter+29) % 2));
	glColor3f((float)(rand() % 2), (float)(rand() % 2), (float)(rand() % 2));
	for (int a = 0; a < NUMBEROFPOINTS; a++) {
			//glColor3f((float)(rand() % 2), (float)(rand() % 2), (float)(rand() % 2));
			glVertex2d(ptAX[a], ptAY[a]);
	}
	glEnd();
}

void display3() {
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen using the background colour
	
	if (counter % 15950 == 1) {
		draw2();
		//draw3();
	}
	glFlush(); // force all drawing to finish
	counter++;
}


// This is the idle function it is called whenever the program is idle
// This has the effect of repeatedly calling the display function
void idle2() {
		display3();
}


// As with many programming languages the main() function
// is the entry point for execution of the program
int main(int argc, char** argv) {
	glutInit(&argc, argv);  //perform the GLUT initialization
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // more initialisation
	glutInitWindowSize(600, 600); // set window position
	glutInitWindowPosition(200, 200); // set window size
	glutCreateWindow("Trying Here..."); // create a display with a given caption for the title bar
	init2(); // call init function defined above
	glutIdleFunc(idle2); //  define what function to call when the program is idle
	glutDisplayFunc(display3); // define what function to call to draw 
							  // the last function in the program puts the program into infinite loop
							  // effectively the loop repeatedly calls the idle function 
	glutMainLoop();

	// this line exits the program
	return 0;
}