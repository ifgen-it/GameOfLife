
#pragma once
#include <iostream>
#include <set>
//#include <time.h> //nanosleep
#include <Windows.h>
#include <conio.h>
#include <cstdlib>

#include "point.h"
#include "figure.h"
#include "display.h"

using namespace std;

// nanosleep parametrs:
//timespec tw = {0, 4000000 };
//timespec tr;
	
const int Rows = 20;
const int Cols = 30;
const int Delay = 1;

void TimeDelay(int t);

int main()
{
	int ar[][2] = {

		                   
		                   //planer2
		                   /*10,10,
		                   10,11,
		                   10,12,
		                   10,13,
		                   9,13,
		                   8,13,
		                   7,12,
		                   9,9,
		                   */
		             
		             //planer3
		                  /* 30,10,
		                   30,11,
		                   30,12,
		                   30,13,
		                   30,14,
		                   30,15,
		                   29,15,
		                   28,15,
		                   27,14,
		                   29,9, */
		                   
		         
		                 
		                   //planer
		                   10, 5,
		                   10, 6,
		                   10, 7,
		                   9, 7,
		                   8, 6 
	};
	int n = sizeof (ar)/sizeof (ar[0]);
	 Figure f1(Rows, Cols);
	 for (int i=0;i<n;i++)
	 {
	 	f1.AddPoint(Point(ar[i][0], ar[i][1]));
	 }
	Display d1(Rows, Cols);
	d1.Fill();
	d1.Print();
	TimeDelay(Delay * 10 );
	system("cls");
	d1.Clear();
	
	///// begin //////
	
					/*d1.AddFigure(f1);
					d1.Print();
					TimeDelay( 20 * Delay);
					d1.Clear();
					system("cls");*/

			

	while ( true )
	{

			d1.AddFigure(f1);
			system("cls");
			d1.Print();
			TimeDelay( 10 * Delay);
	
	
			f1.Update1();
			d1.Clear();
	}




	// тестирование экрана
	/*char Test[40][41];
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			Test[i][j] = '@';
		}
	}


	for (int k = 0; k < 30; k++)
	{
				
		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
				Test[i][j] += k;
			}
		}
		for (int i = 0; i < 40; i++)
		{
			Test[i][40] = '\0';
		}

		for (int i = 0; i < 40; i++)
		{
			for (int j = 0; j < 40; j++)
			{
						cout << Test[i][j];
			

			}
			cout << endl;
		}
		
		
		TimeDelay(150);
		system("cls");
	}*/
	

	
	system("pause");

	return 0;
}
void TimeDelay(int t)
{
   for (int i = 0; i < t ; i ++)
   {
   	 // nanosleep(&tw, &tr);
	   Sleep(10);
   }  
}