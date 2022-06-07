
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

int pretvorba(char y);
void game_board(char player_ocean[][11]);
void game_board2(char ocean_PLAYER_2[][11]);
void postavljanje_brodova(char(&player_ocean)[11][11]);
void postavljanje_brodova2(char(&ocean_PLAYER_2)[11][11]);
void save_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11]);
void load_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11]);

void player_v_player(char &y, int &x, char (&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	char znak = 'A';
	char oceanmask1[11][11];
	char oceanmask2[11][11];
	for (int i = 0; i < 11; i++)
	{
		player_ocean[i][0] = i + 1;
		oceanmask1[i][0] = i + 1;
		oceanmask2[i][0] = i + 1;
		for (int j = 0; j < 11; j++)
		{
			znak++;
			if (i == 0)
			{
				player_ocean[i][j] = znak - 2;
				oceanmask1[i][j] = znak - 2;
				oceanmask2[i][j] = znak - 2;
			}
				
			else
			{
				player_ocean[i][j] = '~';
				oceanmask1[i][j] = '~';
				oceanmask2[i][j] = '~';
			}
				
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
			ocean_PLAYER_2[i][j] = player_ocean[i][j];
	}
	
	int hits_by_player1 = 0, hits_by_player2 = 0, turns = 0;
	string player1, player2;
	cout << "Enter player's 1 name: ";
	getline(cin, player1);
	cout << endl << "Enter player's 2 name: ";
	getline(cin, player2);
	system("cls");

	cout << endl;
	game_board(player_ocean);
	cout << player1 << "'s turn to place the ships:" << endl;
	postavljanje_brodova(player_ocean);

	cout << endl;
	game_board2(ocean_PLAYER_2);
	cout << player2 << "'s turn to place the ships:" << endl;
	postavljanje_brodova2(ocean_PLAYER_2);

	while (hits_by_player1 < 18 || hits_by_player2 < 18)
	{
		
		// PLAYER 1 turn
		if (turns % 2 == 0)
		{
			cout << endl << player1 << "'s turn to play: " << endl;
			cout << player1 << ", where do you want to shoot: " << endl;
			cin >> y >> x;
			y = pretvorba(y);	
		opet:
			if (ocean_PLAYER_2[x][y] == '#')
			{																				//player_ocean --> polje igraca 1 nice
																							//ocean_PLAYER_2 --> polje igraca 2
				hits_by_player1++;
				ocean_PLAYER_2[x][y] = 'X';
				oceanmask2[x][y] = 'X';
	
			}
			else if (ocean_PLAYER_2[x][y] == 'X')
			{
				
				cout << "Generale, ovdje ste vec pucali! Gadajte drugu koordinatu: " << endl;
				cin >> y >> x;
				y = pretvorba(y);
				goto opet; 
			}
			else
			{
				ocean_PLAYER_2[x][y] = 'O';
				oceanmask2[x][y] = 'O';

			}
			system("CLS");
			// Ispisuje polje igraća 2 (PLAYER 1)
			cout << "\t\t\t" << player1 << "'s game board\n";
			cout << "--------------------------------------------------------------------------" << endl;
			game_board(oceanmask1);
			//Ispisuje polje igrača 1 (PLAYER 2)
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "\t\t\t" << player2 << "'s game board\n";
			game_board(oceanmask2);
		}
		if (hits_by_player1 == 17)
		{
			cout << player1 << " has WON!" << endl << player2 << " has LOST!" << endl;
			exit(0);

		}
		// PLAYER 2 turn
		if (turns % 2 == 1)
		{
			cout << endl << player2 << "'s turn to play: " << endl;
			cout << player2 << ", where do you want to shoot: " << endl;
			cin >> y >> x;
			y = pretvorba(y);
		opet2:
			if (player_ocean[x][y] == '#')
			{
				hits_by_player2++;
				player_ocean[x][y] = 'X';
				oceanmask1[x][y] = 'X';
			}
			else if (player_ocean[x][y] == 'X')
			{
				cout << "Generale, ovdje ste vec pucali! Gadajte drugu koordinatu: " << endl;
				cin >> y >> x;
				y = pretvorba(y);
				goto opet2;
			}
			else
			{
				player_ocean[x][y] = 'O';
				oceanmask1[x][y] = 'O';

			}
			system("CLS");
			// Ispisuje polje igraća (PLAYER 2)
			cout << "\t\t\t" << player2 << "'s game board\n";
			cout << "--------------------------------------------------------------------------" << endl;
			game_board(oceanmask2);
			//Ispisuje polje igrača (PLAYER 1)  
			cout << "--------------------------------------------------------------------------" << endl;
			cout << "\t\t\t" << player1 << "'s game board\n";
			game_board(oceanmask1);

		}
		if (hits_by_player2 == 17)
		{
			cout << player2 << " has WON!" << endl << player1 << " has LOST!" << endl;
			exit(0);
		}
		turns++;
		save_file(oceanmask1, oceanmask2);
	}
		
}
	
