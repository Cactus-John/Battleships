
#include <iostream>
#include <fstream>
using namespace std;

void game_board(char player_ocean[][11]);
void game_board2(char ocean_PLAYER_2[][11]);

void save_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	ofstream datoteka("battleships.bin", ofstream::out);
	datoteka.write((char*)&player_ocean, sizeof(player_ocean));
	datoteka.write((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
	datoteka.close();
}

void load_file(char(&player_ocean)[11][11], char(&ocean_PLAYER_2)[11][11])
{
	ifstream datoteka("battleships.bin", ifstream::in);
	datoteka.read((char*)&ocean_PLAYER_2, sizeof(ocean_PLAYER_2));
	datoteka.read((char*)&player_ocean, sizeof(player_ocean));
	datoteka.close();
	if (datoteka.fail())
		cout << "Greska kod ucitavanja datoteke!" << endl;
	game_board(player_ocean);
	game_board2(ocean_PLAYER_2);
}