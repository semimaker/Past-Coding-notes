#include <stdio.h>

int Abs(int a, int b); // a:1 b:3,r = -2;;;;;;;;;
float pi;

main()
{
    int a, b, r; 
    pi = 3.14;
    while(1)
    {
        printf("(%f)두 정수를 입력하세요 : ",pi);  // 사용하기 전에 입력받을 변수선언 필. 
        scanf("%d %d", &a, &b);  // 사용하기 전에 입력받을 변수선언 필. 
        r = Abs(a,b);
        printf("두 정수 %d와 %d의 차이의 절대값은 %d입니다\n", a, b, r);
    }
}

int Abs(int a, int b) // a:1 b:3,r = -2
{
    int r = a - b;
    if(r < 0) r = r * (-1);
    pi = 3.14159265;
    return r;
}

