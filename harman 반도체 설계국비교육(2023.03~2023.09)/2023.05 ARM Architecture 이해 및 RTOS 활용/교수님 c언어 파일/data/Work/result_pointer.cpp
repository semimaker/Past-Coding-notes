#include <stdio.h>
#include <malloc.h>
#include <conio.h>

void report(int n);
void sorting();
void swap(int *x,int *y);

int kor[10],eng[10],mat[10],com[10],tot[10];
char *nam[10]; //[20];  // 이름 : 각 이름의 길이는 20(영문기준), 최대 10명까지의 명단 입력 공간 : buffer 

main()
{
    char buf[512]; // 입력용 
    double avr[10];
    int i, j, k;
    
    for(i=0;i<3;i++)
    {
        printf("이름:"); scanf("%s",buf); // buf = "abc"
        
        for(k=0;buf[k];k++) ;  // buf 에 입력된 문자열의 길이 count 

        //if(k==0) break;
        nam[i] = (char*)malloc(k+1);
        for(k=0;;k++)
        {
             *(nam[i] + k) = buf[k];
             if(buf[k] == 0) break;
        }
        printf("국어:"); scanf("%d",kor+i); // 배열값은 0으로 초기화됨 
        printf("영어:"); scanf("%d",eng+i); 
        tot[i] = kor[i] + eng[i];
        //printf("수학:"); scanf("%d",&mat[i]); 
        //printf("컴터:"); scanf("%d",&com[i]); 
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
        printf("[%s]: %5d %5d %5d %5d %5d \n",nam[i],kor[i],eng[i],mat[i],com[i],tot[i]); 
    }    
}

void sorting()
{
    int i,j,k;
    for(i=0;i<10-1;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(tot[i] < tot[j])
            {
                swap(tot+i,tot+j);
                swap(kor+i,kor+j);
                swap(eng+i,eng+j);
                swap((int*)nam+i,(int*)nam+j);                
            }
        }
    }
}

void swap(int *x,int *y)  // *x , *y 변수의 포인터 value의 교환 
{
    int c = *x; // 임시변수에 a의 값을 저장 
    *x = *y;
    *y = c;
}

