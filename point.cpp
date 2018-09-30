#pragma once
#include "point.h"

Point::Point()
{
	m_x = 0;
	m_y = 0;
}

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
}

Point::Point(const Point& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
}

Point::Point(Point&& temp)
{
	m_x = temp.m_x;
	m_y = temp.m_y;
}


Point::~Point()
{
}

void Point::SetPoint(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Point::GetPoint(int& x, int& y) const
{
	x = m_x;
	y = m_y;
}

void Point::Print() const
{
	cout << "m_x = " << m_x << endl;
	cout << "m_y = " << m_y << endl;
}

bool Point::operator==(const Point& other) const
{
	return (m_x == other.m_x) && (m_y == other.m_y);
}

bool Point::operator<(const Point& other) const
{
	if (m_x < other.m_x) { return true; }
	else if (m_x > other.m_x) { return false; }
	else if (m_x == other.m_x )
	{
		if (m_y  < other.m_y) { return true; }
		else { return false; }
	}
}

Point& Point::operator=(const Point& other)
{
	this->m_x = other.m_x;
	this->m_y = other.m_y;
	return *this;
}

Point& Point::operator=(Point&& temp)
{
	this->m_x = temp.m_x;
	this->m_y = temp.m_y;
	return *this;
}

Point& Point::operator=(int d)
{
	this->m_x = d;
	this->m_y = d;
	return *this;
}

Point& Point::operator+=(const Point& other)
{
	this->m_x += other.m_x;
	this->m_y += other.m_y;
	return *this;
}

Point& Point::operator+=(int d)
{
	this->m_x += d;
	this->m_y += d;
	return *this;
}

Point& operator-=(Point& first, Point& second)
{
	first.m_x -= second.m_x;
	first.m_y -= second.m_y;
	return first;
}

Point& operator-=(Point& first, int second)
{
	first.m_x -= second;
	first.m_y -= second;
	return first;
}

Point Point::operator+(const Point& other) const
{
	int x, y;
	x = m_x + other.m_x;
	y = m_y + other.m_y;
	Point temp(x, y);
	return temp;
}

Point Point::operator+(int d) const
{
	int x, y;
	x = m_x + d;
	y = m_y + d;
	return Point(x, y);
}

Point operator+(int second, const Point& first)
{
	int x, y;
	x = first.m_x + second;
	y = first.m_y + second;
	return Point(x, y);
}

Point operator-(const Point& first, const Point& second)
{
	int x, y;
	x = first.m_x - second.m_x;
	y = first.m_y - second.m_y;
	return Point(x, y);
}

Point operator-(const Point& first, int second)
{
	int x, y;
	x = first.m_x - second;
	y = first.m_y - second;
	return Point(x, y);
}

Point operator-(int second, const Point& first)
{
	int x, y;
	x = second - first.m_x;
	y = second - first.m_y;
	return Point(x, y);
}

Point operator-(const Point& first)
{
	int x, y;
	x = -first.m_x;
	y = -first.m_y;
	return Point(x, y);
}

const Point& operator+(const Point& first)
{
	return first;
}

ostream& operator<<(ostream& os, const Point& P)
{
	os << "x= " << P.m_x << " y= " << P.m_y;
	//os << P.m_x << " " << P.m_y ;
	return os;
}

istream& operator>>(istream& is, Point& P)
{
	char Temp[8] = { 0 };
	is >> Temp >> P.m_x >> Temp >> P.m_y;

	return is;
}