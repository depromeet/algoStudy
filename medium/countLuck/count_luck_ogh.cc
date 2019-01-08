#include <bits/stdc++.h>
#include <cstring>
#include <queue>

using namespace std;

vector<string> split_string(string);

struct Point {
	int x;
	int y;
	Point(int _x, int _y)
		: x(_x), y(_y) {}
};

bool isInBound(int x, int y, int mx, int my) {
	return 0 <= x && 0 <= y && x < mx && y < my;
}

string countLuck(vector<string> matrix, int k) {
	int sx = 0 , sy = 0; 
	int ex = 0 , ey = 0;
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int decision[128][128];
	int rows = matrix.size();
	int cols = matrix[0].size();
	
	queue<Point> q;

	// set to -1 
	memset(decision, 0xff, sizeof(decision));

	// get start point, end point. check tree
	for (int i = 0 ;i < rows; i++) { 
		for (int j = 0 ;j < cols; j++) { 
			if (matrix[i][j] == 'M') { 
				sx = i; sy = j; 
				q.push(Point(i, j));
				decision[i][j] = 0;
			} else if (matrix[i][j] == 'X') {
				decision[i][j] = 0;
			} else if (matrix[i][j] == '*') {
				ex = i; ey = j;
			}
		} 
	} 


	// bfs
	while (!q.empty()) {
		Point current = q.front();
		int cx = current.x, cy = current.y;
		q.pop();

		if (current.x == ex && current.y == ey) break;

		queue<Point> temp;

		for (int i = 0;i < 4;i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			// if it's road
			if (isInBound(nx, ny, rows, cols)
					&& decision[nx][ny] == -1) {
				q.push(Point(nx,ny));
				temp.push(Point(nx, ny));
				decision[nx][ny] = decision[cx][cy];
			}
		}

		// blocked or single route
		if (temp.size() < 2) continue;

		// multi routes: decision needed
		while (!temp.empty()) {
			Point tp = temp.front();
			temp.pop();
			decision[tp.x][tp.y]++;
		}
	}

	if (decision[ex][ey] == k) {
		return "Impressed";
	} else {
		return "Oops!";
	}
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nm_temp;
        getline(cin, nm_temp);

        vector<string> nm = split_string(nm_temp);

        int n = stoi(nm[0]);

        int m = stoi(nm[1]);

        vector<string> matrix(n);

        for (int i = 0; i < n; i++) {
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

