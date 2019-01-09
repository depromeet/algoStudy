#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <cmath>
#include <queue>

using namespace std;

vector<string> split_string(string);

int getTopDisc(int x) {
    for (int i = 0 ;i < 10;i++) {
        if (x & (1 << i)) return i;
    }
    return -1;
}
void bfs(map<long long, int>& visited, long long start, long long target) {
    queue<long long> q;
    q.push(start);

    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        if (current == target) break;
        for (int i = 0; i < 4; i++)
        {
            // 현재 봉 중에서 가장 위 디스크
            int topDisc = (((current >> (10 * i)) & 0x3ff));
            if (topDisc != 0) // 디스크가 있을 때만
            {
                topDisc = getTopDisc(topDisc);
                for (int j = 0; j < 4; j++)
                {
                    if (i != j)
                    {
                        // 옮길 봉 중에서 가장 위 디스크
                        int jtopDisc = ((current >> (10 * j)) & 0x3ff);
                        if (jtopDisc != 0)
                        {
                            jtopDisc = getTopDisc(jtopDisc);
                        }
                        else
                        {
                            jtopDisc = -1;
                        }
                        if (jtopDisc == -1 || jtopDisc > topDisc)
                        {
                            // 옮길 봉 에 있는 디스크가 옮겨지는 애보다 클 때만
                            long long next =
                                (current ^ (((long long)1 << topDisc) << (10 * i)));
                            next |= (((long long)1 << topDisc) << (10 * j));
                            if (visited.find(next) == visited.end())
                            {
                                visited[next] = visited[current]+ 1;
                                q.push(next);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    long long status = 0LL;
    long long target = 0LL;
    map<long long, int> visited;
    for (int i = 0; i < N; i++) {
        int a_item = stoi(a_temp[i]);

        status |= (((long long)1 << i) << (10 * (a_item - 1)));
        // printf("Status: 0x%LX\n", status);
        target |= (1 << i);
    }
    visited.insert(make_pair(status, 0));
    bfs(visited, status, target);
    printf("%d\n", visited[target]);
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
