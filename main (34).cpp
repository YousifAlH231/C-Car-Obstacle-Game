#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class drive
{
private:
    int carpos = 1;
    int obstacle = 0;
    int score = 0;
    char move;
    int live = 3;

public:
    void displayGame();
    void moveCar();
    bool checkCollision();
    void spawnObstacle();
};

void drive::displayGame()
{

    cout << "===== CAR GAME =====\n";
    cout << "A = Left | D = Right\n";
    cout << "Lives: " << live << endl;
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        if (i == obstacle)
            cout << "[O]";
        else
            cout << "[ ]";
    }

    cout << "\n";

    for (int i = 0; i < 3; i++)
    {
        if (i == carpos)
            cout << "[C]";
        else
            cout << "[ ]";
    }

    cout << "\n\nScore: " << score << endl;
}

void drive::moveCar()
{
    cout << "\nMove (A/D): ";
    cin >> move;
    if ((move == 'a' || move == 'A') && carpos > 0)
        carpos--;

    if ((move == 'd' || move == 'D') && carpos < 2)
        carpos++;
}

bool drive::checkCollision()
{
    if (carpos == obstacle)
    {
        live--;
        cout << "\nCRASH! You lost 1 life.\n";

        if (live == 0)
        {
            cout << "==== GAME OVER ====\n";
            cout << "Final Score: " << score << endl;
            return true;
        }
        else
        {
            carpos = 1; // reset car position after crash
        }
    }

    score++;
    return false;
}

void drive::spawnObstacle()
{
    obstacle = rand() % 3;
}

int main()
{
    srand(time(0));

    drive game;

    while (true)
    {
        game.displayGame();
        game.moveCar();

        game.spawnObstacle();

        if (game.checkCollision())
            break;
    }

    return 0;
}