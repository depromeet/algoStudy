#include <bits/stdc++.h>

using namespace std;

// Complete the steadyGene function below.
map<char, int> cmap; // count 저장 
char arr[4] = {'G', 'C', 'T', 'A'};
map<char, int> imap; // index 저장
int scount[500010][4] ={0}; // 누적 카운트

int solve(string& gene) {
    int ret = 0x7fffffff;
    int avg = gene.size() / 4;

    for(int i = 0; i < gene.size();i++) {
        if (cmap[gene[i]] > avg) {
            // 시작점 혹은 끝점이 된다. 
            int lower = i;
            int upper = gene.size() - 1;
            while(lower < upper) {
                int mid = (lower + upper) / 2;
                int direction = 0;
                for(int j =0 ;j < 4;j++) {
                    if (cmap[arr[j]] > avg) {
                        // 줄어들어야 할 gene 의 경우 
                        // 현재 위치 까지의 gene 수 계산
                        int temp = scount[mid][j] - (i == 0? 0 : scount[i-1][j]);
                        if (temp < cmap[arr[j]] - avg) {
                            // 아직 더 많은 gene 이 필요하다.
                            direction = 1;
                        }
                    }
                }
                if (direction) {
                    // 뒤쪽으로 이동
                    lower = mid + 1;
                } else {
                    // 앞쪽으로 이동
                    upper = mid;
                }
            }
            int j;
            for (j = 0; j < 4; j++)
            {
                if (cmap[arr[j]] > avg)
                {
                    int temp = scount[lower][j] - (i == 0 ? 0 : scount[i - 1][j]);
                    if (temp < cmap[arr[j]] - avg)
                    {
                        break;
                    }
                }
            }
            if (j == 4) {
                ret = min(ret, lower - i + 1);
            }
        }
    }
    return ret;
}

int steadyGene(string gene) {
    for(int i = 0 ;i < 4;i++) {
        cmap[arr[i]] = 0;
        imap[arr[i]] = i;
    }
    for(int i = 0 ;i < gene.size();i++) {
        cmap[gene[i]]++;
        if (i) {
            for (int j = 0; j < 4; j++) {
                scount[i][j] = scount[i - 1][j];
            }
        }
        scount[i][imap[gene[i]]]++;
    }

    int dap = 0;
    vector<char> v;

    for (int i = 1; i < 4; i++)
    {
        if (cmap[arr[i]] != cmap[arr[i - 1]])
        {
            dap = solve(gene);
            break;
        }
    }
    return dap;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string gene;
    getline(cin, gene);

    int result = steadyGene(gene);

    fout << result << "\n";

    fout.close();

    return 0;
}
