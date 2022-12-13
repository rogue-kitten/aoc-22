#include<iostream>
#include<string>
#include<vector>
#include<numeric>

using namespace std;

bool isNumeric(char a){
  return (a >= '0' && a <= '9');
}

int main(){

  string line1, line2;
  vector<int> right;
  int list = 0;
  while(getline(cin,line1)){
    if(line1.length() == 0) continue;
    list++;
    getline(cin, line2);
    int i = 0, j = 0;
    while(i < line1.length() && j < line2.length()){
      if(isNumeric(line1[i]) && isNumeric(line2[j])){
        string x1 = "", x2 = "";
        while(i < line1.length() && isNumeric(line1[i])){
          x1 += line1[i];
          i++;
        }
        while(j < line2.length() && isNumeric(line2[j])){
          x2 += line2[j];
          j++;
        }
        if(stoi(x1) == stoi(x2)) continue;
        if(stoi(x1) < stoi(x2))
          right.push_back(list);
        break;
      }
      if(line1[i] == line2[j]){
        i++;
        j++;
        continue;
      }
      else{
        if(line1[i] == ']'){
          right.push_back(list);
          break;
        }
        else if(line2[j] == ']') break;
        else if(line1[i] == '[' || line1[i] == ','){ 
            i++;
            continue;
        }
        else if(line2[j] == '[' || line2[j] == ','){
            j++;
            continue;
          }
      }
    }
    if(i == line1.length()) right.push_back(list);
  }
  int ans = 0;
  cout << accumulate(right.begin(), right.end(), ans) << endl;
}
