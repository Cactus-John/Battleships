
#include <ctime>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
#include "generate_AI.h"
#include "PvP.h"
#include "ship_placement.h"

using namespace std;

int pretvorba(char y)
{
	y = toupper(y);	
	switch(y)
	{
		case('A'):y = 1; break;
		case('B'):y = 2; break;
		case('C'):y = 3; break;
		case('D'):y = 4; break;
		case('E'):y = 5; break;
		case('F'):y = 6; break;
		case('G'):y = 7; break;
		case('H'):y = 8; break;
		case('I'):y = 9; break;
		case('J'):y = 10; break;
	}
	return y;
}

void game_diff_1(char& y, int&x, char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11], char(&ocean)[11][11])
{

	int hits_by_player = 0, hits_by_AI = 0, turns = -1;
	fstream datoteka;
	while (hits_by_player < 18 || hits_by_AI < 18)
	{
		turns++;
		// player turn
		if (turns % 2 == 0)
		{
			cout << "Enter cordinates where you want to shoot: " << endl;
			cin >> y >> x;
			y = pretvorba(y);
		opet3:
			if (ocean[x][y] == '#')
			{
				hits_by_player++;
				ocean_PLAYER_2[x][y] = 'X';
				ocean[x][y] = 'X';
			}
			else if (ocean[x][y] == 'X')
			{
				cout << "Ovdje ste vec gadali! Gadajte drugu koordinatu: " << endl;
				cin >> y >> x;
				y = pretvorba(y);
				goto opet3;
			}
			else
			{
				ocean_PLAYER_2[x][y] = 'O';
			}
			system("CLS");
			// Ispisuje polje igraća 2 (AI-player 2)
			cout << "Your game board" << endl;
			game_board(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			cout << "AI game board" << endl;
			game_board(player_ocean);
			//save_file(player_ocean, ocean_PLAYER_2);
			
		}
		if (hits_by_player == 17) 
		{
			//string odabir;
			cout << "You won" << endl;
			//cout << "If you want to leave the game just press any key! Good luck summoner!" << endl;
			exit(0);
			
		}

		// AI turn
		if (turns % 2 == 1)
		{
			int r = rand() % 10 + 1;
			int p = rand() % 10 + 1;
			if (player_ocean[r][p] == '#')
			{
				hits_by_AI++;
				player_ocean[r][p] = 'X';
			}
			else
			{
				player_ocean[r][p] = 'O';
			}
			system("CLS");
			// Ispisuje polje igraća 2 (AI-player 2)
			cout << "Your game board" << endl;
			game_board(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			cout << "AI game board" << endl;
			game_board(player_ocean);
		}
		if (hits_by_AI == 17)
		{
			cout << "You lost" << endl;
			exit(0);
		}
		datoteka.open("battleships.bin", ios::binary | ios::out);
		datoteka.write((char*)&player_ocean, sizeof(player_ocean));
		datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
		datoteka.close();
	}
}

void game_diff_2(char& y, int&x, char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11], char(&ocean)[11][11])
{
	int hits_by_player = 0, hits_by_AI = 0, turns = 0;
	fstream datoteka;

	while (hits_by_player < 18 || hits_by_AI < 18)
	{
		//Player turn
		if (turns % 2 == 1)
		{
			cout << "Enter cordinates where you want to shoot:\n";
			cin >> y >> x;
			y = pretvorba(y);
		opet4:
			if (ocean[x][y] == '#')
			{
				ocean_PLAYER_2[x][y] = 'X';
				ocean[x][y] = 'X';
				hits_by_player++;
			}
			else if (ocean[x][y] == 'X')
			{
				cout << "Ovdje ste vec gadali! Gadajte drugu koordinatu: " << endl;
				cin >> y >> x;
				y = pretvorba(y);
				goto opet4;
			}
			else
			{
				ocean_PLAYER_2[x][y] = 'O';
			}
			// Ispisuje polje igraća 2 (AI-player 2)
			system("CLS");

			cout << "Your game board" << endl;
			game_board(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			cout << "AI game board" << endl;
			game_board(player_ocean);
			// turns++;
		}
		//save_file(player_ocean, ocean_PLAYER_2);
		if (hits_by_player == 17)
		{
			cout << "You won" << endl;
			exit(0);
		}
		//AI turn    
		if (turns % 2 == 0)
		{
			int r, p;
			bool flag = false;
			while (flag == false || player_ocean[r][p] != '#')
			{
				r = rand() % 10 + 1;
				p = rand() % 10 + 1;
				flag = true;
			}
			if (player_ocean[r][p] == '#')
			{
				hits_by_AI++;
				player_ocean[r][p] = 'X';
			}
			else 
			{
				player_ocean[r][p] = 'O';
			}
					
			// Ispisuje polje igraća 2 (AI-player 2)
			system("CLS");
			cout << "Your game board" << endl;
			game_board(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			cout << "AI game board" << endl;
			game_board(player_ocean);
		}
		if (hits_by_AI == 17)
		{
			//string odabir;
			cout << "You lost" << endl;
			exit(0);
		}
		turns++;

		datoteka.open("battleships.bin", ios::binary | ios::out);
		datoteka.write((char*)&player_ocean, sizeof(player_ocean));
		datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
		datoteka.close();
	}
}

int main()
{
	srand(time(nullptr));
	fstream datoteka, file;
	bool load_GAME = false;
	char player_ocean[11][11];
	char ocean_PLAYER_2[11][11];
	
	int x;
	char y;
	char ocean[11][11];
	char znak = 'A';

	for (int i = 0; i < 11; i++)
	{
		ocean[i][0] = i + 1;
		for (int j = 0; j < 11; j++)
		{
			znak++;
			if (i == 0)
				ocean[i][j] = znak - 2;
			else
				ocean[i][j] = '~';
		}
	}
	
	znak = 'A';
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			player_ocean[i][j] = ocean[i][j];
	}
	char ocean_PLAYER_1[11][11];
	znak = 'A';
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			ocean_PLAYER_1[i][j] = player_ocean[i][j];
	}
	
	znak = 'A';
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			ocean_PLAYER_2[i][j] = ocean_PLAYER_1[i][j];
	}

	// selecting AI or PLAYER 
	string odabir = "Player";
	if (odabir == "AI")
	{
		bool load_GAME = false;
		cout << "0. New game\n1. Load game\n";
		cin >> load_GAME;
		system("cls");
		if (load_GAME)
		{
			datoteka.open("battleships.bin", ios::binary | ios::in);
			if (datoteka.fail())
			{
				cout << "Greska kod ucitavanja datoteke!" << endl;
				exit(0);
			}

			datoteka.read((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
			datoteka.read((char*)&player_ocean, sizeof(player_ocean));
			datoteka.close();
		}
		
		generating_AI(ocean);
		cout << endl << endl;
		// Postavlja brodove
		postavljanje_brodova(player_ocean);

		// Inicijalizira igraču ploču za igrača 2 (AI)
		char ocean_PLAYER_AI[11][11];
		znak = 'A';
		for (int i = 0; i < 11; i++)
		{
			ocean_PLAYER_AI[i][0] = i + 1;
			znak++;
			for (int j = 0; j < 11; j++)
			{
				if (j == 0)
					ocean_PLAYER_AI[i][j] = ocean[i][j];
				if (i != 0)
					ocean_PLAYER_AI[i][j] = '~';
			}
		}

		int diff = 0;
		cout << "Select difficulty:\n\t\t\t1.NOOB\n\t\t\t2.IMPOSSIBLE\n";
		cin >> diff;
		system("CLS");
		// noob bot
		if (diff == 1)
			game_diff_1(y, x, player_ocean, ocean_PLAYER_2, ocean);

		system("CLS");

		// pro bot
		if (diff == 2)
			game_diff_2(y, x, player_ocean, ocean_PLAYER_2, ocean);
	}
	
	if (odabir == "Player")
	{
		player_v_player(y, x, player_ocean, ocean_PLAYER_1);
	}

	return 0;
}
