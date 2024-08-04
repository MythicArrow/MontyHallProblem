#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    const int numTrials = 1000000;
    int switchWins = 0;
    int stickWins = 0;

    for (int i = 0; i < numTrials; ++i) {
        // Randomly assign the car to one of the three doors
        int carDoor = rand() % 3;
        // Player randomly picks a door
        int playerPick = rand() % 3;

        // Monty reveals a door with a goat
        int montyReveal;
        do {
            montyReveal = rand() % 3;
        } while (montyReveal == carDoor || montyReveal == playerPick);

        // Determine the remaining door
        int remainingDoor;
        for (int j = 0; j < 3; ++j) {
            if (j != playerPick && j != montyReveal) {
                remainingDoor = j;
                break;
            }
        }

        // Check if switching wins
        if (remainingDoor == carDoor) {
            ++switchWins;
        }
        // Check if sticking wins
        if (playerPick == carDoor) {
            ++stickWins;
        }
    }

    // Calculate and display the results
    std::cout << "Number of trials: " << numTrials << std::endl;
    std::cout << "Wins by switching: " << switchWins << " (" << (static_cast<double>(switchWins) / numTrials) * 100 << "%)" << std::endl;
    std::cout << "Wins by not switching: " << stickWins << " (" << (static_cast<double>(stickWins) / numTrials) * 100 << "%)" << std::endl;

    return 0;
}


