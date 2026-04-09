#include <stdio.h> 
#include <conio.h>	// 주석문 예시  : 화면이 꺼지는 경우 포함

main()	// 함수의 type이 지정되지 않으면 int (정수)로 자동 간주.
        // 함수의 인수(argument)가 지정되지 않으면 자동으로 void로 간주 
{
   int i,j,k;
    
   //while(1) // while 문을 이용한 무한루프 
   for(;;)    // for 문을 이용한 무한루프 
   {
        printf("숫자 키를 입력하세요.(끝내시려면 'q'를 입력하세요)\n");
        i = getch();  // key stroke
        
    	if(i == 'q') break;

        switch(i)
        {
            case '1':
                printf("%c : One\n", i); break;
            case '2':
                printf("%c : Two\n", i); break;
            case '3':
                printf("%c : Three\n", i); break;
            case '4':
                printf("%c : Four\n", i); break;
            case '5':
                printf("%c : Five\n", i); break;
            case '6':
                printf("%c : Six\n", i); break;
            case '7':
                printf("%c : Seven\n", i); break;
            case '8':
                printf("%c : Eight\n", i); break;
            case '9':
                printf("%c : Nine\n", i); break;
            case '0':
                printf("%c : Zero\n", i); break;
            default :  ;  
        }
    	//printf("입력된 키값은 %c[%x(%d)] 입니다\n", i, i, i);
   }
   printf("Press any key to Close....\n");
   getch();   // 주석문 예시  : 화면이 꺼지는 경우 포함; 	printf("이러시면 아니되옵니다"); 
}
