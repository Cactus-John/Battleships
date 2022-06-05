
#include <iostream>
#include <fstream>
using namespace std;

int pretvorba(char y);
void ispis(char player_ocean[][11]);
void ispis2(char ocean_PLAYER_1[][11]);
void postavljanje_brodova(char(&player_ocean)[11][11]);

void player_v_player(char &y, int &x, char (&player_ocean)[11][11], char(&ocean_PLAYER_1)[11][11])
{

	char znak = 'A';
	for (int i = 0; i < 11; i++)
	{
		player_ocean[i][0] = i + 1;
		for (int j = 0; j < 11; j++)
		{
			znak++;
			if (i == 0)
				player_ocean[i][j] = znak - 2;
			else
				player_ocean[i][j] = '~';
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			ocean_PLAYER_1[i][j] = player_ocean[i][j];
	}
	
	int hits_by_player1 = 0, hits_by_player2 = 0, turns = 0;

	while (hits_by_player1 < 18 || hits_by_player2 < 18)
	{
		string player1, player2;
		// PLAYER 1 turn
		if (turns % 2 == 0)
		{
			cout << "PLAYER'S 1 turn to play: " << endl;
			postavljanje_brodova(player_ocean);
			if (player_ocean[x][y] == '#')
			{
				hits_by_player1++;
				ocean_PLAYER_1[x][y] = 'X';
				player_ocean[x][y] = 'X';
			}
			else
			{
				ocean_PLAYER_1[x][y] = 'O';
			}
			system("CLS");
			// Ispisuje polje igraća 1 (PLAYER 1)
			ispis2(ocean_PLAYER_1);
			//Ispisuje polje igrača 2 (PLAYER 2)
			//ispis(player_ocean);
		}
		if (hits_by_player1 == 17)
		{
			cout << "PLAYER 1 has WON!\nPLAYER 2 has LOST!" << endl;
			exit(0);

		}
		// PLAYER 2 turn
		if (turns % 2 == 1)
		{
			cout << "PLAYER'S 2 turn to play: " << endl;
			postavljanje_brodova(player_ocean);
			if (player_ocean[x][y] == '#')
			{
				hits_by_player2++;
				player_ocean[x][y] = 'X';
			}
			else
			{
				player_ocean[x][y] = 'O';
			}
			system("CLS");
			// Ispisuje polje igraća 2 (PLAYER 2)
			ispis(player_ocean);
			//Ispisuje polje igrača 1 (PLAYER 1)
			ispis2(ocean_PLAYER_1);

		}
		if (hits_by_player2 == 17)
		{
			cout << "PLAYER 2 has WON!\nPLAYER 1 has LOST!" << endl;
			exit(0);
		}
		turns++;
	}
		// doadaj unos imena igraca i na kraju ime pobjednika tj. gubitnika;
}
	
