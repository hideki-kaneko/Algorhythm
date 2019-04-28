#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>

using namespace std;

class Point2d
{
public:
    Point2d();
    Point2d(float x, float y);
    float GetX() const;
    float GetY() const;
    Point2d operator + (Point2d obj);
    Point2d operator * (float val);
private:
    float m_X;
    float m_Y;
};

Point2d::Point2d()
{

}

Point2d::Point2d(float x, float y)
{
    m_X = x;
    m_Y = y;
}

float Point2d::GetX() const
{
    return m_X;
}

float Point2d::GetY() const
{
    return m_Y;
}

Point2d Point2d::operator+(Point2d obj)
{
    float newX = m_X + obj.GetX();
    float newY = m_Y + obj.GetY();
    Point2d newP(newX, newY);
    return newP;
}

Point2d Point2d::operator*(float val)
{
    float newX = m_X * val;
    float newY = m_Y * val;
    Point2d newP(newX, newY);
    return newP;
}

class Vector2d
{
public:
    Vector2d();
    Vector2d(Point2d begin, Point2d end);
    Vector2d GetRotate(float degree);       // 始点から時計回りにtheta回転させたベクトルを取得
    Point2d GetPointBegin();
    Point2d GetPointEnd();
    Vector2d operator + (Vector2d obj);
    Vector2d operator * (float val);

private:
    Point2d m_Begin;
    Point2d m_End;
    const float PI = 3.1415;
};

Vector2d::Vector2d()
{

}

Vector2d::Vector2d(Point2d begin, Point2d end)
{
    m_Begin = begin;
    m_End = end;
}

Vector2d Vector2d::GetRotate(float degree)
{
    float rad = degree * PI / 180.;
    float newX = m_Begin.GetX() + cos(rad) * (m_End.GetX() - m_Begin.GetX()) - sin(rad) * (m_End.GetY() - m_Begin.GetY());
    float newY = m_Begin.GetY() + sin(rad) * (m_End.GetX() - m_Begin.GetX()) + cos(rad) * (m_End.GetY() - m_Begin.GetY());
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
    float newX = m_End.GetX() + obj.m_End.GetX();
    float newY = m_End.GetY() + obj.m_End.GetY();
    Vector2d newV(m_Begin, Point2d(newX, newY));
    return newV;
}

Vector2d Vector2d::operator*(float val)
{
    float newX = m_Begin.GetX() + (m_End.GetX() - m_Begin.GetX()) * val;
    float newY = m_Begin.GetY() + (m_End.GetY() - m_Begin.GetY()) * val;
    Vector2d newV(m_Begin, Point2d(newX, newY));
    return newV;
}

void koch(int n, const Point2d* p1, const Point2d* p2)
{
    
}


int main3()
{
    int n;  // コッホ曲線の分割回数

    return 0;
}