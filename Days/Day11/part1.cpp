#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>

using namespace std;
#define ll long long

int main() {

  string str;
  vector<vector<ll>> items; //stores all the items contained by the monkeys;
  vector<string> operation; //stores the operation performed by monkey on each item
  vector<int> test; //stores the divisibility test
  vector<pair<int, int>> options; //stores where the monkey throws the item to

  // parsing the data
  while (getline(cin, str)) {
    if (str[0] == 'M') { //this is a monkey
      // first line of monkey is the starting item
      getline(cin, str);
      stringstream s(str);
      string word;
      int cnt = 0;
      while (cnt < 2) {
        s >> word;
        cnt++;
      }
      vector<ll> tempItem;
      while (s >> word) {
        tempItem.push_back(stoi(word));
      }
      items.push_back(tempItem);

      //next is the operation
      getline(cin, str);
      stringstream s1(str);
      cnt = 0;
      while (cnt < 4) {
        s1 >> word;
        cnt++;
      }
      string tempOp;
      while (s1 >> word) {
        tempOp += word;
      }
      operation.push_back(tempOp);

      //next is the divisibility test;
      getline(cin, str);
      cnt = 0;
      stringstream s2(str);
      while (cnt < 4) {
        s2 >> word;
        cnt++;
      }
      s2 >> word;
      test.push_back(stoi(word));

      //next are the two options
      getline(cin, str);
      int op1 = str.back() - '0';
      getline(cin, str);
      int op2 = str.back() - '0';
      options.push_back(make_pair(op1, op2));
    }
  }
  int monkeys = items.size();
  vector<ll> inspection(monkeys, 0ll);

  for (int round = 1; round <= 20; round++) {
    for (int i = 0; i < monkeys;  i++) {
      inspection[i] += items[i].size();
      for (int j = 0; j < items[i].size(); j++) {
        if (operation[i].substr(1) == "old") {
          switch (operation[i][0]) {
          case '+':
            items[i][j] += items[i][j];
            break;
          case '-':
            items[i][j] -= items[i][j];
            break;
          case '*':
            items[i][j] *= items[i][j];
            break;
          case '/':
            items[i][j] /= items[i][j];
            break;
          }
          items[i][j] /= 3;
          if (items[i][j] % test[i]) {
            items[options[i].second].push_back(items[i][j]);
          }
          else {
            items[options[i].first].push_back(items[i][j]);
          }
        }
        else {
          switch (operation[i][0]) {
          case '+':
            items[i][j] += stoi(operation[i].substr(1));
            break;
          case '-':
            items[i][j] -= stoi(operation[i].substr(1));
            break;
          case '*':
            items[i][j] *= stoi(operation[i].substr(1));
            break;
          case '/':
            items[i][j] /= stoi(operation[i].substr(1));
            break;
          }
          items[i][j] /= 3;
          if (items[i][j] % test[i]) {
            items[options[i].second].push_back(items[i][j]);
          }
          else {
            items[options[i].first].push_back(items[i][j]);
          }
        }
      }
      items[i].clear();
    }
  }
  sort(inspection.rbegin(), inspection.rend());
  ll ans = inspection[0] * inspection[1];
  cout << ans;
}
