#include <iostream>
#include <thread>
#include <GL/glut.h>

void render(void);

void keyboard(unsigned char c, int x, int y);

void mouse(int button, int state, int x, int y);

void test()
{
	std::cout<<"Test func!!"<<std::endl;
}

void renderThread(void);

int main( int argc, char** argv )
{
	std::cout<<"Hello World!"<<std::endl;
	test();
	std::thread t(test);
	t.join();

//initialise GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode( GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA );
	glutInitWindowPosition( 100, 100 );
	glutInitWindowSize( 640, 480 );
	glutCreateWindow( "Test Glut App" );
//GLUT initialised, now render
	std::thread render(renderThread);
	render.join();	
//glutDisplayFunc(render);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	glutMainLoop();
	return 0;
}

//keyboard handler
void keyboard(unsigned char c, int x, int y)
{
	switch (c){
	//escape key, exit
	case 27: std::cout<<"Key "<<c<<" pressed"<<std::endl;	
		exit(0);
		break;	
	default: std::cout<<"Unhandled Key Press ("<<c<<")"<<std::endl;
	}
	
}

//mouse handler
void mouse(int button, int state, int x, int y)
{
	switch (button){
	case GLUT_LEFT_BUTTON: std::cout<<"LEFT BUTTON CLICKED"<<std::endl;
		break;
	//right mouse, exit
	case GLUT_RIGHT_BUTTON: std::cout<<"RIGHT BUTTON CLICKED"<<std::endl;
		exit(0);
		break;
	default: std::cout<<"Unhandled Button Click"<<std::endl;
		break;
	}

}

void render(void)
{
//clear the screen
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
//begin and end necessary
	glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(-0.5, -0.5);
		glColor3f(0,1,0);
		glVertex2f(0.5, -0.5);
		glColor3f(0,0,1);
		glVertex2f(0.0, 0.5);
	glEnd();
//cant remember what this is about
	glutSwapBuffers();	
}

void renderThread(void)
{
	glutDisplayFunc(render);
}
