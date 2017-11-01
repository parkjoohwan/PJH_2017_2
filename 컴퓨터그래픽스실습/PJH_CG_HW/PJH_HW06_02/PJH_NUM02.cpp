#include<gl\glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>

#define SIZE 300

//�κ� ��
void Arm(float x, float y, float angle){
	glPushMatrix();
	{
		glTranslatef(x,y,0);
		glRotated(angle, 0,0,1);
		glutWireSphere(0.1,20,10);
		glTranslatef(0,-0.33,0);
		glScalef(1,3,1);
		glutWireCube(0.15);
	}
	glPopMatrix();
	glFlush();
}

//�κ� ��
void body(){
	glPushMatrix();
	{
		glTranslatef(0,0.1,0);
		glScalef(1,2,1);
		glutWireCube(0.4);
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0,0.7,0);
		glutWireSphere(0.2,30,20);
	}
	glPopMatrix();
	glFlush();
}

//�κ� �Ӹ�
void Head(){
	glPushMatrix();
	glTranslatef(0,0.7,0);
	glutWireSphere(0.2,30,20);
	glPopMatrix();
	glFlush();
}

// display
void Display(){

	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.0, 0.5);	// �׸� �׸� ���� ����
	body();
	//Head();
	Arm(-0.3,0.4,-45);
	Arm(0.3,0.4,90);
	Arm(-0.1,-0.4,-45);
	Arm(0.1,-0.4,45);
	glPopMatrix();

}


int main(int argc, char** argv)
{
	glutInit(&argc, argv); //glut�ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize( SIZE , SIZE );	//�ʱ�ȭ�� ������ ����� ���� �Ұ�
	glutInitWindowPosition(0,0);
	glutCreateWindow("OpenGL Drawing Example");

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	glutDisplayFunc(Display);		// ���

	glutMainLoop( );
	return 0;
}