
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

/*class openWindow
{
public:
	openWindow(GetConsoleWindow());
};*/

int pretvorba(char y)
{
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
	inty = pretvorba(y);
	while (x < 0 || x > 10 || inty == 0 || zastavica == true)
	{
		cout << "Krivi unos\n";
		system("pause");
		cout << "Unesite kordinatu:";
		cin >> y >> x;
		inty = pretvorba(y);
		zastavica = false;
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
		for (int i = x; i < n + x && i < 11; i++)
		{
			zastavica = false;
			if (player_ocean[i][inty] == '#')
			{
				//exit(0);
				zastavica = true;
				unos(x, inty, y, zastavica);
				continue;
			}
		}

		for (int i = x; i < n + x && i < 11; i++)
			player_ocean[i][inty] = '#';
	}

	if (answer == 0) // vodoravno
	{
		for (int i = inty; i < n + y && i < 11; i--)
			if (player_ocean[x][i] == '#')
			{
				unos(x, inty, y, zastavica);
				continue;
			}
		for (int i = x; i < n + x && i < 11; i++)
			player_ocean[x][i] = '#';
	}
	game_board(player_ocean);
	system("pause");
}

int main()
{

	srand(time(nullptr));
	bool load_GAME = false;
	char player_ocean[11][11];
	char ocean_PLAYER_2[11][11];
	cout << "0. New game\n1. Load game\n";
	cin >> load_GAME;
	if(load_GAME)
	{
		ifstream datoteka("battleships.bin", ifstream::in);
		datoteka.read((char*) &player_ocean, sizeof (player_ocean));
		datoteka.read((char*) &ocean_PLAYER_2, sizeof (ocean_PLAYER_2));
		datoteka.close();
		game_board(player_ocean);
		game_board2(ocean_PLAYER_2);
		//goto game;//dodaj; il nemoj ili funkcija i doajd save...
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
		int x,ans;
		char y;
		cin >> ans;
		for (int i = 5; i > 1; i--)
		{
			if (i == 3)
			{
				postavi_brod(ans, player_ocean, i);
				postavi_brod(ans, player_ocean, i);
				i -= 1;
			}
			postavi_brod(ans, player_ocean, i);
		}
		system("cls");
		game_board(player_ocean);
		cout << endl;

		int hits_by_player = 0, hits_by_AI = 0, turns = 1;

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

		turns = -1;
		string unos;
		if (diff == 1)
		{
			while (hits_by_player < 18 || hits_by_AI < 18)
			{
				cout << "Would you like to save the game: " << endl;
				cout << "Yes or No" << endl;
				cin >> unos;
				if (unos == "yes" || unos == "Yes")
				{
					ofstream datoteka("battleships.bin", ofstream::out);
					datoteka.write((char*)&player_ocean, sizeof(player_ocean));
					datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
					datoteka.close();
				}
				else 
				{
					turns = turns + 1;
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

					}
					if (hits_by_player == 17)
					{
						cout << "You won" << endl;
						exit(0);
					}

					// AI turn
					if (turns % 2 == 1)
					{
						r = rand() % 10 + 1;
						p = rand() % 10 + 1;
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
		}

		system("CLS");
		// pro bot
		if (diff == 2)
		{
			turns = 0;
			while (hits_by_player < 18 || hits_by_AI < 18)
			{
				if (turns % 2 == 1)
				{
					cout << "\nEnter cordinates where you want to shoot:\n";
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
				if (hits_by_player == 17)
				{
					cout << "You won" << endl;
					exit(0);
				}
				//AI turn    
				if (turns % 2 == 0)
				{
					while (zastavica == 0 || player_ocean[r][p] != '#')
					{
						r = rand() % 10 + 1;
						p = rand() % 10 + 1;
						zastavica = 1;
					}
					if (player_ocean[r][p] == '#')
					{
						hits_by_AI++;
						player_ocean[r][p] = 'X';
					}
					else
						player_ocean[r][p] = 'O';
					// Ispisuje polje igraća 2 (AI-player 2)
					system("CLS");

					game_board2(ocean_PLAYER_2);
					//Ispisuje polje igrača 1 (player)
					game_board(player_ocean);
				}
				if (hits_by_AI == 17)
				{
					cout << "You lost" << endl;
					exit(0);
				}

				turns++;
			}
			
		}

	return 0;
}
