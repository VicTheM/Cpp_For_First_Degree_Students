#include "header.h"
#include <iomanip>
using namespace std;

// Function definitions
/**
 * configure_game - sets up the gaming enviroment
 * this function gets the number of players
 */
int configure_game()
{
	int n_players;

	cout << "\t\t\t\tTHE LUDO GAME\n";
	cout << "-----------------------------------------------------------------------------------\n" << endl;
	cout << "Enter the number of Players (2, 3, or 4)\n\t>> ";
	cin >> n_players;
	while (n_players < 2 || n_players > 4)
	{
		cout << "Wrong Value inputed! Number of players should either be:\n";
		cout << "\t2 or\n\t3 or\n\t4\n";
		cout << "Re-enter the number of players (2, 3, or 4)\n\t>> ";
		cin >> n_players;
	}

	cout << "Great! " << n_players << " people will play the game.\n" << endl;
	return (n_players);
}




/**
 * initialize-player: assign proper values to a player
 * and house color
 */
int initialize_player(Player *player, int player_no, int n_house, House *arr)
{
	static int n_call = 1;//number of times this function has been called
	static int taken1, taken2, taken3 = -1; // This can be implemented using vectors/ dynamic arrays
	string houses[] = {"RED", "BLUE", "YELLOW", "GREEN"};
	int house_no;

	cin.ignore();
	cout << "Enter name of Player " << player_no << ": >> ";
	getline(cin, player->name);
	cout << "Which house do you choose?\n";
	for (int c = 1; c <= 4; c++)
	{
		if (!(c == taken1 || c == taken2 || c == taken3))
			cout << "[" << c << "]" << "\t" << houses[c - 1] << endl;
	}

	cout << "Enter any of the number in the braces []: >> ";
	cin >> house_no;
	while (house_no < 1 || house_no > 4 || house_no == taken1 || house_no == taken2 || house_no == taken3)
	{
		if (house_no == taken1 || house_no == taken2 || house_no == taken3)
			cout << "That House has already been chosen! Chose another house :>> ";
		else
			cout << "Wrong Input! Enter any number between 1 and 4 :>> ";
		cin >> house_no;
	}
	if (n_call == 1)
		taken1 = house_no;
	else if (n_call == 2)
		taken2 = house_no;
	else if (n_call == 3)
		taken3 = house_no;

	player->house = arr[house_no - 1];
	player->house.color = static_cast<Color>(house_no - 1);
	player->house.member = 4;
	player->house.status = true;

	n_call++;
	cout << endl;
	return (n_house - 1);
}



/**
 * display player - display details in properly formatted form
 */
void display(Player *player)
{
	string color;
	switch (player->house.color)
	{
	case 0:
		color = "Red";
		break;
	case 1:
		color = "Blue";
		break;
	case 2:
		color = "Yellow";
		break;
	case 3:
		color = "Green";
		break;
	default:
		color = "Red";
		break;
	}
	cout << setw(15) << player->name << "\t\t|" << setw(15) << color << "\t\t|\t" << setw(15) << player->house.member << endl;
	cout << "---------------------------------------------------------------------------------------------" << endl;
}




/**
 * deduct_member - subtracts members from each player
 */
void deduct_member(Player *players, int size)
{
	for (int c = 0; c < size; c++)
	{
		players[c].house.member -= (c + 1);
	}
}
