#include<bits/stdc++.h>

using namespace std;
# define ll long long

int main() {
	ifstream file("inputf.in");
	string text;
	ll ans = 0;
	vector<ll> temp;
	while (getline (file, text)) {
		if (text.length() == 0) {
			temp.push_back(ans);
			ans = 0;
		}
		else ans += stoi(text);
	}
	temp.push_back(ans);
	sort(temp.rbegin(), temp.rend());
	cout << temp[0] + temp[1] + temp[2];
}
