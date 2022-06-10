
#pragma once
#include <iostream>
using namespace std;

void game_board(char player_ocean[][11])
{
	cout << "\t\t" << "--------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 11; i++)
	{
		cout << "\t\t";
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
	cout << "\t\t" << "--------------------------------------------------------------------------" << endl;
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

void postavljanje_brodova(char(&player_ocean)[11][11])
{
	int ans;
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
}

void postavi_brod2(int answer, char(&ocean_PLAYER_2)[11][11], int n)
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
			if (ocean_PLAYER_2[i][inty] == '#' || i > 10)
			{
				//exit(0);
				zastavica = true;
				unos(x, inty, y, zastavica);
				//continue;
				goto ponovno;
			}
		}

		for (int i = x; i < n + x && i < 11; i++)
			ocean_PLAYER_2[i][inty] = '#';
	}

	if (answer == 0) // vodoravno
	{
	ponovno_2:
		for (int i = inty; i < n + inty; i++)
		{
			zastavica = false;
			if (ocean_PLAYER_2[x][i] == '#' || i > 10)
			{
				zastavica = true;
				unos(x, inty, y, zastavica);
				goto ponovno_2;
			}
		}

		for (int i = inty; i < n + inty && i < 11; i++)
		{
			ocean_PLAYER_2[x][i] = '#';
		}
	}
	game_board(ocean_PLAYER_2);
	system("pause");
}

void postavljanje_brodova2(char(&ocean_PLAYER_2)[11][11])
{
	int ans;
	for (int i = 5; i > 1; i--)
	{
		cout << "Zelitie li postaviti brod:\n0.Vodorano\n1.Okomito\n";
		cin >> ans;
		if (i == 3)
		{
			postavi_brod2(ans, ocean_PLAYER_2, i);
			cout << "Zelitie li postaviti brod:\n0.Vodorano\n1.Okomito\n";
			cin >> ans;
			postavi_brod2(ans, ocean_PLAYER_2, i);
			i -= 1;
			cout << "Zelitie li postaviti brod:\n0.Vodorano\n1.Okomito\n";
			cin >> ans;
		}
		postavi_brod2(ans, ocean_PLAYER_2, i);
	}
	system("cls");
	game_board(ocean_PLAYER_2);
	cout << endl;
	system("CLS");
}