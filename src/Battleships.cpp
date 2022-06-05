
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include "PvP.h"
using namespace std;


int pretvorba(char y)
{
	y=toupper(y);	
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

void ispis(char player_ocean[][11])
{
	
	for (int i = 0; i < 11; i++)
	{
		if (i != 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
		for (int j = 1; j < 11; j++)
			cout << player_ocean[i][j] << " ";
		cout << endl;
	}
}

void game_board(char player_ocean[][11])
{
	for (int i = 0; i < 11; i++)
	{
		if (i != 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
		for (int j = 1; j < 11; j++)
		{
			cout << player_ocean[i][j] << '\t';
		}
		cout << endl << endl;
	}
}

void game_board2(char ocean_PLAYER_2[][11])
{
	for (int i = 0; i < 11; i++)
	{
		if (i != 10)
			cout << " " << i << " ";
		else
			cout << i << " ";
		for (int j = 1; j < 11; j++)
		{
			cout << ocean_PLAYER_2[i][j] << '\t';
		}
		cout << endl << endl;
	}
}

void unos(int& x, int& inty, char y, bool zastavica)
{
	while (x < 0 || x > 10 || inty == 0 || zastavica == true)
	{
		cout << "Krivi unos\n";
		system("pause");
		cout << "Unesite kordinatu:";
		cin >> y >> x;
		inty = pretvorba(y);
		zastavica = false;
		system("cls");
	}
}

void postavi_brod(int answer, char(&player_ocean)[11][11], int n)
{
	system("cls");
	int x, inty;
	char y;
	bool zastavica = false;
	cout << "Unesite kordinatu:";
	cin >> y >> x;
	inty = pretvorba(y);
	unos(x, inty, y, zastavica);
	if (answer == 1) // okomito
	{
		ponovno:
			for (int i = x; i < n + x; i++)//mislim da ako 5ticu postovis okmoito na a1 da ce proc? ->projvera spigana
				{
					zastavica = false;
					if (player_ocean[i][inty] == '#' || i > 10)
					{
						//exit(0);
						zastavica = true;
						unos(x, inty, y, zastavica);
						//continue;
						goto ponovno;
					}
				}

		for (int i = x; i < n + x && i < 11; i++)
			player_ocean[i][inty] = '#';
	}

	if (answer == 0) // vodoravno
	{
	ponovno_2:
		for (int i = inty; i < n + inty; i++)
			{
				zastavica = false;
				if (player_ocean[x][i] == '#' || i > 10)
				{
					zastavica = true;
					unos(x, inty, y, zastavica);
					goto ponovno_2;
				}
			}

		for (int i = inty; i < n + inty && i < 11; i++)
		{
			player_ocean[x][i] = '#';
		}
	}
	game_board(player_ocean);
	system("pause");
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
			{
				ofstream datoteka("battleships.bin", ofstream::out);
				datoteka.write((char*)&player_ocean, sizeof(player_ocean));
				datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
				datoteka.close();
				if (datoteka.fail())
					cout << "Greska kod otvaranja datoteke!" << endl;
			}

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
		{
			ofstream datoteka("battleships.bin", ofstream::out);
			datoteka.write((char*)&player_ocean, sizeof(player_ocean));
			datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
			datoteka.close();
			if (datoteka.fail())
				cout << "Greska kod otvaranja datoteke!" << endl;
		}
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
	if(load_GAME)
	{
		ifstream datoteka("battleships.bin", ifstream::in);
		datoteka.read((char*) &ocean_PLAYER_2, sizeof (ocean_PLAYER_2));
		datoteka.read((char*)&player_ocean, sizeof(player_ocean));
		datoteka.close();
			game_board(player_ocean);
			game_board2(ocean_PLAYER_2);
	}

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
	// selecting difficulty
	int diff = 0;
	cout << "Select difficulty:\n\t\t\t1.NOOB\n\t\t\t2.IMPOSSIBLE\n";
	cin >> diff;
	system("CLS");
	//AI GENERATED BATTLESHIP
	int r, p;
	r = rand() % 10 + 1;
	r = r % 2;
	if (r == 0)
	{
		r = rand() % 10 + 1;
		while (r + 4 > 10)
		{
			r = rand() % 10 + 1;

		}
		p = rand() % 10 + 1;
		int Battleship_cordsAI[4][4];
		for (int i = 0; i < 4; i++)
		{
			Battleship_cordsAI[i][0] = r;
			Battleship_cordsAI[i][1] = p;
			ocean[r + i][p] = '#';
		}
	}
	else
	{
		r = rand() % 10 + 1;
		p = rand() % 10 + 1;
		while (p + 4 > 10)
			p = rand() % 10 + 1;
		int Battleship_cordsAI[4][4];
		for (int i = 0; i < 4; i++)
		{
			Battleship_cordsAI[i][0] = r;
			Battleship_cordsAI[i][1] = p;
			ocean[r][p + i] = '#';
		}
	}

	// AI GENERATED CARRIER

	int sus = 0; //sus -> ships under ships
	r = rand() % 10 + 1;
	int zastavica = 0;
	r = r % 2;
	if (r == 0)
	{
		while (zastavica == 0)
		{
			r = rand() % 10 + 1;
			while (r + 5 > 10)
			{
				r = rand() % 10 + 1;
			}
			p = rand() % 10 + 1;
			int Carrier_cordsAI[5][5];
			for (int i = 0; i < 5; i++)
			{
				Carrier_cordsAI[i][0] = r;
				Carrier_cordsAI[i][1] = p;
				if (ocean[r + i][p] == '#')
					continue;
			}
			for (int i = 0; i < 5; i++)
			{
				Carrier_cordsAI[i][0] = r;
				Carrier_cordsAI[i][1] = p;
				ocean[r + i][p] = '#';
			}
			zastavica = 1;
		}
	}
	else
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			p = rand() % 10 + 1;
			while (p + 5 > 10)
				p = rand() % 10 + 1;
			int Carrier_cordsAI[5][5];
			for (int i = 0; i < 5; i++)
			{
				Carrier_cordsAI[i][0] = r;
				Carrier_cordsAI[i][1] = p;
				if (ocean[r][p + i] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;

			for (int i = 0; i < 5; i++)
			{
				Carrier_cordsAI[i][0] = r;
				Carrier_cordsAI[i][1] = p;
				ocean[r][p + i] = '#';
			}
			zastavica = 1;
		}
	}

	// AI GENERATED CRUISER_SHIP
	sus = 0;
	r = rand() % 10 + 1;
	zastavica = 0;
	r = r % 2;
	if (r == 0)
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			while (r + 3 > 10)
			{
				r = rand() % 10 + 1;
			}
			p = rand() % 10 + 1;
			int Cruiser_cordsAI[5][5];
			for (int i = 0; i < 3; i++)
			{
				Cruiser_cordsAI[i][0] = r;
				Cruiser_cordsAI[i][1] = p;
				if (ocean[r + i][p] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;

			//Zapisuje u ploču
			for (int i = 0; i < 3; i++)
			{
				Cruiser_cordsAI[i][0] = r;
				Cruiser_cordsAI[i][1] = p;
				ocean[r + i][p] = '#';
			}
			zastavica = 1;
		}
	}
	else
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			p = rand() % 10 + 1;
			while (p + 3 > 10)
				p = rand() % 10 + 1;
			int Cruiser_cordsAI[3][3];
			for (int i = 0; i < 3; i++)
			{
				Cruiser_cordsAI[i][0] = r;
				Cruiser_cordsAI[i][1] = p;
				if (ocean[r][p + i] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;

			for (int i = 0; i < 3; i++)
			{
				Cruiser_cordsAI[i][0] = r;
				Cruiser_cordsAI[i][1] = p;
				ocean[r][p + i] = '#';
			}
			zastavica = 1;
		}
	}

	// AI GENERATED SUBMARINE_SHIP

	sus = 0;
	r = rand() % 10 + 1;
	zastavica = 0;
	r = r % 2;
	if (r == 0)
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			while (r + 3 > 10)
			{
				r = rand() % 10 + 1;
			}
			p = rand() % 10 + 1;
			int Submarine_cordsAI[3][3];
			for (int i = 0; i < 3; i++)
			{
				Submarine_cordsAI[i][0] = r;
				Submarine_cordsAI[i][1] = p;
				if (ocean[r + i][p] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;
			//Zapisuje u ploču
			for (int i = 0; i < 3; i++)
			{
				Submarine_cordsAI[i][0] = r;
				Submarine_cordsAI[i][1] = p;
				ocean[r + i][p] = '#';
			}
			zastavica = 1;
		}
	}
	else
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			p = rand() % 10 + 1;
			while (p + 3 > 10)
				p = rand() % 10 + 1;
			int Submarine_cordsAI[3][3];
			for (int i = 0; i < 3; i++)
			{
				Submarine_cordsAI[i][0] = r;
				Submarine_cordsAI[i][1] = p;
				if (ocean[r][p + i] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;

			for (int i = 0; i < 3; i++)
			{
				Submarine_cordsAI[i][0] = r;
				Submarine_cordsAI[i][1] = p;
				ocean[r][p + i] = '#';
			}
			zastavica = 1;
		}
	}
	// AI GENERATED DESTROYER_SHIP

	sus = 1;
	r = rand() % 10 + 1;
	zastavica = 0;
	r = r % 2;
	if (r == 0)
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			while (r + 2 > 10)
			{
				r = rand() % 10 + 1;
			}
			p = rand() % 10 + 1;
			int Destroyer_cordsAI[2][2];
			for (int i = 0; i < 2; i++)
			{
				Destroyer_cordsAI[i][0] = r;
				Destroyer_cordsAI[i][1] = p;
				if (ocean[r + i][p] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;
			//Zapisuje u ploču
			for (int i = 0; i < 2; i++)
			{
				Destroyer_cordsAI[i][0] = r;
				Destroyer_cordsAI[i][1] = p;
				ocean[r + i][p] = '#';
			}
			zastavica = 1;
		}
	}
	else
	{
		while (zastavica == 0)
		{
			sus = 0;
			r = rand() % 10 + 1;
			p = rand() % 10 + 1;
			while (p + 2 > 10)
				p = rand() % 10 + 1;
			int Destroyer_cordsAI[2][2];
			for (int i = 0; i < 2; i++)
			{
				Destroyer_cordsAI[i][0] = r;
				Destroyer_cordsAI[i][1] = p;
				if (ocean[r][p + i] == '#')
					sus = 1;
			}
			if (sus == 1)
				continue;
			for (int i = 0; i < 2; i++)
			{
				Destroyer_cordsAI[i][0] = r;
				Destroyer_cordsAI[i][1] = p;
				ocean[r][p + i] = '#';
			}
			zastavica = 1;
		}
	}
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

	// Upsiuje koordinate carriera (1)
	int ans;
	//cin >> ans;
	for (int i = 5; i > 1; i--)
	{
		cout << "Zelitie li postaviti brod:\n0.Vodorano\n1.Okomito\n";
		cin >> ans;
		if (i == 3)
		{
			postavi_brod(ans, player_ocean, i);
			cout << "Zelitie li postaviti brod:\n0.Vodorano\n1.Okomito\n";
			cin >> ans;
			postavi_brod(ans, player_ocean, i);
			i -= 1;
			cout << "Zelitie li postaviti brod:\n0.Vodorano\n1.Okomito\n";
			cin >> ans;
		}
		postavi_brod(ans, player_ocean, i);
	}
	system("cls");
	game_board(player_ocean);
	cout << endl;
	system("CLS");

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
		cout << endl << endl;
	}
	
	// noob bot
	if (diff == 1)
		game_diff_1(y, x, player_ocean, ocean_PLAYER_2, ocean);
		
	system("CLS");

	// pro bot
	if (diff == 2)
		game_diff_2(y, x, player_ocean, ocean_PLAYER_2, ocean);	

	return 0;
}
