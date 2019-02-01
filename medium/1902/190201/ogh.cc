#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the pylons function below.
struct Coverage {
    int begin;
    int end;
    Coverage(int b, int e) : begin(b), end(e) {}
};
bool isOverlapped(Coverage a, Coverage b) {
    // 겹치는 지점이 있는 경우 
    return a.begin <= b.begin && b.begin <= a.end;
}

bool isConnected(Coverage a, Coverage b) {
    return a.end + 1 == b.begin;
}
int pylons(int k, vector<int> arr) {
    int cnt = 0;
    vector<Coverage> v;
    for(int i = 0 ;i < arr.size();i++) {
        if (arr[i] == 1) {
            v.push_back(Coverage(i-k+1, i+k-1));
        }
    }
    sort(v.begin(), v.end(), [](Coverage a, Coverage b) {
        return a.begin < b.begin;
    });
    int begin = v[0].begin;
    int end = v[0].end;
    if(begin > 0) return -1;
    
    vector<int> plant; // 짓기로 확정된 공장 index 저장
    plant.push_back(0);
    for(int i = 1; i < v.size();i++) {
        int numPlant = plant.size();
        // 이미 지어진 건물과 coverage가 겹치는지 확인
        if (isOverlapped(v[plant[numPlant - 1]], v[i])) {
            // 겹치는 경우, 이미 결정된 것을 제외 할 수 있는지 확인. 
            Coverage leader(-100010,-1);
            if (numPlant != 1) leader = v[plant[numPlant-2]];
            if(isOverlapped(leader, v[i]) || isConnected(leader, v[i])) {
                // 2번 째 앞의 공장과 겹치는 범위거나 이어지면, 
                // 바로 앞의 공장은 제거해도 됨. 
                plant[numPlant - 1] = i;
            } else {
                // 앞의 공장을 못 없애면 그냥 추가
                plant.push_back(i);
            }
        } else if (isConnected(v[plant[numPlant - 1]], v[i])) {
            // 단순히 이어지는 포인트면 추가
            plant.push_back(i);
        } else {
            // 겹치는 지점도 없고 이어지지도 않으면 cover 불가능
            return -1;
        }
    }
    if (v[plant[plant.size()-1]].end >= v.size() - 1) {
        return plant.size();
    } else {
        return -1;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = pylons(k, arr);

    fout << result << "\n";

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
