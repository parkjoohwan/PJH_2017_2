///////////////////////////////////////////////////////////////////
/*                                                               */
/* File add 0.1.1-i386                                           */
/* author = Boram Yang (a.k.a botta)                             */
/* date = 13.11.2008                                             */
/*                                                               */
/* Korea University of Technology and Education                  */
/* Internet Media Engnieering                                    */
/*                                                               */
///////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAXCHAR 256
#define DEFAULTSIZE 512

int itoa(int value, char * str);

int main(int argc, char ** argv){

	int srcfd, dstfd;// �ҽ����ϼ�����, �������ϼ�����
	int i, j, temp;
	int delsrc = 0;//������ ��������
	int filecount;
	int invalid = 0;
	char * srcname;//�ҽ������̸�
	char * dstname;//���������̸�
	char * directory;//���丮 ���
	char * option[4] = {"-o","-n","-x","-d"};//���Ͽɼ�
	char * optionvalue[4] = {0};//���� �ɼ� ��
	char data[MAXCHAR+1];//�ҽ����Ͽ��� ���� ��
	char name[MAXCHAR+1];//���������� ���鶧 ���
	char charcnt[4];//�������� ��ȣ
	ssize_t nread;
	struct stat srcstat;
//	struct DIR dir;

	if(argc > 9){
		printf("too many predicates.\n");
		exit(0);
	}
	if(argc < 2){
		printf("need predicate.\n");
		exit(0);
	}

	for(i = 1; i < argc; i++){
		invalid = i;
		if(*argv[i] == '-'){//������ ù��° ���ڰ� '-'�� ��츸 �˻��Ѵ�.
			for(j = 0; j < 4; j++){
				if(!strcmp(argv[i],option[j])){//���ڰ��� ���Ѵ�.
					optionvalue[j] = argv[i+1];//�ɼǰ��� ü���ִ´�.
					if(j == 2){
						optionvalue[j] = argv[i];//-x�� ���
					}
					invalid = 0;
					break;
				}
			}
			if(invalid > 0){//�ɼ� ���ڰ� �´��� üũ�Ѵ�.
				printf("invlied predicate : [%s]\n", argv[invalid]);
				exit(0);
			}
		}
	}

	//�ɼǰ��� �ִ´�.	
	if(optionvalue[0] != NULL){
		srcname = optionvalue[0];
		temp = strlen(srcname);
		srcname[temp-3] = '\0';
	}
	if(optionvalue[1] != NULL){
		dstname = optionvalue[1];
	}
	else{
		dstname = srcname;
	}
	if(optionvalue[2] != NULL){//-x���ڰ� ������ ��
		delsrc = 1;
	}
	if(optionvalue[3] != NULL){
		directory = optionvalue[3];
		strcat(directory, "/");
	}
	else{
		directory = "./";
	}

	//������ ����Ѵ�.
	printf("delete source file   = %d\n" , delsrc);
	printf("source filename      = %s\n", srcname);
	printf("destination filename = %s\n", dstname);
	printf("directory            = %s\n", directory);

	//�Ʒ����� �ڵ� �Ͻÿ�!!

	if(opendir(directory) == NULL){
		mkdir(directory, 0777);
	}

	//���� ������ ����
	strcpy(name, directory);
	strcat(name, dstname);
	dstfd = open(name, O_WRONLY | O_CREAT, 0666);

	//���������� ����
	for(i = 0; i < 1000 ; i++){
		itoa(i, charcnt);
		strcpy(name, srcname);
		strcat(name, charcnt);
		if((srcfd = open(name, O_RDONLY)) < 0){
			close(dstfd);
			exit(1);
		}
		//������ ����.
		printf("%s", name);
		while((nread = read(srcfd, data, MAXCHAR)) > 0){
			write(dstfd, data, nread);
		}
		

		close(srcfd);

		if(delsrc == 1){
			unlink(name);
			printf("...deleted");
		}

		printf("...OK\n");
	}
	

	close(dstfd);
	return 0;
}
//������ ���ڷ� �ٲٴ� �Լ�
int itoa(int value, char * str){
	
	*str = (value / 100) + 48;
	value = value % 100;
	*(str+1) = (value / 10) + 48;
	value = value % 10;
	*(str+2) = value + 48;
	*(str+3) = '\0';

	return 0;
}

