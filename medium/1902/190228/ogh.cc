#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the bomberMan function below.
bool is_in_bound(int x, int y, int bx, int by) {
    return 0 <= x && x < bx && 0 <=y && y < by;
}

string serialize_grid(const vector<string> &grid) {
    string ret;
    for(int i = 0 ;i < grid.size();i++) ret += grid[i];
    return ret;
}
vector<string> deserialize_grid(const string &s, int n) {
    vector<string> ret;
    for(int i = 0 ;i < s.size();i += n) {
        ret.push_back(s.substr(i, n));
    }
    return ret;
}
vector<string> bomberMan(int n, vector<string> grid) {
    if (n < 2) grid;
    
    int row = grid.size();
    int col = grid[0].size();
    vector<string> full_grid(row, string(col, 'O'));

    if (n % 2 == 0)
        return full_grid;

    int dx[4] {1,-1,0,0};
    int dy[4] {0,0,1,-1};
    vector<string> grid_list;
    string prev_grid = serialize_grid(grid);
    int rep_begin = -1;
    while (true)
    {
        grid_list.push_back(prev_grid);
        string next_grid(col * row, 'O');
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (prev_grid[i * col + j] == 'O')
                {
                    next_grid[i * col + j] = '.';
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (is_in_bound(nx, ny, row, col))
                        {
                            next_grid[nx * col + ny] = '.';
                        }
                    }
                }
            }
        }
        
        prev_grid = next_grid;
        for(int i = 0;i < grid_list.size();i++) {
            if (grid_list[i] == next_grid) {
                rep_begin = i;
                break;
            }
        }
        if (rep_begin != -1) break;
    }
    n = n / 2;
    if (n < grid_list.size()) return deserialize_grid(grid_list[n], col);
    int rep_size = grid_list.size() - rep_begin;
    n -= rep_begin;
    return deserialize_grid(grid_list[rep_begin + n % rep_size], col);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string rcn_temp;
    getline(cin, rcn_temp);

    vector<string> rcn = split_string(rcn_temp);

    int r = stoi(rcn[0]);

    int c = stoi(rcn[1]);

    int n = stoi(rcn[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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
