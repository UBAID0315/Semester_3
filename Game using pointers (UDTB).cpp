#include<iostream>
#include <cstdlib>
#include<ctime>
using namespace std;

const int rows = 3,columns=3;

void print(char arr[][columns])
{
	for(int i = 0;i < rows;i++)
	{
		for (int j = 0; j < columns; j++)
		 {
			cout<<arr[i][j]<<" "<<" "<<" ";
		 }
		 cout<<endl<<endl;
	}
}
int main()
{
	char *curr;
	string choice;
	int move,count=0;
	srand(time(NULL));
	char arr[rows][columns];
	
	for(int i = 0;i < rows;i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int randomValue = rand() % 2;
			arr[i][j] = (randomValue == 0)?'*':'-';
		}
	}
	arr[1][1] = 'o';
	curr = &arr[1][1];
	print(arr);
	cout<<endl;

	loop:
	while (1)
	{
		cout<<endl;
		cout<<"Your current position is 'o'"<<endl;
		cout<<"Choose a safe move, try to away from the 'x'(hint)"<<endl;
		cout<<"1) Top"<<endl;
		cout<<"2) Bottom"<<endl;
		cout<<"3) Right"<<endl;
		cout<<"4) Left"<<endl;
		cout<<endl;
		cout<<"Enter your move: ";
		cin>>move;

		if (move == 1)
		{
			char temp = *(curr-rows);
			if (*(curr-rows) == '-')
			{
				*(curr-rows) = *curr;
				*curr = temp;
				cout<<"Congrats! you got a reward"<<endl;
				curr = (curr-rows);
				count++;
			}
			else if(*(curr-rows) == '*')
			{
				cout<<"Alas! you collide with the bomb"<<endl;
				count--;
				break;
			}
			print(arr);
		}
		else if (move == 2)
		{
			char temp = *(curr+rows);
			if (*(curr+rows) == '-')
			{
				*(curr+rows) = *curr;
				*curr = temp;
				cout<<"Congrats! you got a reward"<<endl;
				curr = (curr+rows);
				count++;
			}
			else if(*(curr+rows) == '*')
			{
				cout<<"Alas! you collide with the bomb"<<endl;
				count--;
				break;
			}
			print(arr);
		}
		else if (move == 3)
		{
			char temp = *(curr+1);
			if (*(curr+1) == '-')
			{
				*(curr+1) = *curr;
				*curr = temp;
				cout<<"Congrats! you got a reward"<<endl;
				curr = (curr+1);
				count++;
			}
			else if (*(curr+1) == '*')
			{
				cout<<"Alas! you collide with the bomb"<<endl;
				count--;
				break;
			}
			print(arr);
		}
		else if (move == 4)
		{
			char temp = *(curr-1);
			if (*(curr-1) == '-')
			{
				*(curr-1) = *curr;
				*curr = temp;
				cout<<"Congrats! you got a reward"<<endl;
				curr--;
				count++;
			}
			else if (*(curr-1) == '*')
			{
				cout<<"Alas! you collide with the bomb"<<endl;
				count--;
				break;
			}
			print(arr);
		}
	}
	print(arr);
	cout<<endl;
	cout<<"Do you want to try again (yes/no) ?"<<endl;
	cin>>choice;
	if (choice == "no")
	{
		if (count > 3)
		{
			cout<<"Congratulations! you won the game by "<<count<<" points"<<endl;
		}
		else
		{
			cout<<"You got rewards but lose"<<endl;
		}
	}
	else
	{
		goto loop;
	}
}