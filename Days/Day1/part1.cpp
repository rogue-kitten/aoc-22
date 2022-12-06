#include<bits/stdc++.h>
#include <fstream>

using namespace std;
int main() {
	ifstream file("inputf.in");
	string text;
	long long maxAns = 0, ans = 0;
	while (getline (file, text)) {
		if (text.length() == 0) {
			maxAns = max(maxAns, ans);
			ans = 0;
		}
		else ans += stoi(text);
	}
    cout << maxAns;
    cout <"Some Random text";
}
