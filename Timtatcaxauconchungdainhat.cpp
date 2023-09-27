#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const long MOD = 1e9 + 7;

string a, b;
int la, lb, lenMax = 0;
int save[105][105];

int LCS(int i, int j){
	int &lcslen = save[i][j];
	if(i == la || j == lb) return lcslen = 0;
	if(lcslen != -1) return lcslen;
	lcslen = 0;
	if(a[i] == b[j]) lcslen = 1 + LCS(i+1, j+1);
	else lcslen = max(LCS(i+1,j), LCS(i,j+1));
	return lcslen;
}

void Print(char res[], int u, int v, int len){
	if(len == lenMax){
		res[len] = '\0';
		puts(res);
		return;
	}
	if(u == la || v == lb) return;
	for(char x = 'a'; x <= 'z'; x++){
		bool check = false;
		for(int i = u; i < la; i++){
			if(x == a[i]){
				for(int j = v; j < lb; j++){
					if(x == b[j] && LCS(i,j) == lenMax - len){
						res[len] = x;
						Print(res, i+1, j+1, len+1);
						check = true;
						break;
					}
				}
			}
			if(check) break;
		}
	}
}

void solve()
{
	cin >> a >> b;
	la = a.size(); lb = b.size();
	memset(save, -1, sizeof(save));
	lenMax = LCS(0,0);
	if(lenMax == 0){
		cout << "khong co xau con chung";
		return;
	}
	char res[105];
	Print(res,0,0,0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}