/* pointer_array3.c */
#include <stdio.h>
#include <conio.h>

int main(void)
{
   int b = 5; 
   int arr[]={1, 2, 3, 4, 5, 6, 7, 8, 9};

   int* pArr = &arr[4];
   printf("%d \n", *pArr); // 1

   printf("%d \n", *(++pArr)); // 2
   printf("%d \n", *(++pArr)); // 3

   printf("%d \n", *(pArr+1)); // 4
   printf("%d \n", *(pArr+2)); // 5

   getch();
   return 0;
}

