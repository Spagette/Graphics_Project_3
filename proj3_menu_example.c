#include <GL/glut.h>
#include <stdlib.h>


void createMenu(void);
void menu(int value);
void disp(void);

static int win;
static int menuExit;
static int menuT;
static int menuQ;
static int val = 0;
static int quadR = 1;
static int quadG = 0;
static int quadB = 0;
static int triR = 1;
static int triG = 0;
static int triB = 0;

int main(int argc, char **argv){
	
	// normal initialisation
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	
	win = glutCreateWindow("GLUT MENU");
	
	// put all the menu functions in one nice procedure
	createMenu();
	
	// set the clearcolor and the callback
	glClearColor(0.0,0.0,0.0,0.0);
	
	glutDisplayFunc(disp);
	
	// enter the main loop
	glutMainLoop();
	
}
void createMenu(void){
	//////////
	// MENU //
	//////////
	
	menuT = glutCreateMenu(menu);
	
	// Add sub menu entry
	glutAddMenuEntry("Set Red", 1);
	glutAddMenuEntry("Set Green", 2);
	glutAddMenuEntry("Set Blue", 3);
	
	menuQ = glutCreateMenu(menu);
	
	glutAddMenuEntry("Set Red", 4);
	glutAddMenuEntry("Set Green", 5);
	glutAddMenuEntry("Set Blue", 6);
					 
	menuExit = glutCreateMenu(menu);
	
	// Create an entry
	glutAddSubMenu("Triangle", menuT);
	glutAddSubMenu("Quad", menuQ);
	glutAddMenuEntry("Exit", 0);
	
	// Let the menu respond on the right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	
}

void disp(void){
	// Just clean the screen
	glClear(GL_COLOR_BUFFER_BIT);
	
	if(val == 1){
		triR = 1;
		triG = 0;
		triB = 0;
	}
	else if(val == 2){
		triR = 0;
		triG = 1;
		triB = 0;
	}
	else if(val == 3){
		triR = 0;
		triG = 0;
		triB = 1;
	}
	else if(val == 4){
		quadR = 1;
		quadG = 0;
		quadB = 0;
	}
	else if(val == 5){
		quadR = 0;
		quadG = 1;
		quadB = 0;
	}
	else if(val == 6){
		quadR = 0;
		quadG = 0;	
		quadB = 1;
	}

	glColor3f(quadR, quadG, quadB);
	glBegin(GL_QUADS);
		glVertex2f(-1.0f, -1.0f);
		glVertex2f(-0.25f, -1.0f);
		glVertex2f(-0.25f, -0.25f);
		glVertex2f (-1.0f, -0.25f);
    glEnd();

	glColor3f(triR, triG, triB);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 0.0f);
		glVertex2f(0.5f, 0.0f);
		glVertex2f(0.25f, 0.75f);
    glEnd();

	glFlush();
}



void menu(int value){
	if(value == 0){
		glutDestroyWindow(win);
		exit(0);
	}else{
		val=value;
	}
	
	// you would want to redraw now
	glutPostRedisplay();
}