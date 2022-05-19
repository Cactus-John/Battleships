
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	time(NULL);
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

	char player_ocean[11][11];
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
	char ocean_PLAYER_2[11][11];
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
		for (int i = 0; i < 5; i++)
		{

			cout << endl;
			cout << "Player 1: place a carrier (occupies 5 spaces): " << endl;
			cin >> y >> x;
			
			switch (y)
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
			player_ocean[x][y] = '#';
			system("CLS");
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
		}
		

		for (int i = 0; i < 4; i++)
		{

			cout << endl;
			cout << "Player 1: place a battleship (occupies 4 places): " << endl;
			cin >> y >> x;

			switch (y)
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
			player_ocean[x][y] = '#';
			system("CLS");
			for (int i = 0; i < 11; i++)
			{
				if (i != 10)
					cout << " " << i << " ";
				else
					cout << " " << i << " ";
				for (int j = 1; j < 11; j++)
				{
					cout << player_ocean[i][j] << " ";
				}
				cout << '\n';
			}
		}
		
		for (int i = 0; i < 3; i++)
		{

			cout << endl;
			cout << "PLAYER 1: place a Submarine ship (occupies 3 spaces): " << endl;
			cin >> y >> x;

			switch (y)
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
			player_ocean[x][y] = '#';
			system("CLS");
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
		}
		cout << "Player 1: place a cruiser ship(occupies 3 spaces): " << endl;
		for (int i = 0; i < 3; i++)
		{
			cin >> y >> x;
			switch (y)
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
			player_ocean[x][y] = '#';
			system("CLS");
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
				cout << '\n';
			}
		}
		cout << "Place a Destroyer ship (occupies 2 spaces): " << endl;
		for (int i = 0; i < 2; i++)
		{
			cin >> y >> x;
			switch (y)
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
			player_ocean[x][y] = '#';
			system("CLS");
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
			while (hits_by_player < 17 || hits_by_AI < 17)
			{
				turns = turns + 1;
				// player turn
				if (turns % 2 == 0)
				{
					cout << "Enter cordinates where you want to shoot: " << endl;
					cin >> y >> x;
					switch (y)
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
							cout << i << " ";
						else
							cout << i << " ";
						for (int j = 1; j < 11; j++)
						{
							cout << player_ocean[i][j] << '\t';
						}
						cout << '\n' << '\n';
					}

				}
			}
		}
		system("CLS");
		// pro bot

		if (diff == 2)
		{
			turns = 0;
			while (hits_by_player < 17 || hits_by_AI < 17)
			{
				if (turns % 2 == 1)
				{
					cout << "\nEnter cordinates where you want to shoot:\n";
					cin >> y >> x;
					switch (y)
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
							cout << " " << i << " ";
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
					// turns++;
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
							cout << i;
						else
							cout << i;
						for (int j = 1; j < 11; j++)
						{
							cout << ocean_PLAYER_2[i][j];
						}
						cout << '\n' << '\n';
					}
					//Ispisuje polje igrača 1 (player)
					for (int i = 0; i < 11; i++)
					{
						if (i != 10)
							cout << i;
						else
							cout << i;
						for (int j = 1; j < 11; j++)
						{
							cout << player_ocean[i][j] << '\t';
						}
						cout << '\n' << '\n';
					}
				}

				turns++;
			}

		}
	
	
	return 0;
}

	




