#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>


int bound(int x,int y, int mx, int my) 
{
	return x >= 0 && y >= 0 && x < mx && y < my;
}

int n, m;
int arr[512][512];
long long max_ = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int chk[512][512];

int ex[4][4] = {
	{0, 0, 0, -1}, 
	{0, 0, 0, 1},
	{0,1,2,1},
	{0,1,2,1}
};
int ey[4][4] = {
	{0,1,2,1}, {0,1,2,1},
	{0,0,0,1}, {0,0,0,-1}
};
void solve(int x, int y, int sum, int depth) {
	sum += arr[x][y];
	if (depth == 3) {
		if (sum > max_)
			max_ = sum;
		return ;
	}
	chk[x][y] = 1;
	for (int i = 0 ;i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (bound(nx,ny,n,m) && !chk[nx][ny]) {
			solve(nx,ny,sum, depth+1);
		}
	}
	chk[x][y] = 0;
}
int main(void){ 
	scanf("%d %d", &n, &m);
	memset(chk,0,sizeof(chk));
	for (int i = 0; i < n ;i++) {
		for(int j = 0 ;j < m ;j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
	for (int j = 0;j < m;j++) {
		solve(i,j,0,0);
		for(int q = 0 ;q < 4;q++) {
			int w;
			int sum = 0;
			for(w = 0 ; w < 4; w++) {
				int nx = i + ex[q][w];
				int ny = j + ey[q][w];
				if (bound(nx,ny,n,m)) {
					sum += arr[nx][ny];
				}
			}
			if (w == 4 && max_ < sum)
				max_ = sum;
		}
	}
	}
	printf("%lld\n", max_);
	return 0;
}

