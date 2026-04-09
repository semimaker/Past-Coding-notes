#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <conio.h>

struct Student {
    char *name;
    int kor,eng,mat,com;
    int tot;
    double avr;
};
typedef struct Student AAA;

void report(int n);
void sorting();
void swap(int *x,int *y);
void swap(AAA *x,AAA *y);

AAA stu[10];  // 실 데이터 배열 
AAA *stp[10]; // 배열요소의 주소(포인터)의 배열 

///  과거의 고민의흔적들...  int kor[10],eng[10],mat[10],com[10],tot[10];
//char *nam[10]; //[20];  // 이름 : 각 이름의 길이는 20(영문기준), 최대 10명까지의 명단 입력 공간 : buffer 

main()
{
    char buf[512]; // 이름 입력용 
    int ko,en,ma,co; // 성적 입력용 변수 
    //double avr[10];
    int i, j, k;
    char *c;
    
    for(i=0;i<10;i++) stp[i] = &stu[i];
    for(i=0;i<3;i++)
    {
        printf("이름:"); scanf("%s",buf); // buf = "abc"
        
        //for(k=0;buf[k];k++) ;  // buf 에 입력된 문자열의 길이 count 
        //if(k==0) break;
        k = strlen(buf);

        c = (char*)malloc(k+1);
        //for(k=0;;k++)
        //{
        //     *(c + k) = buf[k];
        //     if(buf[k] == 0) break;
        //}    
        strcpy(c, buf);    
        printf("국어:"); scanf("%d",&ko); // 배열값은 0으로 초기화됨 
        printf("영어:"); scanf("%d",&en); 
        //printf("수학:"); scanf("%d",&ma); 
        //printf("컴터:"); scanf("%d",&co); 
        // 지역변수에 입력작업 완료 : 1사람 분 
        
        stu[i].name = c;
        stu[i].kor = ko;
        stu[i].eng = en;
        //stu[i].mat = ma;
        //stu[i].com = co;
        stu[i].tot = ko + en;//
    }
    report(10);
    sorting();
    report(10);
    getch();
}

void report(int n)
{
    for(int i=0;i<n;i++)
    {
        printf("[%s]: %5d %5d %5d %5d %5d \n",stu[i].name,stu[i].kor,stu[i].eng,stu[i].mat,stu[i].com,stu[i].tot);
    }    
    printf("===============================================\n");
    for(int i=0;i<n;i++)
    {
        printf("[%s]: %5d %5d %5d \n",stp[i]->name,stp[i]->kor,stp[i]->eng,stp[i]->tot);
    }    
}

void sorting()
{
    int i,j,k;
    //int n = sizeof(tot);  
    for(i=0;i<10-1;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(stp[i]->tot < stp[j]->tot)
            {
                swap((int*)(stp+i),(int*)(stp+j));                
                //swap(stu+i,stu+j);                
            }
        }
    }
}

void swap(AAA *x,AAA *y)  // *x , *y 변수의 포인터 value의 교환 
{
    AAA c = *x; // 임시변수에 a의 값을 저장 
    *x = *y;
    *y = c;
}

void swap(int *x,int *y)  // *x , *y 변수의 포인터 value의 교환 
{
    int c = *x; // 임시변수에 a의 값을 저장 
    *x = *y;
    *y = c;
}

