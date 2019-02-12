#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the aOrB function below.
 */

int getOneBit(int a, int bit) {
    return (a & (1 << bit)) >> bit;
}
void aOrB(int k, string a, string b, string c) {
    /*
     * Write your code here.
     */
    int alen = a.size();
    int blen = b.size();
    int clen = c.size();
    int mlen = max(alen, max(blen, clen));
    a = string(mlen - a.size(), '0') + a;
    b = string(mlen - b.size(), '0') + b;
    c = string(mlen - c.size(), '0') + c;
    vector<int> av, bv, cv;
    for(int i = 0 ;i < a.size();i++) {
        int temp;
        stringstream(string(1,a[i])) >> std::hex >> temp;
        av.push_back(temp);
        stringstream(string(1,b[i])) >> std::hex >> temp;
        bv.push_back(temp);
        stringstream(string(1,c[i])) >> std::hex >> temp;
        cv.push_back(temp);
    }

    for(int i = 0;i < a.size();i++) {
        int abi = av[i] | bv[i];
        if (abi != cv[i]) {
            for(int j = 0; j < 4;j++) {
                if (getOneBit(cv[i], j)) {
                    // 비트가 on 해야하면, B만 키면됨 (A는 최소 유지)
                    if (getOneBit(bv[i], j) == 0 && getOneBit(av[i],j) == 0) {
                        bv[i] |= (1 << j);
                        k--;
                    }
                } else {
                    // 비트를 off 해야되면, 둘다 off해야함
                    if (getOneBit(av[i], j)) {
                        av[i] ^= (1 << j);
                        k--;
                    }
                    if (getOneBit(bv[i], j)) {
                        bv[i] ^= (1 << j);
                        k--;
                    }
                }
            }
        } 
    }
    if (k < 0) {
        printf("-1\n");
        return ;
    }
    for(int i = 0 ;i < a.size() && k > 0;i++) {
        // 필요없는 a 비트 다 off, 단 앞에서부터 off 해야 최소
        for(int j = 3 ;j >= 0 && k > 0;j--) {
            if (getOneBit(av[i],j)) {
                if (getOneBit(bv[i],j)) {
                    // B 가 on 되어 있으니까 A는 off 해도 됨. 
                    av[i] ^= (1 << j);
                    k--;
                } else if (k >= 2) {
                    // B를 on 시키고 A를 off 함. 
                    av[i] ^= (1 << j);
                    bv[i] ^= (1 << j);
                    k -= 2;
                }
            }
        }
    }
    for(int i = 0 ;i < a.size();i++) {
        stringstream sa, sb;
        sa << std::hex << std::uppercase << av[i];
        sb << std::hex << std::uppercase << bv[i];
        a[i] = sa.str()[0];
        b[i] = sb.str()[0];
    }
    int non0;
    for(non0 = 0 ;non0 < a.size() && a[non0] == '0';non0++);
    a = a.substr(non0, a.size() - non0);
    for(non0 = 0 ;non0 < b.size() && b[non0] == '0';non0++);
    b = b.substr(non0, b.size() - non0);
    // 얘 떄문에 오답. 길이 0인 경우 고려해서 출력해야함! 멍!청!
    cout << ((a.size() > 0) ? a : "0") << endl << ((b.size() > 0) ? b: "0") << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        int k;
        cin >> k;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string a;
        getline(cin, a);

        string b;
        getline(cin, b);

        string c;
        getline(cin, c);

        aOrB(k, a, b, c);
    }

    return 0;
}
