#include "header.h"

using namespace std;


// The Main Function: Program Entry Point
int main(void)
{
	// Declare variables
	int n_house = 4;
	int number_of_player;
	House *houses = new House[4];
	number_of_player = configure_game();
	Player *players = new Player[number_of_player];

	// Initialize all created players
	for (int c = 0; c < number_of_player; c++)
	{
		n_house = initialize_player(&(players[c]), c + 1, n_house, houses);
	}


	// Display game stats in tabular form
	cout << "\n\n" << setw(15) << "NAME" << "\t\t|" << setw(15) << "HOUSE" << "\t\t|" << setw(15) << "MEMBER" << endl;
	cout << "********************************************************************************************" << endl;
	for (int c = 0; c < number_of_player; c++)
		display(&players[c]);

	// Play game and deduct players
	deduct_member(players, number_of_player);
	cout << "\n\t\t\t\tAfter some player loses piece...\n" << endl;
	for (int c = 0; c < number_of_player; c++)
		display(&players[c]);

	// Cleanup and free allocated memory
	system("pause");
	delete [] houses;
	delete [] players;
	return (0);
}