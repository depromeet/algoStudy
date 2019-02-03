#include <cstdio>
#include <vector>
#include <stack>

using namespace std;


bool chk[1010];
vector<int> e[1010];

int dfs(int v, int b, stack<int> &st) {
    chk[v] = true;
    int cycle = -1;
    st.push(v);
    for(int i = 0 ;i < e[v].size();i++) {
        int x = e[v][i];
        if (!chk[x]) {
            cycle = dfs(x, v, st);
            if (cycle != -1) {
                return cycle;
            }
        } else if (x != b) {
            return x;
        }
    }
    st.pop();
    return cycle;
}

int dist[1010];

void setDist(int v, int d) {
    chk[v] = true;
    dist[v] = d;
    for(int i =0 ;i < e[v].size();i++) {
        if(!chk[e[v][i]]) {
            setDist(e[v][i], d + 1);
        }
    }
}
int main(void){
    int t;
    scanf("%d" , &t);

    for(int test = 0 ; test < t; test++) {
        int n;
        stack<int> st;
        for(int i = 0 ;i < n+1;i++) {
            e[i].resize(0);
        }
        memset(chk, 0, sizeof(chk));
        scanf("%d", &n);
        for(int i = 0 ;i < n;i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            e[x].push_back(y);
            e[y].push_back(x);
            dist[i+1] = 0x7fffffff;
        }
        int cStart = dfs(1, 0, st);
        vector<int> group;
        memset(chk, 0, sizeof(chk));
        while(st.top() != cStart) {
            group.push_back(st.top());
            chk[st.top()] = true;
            st.pop();
        }
        chk[st.top()] = true;
        group.push_back(st.top());
        memset(dist,0,sizeof(dist));
        for(int i = 0 ;i < group.size();i++) {
            setDist(group[i], 0);
        }
        printf("Case #%d:", test + 1);
        for(int i = 1 ;i <= n;i++) {
            printf(" %d", dist[i]);
        }
        printf("\n");
    }

    return 0;
}