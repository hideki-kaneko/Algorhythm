#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_C&lang=jp

class Point2d
{
public:
    Point2d();
    Point2d(double x, double y);
    double GetX() const;
    double GetY() const;
    Point2d operator + (Point2d obj);
    Point2d operator * (double val);
private:
    double m_X;
    double m_Y;
};

Point2d::Point2d()
{

}

Point2d::Point2d(double x, double y)
{
    m_X = x;
    m_Y = y;
}

double Point2d::GetX() const
{
    return m_X;
}

double Point2d::GetY() const
{
    return m_Y;
}

Point2d Point2d::operator+(Point2d obj)
{
    double newX = m_X + obj.GetX();
    double newY = m_Y + obj.GetY();
    Point2d newP(newX, newY);
    return newP;
}

Point2d Point2d::operator*(double val)
{
    double newX = m_X * val;
    double newY = m_Y * val;
    Point2d newP(newX, newY);
    return newP;
}

class Vector2d
{
public:
    Vector2d();
    Vector2d(Point2d begin, Point2d end);
    Vector2d GetRotate(double degree);       // 始点から反時計回りにtheta回転させたベクトルを取得
    Point2d GetPointBegin();
    Point2d GetPointEnd();
    Vector2d operator + (Vector2d obj);
    Vector2d operator * (double val);

private:
    Point2d m_Begin;
    Point2d m_End;
    const double PI = 3.14159265359;
};

Vector2d::Vector2d()
{

}

Vector2d::Vector2d(Point2d begin, Point2d end)
{
    m_Begin = begin;
    m_End = end;
}

Vector2d Vector2d::GetRotate(double degree)
{
    double rad = degree * PI / 180.;
    double newX = m_Begin.GetX() + cos(rad) * (m_End.GetX() - m_Begin.GetX()) - sin(rad) * (m_End.GetY() - m_Begin.GetY());
    double newY = m_Begin.GetY() + sin(rad) * (m_End.GetX() - m_Begin.GetX()) + cos(rad) * (m_End.GetY() - m_Begin.GetY());
    Vector2d newVec = Vector2d(m_Begin, Point2d(newX, newY));
    return newVec;
}

Point2d Vector2d::GetPointBegin()
{
    return m_Begin;
}

Point2d Vector2d::GetPointEnd()
{
    return m_End;
}

Vector2d Vector2d::operator+(Vector2d obj)
{
    double newX = m_End.GetX() + obj.m_End.GetX();
    double newY = m_End.GetY() + obj.m_End.GetY();
    Vector2d newV(m_Begin, Point2d(newX, newY));
    return newV;
}

Vector2d Vector2d::operator*(double val)
{
    double newX = m_Begin.GetX() + (m_End.GetX() - m_Begin.GetX()) * val;
    double newY = m_Begin.GetY() + (m_End.GetY() - m_Begin.GetY()) * val;
    Vector2d newV(m_Begin, Point2d(newX, newY));
    return newV;
}

void koch(int n, Point2d p1, Point2d p2)
{
    if (n == 0)
    {
        return;
    }

    Point2d s = (Vector2d(p1, p2) * (1. / 3.)).GetPointEnd();
    Point2d t = (Vector2d(p1, p2) * (2. / 3.)).GetPointEnd();
    Vector2d vST(s, t);
    Point2d u = vST.GetRotate(60).GetPointEnd();

    koch(n - 1, p1, s);
    cout << s.GetX() << " " << s.GetY() << endl;

    koch(n - 1, s, u);
    cout << u.GetX() << " " << u.GetY() << endl;

    koch(n - 1, u, t);
    cout << t.GetX() << " " << t.GetY() << endl;

    koch(n - 1, t, p2);
}


int main3()
{
    int n;  // コッホ曲線の分割回数
    Point2d p1(0.f, 0.f);
    Point2d p2(100.f, 0.f);

    cin >> n;

    cout << fixed;
    cout << setprecision(8);
    cout << p1.GetX() << " " << p1.GetY() << endl;
    koch(n, p1, p2);
    cout << p2.GetX() << " " << p2.GetY() << endl;

    return 0;
}