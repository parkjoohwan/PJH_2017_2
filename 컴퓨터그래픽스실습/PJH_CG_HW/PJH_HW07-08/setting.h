// ī�޶�/Ÿ�̸�
float camEyeX;  // ī�޶� ���� �� ����
float camEyeY;
float camEyeZ;
float camAtX;
float camAtY;
float camAtZ;
float camUpX;
float camUpY;
float camUpZ;


// Ÿ�̸� �Լ�
void MyTimer(int Value){
	if(robotRun){                       // �޸��� ����̸� Ÿ�̸� �Լ� ����
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
	if(robotpunch){						// �ָ��� ������ ����̸� Ÿ�̸� �Լ� ����
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
	if(robotview){						// �ָ��� ������ ����̸� Ÿ�̸� �Լ� ����
		glutPostRedisplay();
		glutTimerFunc(40, MyTimer, 1);
	}
}
// ī�޶�/���� ���� �Լ�
void setCamera(float EyeX, float EyeY, float EyeZ, float AtX, float AtY, float AtZ, float UpX, float UpY, float UpZ){
	camEyeX = EyeX;
	camEyeY = EyeY;
	camEyeZ = EyeZ;
	camAtX = AtX;
	camAtY = AtY;
	camAtZ = AtZ;
	camUpX = UpX;
	camUpY = UpY;
	camUpZ = UpZ;
}
