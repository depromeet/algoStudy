#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    // s를 t로 바꾸는데 걸리는 연산 개수 세기
    int num_op;
    // 두 문자열 앞에서부터 비교하며 불일치 지점 찾기
    int min_length = (s.length() < t.length()) ? s.length() : t.length();
    int index = min_length;
    for (int i = 0; i < index; i++) {
        if (s[i] != t[i]) {
            index = i;
            break;
        }
    }
    /* s의 불일치 지점부터 문자열 끝까지 지우고, 
       t의 불일치 지점부터 문자열 끝까지 붙인다고 생각하고 num_op 계산
    */ 
    if (index == min_length) {
        num_op = (s.length() > t.length()) ? (s.length() - index) : (t.length() - index);
    }
    else {
        num_op = (s.length() - index) + (t.length() - index);
    }
    cout << s.length() << " : " << index << " : " << num_op << "\n";

    // k가 가능한지 따지기
    // k가 연산개수보다 적으면 no 출력
    if (k < num_op) {
        return "No";
    }
    // k가 연산개수와 일치하면 yes 출력
    else if (k == num_op) {
        return "Yes";
    }
    // k가 연산개수보다 클 경우,
    else {
        // k가 두 문자열의 길이 합보다 작은 경우,
        if (k < (s.length() + t.length())) {
            // k가 op 더하기 짝수인 경우 yes 출력 (delete + add 연산)
            if ((k % 2) == (num_op % 2)) {
                return "Yes";
            }
            else {
                return "No";
            }
        }
        // 두 문자열의 길이 합보다 큰 경우, s 다지우고 t 하나씩 더하면 되기에 yes 출력 (빈 문자열에 delete 계속 가능)
        else {
            return "Yes";
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
