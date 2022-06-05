
#include <iostream>
#include <fstream>
using namespace std;

void generating_AI(char(&ocean)[11][11])
{
	
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
}