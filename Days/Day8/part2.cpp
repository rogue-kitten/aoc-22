#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

int main(){
  
  string line;
  vector<string> map;
  while(getline(cin, line)){
    map.push_back(line);
  }
  
  int row = map.size();
  int col = map[0].length();
  vector<vector<bool>> visited(row, vector<bool>(col, false));

  int ans = 0;

  for(int i = 1; i < row - 1; i++){
    for(int j = 1; j < col - 1; j++){
      int left = 0, right = 0, top = 0, bottom = 0;
      for(int x = j - 1; x >= 0; x--){
        if(map[i][x] >= map[i][j]){
          left++;
          break;
        }
        left++;
      }
      for(int x = j + 1; x < col; x++){
        if(map[i][x] >= map[i][j]){
          right++;
          break;
        }
        right++;
      }
      for(int x = i - 1; x >= 0; x--){
        if(map[x][j] >= map[i][j]){
          top++;
          break;
        }
        top++;
      }
      for(int x = i + 1; x < row; x++){
        if(map[x][j] >= map[i][j]){
          bottom++;
          break;
        }
        bottom++;
      }
      ans = max(ans, top*bottom*left*right);
    }
  }

   cout << ans;
}
