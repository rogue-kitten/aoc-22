#include<bits/stdc++.h>

using namespace std;
# define ll long long
// A -> rock, B -> paper, C-> scissor (1,2,3 score) and x,y,z would be my choice
int main() {
	ifstream file("inputf.in");
	string text;
	ll ans = 0;
	while (getline (file, text)) {
		if (text[2] == 'X') {
			if (text[0] == 'A') ans += 3;
			else if (text[0] == 'B') ans += 1;
			else ans += 2;
		}
		else if (text[2] == 'Y')
			ans += (text[0] - 'A' + 4);
		else {
			ans += 6;
			if (text[0] == 'A') ans += 2;
			else if (text[0] == 'B') ans += 3;
			else ans += 1;
		}
	}
	cout << ans;
}
