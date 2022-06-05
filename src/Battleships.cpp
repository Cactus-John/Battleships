
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
#include "PvP.h"
#include "AI.h"
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

void save_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	ofstream datoteka("battleships.bin", ofstream::out);
	datoteka.write((char*)&player_ocean, sizeof(player_ocean));
	datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
	datoteka.close();
	if (datoteka.fail())
		cout << "Greska kod otvaranja datoteke!" << endl;
}

void game_diff_1(char& y, int&x, char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11], char(&ocean)[11][11])
{
	int hits_by_player = 0, hits_by_AI = 0, turns = -1;
	while (hits_by_player < 18 || hits_by_AI < 18)
	{
		turns++;
		// player turn
		if (turns % 2 == 0)
		{
			cout << "Enter cordinates where you want to shoot: " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			if (ocean[x][y] == '#')
			{
				hits_by_player++;
				ocean_PLAYER_2[x][y] = 'X';
				ocean[x][y] = 'X';
			}
			else
			{
				ocean_PLAYER_2[x][y] = 'O';
			}
			system("CLS");
			// Ispisuje polje igraća 2 (AI-player 2)
			game_board2(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			game_board(player_ocean);

			cout << "Would you like to save the game: " << endl;
			cout << "Y or N" << endl;
			char unos;
			cin >> unos;
			if (tolower(unos) == 'y')
				save_file(player_ocean, ocean_PLAYER_2);
			

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
			game_board2(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			game_board(player_ocean);
		}
		if (hits_by_AI == 17)
		{
			cout << "You lost" << endl;
			exit(0);
		}
	}
}

void game_diff_2(char& y, int&x, char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11], char(&ocean)[11][11])
{
	int hits_by_player = 0, hits_by_AI = 0, turns = 0;

	while (hits_by_player < 18 || hits_by_AI < 18)
	{
		if (turns % 2 == 1)
		{
			cout << "Enter cordinates where you want to shoot:\n";
			cin >> y >> x;
			y = pretvorba(y);

			if (ocean[x][y] == '#')
			{
				ocean_PLAYER_2[x][y] = 'X';
				ocean[x][y] = 'X';
				hits_by_player++;
			}
			else
			{
				ocean_PLAYER_2[x][y] = 'O';
			}
			// Ispisuje polje igraća 2 (AI-player 2)
			system("CLS");

			game_board2(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			game_board(player_ocean);
			// turns++;
		}
		cout << "Would you like to save the game: " << endl;
		cout << "Y or N" << endl;
		char unos;
		cin >> unos;
		if (tolower(unos) == 'y')
			save_file(player_ocean, ocean_PLAYER_2);
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

			game_board2(ocean_PLAYER_2);
			//Ispisuje polje igrača 1 (player)
			game_board(player_ocean);
		}
		if (hits_by_AI == 17)
		{
			//string odabir;
			cout << "You lost" << endl;
			cout << "If you want to leave the game just press any key! Good luck!" << endl;
			exit(0);
		}
		turns++;
	}
}

void load_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	ifstream datoteka("battleships.bin", ifstream::in);
	datoteka.read((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
	datoteka.read((char*)&player_ocean, sizeof(player_ocean));
	datoteka.close();
	game_board(player_ocean);
	game_board2(ocean_PLAYER_2);
}

int main()
{
	srand(time(nullptr));
	bool load_GAME = false;
	char player_ocean[11][11];
	char ocean_PLAYER_2[11][11];
	
	int x;
	char y;
	cout << "0. New game\n1. Load game\n";
	cin >> load_GAME;
	if (load_GAME)
		load_file(player_ocean, ocean_PLAYER_2);

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
	cout << "Do you want to play against AI or Player" << endl;
	string odabir;
	cin >> odabir;
	if (odabir == "AI")
	{
		generating_AI(ocean);
		cout << " Enemy teritory\n";
		//Ispisuje igraču ploču protivnika
		ispis(player_ocean);
		cout << endl << endl;
		cout << " Your teritory\n";
		// Ispisuje igraču ploču igrača
		for (int i = 0; i < 11; i++)
		{
			if (i != 10)
				cout << " " << i << " ";
			else
				cout << i << " ";
			for (int j = 1; j < 11; j++)
			{
				cout << player_ocean[i][j] << " ";
			}
			cout << endl;
		}
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
		// Ispisuje polje igraća 2 (AI-player 2)

		for (int i = 0; i < 11; i++)
		{
			if (i != 10)
				cout << " " << i << " ";
			else
				cout << " " << i << " ";
			for (int j = 1; j < 11; j++)
			{
				cout << ocean_PLAYER_2[i][j] << " ";
			}
			cout << endl << endl;
		}
		//Ispisuje polje igrača 1 (player)
		ispis(player_ocean);

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
		player_v_player(y, x, player_ocean, ocean_PLAYER_1);


	return 0;
}
