#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the matrixRotation function below.
#define OGH_SERIALIZE 0
#define OGH_DESERIALIZE 1
void transform(vector<int>& flatten, vector<vector<int>>& matrix, int shrink, int serialize) {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int direction = 0;
    int row = matrix.size() - shrink * 2;
    int col = matrix[0].size() - shrink * 2;
    int x = shrink;
    int y = shrink; 
    int i = 0;
    while(i < col * 2 + (row - 2) * 2) {
        if (serialize == OGH_SERIALIZE) {
            flatten.push_back(matrix[x][y]);
        } else {
            matrix[x][y] = flatten[i];
        }
        i++;
        if (i == col) direction++;
        else if (i == col + row -1) direction++;
        else if (i == 2 * col + row - 2) direction++;
        x += dx[direction];
        y += dy[direction];
    }
}

void matrixRotation(vector<vector<int>> matrix, int r) {
    int sub = matrix.size() / 2;
    sub = min(sub, (int)matrix[0].size() / 2);
    for(int i = 0 ;i < sub;i++) {
        vector<int> flatten;
        transform(flatten, matrix, i, OGH_SERIALIZE);
        int rot = r % flatten.size();
        rotate(flatten.begin(), flatten.begin() + rot, flatten.end());
        transform(flatten, matrix, i, OGH_DESERIALIZE);
    }
    for(int i = 0 ;i < matrix.size();i++) {
        for(int j =0 ;j < matrix[i].size();j++) {
            if(0 != j) printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    string mnr_temp;
    getline(cin, mnr_temp);

    vector<string> mnr = split(rtrim(mnr_temp));

    int m = stoi(mnr[0]);

    int n = stoi(mnr[1]);

    int r = stoi(mnr[2]);

    vector<vector<int>> matrix(m);

    for (int i = 0; i < m; i++) {
        matrix[i].resize(n);

        string matrix_row_temp_temp;
        getline(cin, matrix_row_temp_temp);

        vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int matrix_row_item = stoi(matrix_row_temp[j]);

            matrix[i][j] = matrix_row_item;
        }
    }

    matrixRotation(matrix, r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
