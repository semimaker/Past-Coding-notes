#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Point 
{
private:
    int x,y;
    
public:
    Point(int x1, int y1)
    {
        x = x1; y = y1;
    }
    int X();
    int Y();
    double Distance(Point &p);
};

int Point::X() { return Point::x; }
int Point::Y() { return Point::y; }
double Point::Distance(Point &p)
{
    int x = Point::x;
    int y = Point::y;
    int x1 = p.x;
    int y1 = p.y;
    
    double r = sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
    return r;
}


int main(int argc, char** argv)
{
    Point *p1 = new Point(10,10);
    Point p2(20,20);
    
    printf("Point p1의 x 값은 %d, y값은 %d 입니다.\n", p1->X(), p1->Y()); 
    printf("Point p2의 x 값은 %d, y값은 %d 입니다.\n", p2.X(), p2.Y());
    printf("두 점(p1,p2)의 거리는 %f입니다.\n", p2.Distance(*p1));
    getch();
	return 0;
}
