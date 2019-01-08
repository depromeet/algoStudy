#include <bits/stdc++.h>
#include <utility> 
#include <queue>

using namespace std;

// Complete the connectedCell function below.
bool isInBound(int x, int y, int mx, int my) {
    return 0 <= x && 0 <= y && x < mx && y < my;
}
int connectedCell(vector<vector<int>> matrix) {
    int maxC = 0;
    int dx[8] = {1,1,1,0,0,-1,-1,-1};
    int dy[8] = {1,0,-1,1,-1,1,0,-1};

    for(int i = 0;i < matrix.size();i++) {
        for (int j = 0 ;j < matrix[i].size();j++) {
            if (matrix[i][j] == 1) {
                int temp = 1;
                queue<pair<int,int>> q;

                q.push(make_pair(i,j));
                matrix[i][j] = 2;
                while(!q.empty()) {
                    pair<int,int> p = q.front();
                    int cx = p.first;
                    int cy = p.second;
                    q.pop();

                    for (int k = 0; k < 8; k++)
                    {
                        int nx = cx + dx[k];
                        int ny = cy + dy[k];
                        if (isInBound(nx, ny, matrix.size(), matrix[0].size()) && matrix[nx][ny] == 1)
                        {
                            q.push(make_pair(nx,ny));
                            matrix[nx][ny] = 0;
                            temp++;
                        }
                    }
                }
                if (temp > maxC) maxC = temp;
            }
        }
    }
    return maxC;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int m;
    cin >> m;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(m);

        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = connectedCell(matrix);

    fout << result << "\n";

    fout.close();

    return 0;
}
