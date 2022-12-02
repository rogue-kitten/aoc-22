#include<bits/stdc++.h>
#include <fstream>

using namespace std;
int main() {
	ifstream MyReadFile("inputf.in");
	string text;
	long long maxAns = 0, ans = 0;
	while (getline (MyReadFile, text)) {
		if (text.length() == 0) {
			maxAns = max(maxAns, ans);
			ans = 0;
		}
		else ans += stoi(text);
	}
	cout << maxAns;
}
