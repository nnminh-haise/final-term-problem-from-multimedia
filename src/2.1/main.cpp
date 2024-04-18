#include <iostream>
#include <vector>
#include <iomanip>
#include <string.h>

#define MAX 10

int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

bool isValid(int a[][MAX], int n, int value, int x, int y)
{
    return (0 <= x) && (x < n) && (0 <= y) && (y < n) && (a[x][y] == value);
}

void tour(int a[][MAX], int n, int i, int x, int y, bool &q)
{
    int k, u, v;
    bool q1;
    k = 0;
    do
    {
        q1 = false;
        u = x + X[k];
        v = y + Y[k];
        if (isValid(a, n, 0, u, v))
        {
            a[u][v] = i;

            if (i < n * n)
            {
                tour(a, n, i + 1, u, v, q1);
                if (q1 == false)
                    a[u][v] = 0;
            }
            else
                q1 = true;
        }
        k++;
    } while ((q1 == false) && (k < 8));
    q = q1;
}

void print(int a[][MAX], int n, int x, int y)
{
    int cx = x, cy = y, step = 1;
    std::vector<std::pair<int, int>> Res;
    Res.push_back({x, y});
    for (int i = 1; i <= n * n; i++)
    {
        int k = 0;
        for (int j = 0; j < 8; j++)
        {
            int nx = cx + X[j], ny = cy + Y[j];
            if (isValid(a, n, i + 1, nx, ny))
            {
                cx = nx;
                cy = ny;
                Res.push_back({cx, cy});
                step++;
            }
        }
    }
    if (step < n * n)
    {
        std::cout << "Can't solve";
        exit(0);
    }
    else
    {
        for (int i = 0; i < Res.size(); i++)
        {
            std::cout << i + 1 << " :(" << Res[i].first << ", " << Res[i].second << ")\n";
        }
        for (int i = 0; i < n; i++) // you can delete this loop if it's unnecessary
        {
            for (int j = 0; j < n; j++)
                std::cout << std::setw(4) << a[i][j];
            std::cout << std::endl;
        }
    }
}
int main()
{
    int n, x, y, step = 2;
    int array[MAX][MAX];
    memset(array, 0, sizeof(array));
    std::cout << "matrix(NxN): ";
    std::cin >> n;
    std::cout << "Start position\nx: ";
    std::cin >> x;
    std::cout << "y: ";
    std::cin >> y;
    bool q = false;
    array[x][y] = 1;
    tour(array, n, step, x, y, q);
    print(array, n, x, y);
    return 0;
}