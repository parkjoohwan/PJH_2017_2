#include<gl\glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#define SIZE 300

int select = 1;
int Width=SIZE*2;
int Height=SIZE;

bool bPressed = false;
int pX, pY;

// mouse click
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
	bPressed = true;
	pX = X; pY = Y; 
	} 
	else bPressed = false;
}

// mouse motion
void MyMouseMove(GLint X, GLint Y) {
	if( bPressed ) {
		int dx = X - pX;
		int dy = Y - pY;
		pX = X; pY = Y;
		glRotatef( dx, 0.0, 1.0, 0.0 );
		glRotatef( dy, 1.0, 0.0, 0.0 );
		glutPostRedisplay();
	}
}

// myname
void MyName() {

	// P
	glBegin(GL_QUADS);
	glVertex3f(-45, -30, 0);
	glVertex3f(-45, 30, 0);
	glVertex3f(-40, 30, 0);
	glVertex3f(-40, -30, 0);
	glVertex3f(-40, 30, 0);
	glVertex3f(-30, 30, 0);
	glVertex3f(-30, 25, 0);
	glVertex3f(-40, 25, 0);
	glVertex3f(-30, 30, 0);
	glVertex3f(-25, 30, 0);
	glVertex3f(-25, 15, 0);
	glVertex3f(-30, 15, 0);
	glVertex3f(-40, 15, 0);
	glVertex3f(-25, 15, 0);
	glVertex3f(-25, 10, 0);
	glVertex3f(-40, 10, 0);

	//J

	glVertex3f(-15, 30, 0);
	glVertex3f(-15, 25, 0);
	glVertex3f(10, 25, 0);
	glVertex3f(10, 30, 0);
	glVertex3f(0, 25, 0);
	glVertex3f(0, -30, 0);
	glVertex3f(5, -30, 0);
	glVertex3f(5, 25, 0);
	glVertex3f(0, -30, 0);
	glVertex3f(0, -25, 0);
	glVertex3f(-15, -25, 0);
	glVertex3f(-15, -30, 0);


	//H
	glVertex3f(20, 30, 0);
	glVertex3f(20, -30, 0);
	glVertex3f(25, -30, 0);
	glVertex3f(25, 30, 0);
	glVertex3f(25, 2.5, 0);
	glVertex3f(35, 2.5, 0);
	glVertex3f(35, -2.5, 0);
	glVertex3f(25, -2.5, 0);
	glVertex3f(35, 30, 0);
	glVertex3f(35, -30, 0);
	glVertex3f(40, -30, 0);
	glVertex3f(40, 30, 0);

	glEnd();
	glFlush( );

}
// cube, sphere, torus, cone, pot
void Draw(){
	switch(select){
	case 1 :
		glutWireCube(30); break;
	case 2 :
		glutWireSphere(30, 20, 20); break;
	case 3 :
		glutWireTorus(10, 20, 20, 20); break;
	case 4 :
		glutWireCone(20, 20, 20, 20); break;
	case 5 :
		glutWireTeapot(30); break;
	default :
		break;
	}
	glFlush();
}
// display
void Display(){

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);	// 그림 그릴 선의 색깔

	// 왼쪽
	glViewport(0, 0, Width/2, Height);
	MyName();
	// 오른쪽
	glViewport( Width/2, 0, Width/2, Height);
	Draw();

}
// keyboard callback
void DoKeyboard(unsigned char KeyPressed, int x, int y)
{
	switch(KeyPressed){
	case 'C' :
		select = 1; break;
	case 'S' :
		select = 2; break;
	case 'T' :
		select = 3; break;
	case 'N' :
		select = 4; break;
	case 'P' :
		select = 5; break;
	case 'Q' :
		exit(0); break;
	case 'q' :
		exit(0); break;
	case 27 :
		exit(0); break;
	default :
		break;
	}
	glutPostRedisplay(); //화면다시그리기
}
// main menu
void MyMainMenu(int sel) {
	switch(sel){
	case 1 :
		select = 1; break;
	case 2 :
		select = 2; break;
	case 3 :
		select = 3; break;
	case 4 :
		select = 4; break;
	case 5 :
		select = 5; break;
	}
	glutPostRedisplay();
}
// Reshape 
void MyReshape(int w, int h) {
	Width=w;
	Height=h;
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut초기화
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize( 2*SIZE , SIZE );	//초기화는 윈도우 만들기 전에 할것
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); //
	glLoadIdentity();
	glOrtho(-50,50,-50,50,-50,50); // 좌우하상

	
	glutDisplayFunc(Display);		// 출력
	glutKeyboardFunc(DoKeyboard);   // 키보드입력 이벤트처리
	glutMouseFunc(MyMouseClick);	// 마우스클릭 이벤트처리
    glutMotionFunc(MyMouseMove);	// 마우스무브 이벤트처리

	// 메뉴 콜백
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Cube", 1);
	glutAddMenuEntry("Sphere", 2);
	glutAddMenuEntry("Torus", 3);
	glutAddMenuEntry("Cone", 4);
	glutAddMenuEntry("Teapot", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutReshapeFunc(MyReshape);		// 리쉐이프
	glutMainLoop( );
	return 0;
}