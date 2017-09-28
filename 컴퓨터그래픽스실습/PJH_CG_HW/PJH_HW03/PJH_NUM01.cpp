#include<gl\glut.h>
#include<gl\GL.h>
#include<gl\GLU.h>

void point(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	glVertex3f( 50, 50, 0);
	glEnd( );
	glFlush( );
}

void line(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glVertex3f( 30, 30, 0);
	glVertex3f( 60, 60, 0);
	glEnd( );
	glFlush( );
}

void linestrip(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glVertex3f( 30, 30, 0);
	glVertex3f( 60, 60, 0);
	glVertex3f( 40, 20, 0);
	glVertex3f( 50, 70, 0);
	glEnd( );
	glFlush( );
}

void lineloop(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex3f( 30, 30, 0);
	glVertex3f( 60, 60, 0);
	glVertex3f( 40, 20, 0);
	glVertex3f( 50, 70, 0);
	glEnd( );
	glFlush( );
}

void poly(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f( 30, 30, 0);
	glVertex3f( 60, 60, 0);
	glVertex3f( 40, 20, 0);
	glVertex3f( 50, 70, 0);
	
	glEnd( );
	glFlush( );
}

void quad(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS); 
	glVertex3f(20, 20, 0);
	glVertex3f(20, 80, 0);
	glVertex3f(80, 80, 0);
	glVertex3f(80, 20, 0);
	glEnd( );
	glFlush( );
}

void quadstrip(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUAD_STRIP); 
	glVertex3f(20, 40, 0);
	glVertex3f(20, 80, 0);
	glVertex3f(40, 80, 0);
	glVertex3f(80, 20, 0);
	glVertex3f(10, 10, 0);
	glVertex3f(10, 80, 0);
	glEnd( );
	glFlush( );
}

void tri(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES); 
	glVertex3f(20, 20, 0);
	glVertex3f(40, 80, 0);
	glVertex3f(80, 20, 0);
	glEnd( );
	glFlush( );
}

void tristrip(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP); 
	glVertex3f(20, 20, 0);
	glVertex3f(40, 80, 0);
	glVertex3f(80, 20, 0);
	glVertex3f(70, 50, 0);
	glEnd( );
	glFlush( );
}

void trifan(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN); 
	glVertex3f(20, 20, 0);
	glVertex3f(40, 60, 0);
	glVertex3f(80, 20, 0);
	glVertex3f(80, 60, 0);
	glEnd( );
	glFlush( );
}


void MyDisplay() {
glClear(GL_COLOR_BUFFER_BIT);


// P
glBegin(GL_QUADS);
glVertex3f(5, 20, 0);
glVertex3f(5, 80, 0);
glVertex3f(10, 80, 0);
glVertex3f(10, 20, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(10, 80, 0);
glVertex3f(20, 80, 0);
glVertex3f(20, 75, 0);
glVertex3f(10, 75, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(20, 80, 0);
glVertex3f(25, 80, 0);
glVertex3f(25, 65, 0);
glVertex3f(20, 65, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(10, 65, 0);
glVertex3f(25, 65, 0);
glVertex3f(25, 60, 0);
glVertex3f(10, 60, 0);
glEnd( );

//J


glBegin(GL_QUADS);
glVertex3f(35, 80, 0);
glVertex3f(35, 75, 0);
glVertex3f(60, 75, 0);
glVertex3f(60, 80, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(50, 75, 0);
glVertex3f(50, 20, 0);
glVertex3f(55, 20, 0);
glVertex3f(55, 75, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(50, 20, 0);
glVertex3f(50, 25, 0);
glVertex3f(35, 25, 0);
glVertex3f(35, 20, 0);
glEnd( );


//H

glBegin(GL_QUADS);
glVertex3f(70, 80, 0);
glVertex3f(70, 20, 0);
glVertex3f(75, 20, 0);
glVertex3f(75, 80, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(75, 52.5, 0);
glVertex3f(85, 52.5, 0);
glVertex3f(85, 47.5, 0);
glVertex3f(75, 47.5, 0);
glEnd( );
glBegin(GL_QUADS);
glVertex3f(85, 80, 0);
glVertex3f(85, 20, 0);
glVertex3f(90, 20, 0);
glVertex3f(90, 80, 0);
glEnd( );

glFlush( );

}

int main( ) {
glutInitWindowSize( 500, 500);	//초기화는 윈도우 만들기 전에 할것
glutInitWindowPosition(0,0);
glutCreateWindow("OpenGL Drawing Example");
//glutDisplayFunc(point);
//glutDisplayFunc(line);
//glutDisplayFunc(linestrip);
//glutDisplayFunc(lineloop);
//glutDisplayFunc(poly);
//glutDisplayFunc(quad);
//glutDisplayFunc(quadstrip);
//glutDisplayFunc(tri);
//glutDisplayFunc(tristrip);
//glutDisplayFunc(trifan);
glutDisplayFunc(MyDisplay);
glOrtho(0,100,0,100,1,-1); // 좌우하상
glutMainLoop( );
return 0;
}