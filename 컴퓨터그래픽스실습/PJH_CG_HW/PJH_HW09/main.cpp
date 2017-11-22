#include<gl\glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<stdio.h>

#define SIZE 300
int select = 1;
int pX=0,pY=0,lX=0,lY=0;

const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

double xmin = 50;
double xmax = 250;
double ymin = 50;
double ymax = 250;

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


// 점이 사각형의 어느쪽에 위치하는지 판단해주는 함수
int ComputeOutCode(double x, double y)
{
	int code;

	code = INSIDE;          // 초기화

	if (x < xmin)           // 사각형의 왼쪽으로 나갔는지
		code |= LEFT;
	else if (x > xmax)      // 사각형의 오른쪽으로 나갔는지
		code |= RIGHT;
	if (y < ymin)           // 사각형의 아래로 나갔는지
		code |= BOTTOM;
	else if (y > ymax)      // 사각형의 위로 나갔는지
		code |= TOP;

	return code;
}


void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1)
{
	// 점들이 사각형의 어느쪽으로 나갔는지 판단하여 저장
	int outcode0 = ComputeOutCode(x0, y0);
	int outcode1 = ComputeOutCode(x1, y1);
	bool accept = false;	// accept가 true가 되면, 클리핑이 완료된 것 

	// 각 점의 위치를 비트 연산을 통해 판단함 선분을 그냥 그릴지, 아예 안그릴지, 클리핑 시켜서 그릴지 판단
	while (true) {
		if (!(outcode0 | outcode1)) { // 둘 다 0이면 참, 클리핑을 할 필요가 없음 루프를 벗어남
			accept = true;
			break;
		} else if (outcode0 & outcode1) { // 두 점이 외부의 같은 영역에 존재 할 경우, 그냥 루프를 빠져나옴, 그릴 필요가 없음
			break;
		} else {
			double x, y;

			// 사각형 밖에 있는 점을 판단. 해당 점을 기록
			int outcodeOut = outcode0 ? outcode0 : outcode1;

			// 각 경우에 따라 직선의 공식을 이용하여 사각형과 직선의 교점을 찾음
			//   slope = (y1 - y0) / (x1 - x0)
			//   x = x0 + (1 / slope) * (ymax - y0)
			//   y = y0 + slope * (xmax - x0)
			if (outcodeOut & TOP) {           // 외부 점이 사각형의 위쪽에 있음
				x = x0 + (x1 - x0) * (ymax - y0) / (y1 - y0);
				y = ymax;
			} else if (outcodeOut & BOTTOM) { // 외부 점이 사각형 아래쪽에 있음
				x = x0 + (x1 - x0) * (ymin - y0) / (y1 - y0);
				y = ymin;
			} else if (outcodeOut & RIGHT) {  // 외부 점이 사각형 오른쪽에 있음
				y = y0 + (y1 - y0) * (xmax - x0) / (x1 - x0);
				x = xmax;
			} else if (outcodeOut & LEFT) {   // 외부 점이 사각형 왼쪽에 있음
				y = y0 + (y1 - y0) * (xmin - x0) / (x1 - x0);
				x = xmin;
			}

			// 어떤 점이 외부에 있는지 판단하고, 위에서 기록한 교점을 해당 점에 저장
			if (outcodeOut == outcode0) {
				x0 = x;
				y0 = y;
				outcode0 = ComputeOutCode(x0, y0);
			} else {
				x1 = x;
				y1 = y;
				outcode1 = ComputeOutCode(x1, y1);
			}
		}
	}
	if (accept) {
		//accept 가 true 면 라인을 다시 그림 false 이면 아예 안그림
		line(x0,y0,x1,y1);
	}
}


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


// Line, Rectangle, Exit
void Draw(){
	switch(select){
	case 1 :
		line(pX,pY,lX,lY); 
		break;
	case 2 :
		CohenSutherlandLineClipAndDraw(pX,pY,lX,lY);
		select=1;
		break;
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
	Rectangle(xmin, ymin, xmax, ymax);	//사각형 고정
	Draw();
}

// keyboard callback
void Keyboard(unsigned char KeyPressed, int x, int y)
{
	switch(KeyPressed){
	case 'C' :
		select = 2; break;
	case 'c' :
		select = 2; break;
	case 'Q' :
		exit(0); break;
	case 'q' :
		exit(0); break;
	default :
		break;
	}
	glutPostRedisplay(); //화면다시그리기
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
	glutKeyboardFunc(Keyboard);   // 키보드입력 이벤트처리
	glutDisplayFunc(Display);		// 출력

	glutMainLoop( );
	return 0;
}