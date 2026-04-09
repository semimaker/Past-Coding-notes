#include <stdio.h>
#include <conio.h>

float pi;

main()
{
    char arr1[] = "Hello1";
    int arr2[52][10] = {'H','e','l','l','o','2'};
    char arr3[] = {'H','e','l','l','o','3','\0'};
    
    printf("아무 문자열이나 입력해 보시게 : ");
    scanf("%s", arr2);  //256
    
    printf("arr1:%s\n", arr1);
    printf("arr2[%08x]:[%08x]:[%08x] \n", arr2, arr2+1, arr2+2);
    printf("arr3:%s\n", arr3);
    
//    scanf("%s",arr2);
    getch();
}
    

