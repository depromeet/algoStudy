#include <bits/stdc++.h>

using namespace std;

// Complete the flippingMatrix function below.
int flippingMatrix(vector<vector<int>> matrix) {
    int sum = 0;
    int dx[4]{0,0,1,1};
    int dy[4]{0,1,0,1};
    for(int i = 0 ;i < matrix.size()/2;i++) {
        for(int j =0 ;j < matrix.size()/2;j++) {
            int max_elm = 0;
            for(int k = 0 ;k < 4;k++) {
                int nx = i + dx[k] * (matrix.size() - 2 * i - 1);
                int ny = j + dy[k] * (matrix.size() - 2 * j - 1);
                max_elm = max(max_elm, matrix[nx][ny]);
            }
            sum += max_elm;
        }
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> matrix(2*n);
        for (int i = 0; i < 2*n; i++) {
            matrix[i].resize(2*n);

            for (int j = 0; j < 2*n; j++) {
                cin >> matrix[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
