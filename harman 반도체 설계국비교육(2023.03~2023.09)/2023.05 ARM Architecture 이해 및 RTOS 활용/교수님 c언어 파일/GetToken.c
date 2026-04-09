#include <stdio.h>

//getToken(1, “11_22_33_44_55”, ‘_’) --> “22” 
char *getToken(int n, char *str, char c);
void StrCopy(char *t, char *s);
int main()
{
	char buf[100];
	StrCopy(buf,"11_22_33_44_55");
	char *r = getToken(0, buf, '_');
	printf("%s\n", r);
}

void StrCopy(char *t, char *s)
{
	while(*s) *t++ = *s++; *t = *s;
}

/// 문자열(str) 구분자(c)의 위치에 따른 인덱스 배열
///   --> ( tmp [ ] )
/// 배열의 값은 문자열 시작 위치
/// N값의 배열값을 리턴. 
/// 단 다음 배열인덱스의 직전위치의 값을 \0(null)로 치환
char * getToken(int n, char *str, char c)
{
//	getToken(1, "11_22_33_44_55", '_'); 결과값으로 "22" 기대
	//int tmp[512];
	char *r;
	int i;//,j,k;
	
	for(i=0;*str;)
	{
		if(*str == c)
		{
			if(++i == n)
			{
				r = ++str; // 반환의 시작위치
				for(;*str;)
				{
					if(*str == c)
					{
						*str = 0; // 반환문자열 끝
						return r;
					}
					str++;
				}
			    return r;
		    }
		}
		str++;	// str = str + 1
	}
	return 0;
}
