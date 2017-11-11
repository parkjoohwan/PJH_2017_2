//�κ� �Ӹ� �׸���
void drawHead(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Head->faceNum; i++){
				glNormal3f(Head->normalList[i].faceNormal[0], Head->normalList[i].faceNormal[1], Head->normalList[i].faceNormal[2]);

				glVertex3f(Head->vertexList[Head->faceList[i].vertexIndex[0]].x / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[0]].y / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Head->vertexList[Head->faceList[i].vertexIndex[1]].x / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[1]].y / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(Head->vertexList[Head->faceList[i].vertexIndex[2]].x / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[2]].y / scale, 
					Head->vertexList[Head->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ���� �׸���
void drawBody(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<Body->faceNum; i++){
				float* n = Body->normalList[i].faceNormal;
				glNormal3f(n[0], n[1], n[2]);
				//glNormal3f(Body->normalList[i].faceNormal[0], Body->normalList[i].faceNormal[1], Body->normalList[i].faceNormal[2]);

				glVertex3f(Body->vertexList[Body->faceList[i].vertexIndex[0]].x / scale, 
					Body->vertexList[Body->faceList[i].vertexIndex[0]].y / scale, 
					Body->vertexList[Body->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(Body->vertexList[Body->faceList[i].vertexIndex[1]].x / scale, 
					Body->vertexList[Body->faceList[i].vertexIndex[1]].y / scale, 
					Body->vertexList[Body->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(Body->vertexList[Body->faceList[i].vertexIndex[2]].x / scale, 
					Body->vertexList[Body->faceList[i].vertexIndex[2]].y / scale, 
					Body->vertexList[Body->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ������ �� �׸���
void drawRightArm(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<RightArm->faceNum; i++){
				glColor3f(0.8, 0.8, 0.8);
				glNormal3f(RightArm->normalList[i].faceNormal[0], RightArm->normalList[i].faceNormal[1], RightArm->normalList[i].faceNormal[2]);
				
				glVertex3f(RightArm->vertexList[RightArm->faceList[i].vertexIndex[0]].x / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[0]].y / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(RightArm->vertexList[RightArm->faceList[i].vertexIndex[1]].x / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[1]].y / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(RightArm->vertexList[RightArm->faceList[i].vertexIndex[2]].x / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[2]].y / scale, 
					RightArm->vertexList[RightArm->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ������ �� �׸���
void drawRightHand(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<RightHand->faceNum; i++){
				glNormal3f(RightHand->normalList[i].faceNormal[0], RightHand->normalList[i].faceNormal[1], RightHand->normalList[i].faceNormal[2]);

				glVertex3f(RightHand->vertexList[RightHand->faceList[i].vertexIndex[0]].x / scale, 
					RightHand->vertexList[RightHand->faceList[i].vertexIndex[0]].y / scale, 
					RightHand->vertexList[RightHand->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(RightHand->vertexList[RightHand->faceList[i].vertexIndex[1]].x / scale, 
					RightHand->vertexList[RightHand->faceList[i].vertexIndex[1]].y / scale, 
					RightHand->vertexList[RightHand->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(RightHand->vertexList[RightHand->faceList[i].vertexIndex[2]].x / scale, 
					RightHand->vertexList[RightHand->faceList[i].vertexIndex[2]].y / scale, 
					RightHand->vertexList[RightHand->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ���� �� �׸���
void drawLeftArm(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<LeftArm->faceNum; i++){
				glNormal3f(LeftArm->normalList[i].faceNormal[0], LeftArm->normalList[i].faceNormal[1], LeftArm->normalList[i].faceNormal[2]);

				glVertex3f(LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[0]].x / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[0]].y / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[1]].x / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[1]].y / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[2]].x / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[2]].y / scale, 
					LeftArm->vertexList[LeftArm->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ���� �� �׸���
void drawLeftHand(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<LeftHand->faceNum; i++){
				glNormal3f(LeftHand->normalList[i].faceNormal[0], LeftHand->normalList[i].faceNormal[1], LeftHand->normalList[i].faceNormal[2]);

				glVertex3f(LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[0]].x / scale, 
					LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[0]].y / scale, 
					LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[1]].x / scale, 
					LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[1]].y / scale, 
					LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[2]].x / scale, 
					LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[2]].y / scale, 
					LeftHand->vertexList[LeftHand->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ������ �ٸ� �׸���
void drawRightLeg(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<RightLeg->faceNum; i++){
				glNormal3f(RightLeg->normalList[i].faceNormal[0], RightLeg->normalList[i].faceNormal[1], RightLeg->normalList[i].faceNormal[2]);

				glVertex3f(RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[0]].x / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[0]].y / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[1]].x / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[1]].y / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[2]].x / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[2]].y / scale, 
					RightLeg->vertexList[RightLeg->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ������ �� �׸���
void drawRightFoot(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<RightFoot->faceNum; i++){
				glNormal3f(RightFoot->normalList[i].faceNormal[0], RightFoot->normalList[i].faceNormal[1], RightFoot->normalList[i].faceNormal[2]);

				glVertex3f(RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[0]].x / scale, 
					RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[0]].y / scale, 
					RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[1]].x / scale, 
					RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[1]].y / scale, 
					RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[1]].z / scale);

				glVertex3f(RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[2]].x / scale, 
					RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[2]].y / scale, 
					RightFoot->vertexList[RightFoot->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ���� �ٸ� �׸���
void drawLeftLeg(){
		glBegin(GL_TRIANGLES);	
			for(int i=0; i<LeftLeg->faceNum; i++){
				glNormal3f(LeftLeg->normalList[i].faceNormal[0], LeftLeg->normalList[i].faceNormal[1], LeftLeg->normalList[i].faceNormal[2]);

				glVertex3f(LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[0]].x / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[0]].y / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[0]].z / scale);	

				glVertex3f(LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[1]].x / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[1]].y / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[1]].z / scale);
				
				glVertex3f(LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[2]].x / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[2]].y / scale, 
					LeftLeg->vertexList[LeftLeg->faceList[i].vertexIndex[2]].z / scale);
			}
		glEnd( );
}
//�κ� ���� �� �׸���
void drawLeftFoot(){
	glBegin(GL_TRIANGLES);	
		for(int i=0; i<LeftFoot->faceNum; i++){
			glNormal3f(LeftFoot->normalList[i].faceNormal[0], LeftFoot->normalList[i].faceNormal[1], LeftFoot->normalList[i].faceNormal[2]);
			glVertex3f(LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[0]].x / scale, 
				LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[0]].y / scale, 
				LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[0]].z / scale);	
			glVertex3f(LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[1]].x / scale, 
				LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[1]].y / scale, 
				LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[1]].z / scale);
			glVertex3f(LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[2]].x / scale, 
				LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[2]].y / scale, 
				LeftFoot->vertexList[LeftFoot->faceList[i].vertexIndex[2]].z / scale);
		}
	glEnd( );
}
//���ļ� �׸���
void drawRobot(){
	
	glPushMatrix();
		setColor(0.5, 0.8, 0.8, 1.0);
		glTranslated(0, 0.1+(sinR2 * 0.08 + 0.08), 0);      // ������ ��ġ ����
//		glScalef (1.0f, 1.0f, 1.0f);
		glRotatef (sinR2*(20-robotWeight) + 10, 1, 0, 0);       // ������ ����ȸ�� ����
		glRotatef (sinR*(18-robotWeight), 0, 1, 0);             // ������ �¿�ȸ�� ����

		drawBody();                            // ���� ���

		glPushMatrix();
			setColor(0.8, 0.8, 0.8, 1.0);
			glTranslated(0.0, 0.45, 0.05);
			glScalef (1.0f, 1.0f, 1.0f);
		//	glRotatef (rotateY, 1, 0, 0);
			glRotatef (cosR*20-90, 0, 1, 0);

			drawHead();                       // �Ӹ� ���

		glPopMatrix();

		glPushMatrix();
			setColor(0.4, 0.4, 0.8, 1.0);
			glTranslated(-0.25, 0.32, 0.0);
			glScalef (1.0f, 1.0f, 1.0f);
			glRotatef (cosR*(70-robotWeight), 1, 0, 0);
			glRotatef (sinR*5 + 5, 0, 1, 0);

			drawRightArm();                                   // ������ ��� ���

			glPushMatrix();
				setColor(0.8, 0.8, 0.8, 1.0);
				if(robotpunch){
				robotRun = false;
				glTranslated(-0.05, -0.3, 0.0+dz);
				glRotatef (cosR*(50-robotWeight) - 70 - (cosR*(70-robotWeight))-(sinR2*(20-robotWeight) + 10), 1, 0, 0);
				glRotatef (sinR*20 + (20-robotWeight), 0, 1, 0);
				}else{
				glTranslated(-0.05, -0.3, 0.0);
				glScalef (1.0f, 1.0f, 1.0f);
				glRotatef (cosR*(50-robotWeight) - 70, 1, 0, 0);
				glRotatef (sinR*20 + (20-robotWeight), 0, 1, 0);
				}
			
				drawRightHand();                               // ������ �ϴ� ���

			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			setColor(0.4, 0.4, 0.8, 1.0);
			
			glTranslated(0.25, 0.32, 0.0);
			glScalef (1.0f, 1.0f, 1.0f);
			glRotatef (d_cosR*(70-robotWeight), 1, 0, 0);
			glRotatef (d_sinR*5 - 5, 0, 1, 0);
			
			drawLeftArm();                                // ���� ��� ���

			glPushMatrix();
				setColor(0.8, 0.8, 0.8, 1.0);
				
				glTranslated(0.05, -0.3, 0.0);
				glScalef (1.0f, 1.0f, 1.0f);
				glRotatef (d_cosR*(50-robotWeight) - 70, 1, 0, 0);
				glRotatef (d_sinR*20 -(20-robotWeight), 0, 1, 0);
				drawLeftHand();                           // ���� �ϴ� ���

			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			setColor(0.8, 0.8, 0.8, 1.0);
			glTranslated(-0.12, -0.1, 0.0);
			glScalef (1.0f, 1.0f, 1.0f);
			glRotatef (d_cosR*(50-robotWeight) - 35, 1, 0, 0);      
			//glRotatef (0, 0, 1, 0);

			drawRightLeg();                            // �����ٸ� ����� ���

			glPushMatrix();
				setColor(0.5, 0.5, 0.6, 1.0);
				glTranslated(0.0, -0.40, 0.0);
				glScalef (1.0f, 1.0f, 1.0f);
				glRotatef (d_sinR * 50 + (60 - robotWeight), 1, 0, 0);   
			//	glRotatef (robotRange/20, 0, 1, 0);

				drawRightFoot();                    // �����ٸ� �ٸ�,�� ���

			glPopMatrix();

		glPopMatrix();

		glPushMatrix();
			setColor(0.8, 0.8, 0.8, 1.0);
			glTranslated(0.12, -0.1, 0.0);
			glScalef (1.0f, 1.0f, 1.0f);
			glRotatef (cosR*(50-robotWeight) - 35, 1, 0, 0);    
			//glRotatef (robotRange/20, 0, 1, 0);

			drawLeftLeg();                        // �޴ٸ� ����� ���

			glPushMatrix();
				setColor(0.5, 0.5, 0.6, 1.0);
				glTranslated(0.0, -0.40, 0.0);
				glScalef (1.0f, 1.0f, 1.0f);
				glRotatef (sinR * 50 + (60 - robotWeight), 1, 0, 0);
			//	glRotatef (-1 * (robotRange/20), 0, 1, 0);

				drawLeftFoot();                  // �޴ٸ� �ٸ�,�� ���

			glPopMatrix();

		glPopMatrix();

	glPopMatrix();
}
