
#include <iostream>
#include <ctime>
#include <fstream>
#include <cstdlib>
using namespace std;

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
		fstream datoteka("battleships.bin", ios::binary | ios::in);
		datoteka.read((char*) &player_ocean, sizeof (player_ocean));
		datoteka.read((char*) &ocean_PLAYER_2, sizeof (ocean_PLAYER_2));
		datoteka.close();
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
		int x;
		char y;

		cout << endl;
		cout << "Player 1: Where would you like to have your boat faced: " << endl;
		cout << " " << "1.V (vertically)\n" << " " << "2.H (horizontally)\n";
		string answer;
		cin >> answer;

		if (answer == "V" || answer == "v" || answer == "vertically" || answer == "Vertically")
		{

			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 5; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				--x;
			}
		}

		if (answer == "H" || answer == "h" || answer == "horizontally" || answer == "Horizontally")
		{
			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 5; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				++y;
			}
		}

		cout << "Player 1: Where would you like to have your boat faced: " << endl;
		cout << " " << "1.V (vertically)\n" << " " << "2.H (horizontally)\n";
		cin >> answer;
		if (answer == "V" || answer == "v" || answer == "vertically" || answer == "Vertically")
		{

			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 4; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				--x;
			}
		}

		if (answer == "H" || answer == "h" || answer == "horizontally" || answer == "Horizontally")
		{
			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 4; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				++y;
			}
		}
		
		cout << "Player 1: Where would you like to have your boat faced: " << endl;
		cout << " " << "1.V (vertically)\n" << " " << "2.H (horizontally)\n";
		cin >> answer;

		if (answer == "V" || answer == "v" || answer == "vertically" || answer == "Vertically")
		{

			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 3; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				--x;
			}
		}

		if (answer == "H" || answer == "h" || answer == "horizontally" || answer == "Horizontally")
		{
			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 3; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				++y;
			}
		}
	
		cout << "Player 1: Where would you like to have your boat faced: " << endl;
		cout << " " << "1.V (vertically)\n" << " " << "2.H (horizontally)\n";
		cin >> answer;

		if (answer == "V" || answer == "v" || answer == "vertically" || answer == "Vertically")
		{

			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 3; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				--x;
			}
		}

		if (answer == "H" || answer == "h" || answer == "horizontally" || answer == "Horizontally")
		{
			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 3; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				++y;
			}
		}
		cout << "Player 1: Where would you like to have your boat faced: " << endl;
		cout << " " << "1.V (vertically)\n" << " " << "2.H (horizontally)\n";
		cin >> answer;

		if (answer == "V" || answer == "v" || answer == "vertically" || answer == "Vertically")
		{

			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 2; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				--x;
			}
		}

		if (answer == "H" || answer == "h" || answer == "horizontally" || answer == "Horizontally")
		{
			cout << "Where would you like to have the bow of your ship placed(enter coordinates): " << endl;
			cin >> y >> x;
			y = pretvorba(y);
			for (int i = 0; i < 2; i++)
			{
				player_ocean[x][y] = '#';
				//int boat_pos = player_ocean[x][y];
				system("CLS");
				ispis(player_ocean);
				++y;
			}
		}

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

		if (diff == 1)
		{
			while (hits_by_player < 18 || hits_by_AI < 18)
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
					for (int i = 0; i < 10; i++)
					{
						if (i != 10)
							cout << " " << i << " ";
						else
							cout << i << " ";
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
					
				}
				if (hits_by_player == 17)
				{
					cout << "You won" << endl;
					system("pause");
					system("CLS");
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
						cout << '\n' << '\n';
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
							cout << player_ocean[i][j] << '\t';
						}
						cout << '\n' << '\n';
					}

				}
				if (hits_by_AI == 17)
				{
					cout << "You lost" << endl;
					system("pause");
					system("CLS");
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
					//Ispisuje polje igrača 1 (player)
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
					// turns++;
				}
				if (hits_by_player == 17)
				{
					cout << "You won" << endl;
					system("pause");
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
					//Ispisuje polje igrača 1 (player)
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
				if (hits_by_AI == 17)
				{
					cout << "You lost" << endl;
					system("pause");
					system("CLS");
				}

				turns++;
			}
			

		}
	
	return 0;
}
