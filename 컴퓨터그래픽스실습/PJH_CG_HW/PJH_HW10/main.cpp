#include<gl\glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>
#include<stdio.h>

#define SIZE 300
int pX=0,pY=0,lX=0,lY=0;

void BresenhamLine( int x1, int y1, int x2, int y2 ){
	
	int addX, addY;
	int cnt = 0;

	int dx = x2-x1;
	int dy = y2-y1;

	// x값의 변화가 음수일때
	if( dx < 0 )
	{
		addX = -1;
		dx = -dx;
	}
	// x값의 변화가 양수일때
	else
	{
		addX=1;
	}

	// y값의 변화가 음수일때
	if( dy < 0 )
	{
		addY = -1;
		dy = -dy;
	}
	// y값의 변화가 양수일때
	else
	{
		addY=1;
	}

	int x = x1;
	int y = y1;

	//dx >= dy  일 경우( 기울기가 < 1 ) y의 조건이 만족하면 y를 1증가시킨다
	if( dx >= dy )
	{
		for(int i = 0 ; i < dx ; i ++ )
		{
			// x를 1 증가시키고 dy만큼 cnt 증가
			x += addX;
			cnt += dy;

			// 증가하는 y값보다 크다면
			if( cnt >= dx)
			{
				//y를 1 증가시키고 cnt 초기화
				y+=addY;
				cnt-= dx;
			}
			printf("찍히는 점 좌표 : (%d, %d)\n", x,y);
			glVertex2i(x,y);
		}
	}
	// dx < dy일 경우(기울기가 > 1) x의 조건이 만족하면 y를 1증가시킨다.
	else
	{
		for( int i = 0 ; i < dy ; i++ )
		{
			// y를 1증가, dx만큼 cnt증가
			y+=addY;
			cnt+=dx;

			// 중가하는 y값 보다 크다면
			if(cnt >= dy)
			{
				// x를 1증가, cnt 초기화
				x+=addX;
				cnt-=dy;
			}
			printf("찍히는 점 좌표 : (%d, %d)\n", x,y);
			glVertex2i(x,y);
		}
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


// display
void Display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);	// 그림 그릴 선의 색깔
	glBegin( GL_POINTS );
	BresenhamLine(lX,(SIZE-lY),pX,(SIZE-pY));
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut초기화
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize( SIZE , SIZE );	//초기화는 윈도우 만들기 전에 할것
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0, SIZE, 0, SIZE, -1.0, 1.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	glutMouseFunc(MyMouseClick);	// 마우스클릭 이벤트처리 
	glutMotionFunc(MyMouseMove);
	glutDisplayFunc(Display);		// 출력

	glutMainLoop( );
	return 0;
}

