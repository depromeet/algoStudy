#include <iostream>
#include <cstring>

using namespace std;

int topni[4][10];
int dx[2]{1, -1};

bool is_in_bound(int x) {
    return 0 <= x && x < 4;
}
void rotate_topni(int no, int dir, bool chk[4]) {
    chk[no] = true;

    for(int i = 0 ;i < 2;i++) {
        int nx = no + dx[i];
        int idx = (8 + dx[i] * 2) % 8;
        int nidx = (8 + dx[i] * -2) % 8;
        if (is_in_bound(nx) && chk[nx] == false && topni[no][idx] != topni[nx][nidx]) {
            rotate_topni(nx, -dir, chk);
        }
    }
    if (dir > 0) {
        int temp = topni[no][7];
        memmove(&topni[no][1], &topni[no][0], sizeof(int) * 7);
        topni[no][0] = temp;
    } else {
        int temp = topni[no][0];
        memmove(&topni[no][0], &topni[no][1], sizeof(int) * 7);
        topni[no][7] = temp;
    }
}

int main(void){ 
    for(int i =0 ;i < 4;i++) {
        string s;
        cin >> s;
        for(int j = 0 ;j < 8;j++) {
            topni[i][j] = s[j] - '0';
        }
    }
    int k;
    cin >> k;

    for(int i = 0 ;i < k;i++) {
        int no, dir;
        cin >> no >> dir;
        bool chk[4] {false};
        rotate_topni(no - 1, dir, chk);
    }
    int sum = 0;
    for(int i = 0 ;i < 4;i++) {
        sum += (topni[i][0] << i);
    }
    cout << sum ;
    return 0;
}