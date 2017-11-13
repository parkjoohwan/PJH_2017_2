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

	int srcfd, dstfd;// 소스파일설명자, 목적파일설명자
	int i, j, temp;
	int delsrc = 0;//파일을 삭제할지
	int filecount;
	int invalid = 0;
	char * srcname;//소스파일이름
	char * dstname;//목적파일이름
	char * directory;//디렉토리 경로
	char * option[4] = {"-o","-n","-x","-d"};//파일옵션
	char * optionvalue[4] = {0};//파일 옵션 값
	char data[MAXCHAR+1];//소스파일에서 읽은 값
	char name[MAXCHAR+1];//실제파일을 만들때 사용
	char charcnt[4];//생성파일 번호
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
		if(*argv[i] == '-'){//인자의 첫번째 문자가 '-'인 경우만 검사한다.
			for(j = 0; j < 4; j++){
				if(!strcmp(argv[i],option[j])){//인자값을 비교한다.
					optionvalue[j] = argv[i+1];//옵션값을 체워넣는다.
					if(j == 2){
						optionvalue[j] = argv[i];//-x일 경우
					}
					invalid = 0;
					break;
				}
			}
			if(invalid > 0){//옵션 인자가 맞는지 체크한다.
				printf("invlied predicate : [%s]\n", argv[invalid]);
				exit(0);
			}
		}
	}

	//옵션값을 넣는다.	
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
	if(optionvalue[2] != NULL){//-x인자가 들어왔을 때
		delsrc = 1;
	}
	if(optionvalue[3] != NULL){
		directory = optionvalue[3];
		strcat(directory, "/");
	}
	else{
		directory = "./";
	}

	//내용을 출력한다.
	printf("delete source file   = %d\n" , delsrc);
	printf("source filename      = %s\n", srcname);
	printf("destination filename = %s\n", dstname);
	printf("directory            = %s\n", directory);

	//아래부터 코딩 하시오!!

	if(opendir(directory) == NULL){
		mkdir(directory, 0777);
	}

	//목적 파일을 연다
	strcpy(name, directory);
	strcat(name, dstname);
	dstfd = open(name, O_WRONLY | O_CREAT, 0666);

	//원본파일을 연다
	for(i = 0; i < 1000 ; i++){
		itoa(i, charcnt);
		strcpy(name, srcname);
		strcat(name, charcnt);
		if((srcfd = open(name, O_RDONLY)) < 0){
			close(dstfd);
			exit(1);
		}
		//파일을 쓴다.
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
//정수를 문자로 바꾸는 함수
int itoa(int value, char * str){
	
	*str = (value / 100) + 48;
	value = value % 100;
	*(str+1) = (value / 10) + 48;
	value = value % 10;
	*(str+2) = value + 48;
	*(str+3) = '\0';

	return 0;
}

