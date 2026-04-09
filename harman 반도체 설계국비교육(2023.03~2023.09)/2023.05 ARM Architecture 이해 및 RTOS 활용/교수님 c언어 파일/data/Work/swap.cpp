#include <stdio.h>
#include <conio.h>

void swap(int *a,int *b); 
int a1,b1;  // 전역변수 
int main()
{
    int a=10,b=20; // 지역변수 
    int ar[2][4] = {1,2,3,4,5,6,7,8};
    
    printf("%08x %08x %08x\n\n\n\n",ar,ar[0][1],ar[1][1]);
    printf("%08x %08x %08x\n\n\n\n",ar,*(*(ar+0)+1),*(*(ar+1)+1));
    
    printf("원래의 변수 값  a:%d  b:%d\n",a,b); // swap 전 
    swap(&a,&b);    // a,b 변수의 교환 
    printf("SWAP후 변수 값  a:%d  b:%d\n",a,b); // swap 후 
    
    getch();
}
void swap(int *i,int *j)  // *x , *y 변수의 포인터 value의 교환 
{
    int *x,*y;
    x = i; 
    y = j;
    printf("SWAP 함수 내에서 변수 값  a:%d  b:%d\n",j[0],j[1]); // swap 후 
    
    int c = *x; // 임시변수에 a의 값을 저장 
    *x = *y;
    *y = c;
    printf("SWAP 함수 내에서 변수 값  a:%d  b:%d\n",*x,*y); // swap 후 
}

