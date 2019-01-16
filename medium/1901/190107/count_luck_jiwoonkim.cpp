#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// function for DFS algorithm (using recursion)
vector<pair<int, int>> DFS(vector<string> matrix, vector<pair<int, int>> decision, vector<pair<int, int>> visited, pair<int, int> cur_pos)
{
    // add current position into visited
    visited.push_back(cur_pos);
    vector<pair<int, int>> new_dec;

    // check if position is portkey(*); base case
    if (matrix[cur_pos.first][cur_pos.second] == '*')
    {
        return decision;
    }
    // if have not arrived to destination, recurse over available pathways
    else
    {
        // create vector to contain all available paths (UP, DOWN, LEFT, RIGHT)
        vector<pair<int, int>> moves;

        // check if they can move UP (check if next position is empty and not visited)
        if (cur_pos.first != 0)
        {
            pair<int, int> new_pos(cur_pos.first - 1, cur_pos.second);
            if ((matrix[new_pos.first][new_pos.second] != 'X') && (find(visited.begin(), visited.end(), new_pos) == visited.end()))
            {
                moves.push_back(new_pos);
            }
        }
        // check if they can move DOWN (check if next position is empty and not visited)
        if (cur_pos.first != matrix.size() - 1)
        {
            pair<int, int> new_pos(cur_pos.first + 1, cur_pos.second);
            if ((matrix[new_pos.first][new_pos.second] != 'X') && (find(visited.begin(), visited.end(), new_pos) == visited.end()))
            {
                moves.push_back(new_pos);
            }
        }
        // check if they can move LEFT (check if next position is empty and not visited)
        if (cur_pos.second != 0)
        {
            pair<int, int> new_pos(cur_pos.first, cur_pos.second - 1);
            if ((matrix[new_pos.first][new_pos.second] != 'X') && (find(visited.begin(), visited.end(), new_pos) == visited.end()))
            {
                moves.push_back(new_pos);
            }
        }
        // check if they can move RIGHT (check if next position is empty and not visited)
        if (cur_pos.second != matrix[0].length() - 1)
        {
            pair<int, int> new_pos(cur_pos.first, cur_pos.second + 1);
            if ((matrix[new_pos.first][new_pos.second] != 'X') && (find(visited.begin(), visited.end(), new_pos) == visited.end()))
            {
                moves.push_back(new_pos);
            }
        }
        // if current position is dead-end, retrack back to last decision point
        if (moves.empty())
        {   
            new_dec = decision;
            return new_dec;
        }
        // move via the available pathway
        else
        {
            // if one-way, move via the path
            if (moves.size() == 1)
            {
                new_dec = DFS(matrix, decision, visited, moves.back());
                return new_dec;
            }
            // if more than one way, add position to decision stack and then, loop over available paths
            else
            {
                decision.push_back(cur_pos);
                for (int i = 0, n = moves.size(); i < n; i++)
                {
                    new_dec = DFS(matrix, decision, visited, moves[i]);
                    // make sure other path does not override the optimal path (study!)
                    if (new_dec.size() > decision.size()) {
                        return new_dec;
                    }
                    else {
                        return decision;
                    }
                }
                // make sure other path does not override the optimal path (study!)
                if (new_dec.size() > decision.size()) {
                    return new_dec;
                }
                else {
                    return decision;
                }
            }
        }
    }
}

// Complete the countLuck function below.
string countLuck(vector<string> matrix, int k)
{
    pair<int, int> start_pos;
    vector<pair<int, int>> decision;
    vector<pair<int, int>> visited;
    // find location of M (starting point)
    for (int i = 0, n = matrix.size(); i < n; i++)
    {
        for (int j = 0, m = matrix[i].length(); j < m; j++)
        {
            if (matrix[i][j] == 'M')
            {
                start_pos = make_pair(i, j);
                break;
            }
        }
    }
    // find the pathway from M to * (portkey)
    decision = DFS(matrix, decision, visited, start_pos);

    // check if Ron's guess is correct (compare k with size of decison stack)
    if (decision.size() == k)
    {
        return "Impressed";
    }
    else
    {
        return "Oops!";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++)
        {
            string matrix_item;
            getline(cin, matrix_item);

            matrix[i] = matrix_item;
        }

        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = countLuck(matrix, k);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
