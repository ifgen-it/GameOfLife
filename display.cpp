#pragma once
#include "display.h"

void Display::AddFigure(const Figure& f)
{
   	set<Point>::iterator it1 = f.Alive.begin(), it2 = f.Alive.end();
	while (it1 != it2)
	{
		int x, y;
		(*it1).GetPoint(x, y);
		vv[ x ] [ y ] = '@';
		
		++it1;
	}
}

void Display::Fill()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			vv[ i ] [ j ] = '@';
		}
	}
}

void Display::Clear()
{
	vv = vv_clear;
}

void Display::Born_clear()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			vv_clear[ i ] [ j ] = ' ';
		}
	}

	/*for (int i = 0; i < m_rows; i++)
	{
		vv_clear[i][0] = '$';
		vv_clear[i][m_cols-1] = '$';
	}

	for (int j = 0; j < m_cols; j++)
	{
		vv_clear[0][j] = '$';
		vv_clear[m_rows-1][j] = '$';
	}*/

}


void Display::Print()
{
	for (int i = 0; i < m_rows; i++)
	{
		for (int j = 0; j < m_cols; j++)
		{
			cout << vv[ i ] [ j ];
		}
		cout << endl;
	}
}