#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int MOD = 1000000007;

int board[9][9] = {0};
int dx[8] = {-2,-2,-1,-1, 1, 1, 2,2};
int dy[8] = {-1, 1,-2, 2,-2, 2,-1,1};
int p;

struct point{
    int d, x, y;
};

int check(int x1, int y1){
    int s = 0;
    for(int i = 0; i < 8; i++){
        int x2 = x1+dx[i];
        int y2 = y1+dy[i];
        if (x2>=1 && x2<=8 && y2>=1 && y2<=8 && !board[x2][y2]) s++;
    }
    return s;
}

bool dfs(int x, int y, int cnt){
    board[x][y] = cnt;
    if(cnt == 64){
        return 1;
    }
    vector <point> v;
    for(int i = 0; i < 8; i++){
        int x1 = x + dx[i];
        int y1 = y + dy[i];
        if(x1 >= 1 && x1 <= 8 && y1 >= 1 && y1 <= 8 && !board[x1][y1]){
            p = check(x1,y1);
            v.push_back({p, x1, y1});
        }
    }
    sort(v.begin(), v.end(), [](const point &a, const point &b){
		return a.d < b.d;
	});
    for(point u : v){
        if(dfs(u.x, u.y, cnt+1)) return 1;
    }
    board[x][y] = 0;
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int n, m;
    cin >> n >> m;
    dfs(m,n,1);
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}