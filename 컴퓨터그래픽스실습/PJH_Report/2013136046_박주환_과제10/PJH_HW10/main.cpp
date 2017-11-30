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

	// x���� ��ȭ�� �����϶�
	if( dx < 0 )
	{
		addX = -1;
		dx = -dx;
	}
	// x���� ��ȭ�� ����϶�
	else
	{
		addX=1;
	}

	// y���� ��ȭ�� �����϶�
	if( dy < 0 )
	{
		addY = -1;
		dy = -dy;
	}
	// y���� ��ȭ�� ����϶�
	else
	{
		addY=1;
	}

	int x = x1;
	int y = y1;

	//dx >= dy  �� ���( ���Ⱑ < 1 ) y�� ������ �����ϸ� y�� 1������Ų��
	if( dx >= dy )
	{
		for(int i = 0 ; i < dx ; i ++ )
		{
			// x�� 1 ������Ű�� dy��ŭ cnt ����
			x += addX;
			cnt += dy;

			// �����ϴ� y������ ũ�ٸ�
			if( cnt >= dx)
			{
				//y�� 1 ������Ű�� cnt �ʱ�ȭ
				y+=addY;
				cnt-= dx;
			}
			printf("������ �� ��ǥ : (%d, %d)\n", x,y);
			glVertex2i(x,y);
		}
	}
	// dx < dy�� ���(���Ⱑ > 1) x�� ������ �����ϸ� y�� 1������Ų��.
	else
	{
		for( int i = 0 ; i < dy ; i++ )
		{
			// y�� 1����, dx��ŭ cnt����
			y+=addY;
			cnt+=dx;

			// �߰��ϴ� y�� ���� ũ�ٸ�
			if(cnt >= dy)
			{
				// x�� 1����, cnt �ʱ�ȭ
				x+=addX;
				cnt-=dy;
			}
			printf("������ �� ��ǥ : (%d, %d)\n", x,y);
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
	glColor3f(0.5, 0.0, 0.5);	// �׸� �׸� ���� ����
	glBegin( GL_POINTS );
	BresenhamLine(lX,(SIZE-lY),pX,(SIZE-pY));
	glEnd();
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut�ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize( SIZE , SIZE );	//�ʱ�ȭ�� ������ ����� ���� �Ұ�
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glOrtho(0, SIZE, 0, SIZE, -1.0, 1.0);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	glutMouseFunc(MyMouseClick);	// ���콺Ŭ�� �̺�Ʈó�� 
	glutMotionFunc(MyMouseMove);
	glutDisplayFunc(Display);		// ���

	glutMainLoop( );
	return 0;
}

