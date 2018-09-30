#pragma once


#include <iostream>
#include <vector>
#include <set>


#include "point.h"
#include "figure.h"

using namespace std;

class Display
{
	const int m_rows;
	const int m_cols;
	vector<vector<char>> vv;
	vector<vector<char>> vv_clear;

public:
	Display(int rows, int cols) : m_rows(rows), m_cols(cols), vv(m_rows)
	{
		for (int i = 0; i < m_rows; i++)
		{
			vv[i].resize(m_cols);
		}
		vv_clear = vv;
		this->Born_clear();
		Clear();
	}

	~Display() {}

	void Print();
	void Fill();
	void Clear();
	void Born_clear();
	void AddFigure(const Figure& f);

};