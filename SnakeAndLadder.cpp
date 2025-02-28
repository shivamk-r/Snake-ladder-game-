#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define the snake and ladder positions
int ladderPositions[8][2] = {{2, 23}, {6, 45}, {20, 59}, {52, 72}, {57, 96}, {71, 92}, {80, 99}};
int snakePositions[8][2] = {{43, 17}, {50, 5}, {56, 8}, {73, 15}, {84, 58}, {87, 49}, {98, 40}, {94, 30}};

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1; // Random number between 1 and 6
}

// Function to check for ladders and snakes
int checkPosition(int position) {
    // Check ladders
    for (int i = 0; i < 8; i++) {
        if (position == ladderPositions[i][0]) {
            cout << "Ladder! Moving up from " << position << " to " << ladderPositions[i][1] << endl;
            return ladderPositions[i][1];
        }
    }

    // Check snakes
    for (int i = 0; i < 8; i++) {
        if (position == snakePositions[i][0]) {
            cout << "Snake! Moving down from " << position << " to " << snakePositions[i][1] << endl;
            return snakePositions[i][1];
        }
    }

    return position;
}

int main() {
    srand(time(0)); // Seed for random number generation

    int position = 0;
    char roll;
    
    cout << "Welcome to the Snake and Ladder game!" << endl;
    cout << "Press 'r' to roll the dice, 'q' to quit." << endl;

    while (position < 100) {
        cout << "Current position: " << position << endl;
        cout << "Roll the dice (press 'r'): ";
        cin >> roll;

        if (roll == 'q') {
            cout << "Game exited. Final position: " << position << endl;
            break;
        } else if (roll == 'r') {
            int diceValue = rollDice();
            cout << "You rolled a " << diceValue << "!" << endl;

            if (position + diceValue <= 100) {
                position += diceValue;
                position = checkPosition(position);
            } else {
                cout << "Roll exceeds 100, try again next turn!" << endl;
            }

            if (position == 100) {
                cout << "Congratulations! You reached 100 and won the game!" << endl;
                break;
            }
        } else {
            cout << "Invalid input! Press 'r' to roll or 'q' to quit." << endl;
        }
    }

    return 0;
}