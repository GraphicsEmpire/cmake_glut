#include <iostream>
#include <stdio.h>
#include "GL/freeglut.h"

//prototypes
void draw();
void resize();
void normalKey(unsigned char key, int x, int y);
void specialKey(int key, int x, int y);
void closeApp();

//Impl
void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glDisable(GL_LIGHTING);
	glColor3f(1,0,0);	
	glBegin(GL_TRIANGLES);
	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);
	glVertex3f(0, 1, 0);
	glEnd();
	glEnable(GL_LIGHTING);

	glutSwapBuffers();
}

void resize(int w, int h) {
  glViewport(0, 0, w, h);
    
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//glOrtho(-1,1,-1,1,-1,1);
	glOrtho(-2.0f, 2.0f, -2.0f, 2.0f, -2.0f, 2.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void normalKey(unsigned char key, int x, int y) {
	printf("pressed normal key is %c\n", key);
	
	int mod = glutGetModifiers();
	if (mod != 0)  {
	  //ALT=4  SHIFT=1  CTRL=2      
          switch(mod)
          {
             case 1 :  printf("SHIFT key %d\n",mod);  break;
             case 2 :  printf("CTRL  key %d\n",mod);  break;
             case 4 :  printf("ALT   key %d\n",mod);  break;
             mod=0;
          }
    	}

	switch(key) {
	case(27): {
		closeApp();
		break;
	}
	}
}


void specialKey(int key, int x, int y) {
	printf("pressed key is %d\n", key);


	switch(key) {
	case(GLUT_KEY_F1): {
		printf("Key F1 is pressed.\n");
	}
	break;
	case(GLUT_KEY_F2): {
		printf("Key F2 is pressed.\n");
	}
	break;
	case(GLUT_KEY_F3): {
		printf("Key F3 is pressed.\n");
	}
	break;
	case(GLUT_KEY_F4): {
		printf("Key F4 is pressed.\n");
	}
	break;


	case(GLUT_KEY_F5): {
		printf("Key F5 is pressed.\n");
	}
	break;
	case(GLUT_KEY_F6): {
		printf("Key F6 is pressed.\n");
	}
	break;
	case(GLUT_KEY_F7): {
		printf("Key F7 is pressed.\n");
	}
	break;
	case(GLUT_KEY_F8): {
		printf("Key F8 is pressed.\n");
	}
	break;


	}
}

void initGL() {
	//Setup Shading Environment
	static const GLfloat lightColor[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
	static const GLfloat lightPos[4] = { 0.0f, 9.0f, 0.0f, 1.0f };

	//Setup Light0 Position and Color
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightColor);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

	//Turn on Light 0
	glEnable(GL_LIGHT0);
	//Enable Lighting
	glEnable(GL_LIGHTING);
	glEnable(GL_LINE_SMOOTH);

	//Enable features we want to use from OpenGL
    	glEnable(GL_TEXTURE_2D);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_STENCIL_TEST);
    	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);

    	glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glClearColor(0.45f, 0.45f, 0.45f, 1.0f);
}


void closeApp() {
	printf("closing the app. store all settings and cleanup!\n");
glutLeaveMainLoop();
}

int main(int argc, char* argv[]) {
	
	//glut
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(400, 400);
	glutCreateWindow("glut keys");
	glutDisplayFunc(draw);
	glutReshapeFunc(resize);
	glutKeyboardFunc(normalKey);
	glutSpecialFunc(specialKey);
	glutCloseFunc(closeApp);

	initGL();

	glutPostRedisplay();

	glutMainLoop();

	return 0;
}
