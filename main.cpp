#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
	if(argc!=3)
	{
		fprintf(stderr,"[argc error] argc is %d\n",argc);
		exit(1);
	}
	if(access(argv[1], F_OK) ==-1 ||access(argv[2], F_OK) ==-1)
	{
		fprintf(stderr,"File Access Error\n");
		exit(1);
	}
	FILE *fp1, *fp2;
	fp1 = fopen(argv[1],"r");
	fp2 = fopen(argv[2],"r");

	if(fp1==NULL || fp2 == NULL)
	{
		fprintf(stderr,"file open error\n");
		exit(1);
	}

	uint32_t one, two;

	fread(&one, sizeof(uint32_t),1,fp1);
	fread(&two, sizeof(uint32_t),1,fp2);

	fclose(fp1);
	fclose(fp2);
	/*
	htonl 함수는 호스트 바이트 순서로 표현된 32비트 정수 값을 네트워크 바이트 순서로 변환하여 반환합니다. 이 함수는 주로 네트워크 프로그래밍에서 사용되며, 네트워크 통신을 위해 데이터를 전송하기 전에 호스트 바이트 순서에서 네트워크 바이트 순서로 변환하는 데 활용됩니다.
	
	*/
	one = htonl(one);
	two = htonl(two);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",\
		one,one,
		two,two,\
		one+two,\
		one+two);

}
