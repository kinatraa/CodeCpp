#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
ll Mod = 1000000007;

string s;
queue <string> mau;
stack <string> toantu;
queue <string> bieuthuc;
stack <ll> tong;

void doi(){
	string tmp = "";
	for(int i = 0; i < s.size(); i++){
		if(s[i] < 48 || s[i] > 57){
			if(tmp != ""){
				mau.push(tmp);
				tmp = "";
			}
			string x = "";
			x += s[i];
			mau.push(x);
		} 
		else{
			tmp += s[i];
		}
	}
	if(tmp != ""){
		mau.push(tmp);
		tmp = "";
	}
}

void kiphap(){
	while(!mau.empty()){
		if(mau.front() != "(" && mau.front() != "-" && mau.front() != "+" && mau.front() != ")" && mau.front() != "*" && mau.front() != "/"){
			bieuthuc.push(mau.front());
			mau.pop();
		}
		else{
			if(mau.front() == ")"){
				while(!toantu.empty()){
					if(toantu.top() == "("){
						toantu.pop();
						break;
					}
					else{
						bieuthuc.push(toantu.top());
						toantu.pop();
					}
				}
				mau.pop();
			}
			else if(mau.front() == "+" || mau.front() == "-"){
				if(toantu.empty()) toantu.push(mau.front());
				else{
					while(!toantu.empty()){
						if(toantu.top() == "(") break;
						else{
							bieuthuc.push(toantu.top());
							toantu.pop();
						}
					}
					toantu.push(mau.front());
				}
				mau.pop();
			}
            else if(mau.front() == "*" || mau.front() == "/"){
                if(toantu.empty()) toantu.push(mau.front());
                else{
                    while(!toantu.empty()){
                        if(toantu.top() == "(") break;
                        else{
                            if(toantu.top() == "*" || toantu.top() == "/"){
                                bieuthuc.push(toantu.top());
                                toantu.pop();
                            }
                            else{
                                break;
                            }
                        }
                    }
                    toantu.push(mau.front());
                }
                mau.pop();
            }
			else{
				toantu.push(mau.front());
				mau.pop();
			}
		}
	}
	while(!toantu.empty()){
		bieuthuc.push(toantu.top());
		toantu.pop();
	}
}

void tinh(){
	while(!bieuthuc.empty()){
        cout << bieuthuc.front();
		if(bieuthuc.front() != "-" && bieuthuc.front() != "+" && bieuthuc.front() != "*" && bieuthuc.front() != "/"){
			ll x;
			stringstream ss(bieuthuc.front());
			ss >> x;
			tong.push(x);
			ss.clear();
		}
		else{
			ll a = tong.top();
			tong.pop();
			ll b;
			if(tong.empty()){
                if(bieuthuc.front() == "+"){
                    tong.push(a);
                }
                else if(bieuthuc.front() == "*"){
                    tong.push(a);
                }
                else if(bieuthuc.front() == "/"){
                    tong.push(a);
                }
                else{
                    tong.push(-a);
                }
            }
			else{
				b = tong.top();
				tong.pop();
                if(bieuthuc.front() == "+"){
                    tong.push(b+a);
                }
                else if(bieuthuc.front() == "*"){
                    tong.push(b*a);
                }
                else if(bieuthuc.front() == "/"){
                    tong.push(b/a);
                }
                else{
                    tong.push(b-a);
                }
			}
		}
		bieuthuc.pop();
	}
	cout << endl << tong.top();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	doi();
	kiphap();
	tinh();
	// while(!bieuthuc.empty()){
	// 	cout << bieuthuc.front() << " ";
	// 	bieuthuc.pop();
	// }
	// while(!mau.empty()){
	// 	cout << mau.front() << " ";
	// 	mau.pop();
	// }
}