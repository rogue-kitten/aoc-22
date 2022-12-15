#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

vector<string> splitString(string str, string delimiter = " ") {
	int start = 0;
	int end = str.find(delimiter);
	vector<string> split;
	while (end != -1) {
		split.push_back(str.substr(start, end - start));
		start = end + delimiter.size();
		end = str.find(delimiter, start);
	}
	split.push_back(str.substr(start, end - start));
	return split;
}

vector<vector<int>> merge(vector<vector<int>> intervals) {
	sort(intervals.begin(), intervals.end());
	vector<vector<int>> ans;
	ans.push_back(intervals[0]);
	for (int i = 1; i < intervals.size(); i++)
	{
		if (intervals[i][0] <= ans.back()[1]) ans.back()[1] = max(intervals[i][1], ans.back()[1]);
		else if (intervals[i][0] == ans.back()[1] + 1) ans.back()[1] = intervals[i][1];
		else ans.push_back(intervals[i]);
	}
	return ans;
}

int main() {
	auto start = high_resolution_clock::now();
	string line;
	int maxLimit = 4000000;
	unordered_map < int, vector<vector<int>>> mergedIntervals;
	while (getline(cin, line)) {
		vector<string> words = splitString(line);
		int sensorX = stoi(words[2].substr(2, words[2].length() - 3));
		int sensorY = stoi(words[3].substr(2, words[3].length() - 3));

		int beaconX = stoi(words[8].substr(2, words[8].length() - 3));
		int beaconY = stoi(words[9].substr(2, words[9].length() - 2));
		// cout << sensorX << " " << sensorY << " " << beaconX << " " << beaconY << endl;

		int dist = abs(sensorX - beaconX) + abs(sensorY - beaconY);

		for (int limit = 0; limit <= maxLimit; limit++) {
			// vector<vector<int>> intervals;
			if (sensorY < limit) {
				// need to check for the maxY coord.
				if (sensorY + dist > limit) {
					int x1 = sensorX + dist - abs(sensorY - limit);
					int x2 = sensorX - dist + abs(sensorY - limit);
					mergedIntervals[limit].push_back(vector<int> {x2, x1});
				}
			}

			//if the sensor lies below the limit
			if (sensorY > limit) {
				//same as the previous case, except we need the minY coord.
				if (sensorY - dist < limit) {
					int x1 = sensorX + dist - abs(sensorY - limit);
					int x2 = sensorX - dist + abs(sensorY - limit);
					mergedIntervals[limit].push_back(vector<int> {x2, x1});
				}
			}

			// if sensor lies on the line, then from maxX to minX all would be blocked position.
			if (sensorY == limit) {
				int x2 = sensorX - dist, x1 = sensorX + dist;
				mergedIntervals[limit].push_back(vector<int> {x2, x1});
			}
		}
	}
	long long ans = 0;
	for (int i = 0; i <= maxLimit; i++) {
		mergedIntervals[i] = merge(mergedIntervals[i]);
		if (mergedIntervals[i].size() > 1) {
			for (auto x : mergedIntervals[i]) {
				if (x[1] + 1 >= 0 && x[1] + 1 <= maxLimit) {
					ans = 4000000 * 1ll * (x[1] + 1) + (i) * 1ll;
					break;
				}
			}
		}
	}
	cout << ans << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << duration.count() << " ms" << endl;
}
