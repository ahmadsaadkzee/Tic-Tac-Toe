#include <iostream>
using namespace std;
struct layout
{
int choice;
char board[3][3] =  {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row, column;
char turn = 'X';
bool draw =false;
string player1, player2;
};

layout a;

void display_board()
{
	system("cls");
	cout<< "\n\t\tT i c   T a c   T o e\n";
	cout<<"\t====================================="<<endl;
	cout<< "\n\t "<<a.player1<<" = [X] \n \t "<<a.player2<<" = [O]\n\n";

	cout<<"\t\t     |     |     "<<endl;								
	cout<<"\t\t  "<<a.board[0][0]<<"  |  "<<a.board[0][1]<<"  |  "<<a.board[0][2]<<"  "<<endl;		
	cout<<"\t\t_____|_____|_____"<<endl;														
	cout<<"\t\t     |     |     "<<endl;														
	cout<<"\t\t  "<<a.board[1][0]<<"  |  "<<a.board[1][1]<<"  |  "<<a.board[1][2]<<"  "<<endl;		
	cout<<"\t\t_____|_____|_____"<<endl;														
	cout<<"\t\t     |     |     "<<endl;														
	cout<<"\t\t  "<<a.board[2][0]<<"  |  "<<a.board[2][1]<<"  |  "<<a.board[2][2]<<"  "<<endl;		
	cout<<"\t\t     |     |     "<<endl;
}

void player_turn()
{
	if (a.turn == 'X')
	cout<<"\n\n\t"<<a.player1<<"'s [X] turn: ";
	if (a.turn == 'O')
	cout<<"\n\n\t"<<a.player2<<"'s [O] turn: ";
	cin>> a.choice;
	switch(a.choice)
	{
		case 1: a.row = 0; a.column = 0; break;
		case 2: a.row = 0; a.column = 1; break;
		case 3: a.row = 0; a.column = 2; break;
		case 4: a.row = 1; a.column = 0; break;
		case 5: a.row = 1; a.column = 1; break;
		case 6: a.row = 1; a.column = 2; break;
		case 7: a.row = 2; a.column = 0; break;
		case 8: a.row = 2; a.column = 1; break;
		case 9: a.row = 2; a.column = 2; break;

		default:
			cout<<"Invalid Input !";
			break;
	}
	if (a.turn == 'X' && a.board[a.row][a.column] != 'X' && a.board[a.row][a.column] != 'O')
	{
		a.board[a.row][a.column] = 'X';
		a.turn = 'O';
	}
	else if (a.turn == 'O' && a.board[a.row][a.column] != 'X' && a.board[a.row][a.column] != 'O')
	{
		a.board[a.row][a.column] = 'O';
		a.turn = 'X';
	}
	else
	{
		cout<< "\n\tBox already filled \n\tChoose another box";
		player_turn();
	}
	display_board();
}


bool game_over()
{
	for (int i=0; i<3; i++)
	if (a.board[i][0] == a.board[i][1] && a.board[i][0] == a.board[i][2] || a.board[0][i] == a.board[1][i] && a.board[0][i] == a.board[2][i])
	return false;

	if(a.board[0][0] == a.board[1][1] && a.board[0][0] == a.board[2][2] || a.board[0][2] == a.board[1][1] && a.board[0][0] == a.board[2][0])
	return false;

	for(int i=0; i<3; i++)
	for(int j=0; j<3; j++)
	if (a.board[i][j] != 'X' && a.board [i][j] != 'O')
	return true;

	a.draw = true;
	return false;
}



int main()
{
	cout<<"What's your name?\n";
getline(cin,a.player1);
cout<<"What's your opponent name?\n";
getline(cin,a.player2);
	while(game_over())
	{
	display_board();
	player_turn();
	game_over();

}

if(a.turn== 'X' && a.draw == false)
cout<<a.player2<<" [O] wins!!\n";
else if(a.turn== 'O' && a.draw == false)
cout<<a.player1<<" [X] wins!!\n";
else
{
	cout<< "GAME DRAW !!";
}

}
