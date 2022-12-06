#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
	int i = 0;
    string line;
	getline(cin, line);
	unordered_map<char, int> temp;
	for (int i = 0; i < 14; i++) {
		temp[line[i]]++;
	}
	for (int i = 14; i < line.length(); i++) {
		if (temp.size() == 14) {
			cout << i;
			break;
		}
		temp[line[i-14]]--;
    if(!temp[line[i-14]])
      temp.erase(line[i-14]);
    temp[line[i]]++;
	}
}
