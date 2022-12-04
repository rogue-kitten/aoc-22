#include <iostream>
#include <string>
#include <unordered_set>
#include<vector>

using namespace std;

int main() {
	int sum = 0;
	string line;

	while (getline(cin, line)) {
		vector<int> a(4, 0);
		int i = 0;
		for (char x : line) {
			if (x >= '0' && x <= '9')
				a[i] = (a[i] * 10) + (x - '0');

			else i++;
		}
		if (a[0] >= a[2] && a[1] <= a[3]) sum++;
		else if (a[2] >= a[0] && a[3] <= a[1]) sum++;
	}
	cout << sum;
	return 0;
}
