

#include<iostream>
#include<ctime>
#include <windows.h> 
#include<conio.h>


using namespace std;

void ClearScreen();

int main()
{

	int num[5][5],number,row,col;
	int ask;
	bool ok = true;

	srand((unsigned) time(0)); 

	do{

		 Clrscr(); 
		cout<<"\n\n\t\t\t\t    BINGO GAME"<<endl;
		for(row=0;row<5;row++)
			for(col=0;col<5;col++)
				num[row][col]=0; 
		cout<<"\n\n\tB\t\tI\t\tN\t\tG\t\tO"<<endl;
		cout<<"\n\n";
		for(col = 0;col < 5; col++)
		{
			for (row=0;row < 5; row++)
			{
				do
				{
					ok = true;
					number = 1+(col*15) + rand()%15;
					for (int ck=0;ck<5;ck++)
					{
						if (number == num[ck][col])
								ok = false; 
					}
				}while (!ok);
			num[row][col] = number;
			}
		}

		for(row = 0;row < 5; row++)
		{
			for (col=0;col < 5; col++)
			{
				if((row==2)&&(col==2))
					cout<<"\tFREE\t";
				else
				cout << "\t" << num[row][col] << "\t";

			}
			cout << endl;
		}

		{
			cout<<"\n\n\tIs this the card you want to use? [0 for no only.] : ";
			cin>>ask;
		}
	} while(ask==0);

	return 0;
}

