#include <bits/stdc++.h>

using namespace std;

// Complete the biggerIsGreater function below.
string biggerIsGreater(string w) {
    string original = w;
    int pivot;
    for(pivot = w.size() - 1;pivot > 0;pivot--) {
        // 현재 헤드 지점
        if (w[pivot-1] < w[pivot]) break;
    }

    // 역순 정렬이 되어 있는 경우
    if (pivot == 0) return "no answer";

    pivot--;

    int next_pivot;
    for(next_pivot = w.size() - 1; ; next_pivot--) {
        // 다음 헤드로 스왑될 엘리먼트
        if (w[next_pivot] > w[pivot]) {
            break;
        }
    }

    swap(w[pivot], w[next_pivot]);
    reverse(w.begin() + pivot + 1, w.end());

    return w;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int T;
    cin >> T;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
