#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecton dir;

void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "*";
            else if (i == fruitY && j == fruitX)
                cout << "%";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "*"; print = true;
                    }
                }
                if (!print)
                    cout << " ";

            }

            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}

void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

bool checkCollision(int x, int y, const vector<int>& snakeX, const vector<int>& snakeY) {
    if (x <= 0  x >= 49  y <= 0 || y >= 19)
        return true;
    for (size_t i = 1; i < snakeX.size(); ++i) {
        if (x == snakeX[i] && y == snakeY[i])
            return true;
    }

    return false;
}
    
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        algorithm();
        CheckCollision();
    }
    return 0;
}
