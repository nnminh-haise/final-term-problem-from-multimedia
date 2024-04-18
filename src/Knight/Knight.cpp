#include<iostream>
//cstring dung cho ham memset
#include<cstring>


using namespace std;

int board[100][100];

// 8 vi tri chu L ma con ma co the di
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// kiem tra xem buoc di cua con ma co hop le hay khong ?
bool Checkmove(int x, int y, int n) {
    return (x >= 0 && y >= 0 && x < n && y < n && board[x][y] == -1);
}

// Ham backtracking
bool Hanhtrinh(int u, int v, int moveCount, int n) {
	// kiem tra xem con ma da di du so buoc hay chua, toi da n*n buoc
    if (moveCount == n * n) {
        return true;
    }
	//cho con ma di chuyen theo chu L
    for (int i = 0; i < 8; i++) {
        int nextu = u + dx[i];
        int nextv = v + dy[i];
        // neu duoc thi di tiep cho den khi khong the di duoc nua
        if (Checkmove(nextu, nextv, n)) {
            board[nextu][nextv] = moveCount;
            if (Hanhtrinh(nextu, nextv, moveCount + 1, n)) {
                return true;
            }
            //lui ve
            board[nextu][nextv] = -1;
        }
    }
    return false;
}

//Ham in hanh trinh di chuyen cua con ma
void out(int n, int u, int v) {
	if (Hanhtrinh(u, v, 1, n)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << board[i][j] << " : " << "(" << i << "," << j << ")" << endl;
            }
        }
    } else {
        cout << "Khong tim duoc duong di" << endl;
    }
}



int main() {
	//khoi tao tat ca gia tri ban dau cua ban co la -1
	// -1 xem nhu co`n di chuyen duoc
	memset(board,-1, sizeof(board));
    int n;
    cout << "nhap lan luot cac gia tri cua n u v: ";
    cin >> n;
    int u, v;
    cin >> u >> v;
    board[u][v] = 0;
    out(n, u, v);
    return 0;
}

