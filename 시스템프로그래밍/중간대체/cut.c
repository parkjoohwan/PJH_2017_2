///////////////////////////////////////////////////////////////////
/*                                                               */
/* File cut 0.1.1-i386                                           */
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
	int filesize = 512;//������ ũ��
	int filecount;
	int invalid = 0;
	char * srcname;//�ҽ������̸�
	char * dstname;//���������̸�
	char * directory;//���丮 ���
	char * option[4] = {"-o","-n","-s","-d"};//���Ͽɼ�
	char * optionvalue[4] = {0};//���� �ɼ� ��
	char data[MAXCHAR+1];//�ҽ����Ͽ��� ���� ��
	char name[MAXCHAR+1];//���������� ���鶧 ���
	char charcnt[4];//�������� ��ȣ
	ssize_t nread;
	struct stat srcstat;


	if(argc > 9){
		printf("too many predicates.\n");
		exit(0);
	}
	if(argc < 2){
		printf("need predicate.\n");
		exit(0);
	}

	for(i = 1; i < argc; i+=2){
		invalid = i;
		for(j = 0; j < 4; j++){
			if(!strcmp(argv[i],option[j])){//���ڰ��� ���Ѵ�.
				optionvalue[j] = argv[i+1];//�ɼǰ��� ü���ִ´�.
				invalid = 0;
				break;
			}
		}
		if(invalid > 0){//�ɼ� ���ڰ� �´��� üũ�Ѵ�.
			printf("invlied predicate : [%s]\n", argv[invalid]);
			exit(0);
		}
	}

	//�ɼǰ��� �ִ´�.	
	if(optionvalue[0] != NULL){
		srcname = optionvalue[0];
	}
	if(optionvalue[1] != NULL){
		dstname = optionvalue[1];
	}
	else{
		dstname = srcname;
	}
	if(optionvalue[2] != NULL){
		filesize = atoi(optionvalue[2]);
	}
	if(optionvalue[3] != NULL){
		directory = optionvalue[3];
		strcat(directory, "/");
	}
	else{
		directory = "./";
	}

	//������ ����Ѵ�.
	printf("file size            = %dkb\n", filesize);
	printf("source filename      = %s\n", srcname);
	printf("destination filename = %s\n", dstname);
	printf("directory            = %s\n", directory);

	//���� ������ ����.
	if((srcfd = open(srcname, O_RDONLY)) < 0){
		printf("file open error!\n");
		exit(1);
	}

	//���Ϸκ��� ������ ���´�.
	if(fstat(srcfd, &srcstat) == -1){
		printf("fstat error!\n");
		close(srcfd);
		exit(1);
	}

//	printf("file size : %d", srcstat.st_size);


	//���� ������ ũ�Ⱑ ������ �޽��� ����� ����
	if(srcstat.st_size < filesize*1024){
		printf("file size is small than %d Kb\n", filesize);
//		close(srcfd);
//		exit(1);
	}

	//������ ������ ������ ���Ѵ�.
	filecount = (srcstat.st_size / (filesize*1024)) + 1;
	printf("%d / %d \n", srcstat.st_size, filesize*1024);

	//������ ������ ������ 1000 �̻��̸� ����� ����
	if(filecount > 999){
		printf("too many file create.(more then 999)\n");
		printf("input size more than %d\n", filesize);
		close(srcfd);
		exit(1);
	}
	
	if(opendir(directory) == NULL){
		mkdir(directory, 0777);
	}

	//������ �����Ѵ�.
	for(i = 0 ; i < filecount ; i++){
		strcpy(name, directory);
		strcat(name, dstname);
		itoa(i, charcnt);
		strcat(name, charcnt);

		dstfd = open(name, O_WRONLY | O_CREAT, srcstat.st_mode);

		printf("%s", name);
		for(j = 0; j < filesize*1024/MAXCHAR ; j++){
			if((nread = read(srcfd, data, MAXCHAR)) <= 0)
				break;
			write(dstfd, data, nread);
		}
		printf("...OK\n");	
	
		close(dstfd);

	}
	
	close(srcfd);
	return 0;
}

int itoa(int value, char * str){
	
	*str = (value / 100) + 48;
	value = value % 100;
	*(str+1) = (value / 10) + 48;
	value = value % 10;
	*(str+2) = value + 48;
	*(str+3) = '\0';

	return 0;
}

