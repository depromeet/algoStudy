#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the printShortestPath function below.
bool isInBound(int n, int x, int y) {
    return 0 <= x && 0 <= y && x < n && y < n;
}
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    // Print the distance along with the sequence of moves.
    bool chk[210][210] = {0};
    int step[210][210];
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(i_start, j_start), 0));
    chk[i_start][j_start] = true;

    string ds[6] = {"UL", "UR","R", "LR", "LL", "L"};
    int dx[6] = {-2, -2, 0, 2, 2, 0};
    int dy[6] = {-1, 1, 2, 1, -1, -2};
    int found = -1;
    while(!q.empty()) {
        pair<pair<int, int>, int> p = q.front();
        q.pop();
        int cx = p.first.first;
        int cy = p.first.second;
        int stepCount = p.second;
        if (cx == i_end && cy == j_end) {
            found = stepCount;
            break;
        }
        for(int i = 0; i < 6;i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if (isInBound(n, nx, ny) && !chk[nx][ny]) {
                chk[nx][ny] = true;
                step[nx][ny] = i;
                q.push(make_pair(make_pair(nx,ny), stepCount + 1));
            }
        }
    }

    if (found != -1) {
        printf("%d\n", found);
        vector<string> v;
        int cx = i_end, cy = j_end;
        while(1) {
            if (cx == i_start && cy == j_start) break;
            int prev = step[cx][cy];
            v.push_back(ds[prev]);
            cx -= dx[prev];
            cy -= dy[prev];
        }
        for(int i = v.size() - 1; i >= 0 ;i--) {
            printf("%s", v[i].c_str());
            if (i != 0) printf(" ");
        }
        printf("\n");
    } else {
        printf("Impossible\n");
    }
}

int main(void)
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string i_startJ_start_temp;
    getline(cin, i_startJ_start_temp);

    vector<string> i_startJ_start = split_string(i_startJ_start_temp);

    int i_start = stoi(i_startJ_start[0]);

    int j_start = stoi(i_startJ_start[1]);

    int i_end = stoi(i_startJ_start[2]);

    int j_end = stoi(i_startJ_start[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
