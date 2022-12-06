#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	int i = 0;
	string line;
	getline(cin, line);
	unordered_map<char, int> temp;
	for (int i = 0; i < 4; i++) {
		temp[line[i]]++;
	}
	for (int i = 4; i < line.length(); i++) {
		if (temp.size() == 4) {
			cout << i;
			break;
		}
		temp[line[i-4]]--;
    if(!temp[line[i-4]])
      temp.erase(line[i-4]);
    temp[line[i]]++;
	}
}
