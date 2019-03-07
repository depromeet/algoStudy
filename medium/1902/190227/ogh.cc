#include <bits/stdc++.h>

using namespace std;

// Complete the knightlOnAChessboard function below.
bool is_in_bound(int x, int y, int n) {
    return 0 <= x && 0 <= y && x < n && y < n;
}


#define point pair<int, pair<int,int>>
#define mp make_pair

void solve(vector<vector<int>> &arr, int dx, int dy, int n) {
    int mx[4] {1, 1, -1, -1};
    int my[4] {1, -1, 1, -1};
    bool chk[n+1][n+1] ;
    memset(chk,0,sizeof(chk));
    queue<point> q;
    q.push(mp(0,mp(0,0)));
    chk[0][0] = true;
    arr[dx - 1][dy - 1] = -1;
    arr[dy - 1][dx - 1] = -1;
    while(!q.empty()) {
        point p = q.front();
        q.pop();
        int x = p.second.first;
        int y = p.second.second;
        int cost = p.first;
        if (x == n-1 && y == n-1) {
            arr[dx - 1][dy - 1] = cost;
            arr[dy - 1][dx - 1] = cost;
            break;
        }
        for(int i = 0 ;i < 4;i++) {
            int nx = x + mx[i] * dx;
            int ny = y + my[i] * dy;
            if (is_in_bound(nx,ny,n) && !chk[nx][ny]) {
                chk[nx][ny] = true;
                q.push(mp(cost + 1, mp(nx,ny)));
            }
        }
        for(int i = 0 ;i < 4;i++) {
            int nx = x + mx[i] * dy;
            int ny = y + my[i] * dx;
            if (is_in_bound(nx,ny,n) && !chk[nx][ny]) {
                chk[nx][ny] = true;
                q.push(mp(cost + 1, mp(nx,ny)));
            }
        }
    }
}

vector<vector<int>> knightlOnAChessboard(int n) {
    vector<vector<int>> ret(n - 1, vector<int>(n - 1, 0));
    for(int i = 0;i < n - 1;i++) {
        for(int j = 0;j < n - 1 ;j++) {
            if (ret[i][j] == 0) {
                // solve 
                solve(ret, i + 1,j + 1,n);
            }
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> result = knightlOnAChessboard(n);

    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            fout << result[i][j];

            if (j != result[i].size() - 1) {
                fout << " ";
            }
        }

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
