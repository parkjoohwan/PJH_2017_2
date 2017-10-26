#include<gl\glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<stdio.h>

#define SIZE 300
int select = 1;
int pX, pY,lX,lY;

// mouse click
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		pX = X; 
		pY = Y; 
	} 
}
// mouse move
void MyMouseMove(GLint X, GLint Y) {
    lX = X; 
    lY = Y; 
    glutPostRedisplay();
}
// Line 그리기
void line(double x1, double y1, double x2, double y2){
	glBegin(GL_LINES);
	glVertex3f( x1/SIZE, (SIZE-y1)/SIZE, 0);
	glVertex3f( x2/SIZE, (SIZE-y2)/SIZE, 0);
	glEnd( );
	glFlush( );
}
// Rectangle 그리기
void Rectangle(double x1, double y1, double x2, double y2){
	glBegin(GL_LINE_LOOP);
	glVertex3f( x1/SIZE, (SIZE-y1)/SIZE, 0);
	glVertex3f( x1/SIZE, (SIZE-y2)/SIZE, 0);
	glVertex3f( x2/SIZE, (SIZE-y2)/SIZE, 0);
	glVertex3f( x2/SIZE, (SIZE-y1)/SIZE, 0);
	glEnd( );
	glFlush( );
}

// Line, Rectangle, Exit
void Draw(){
	switch(select){
	case 1 :
		line(pX,pY,lX,lY); break;
	case 2 :
		Rectangle(pX,pY,lX,lY); break;
	case 3 :
		exit(1); break;
	default :
		break;
	}
}
// display
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);	// 그림 그릴 선의 색깔
	Draw();
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
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut초기화
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize( SIZE , SIZE );	//초기화는 윈도우 만들기 전에 할것
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	glutMouseFunc(MyMouseClick);	// 마우스클릭 이벤트처리 
	glutMotionFunc(MyMouseMove);
	glutDisplayFunc(Display);		// 출력
	
	// 메뉴 콜백
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Line", 1);
	glutAddMenuEntry("Draw Rectangle", 2);
	glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop( );
	return 0;
}