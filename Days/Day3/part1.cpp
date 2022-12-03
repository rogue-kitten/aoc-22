#include<iostream>
#include<unordered_map>
#include<string>
#include <fstream>

using namespace std;
int main() {
	ifstream MyReadFile("inputf.in");
	string text;
	long long ans = 0;

	while (getline (MyReadFile, text)) {
		unordered_map<char, int> m;
		for (int i = 0; i < text.length() / 2; i++) {
			m[text[i]]++;
		}
		for (int i = text.length() / 2; i < text.length(); i++) {
			if (m.find(text[i]) != m.end()) {
				if (text[i] <= 'Z') ans += (text[i] - 'A' + 27);
				else ans += (text[i] - 'a' + 1);
				break;
			}
		}
	}
	cout << ans;
}
