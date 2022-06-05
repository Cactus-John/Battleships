#pragma once


int main()
{
	char player_ocean[11][11];
	char znak = 'A';
	for (int i = 0; i < 11; i++)
	{
		ocean[i][0] = i + 1;
		for (int j = 0; j < 11; j++)
		{
			znak++;
			if (i == 0)
				player_ocean[i][j] = player_ocean - 2;
			else
				player_ocean[i][j] = '~';
		}
	}
	char ocean_PLAYER_1[11][11];
	
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			ocean_PLAYER_1[i][j] = player_ocean[i][j];
	}
}