/* C++ IMPLEMENTATION */
#ifndef _HEADER_
#define _HEADER_
#include <string>
#include <iostream>
#include <iomanip>

/*
This header file contains all structure/classes,
Function Prototypes and global constants
*/

// ---------------  THE LUDO GAME  ------------------//
enum Color {RED, BLUE, YELLOW, GREEN};

struct House
{
	Color color;
	int member;
	bool status;
};

const House HOUSE_INITIALIZER = {RED, 4, false};

struct Player
{
	std::string name;
	House house;
};

// Function prototypes
int configure_game();
int initialize_player(Player *player, int player_no, int n_house, House *arr);
void display(Player *player);
void deduct_member(Player *players, int size);


#endif // _HEADER