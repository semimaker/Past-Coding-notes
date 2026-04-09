#include <iostream>
#include <conio.h> // _getch

using namespace std;

/*
0: 벽, 1: 길, 2: 시작점, 3: 도착점 4 : 폭탄 5 : 폭탄 이펙트
*/
struct _tagPoint //구조체를 활용하여 플레이어의 위치를 만든다.
{
	int x;
	int y;
};

typedef _tagPoint POINT; //tagPoint 와 POINT 라는 파일로 받는 것.
typedef _tagPoint* PPOINT;//타입을 재정의하는 기능

static void SetMaze(char Maze[21][21], PPOINT pPlayerPos, PPOINT pStartPos,
	PPOINT pEndPos) //3개의 함수를 전달.
{
	pStartPos->x = 0;
	pStartPos->y = 0;

	pEndPos->x = 19;
	pEndPos->y = 19;

	*pPlayerPos = *pStartPos;

	strcpy_s(Maze[0], "21100000000000000000"); //요소를 하나하나 설정하지 않고 통합.
	strcpy_s(Maze[1], "00111111111100000000");
	strcpy_s(Maze[2], "00100010000111111100");
	strcpy_s(Maze[3], "01100010000000000100");
	strcpy_s(Maze[4], "01000011110001111100");
	strcpy_s(Maze[5], "01000000001111000000");
	strcpy_s(Maze[6], "01100000001100000000");
	strcpy_s(Maze[7], "00001110001000000000");
	strcpy_s(Maze[8], "01111011111111111000");
	strcpy_s(Maze[9], "01000000000000000000");
	strcpy_s(Maze[10], "01111100111111100000");
	strcpy_s(Maze[11], "00000111100000111110");
	strcpy_s(Maze[12], "01111100000000000010");
	strcpy_s(Maze[13], "01000000011111111110");
	strcpy_s(Maze[14], "01000000110000000000");
	strcpy_s(Maze[15], "01111110100000000000");
	strcpy_s(Maze[16], "00000010110000000000");
	strcpy_s(Maze[17], "01111110011111000000");
	strcpy_s(Maze[18], "01000000000001100000");
	strcpy_s(Maze[19], "11000000000000111113");//Alt + Shift 
}
void Output(char Maze[21][21], PPOINT pPlayerPos)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if(Maze[i][j] == '4')
				cout << "♨";

			else if (pPlayerPos->x == j && pPlayerPos->y == i)
				cout << "☆";

			else if (Maze[i][j] == '0')
				cout << "■";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "★";

			else if (Maze[i][j] == '3')
				cout << "◎";

		
		}//특수문자 : ㅁ에 커서 올리고, 한자 버튼.
		cout << endl;
	}
}

void MoveUp(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y - 1 >= 0)
	{
		if (Maze[pPlayerPos->y - 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y - 1][pPlayerPos->x] != '4')
		{
			--pPlayerPos->y;
		}
	}
}

void MoveDown(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->y + 1 < 20)
	{
		if (Maze[pPlayerPos->y + 1][pPlayerPos->x] != '0' &&
			Maze[pPlayerPos->y + 1][pPlayerPos->x] != '4')
		{
			++pPlayerPos->y;
		}
	}
}

void MoveLeft(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x - 1 < 20)
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x - 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x - 1] != '4')
		{
			--pPlayerPos->x;
		}
	}
}

void MoveRight(char Maze[21][21], PPOINT pPlayerPos)
{
	if (pPlayerPos->x + 1 < 20)
	{
		if (Maze[pPlayerPos->y][pPlayerPos->x + 1] != '0' &&
			Maze[pPlayerPos->y][pPlayerPos->x + 1] != '4')
		{
			++pPlayerPos->x;
		}
	}
}

void MovePlayer(char Maze[21][21], PPOINT pPlayerPos, char cInput)
{
	switch (cInput)
	{
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayerPos);
		break;

	case 's':
	case 'S':
		MoveDown(Maze, pPlayerPos);
		break;

	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayerPos);
		break;

	case 'd':
	case 'D':
		MoveRight(Maze, pPlayerPos);
		break;
	}
}

//포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 없다.
void CreateBomb(char Maze[21][21], const PPOINT pPlayer,
	PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;

	for (int i = 0; i < *pBombCount; ++i)
	{
		if (pPlayer->x == pBombArr[i].x &&
			pPlayer->y == pBombArr[i].y)
			return;
	}
	pBombArr[*pBombCount] = *pPlayer;
	++(*pBombCount);

	Maze[pPlayer->y][pPlayer->x] = '4';


}

void Fire(char Maze[21][21], const PPOINT pPlayer, PPOINT pBombArr, int* pBombCount)
{
	for (int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		//플레이어가 폭탄에 맞았을 때 시작점으로 보낸다. 주석 단축키 : ctrl + K + C
		if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y)
		{
			pPlayer->x = 0;
			pPlayer->y = 0;
		}

		if (pBombArr[i].y - 1 >= 0)
		{
			if (Maze[pBombArr[i].y - 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y - 1][pBombArr[i].x] = '1';

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y - 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		if (pBombArr[i].y + 1 < 20)
		{
			if (Maze[pBombArr[i].y + 1][pBombArr[i].x] == '0')
				Maze[pBombArr[i].y + 1][pBombArr[i].x] = '1';

			if (pPlayer->x == pBombArr[i].x && pPlayer->y == pBombArr[i].y + 1)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		if (pBombArr[i].x - 1 >= 0)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x - 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x - 1] = '1';

			if (pPlayer->x == pBombArr[i].x - 1 && pPlayer->y == pBombArr[i].y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}

		if (pBombArr[i].x + 1 < 20)
		{
			if (Maze[pBombArr[i].y][pBombArr[i].x + 1] == '0')
				Maze[pBombArr[i].y][pBombArr[i].x + 1] = '1';

			if (pPlayer->x == pBombArr[i].x + 1 && pPlayer->y == pBombArr[i].y)
			{
				pPlayer->x = 0;
				pPlayer->y = 0;
			}
		}
	}
	*pBombCount = 0;
}
int main() {

	//20 X 20 미로를 만들어준다.
	char strMaze[21][21] = {};
	//미로를 설정

	POINT tPlayerPos;
	POINT tStarPos;
	POINT tEndPos;
	

	int iBombCount = 0;
	int iAddBomb = 0;

	POINT tBombPos[5];

	SetMaze(strMaze, &tPlayerPos, &tStarPos, &tEndPos);
	char cInput;


	while (true)
	{
		system("cls");
		Output(strMaze, &tPlayerPos);

		if (tPlayerPos.x == tEndPos.x && tPlayerPos.y == tEndPos.y)
		{
			cout << "도착했습니다." << endl;
			break;
		}

		cout << "t : 폭탄설치 u : 폭탄 터트리기" << endl;
		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : ";
		char  cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		else if (cInput == 't' || cInput == 'T')
		{
			//strMaze[tPlayerPos.y][tPlayerPos.x] = '4';
			CreateBomb(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}

		else if (cInput == 'u' || cInput == 'U')
		{	
			Fire(strMaze, &tPlayerPos, tBombPos, &iBombCount);
		}
		else
			MovePlayer(strMaze, &tPlayerPos, cInput);
	}
	return 0;
}//C++ games 미로게임 3,4,5만 추가하면 된다.

//Maze[pBombArr[i].y][pBombArr[i].x] = '0';