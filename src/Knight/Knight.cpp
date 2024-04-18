#include<bits/stdc++.h>

using namespace std;

// 8 vi tri chu L ma con ma co the di
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// kiem tra xem buoc di cua con ma co hop le hay khong ?
bool Checkmove(int x, int y, int n, const vector<vector<int>>& board) {
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
}

// backtracking
bool Hanhtrinh(int u, int v, int moveCount, vector<vector<int>>& board, int n) {
	// kiem tra xem con ma da di du so buoc hay chua, toi da n*n buoc
    if (moveCount == n * n) {
        return true;
    }
	//cho con ma di chuyen theo chu L
    for (int i = 0; i < 8; i++) {
        int nextu = u + dx[i];
        int nextv = v + dy[i];
        // neu duoc thi di tiep cho den khi khong the di duoc nua
        if (Checkmove(nextu, nextv, n, board)) {
            board[nextu][nextv] = moveCount;
            if (Hanhtrinh(nextu, nextv, moveCount + 1, board, n)) {
                return true;
            }
            board[nextu][nextv] = -1;
        }
    }
    return false;
}

// Ham sap sep lai vector 2 chieu
void sortBoard(vector<vector<int>>& board) {
    int n = board.size();

    vector<int> flattened;
    flattened.reserve(n * n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            flattened.push_back(board[i][j]);
        }
    }

    sort(flattened.begin(), flattened.end());
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = flattened[index++];
        }
    }
}

int main() {
    int n;
    cout << "nhap lan luot cac gia tri cua n u v: ";
    cin >> n;
    int u, v;
    cin >> u >> v;
    vector<vector<int>> board(n, vector<int>(n, -1));
    board[u][v] = 0;
    if (Hanhtrinh(u, v, 1, board, n)) {
    	sortBoard(board);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " : " << "(" << i << "," << j << ")" << endl;
            }
        }
    } else {
        cout << "Khong tim duoc duong di" << endl;
    }

    return 0;
}

