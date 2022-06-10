
#pragma once
#include <iostream>
#include <fstream>
using namespace std;

void game_board(char player_ocean[][11]);
void player_v_player(char &y, int&x, char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11]);

void save_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	ofstream datoteka("battleships.bin", ofstream::out);
	datoteka.write((char*)&player_ocean, sizeof(player_ocean));
	datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
	//datoteka.write((int*)&hits_by_player1, sizeof(int));
	//datoteka.write((int*)&hits_by_player2, sizeof(int));
	datoteka.close();
}

void load_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	ifstream datoteka("battleships.bin", ifstream::in);
	datoteka.read((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
	datoteka.read((char*)&player_ocean, sizeof(player_ocean));
	datoteka.close();
	if (datoteka.fail())
	{
		cout << "Greska kod ucitavanja datoteke!" << endl;
		exit(0);
	}	
	game_board(player_ocean);
	game_board(ocean_PLAYER_2);
	
}
