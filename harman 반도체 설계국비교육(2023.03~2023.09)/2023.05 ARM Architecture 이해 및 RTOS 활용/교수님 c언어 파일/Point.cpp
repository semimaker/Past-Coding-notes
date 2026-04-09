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
    Point(int x1 = 0, int y1 = 0) : x(x1), y(y1)
    {
        //x = x1; 
        //y = y1;
    }
    //Point() { x = y = 0; }   // null 생성자 : 아무것도 하지 않음  
    int X();
    int Y();
    void SetX(int x1);
    void SetY(int y1);
    void SetP(int x1, int y1);
    void SetP(Point &p)
    {
        this->x = p.x; y = p.y;
    }
    double Distance(Point &p);
};

class Point3D : public Point
{
private:
    int z;
public:
    Point3D(int x1, int y1,int z1) : Point(x1,y1), z(z1) {}
    int Z() 
    {
       return z; 
    }
    void SetZ(int z1) { z = z1; }
    void SetP(int x1, int y1, int z1) { SetX(x1); SetY(y1); z = z1; }
    void SetP(Point3D &p)
    {
        SetX(p.X()); SetY(p.Y()); z = p.z;
    }
    double Distance(Point3D &p)
    {
        int x1 = p.X();
        int y1 = p.Y();
        int z1 = p.z;
        int xx = X();
        int yy = Y();
        
        double r = sqrt((x1-xx)*(x1-xx) + (y1-yy)*(y1-yy) + (z1-z)*(z1-z));
        return r;
    }
};

class Line
{
private:
    Point p1, p2;    
public:
    double dist;
    Line(Point pp1, Point pp2)
    {
        p1.SetP(pp1); p2.SetP(pp2); dist = p1.Distance(p2);
    }
};

class Rect
{
private:
    Point p1, p2;   
public:
    Point LL, LR, UL, UR;    // (0,0) 으로 초기화 
    double dist;
    Rect(Point pp1, Point pp2)
    {
        p1.SetP(pp1); p2.SetP(pp2); dist = p1.Distance(p2);
        calcP();
    }
    
#define MAX(a,b) (a<b)?b:a
#define MIN(a,b) (a<b)?a:b
  
    void calcP() // LL,LR,UL,UR Point 생성 
    {
        int x1, x2, y1, y2;  // x1 < x2, y1 < y2
        x1 = MIN(p1.X(), p2.X());
        x2 = MAX(p1.X(), p2.X());
        y1 = MIN(p1.Y(), p2.Y());
        y2 = MAX(p1.Y(), p2.Y());
        
        LL.SetP(x1,y1); LR.SetP(x2,y1); UL.SetP(x1,y2); UR.SetP(x2,y2);
    }
};

int Point::X() { return x; }
int Point::Y() { return y; }
void Point::SetX(int x1) { x = x1; }
void Point::SetY(int y1) { y = y1; }
void Point::SetP(int x1, int y1) { x = x1; y = y1; }
double Point::Distance(Point &p)
{
    //int x = Point::x;
    //int y = Point::y;
    int x1 = p.x;
    int y1 = p.y;
    
    double r = sqrt((x1-x)*(x1-x) + (y1-y)*(y1-y));
    return r;
}


int main(int argc, char** argv)
{
    Point *p1 = new Point(10,10);
    Point p2(20,20);
    Point p3(p2);
    Rect r(*p1,p2);
    
    Point3D p31 = Point3D(10,10,10);
    Point3D p32 = Point3D(20,20,20);      
    
    printf("Point p1의 x 값은 %d, y값은 %d 입니다.\n", p1->X(), p1->Y()); 
    printf("Point p2의 x 값은 %d, y값은 %d 입니다.\n", p2.X(), p2.Y());
    printf("Point p3의 x 값은 %d, y값은 %d 입니다.\n", p3.X(), p3.Y());
    printf("두 점(p1,p2)의 거리는 %f입니다.\n", p2.Distance(*p1));
    printf("p1(%d,%d)과 p2(%d,%d)에 의해 정의되는 사각형은\n", p1->X(), p1->Y(), p2.X(), p2.Y());
    printf("UL(%d,%d),UR(%d,%d),LL(%d,%d),LR(%d,%d) 입니다\n", 
        r.UL.X(), r.UL.Y(),
        r.UR.X(), r.UR.Y(),
        r.LL.X(), r.LL.Y(),
        r.LR.X(), r.LR.Y()
        );
        
    printf("\n\n\nPoint3D p31과 p32의 거리는 %f 입니다.\n", p31.Distance(p32));
    getch();
	return 0;
}
