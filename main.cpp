#include "GameBoard.hpp"

using namespace std;

int main(void) {

	srand(unsigned(time(NULL)));

	GameBoard game;

	game.initializeGameBoard();

	game.gameplay();

	std::cout << "Player has won!\n";

	game.printGameStatistics();

 	return 0;

}
