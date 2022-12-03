#include<iostream>
#include<unordered_map>
#include<string>
#include <fstream>

using namespace std;
int main() {
	ifstream MyReadFile("inputf.in");
	string text;
	long long ans = 0;
	int grp = 0;
	unordered_map<char, int> m;
	while (getline (MyReadFile, text)) {
		if (grp < 2) {
			unordered_map<char, bool> visited;
			for (int i = 0; i < text.length(); i++) {
				if (!visited[text[i]]) {
					m[text[i]]++;
					visited[text[i]] = true;
				}
			}
			grp++;
		}
		else if (grp == 2) {
			for (int i = 0; i < text.length(); i++) {
				if (m.find(text[i]) != m.end() && m[text[i]] == 2) {
					cout << text[i] << endl;
					if (text[i] <= 'Z') ans += (text[i] - 'A' + 27);
					else ans += (text[i] - 'a' + 1);
					break;
				}
			}
			grp = 0;
			m.clear();
		}
	}
	cout << ans;
}
