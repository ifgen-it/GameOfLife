#pragma once

#include <iostream>
#include <vector>
#include <set>


#include "point.h"

typedef set<Point>::iterator ITS;
typedef vector<Point> VECT;
typedef set<Point> SET;

using namespace std;

class Figure
{
	int m_rows;
	int m_cols;
	SET Alive;
	SET Empty;


	friend class Display;

public:
	Figure(int rows, int cols) : m_rows(rows), m_cols(cols) { }

	void AddPoint(const Point p);
	void PrintAlive();
	void Update();
	void Update1();
	bool WillSurvive(const Point& p, int Status);
	VECT GetNeighb(const Point& p);
	void PrintSet(const set<Point>& s);

};
