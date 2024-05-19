#include <iostream>
#include <stack>
#include <vector>

int X[8] = {1, 1, 2, 2, -1, -1, -2, -2};
int Y[8] = {2, -2, 1, -1, 2, -2, 1, -1};

bool isValid(std::vector<std::vector<int>> a, int n, int value, int x, int y)
{
    return (0 <= x) && (x < n) && (0 <= y) && (y < n) && (a[x][y] == value);
}

bool knightTour(int n, int startX, int startY)
{
    int move = 0;
    std::vector<std::vector<int>> Board(n, std::vector<int>(n, -1));
    Board[startX][startY] = ++move;
    std::stack<std::pair<int, int>> posMoves;
    posMoves.push({startX, startY});
    while (!posMoves.empty())
    {
        int x = posMoves.top().first,
            y = posMoves.top().second;
        posMoves.pop();
        if (move == n * n)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    std::cout << Board[i][j] << "\t";
                }
                std::cout << std::endl;
            }
            return true;
        }
        for (int i = 0; i < 8; i++)
        {
            int nextX = x + X[i],
                nextY = y + Y[i];
            if (isValid(Board, n, -1, nextX, nextY))
            {
                Board[nextX][nextY] = ++move;
                posMoves.push({nextX, nextY});
            }
        }
    }
    return false;
}

int main()
{
    int N, posX, posY;
    std::cout << "Enter matrix[NxN]: ";
    std::cin >> N;
    std::cout << "position start of knight\n";
    std::cout << "X: ";
    std::cin >> posX;
    std::cout << "Y: ";
    std::cin >> posY;
    std::cout << "\n";
    if (!knightTour(N, posX, posY))
    {
        std::cout << "The knight can't move all positions on the board";
    }
}