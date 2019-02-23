#include <bits/stdc++.h>

using namespace std;

// Complete the organizingContainers function below.
string organizingContainers(vector<vector<int>> container) {
    long long balls[101] {0};
    long long containers[101] {0};
    for(int i = 0 ;i < container.size();i++) {
        for(int j = 0 ;j < container[i].size();j++) {
            balls[j] += container[i][j];
            containers[i] += container[i][j];
        }
    }
    sort(balls, balls + container.size());
    sort(containers, containers + container.size());
    for(int i = 0 ;i < container.size();i++) {
        if (balls[i] != containers[i]) return "Impossible";
    }
    return "Possible";
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

        vector<vector<int>> container(n);
        for (int i = 0; i < n; i++) {
            container[i].resize(n);

            for (int j = 0; j < n; j++) {
                cin >> container[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        string result = organizingContainers(container);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
