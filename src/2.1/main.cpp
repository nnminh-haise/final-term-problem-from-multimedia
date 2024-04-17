// BT ve con ma di tuan
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

// Thuat toan
void tour(vector<vector<int>> &a, int i, int x, int y, bool &q)
{
    int k, u, v, n = a.size();
    bool q1;
    k = 0;
    do
    {
        q1 = false;
        u = x + X[k];
        v = y + Y[k];
        if ((0 <= u) && (u < n) && (0 <= v) && (v < n) && (a[u][v] == 0))
        {
            a[u][v] = i;

            if (i < n * n)
            {
                tour(a, i + 1, u, v, q1);
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
// Truy vet
void print(vector<vector<int>> a, int x, int y)
{
    int n = a.size(), cx = x, cy = y, step = 1;
    vector<pair<int, int>> Res;
    Res.push_back({x, y});
    for (int i = 1; i <= n * n; i++)
    {
        int k = 0;
        for (int j = 0; j < 8; j++)
        {
            int nx = cx + X[j], ny = cy + Y[j];
            if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < n) && a[nx][ny] == i + 1)
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
        cout << "Can't solve";
        exit(0);
    }
    else
    {
        for (int i = 0; i < Res.size(); i++)
        {
            cout << i + 1 << " :(" << Res[i].first << ", " << Res[i].second << ")\n";
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << setw(4) << a[i][j];
            cout << endl;
        }
    }
}
int main()
{
    int n, x, y, step = 2;
    cout << "matrix(NxN): ";
    cin >> n;
    cout << "Start position\nx: ";cin >> x;
    cout << "y: ";cin >> y;
    vector<vector<int>> array(n, vector<int>(n));
    bool q = false;
    array[x][y] = 1;
    tour(array, step, x, y, q);
    print(array, x, y);
    return 0;
}