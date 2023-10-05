#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
const long MOD = 1e9 + 7;
typedef vector<vector<int>> matrix;

matrix base = {{1,1,1}, {1,0,0}, {0,0,1}};

matrix mul(matrix a, matrix b)
{
	matrix res = {{0,0,0}, {0,0,0}, {0,0,0}};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++){
                res[i][j] += a[i][k]*b[k][j];
                res[i][j] %= MOD;
            }
		}
	}
    return res;
}

matrix pow_mod(int n){
    if(n == 1){
        return base;
    }
    matrix tmp = pow_mod(n/2);
    matrix res = mul(tmp,tmp);
    if(n%2==1)  res = mul(res,base);
    return res;
}

void solve(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0;
        return;
    }
    if(n == 1){
        cout << 1;
        return;
    }
    matrix res = pow_mod(n-1);
    cout << (res[0][0] + res[0][2])%MOD;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}