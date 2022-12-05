#include <iostream>
#include <string>
#include <unordered_set>
#include<vector>
#include<deque>

using namespace std;

int main() {
	int sum = 0;
	string line;
	getline(cin, line);
	int size = (line.length() + 1) / 4;
	vector<deque<char>> crates(size);
	while (line.length()) {
		for (int i = 0; i < line.length(); i++) {
			if (line[i] >= 'A' && line[i] <= 'Z') {
				crates[i / 4].push_back(line[i]);
			}
		}
		getline(cin, line);
	}
	while (getline(cin, line)) {
		int arr[3] = {0}, i = 0, j = 0;
		while (j < line.length()) {
			if (line[j] >= '0' && line[j] <= '9') {
				while (j < line.length() && line[j] >= '0' && line[j] <= '9') {
					arr[i] = (10 * arr[i]) + (line[j] - '0');
					j++;
				}
				i++;
			}
			else j++;
		}
		while (arr[0] > 0) {
			char x = crates[arr[1] - 1].front();
			crates[arr[1] - 1].pop_front();
			crates[arr[2] - 1].push_front(x);
			arr[0]--;
		}
	}
	string ans;
	for (int i = 0; i < size; i++) {
		ans += crates[i].front();
	}
	cout << ans;
	return 0;
}
