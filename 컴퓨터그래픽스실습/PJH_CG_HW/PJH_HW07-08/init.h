// �⺻ �ʱ�ȭ
#include <gl/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>

//Mesh *Robot;
Mesh *Head;        // �κ��� �� ���� ��ü
Mesh *Body;
Mesh *RightArm;
Mesh *RightHand;
Mesh *LeftArm;
Mesh *LeftHand;
Mesh *RightLeg;
Mesh *RightFoot;
Mesh *LeftLeg;
Mesh *LeftFoot;

float scale;         // ase ������ �ҷ��� �� �� mesh ��ü�� ũ�⸦ ����Ʈ ���� �˸°� �����ϱ� ���� ����
float scaleRate;     // ���α׷����� z, x Ű�� ���� ����/�ܾƿ��� �ϱ� ���� ����

float rotateX1;   // 1�� ����Ʈ�� Y�� ���� ȸ�� ���� ����
float rotateY1;   // 1�� ����Ʈ�� X�� ���� ȸ�� ���� ����
float rotateX2;
float rotateY2;
float rotateX3;
float rotateY3;
float rotateX4;
float rotateY4;

float p_near;   // ���������� near ��
float p_scale;  // ���������� Ȯ��, ��Ҹ� ���� ����

bool robotRun;            // �κ��� �޸��� �ִϸ��̼� ����
bool robotpunch;		  // �κ� ��ġ ����
bool robotview;			  // �κ� �� �� ����
float robotWeight;        // �κ��� ����
char robotWeightStr[3];   // �κ��� ���Ը� ����ϱ� ���� ���ڿ� 
double robotSpeed;        // �κ��� �޸��� �ӵ�
char robotSpeedStr[3];    // �κ��� �ӵ��� ����ϱ� ���� ���ڿ� 
double robotRange;        // �κ��� �޸��� ������ ���ϱ� ���� ����
double dRadian;           // �� ������ ������ sin, cos ���� ���ϱ� ���� ���� ����
float sinR;               // sin, cos ������ �κ��� ��,�ٸ�, ��, �Ӹ��� �� ȸ�� ������ ����
float sinR2;
float cosR;
float d_cosR;
float d_sinR;
float dz;				// �κ� ��ġ 
float vy;				// �κ� �� ��
float tspd;				// �� �� ���ǵ�
GLfloat mat_diffuse[6];
GLfloat mat_ambient[6];

// ase ���� �б�
void meshLoad(){      

	Head = new Mesh();
	Head->readAse("S_Head.ASE");

	Body = new Mesh();
	Body->readAse("S_Body.ASE");

	RightArm = new Mesh();
	RightArm->readAse("S_RightArm.ASE");

	RightHand = new Mesh();
	RightHand->readAse("S_RightHand.ASE");

	LeftArm = new Mesh();
	LeftArm->readAse("S_LeftArm.ASE");

	LeftHand = new Mesh();
	LeftHand->readAse("S_LeftHand.ASE");

	RightLeg = new Mesh();
	RightLeg->readAse("S_RightLeg.ASE");

	RightFoot = new Mesh();
	RightFoot->readAse("S_RightFoot.ASE");

	LeftLeg = new Mesh();
	LeftLeg->readAse("S_LeftLeg.ASE");

	LeftFoot = new Mesh();
	LeftFoot->readAse("S_LeftFoot.ASE");

}
// mesh �� ȸ������, �̵� ��ġ ��ǥ�� �ʱ�ȭ
void meshInit() {      
	robotWeight = 10;
	robotSpeed = 20;
	robotRun = false;
	robotpunch = false;
	robotview = false;
	robotRange = 0;
	dRadian = 0;
	sinR = 0;
	cosR = 0;
	sinR2 = 0;
	d_cosR = 0;
	d_sinR = 0;
	dz = 0;
	vy = 0;
	tspd = 0;

	sprintf(robotWeightStr, "%.f", robotWeight - 5);
	sprintf(robotWeightStr, "%.f", (float)robotSpeed - 15);

	scaleRate = 1;
	rotateX1 = 0.0f;
	rotateY1 = 0.0f;
	rotateX2 = 0.0f;
	rotateY2 = 0.0f;
	rotateX3 = 0.0f;
	rotateY3 = 0.0f;
	rotateX4 = 0.0f;
	rotateY4 = 0.0f;
	p_near = 0.2;
	p_scale = 1;

	if( Body->max > 1 )
		scale = (float)floor((double)(Body->max+0.5)) * 2;
	else
		scale = 1;
}
// �׸��� �� ����
void setColor(float r, float g, float b, float a){

	mat_diffuse[0] = r;
	mat_diffuse[1] = g;
	mat_diffuse[2] = b;
	mat_diffuse[3] = a;

	mat_ambient[0] = r;
	mat_ambient[1] = g;
	mat_ambient[2] = b;
	mat_ambient[3] = a;

	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mat_ambient);
}
// ���� �ʱ�ȭ
void InitLight(){
	    // mesh �� ���� ��, ���� ��
	GLfloat mat_specular[ ] = {0.5, 1.0, 0.5, 1.0};
	GLfloat mat_shininess[ ] = {70.0};
	    // ������ ��, ���� ��
	GLfloat light_specular[ ] = {0.8, 0.5, 0.8, 1.0};
	GLfloat light_diffuse[ ] = {0.7, 0.7, 0.7, 1.0};
	GLfloat light_ambient[ ] = {0.4, 0.4, 0.4, 1.0};
	GLfloat light_position[ ] = {-1.5 / scaleRate, 0.5 / scaleRate, 0.5, 0.0};
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);  // ���� ��� ����
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE); // ����ȭ
        // mesh �� ���� ��, ����  ��  ������ ��, ���� ����
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	setColor(0.5, 0.5, 0.5, 1.0);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, mat_shininess);
}