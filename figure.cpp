#pragma once

#include "point.h"
#include "figure.h"

void Figure::PrintSet(const set<Point>& s)
{
	ITS it1 = s.begin(), it2 = s.end();
	while (it1 != it2)
	{
	cout << *it1 << ", ";
	++it1;
	}
}


VECT Figure::GetNeighb(const Point& p)
{
	VECT Neighb;
	int Add[8][2] = { 
	                            -1, -1,
	                            -1, 0,
	                            -1, 1,
	                            0, -1,
	                            0, 1,
	                            1, -1,
	                            1, 0,
	                            1, 1
	};
	
	int x, y;
    p.GetPoint(x, y);
    int Nx, Ny;
    
    for (int i=0; i < 8; i++)
    {
    	Nx = ( x + Add[ i ] [ 0 ] ) % m_rows;
    	Ny = ( y + Add[ i ] [ 1 ] ) % m_cols;
    	if (Nx == -1 ) { Nx += m_rows; }
    	if (Ny == -1) { Ny += m_cols; }
    	
    	Neighb.push_back(Point(Nx,Ny));	
    }
	
	return Neighb;
}

void Figure::Update1()
{
	Empty = Alive;
	//	cout << "begin Empty size " << Empty.size() << endl << endl;
	
	ITS it1 = Alive.begin(), it2 = Alive.end();
	while (it1 != it2)
	{
//		cout << *it1 << "'s neighb:" << endl;
		VECT N = GetNeighb(*it1);
		for (int i =0; i < 8;i++)
		{
		//	cout << N[ i ] << ", ";
			Empty.insert(N[ i ]);
		} cout << endl << endl;
		
		//Empty.insert(N.begin(), N.end());
			
	//	cout << "Inserted N in Empty, size: " << Empty.size() << endl << endl;
	//	cout << "PrintSet Empty:"<< endl;	
	//	PrintSet(Empty);
	//	cout << endl;
		++it1;
	}
	
	//	cout <<endl <<  "Inserted alived neighb Empty size : " << Empty.size() << endl;
	//	cout << "Final Empty:"<< endl;	
	//	PrintSet(Empty);
		
		
	// minus Alive
	it1 = Alive.begin(), it2 = Alive.end();
	while (it1 != it2)
	{
		
	
	Empty.erase(*it1);
	//	cout << "Empty size " << Empty.size() << endl;
		++it1;
	}
//	cout << "End Empty size " << Empty.size() << endl;
//	cout << endl << "Empty without alive:"<< endl;	
	//	PrintSet(Empty);
		
//	Alive = Empty;
	
//cout << endl <<  "Alive, size: "<< Alive.size() << endl;	
	//	PrintSet(Alive);
		
	//now we have 2 sets:
	// Alive - alive points
	// Empty - points near alive points
	
	// will check it for survive and birth
	SET NewAlive;
	
	ITS itA1 = Alive.begin(), itA2 = Alive.end();
	while (itA1 != itA2)
	{
		bool Will = WillSurvive( *itA1, 1);
		if ( Will )
		{
			NewAlive.insert( *itA1);
		}	
		++itA1;
	}
	
		ITS itE1 = Empty.begin(), itE2 = Empty.end();
	while (itE1 != itE2)
	{
		bool Will = WillSurvive( *itE1, 0);
		if ( Will )
		{
			NewAlive.insert( *itE1);
		}	
		++itE1;
	}
	
	//update alive
	Alive = NewAlive;
	
	
}

bool Figure::WillSurvive(const Point& p, int Status)
{
	//get all neighbours
	VECT N = GetNeighb(p);
	int NumAliveNeighb = 0;
	
		for (int i =0; i < 8;i++)
		{
			
			ITS itN = Alive.find( N[ i ] );
			if (itN != Alive.end() )
			{
				NumAliveNeighb++;
			}
			//cout << N[ i ] << ", ";	
		} 
    if (Status == 1) // alive
    {
    	if ( NumAliveNeighb >= 2 && NumAliveNeighb <= 3) return true;
    	else return false;
    }
    else // newBorn
    {
    	if ( NumAliveNeighb == 3 ) return true;
    	else return false;
    }
    
}

void Figure::Update()
{
	set<Point> Temp;
	ITS it1 = Alive.begin(), it2 = Alive.end();
	while (it1 != it2)
	{
		int x, y;
		(*it1).GetPoint(x, y);
		x = ( x + 1 )% m_rows;
		y  = ( y + 1 ) % m_cols;
   	Temp.insert(Point(x, y));
		++it1;
	}
	Alive = Temp;
}

  void Figure::AddPoint(const Point p)
   {
        int x, y;
		p.GetPoint(x, y);
		x = x % m_rows;
		y  = y % m_cols;
   	Alive.insert(Point(x, y));
   	
   }

void Figure::PrintAlive()
{
	ITS it1 = Alive.begin(), it2 = Alive.end();
	while (it1 != it2)
	{
		cout << *it1 << ", ";
		++it1;
	}
	
	
}