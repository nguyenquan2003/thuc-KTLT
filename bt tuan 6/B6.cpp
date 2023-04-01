#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<string.h>
#define MAX 100
typedef struct  sinhvien
{
	char hoten[50];
}SV;
void Docfile(SV sv[],int &n)
{
	FILE* f = fopen("data.txt", "rt");
	if (f == NULL)
	   return;
	//int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<=n;i++)
	{
		fgets(sv[i].hoten,50,f);		
	}
	fclose(f);
	
}
void Xuatfile(SV sv[],int n)
{
	for(int i=1;i<=n;i++)
		puts(sv[i].hoten);
}
int BF_StringSearch(char *P,char *T)
{
	int n=strlen(T);
	int m=strlen(P);
	for(int i=0;i<n-m;i++)
	{
		int j=0;
		while(j<m)
			if(T[i+j]==P[j])
				j++;
			else
				break;
		if(j==m)
			return i;
	}
	return -1;
}
void timten(SV sv[],int n)
{
	int i;
	char *p;
	printf("NHap ten can tim:");
	fflush(stdin);
	gets(p);
	for(i=1;i<=n;i++)
	{
		int a=BF_StringSearch(p,sv[i].hoten);
		if(a!=-1)
			printf("\n o dong %d co tai vi tri: %d", i,a);
		else
			printf("\n o dong %d khong co: ", i);
	}
}
void main()
{
	SV sv[MAX];
	int n;
	Docfile(sv,n);
	Xuatfile(sv,n);
	getch();
}