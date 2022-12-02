#include<bits/stdc++.h>

using namespace std;
# define ll long long
// A -> rock, B -> paper, C-> scissor (1,2,3 score) and x,y,z would be my choice
int main() {
	ifstream file("inputf.in");
	string text;
	ll ans = 0;
	while (getline (file, text)) {
		ans += (text[2] - 'X' + 1);
		if ((text[2] - 'X') == (text[0] - 'A')) ans += 3;
		else if (text[2] == 'X') {
			if (text[0] == 'C') ans += 6;
		}
		else if (text[2] == 'Y') {
			if (text[0] == 'A') ans += 6;
		}
		else {
			if (text[0] == 'B') ans += 6;
		}
	}
	cout << ans;
}
