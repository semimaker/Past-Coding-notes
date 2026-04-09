#include <stdio.h>
#include <conio.h>
#include <malloc.h>
int slength(char *s);
void sub(char **s,int n);
main()  // if sub 함수라면????? 
{
    int i,j,k = 100;
    char *s2[10] = {"홍길동","전우치","제갈공명",
                    "누루하치","삼천갑자동방삭"};
                    // 문자열(pointer)배열 40 byte                    
    sub(s2,5);      // 입력을 위한 함수 
    for(i=0;i<10;i++)
    {
        printf("%s\n",s2[i]);
    }
    getch();
}

void sub(char **s2,int n)
{
    int i,j,k;
    char *kbuf = (char*)malloc(512);
    int offset = 0;
    
    for(j = n;j<10;j++)
    {
        scanf("%s", kbuf + offset);
        s2[j] = kbuf + offset;
        offset = offset + slength(kbuf + offset) + 1;
    }
}

int slength(char *s)  // null 까지의 문자 갯수 
{
    int n = 0;
    while(*s++) n++;
    //{
    //    if(*(s+n) == 0) break;
    //    n++;
    //}
    return n;
}
