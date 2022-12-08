#include<iostream>
#include<fstream>
#include<string>
#include<vector>

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

  int ans = 2*row + 2*col - 4;

  for(int i = 1; i < row - 1; i++){
    //from left to right
    char maxi = map[i][0];
    for(int j = 1; j < col - 1; j++){
      if(map[i][j] > maxi){
        maxi = map[i][j];
        visited[i][j] = true;
        ans++;
      }
    }

    //right to left
    maxi = map[i][col - 1];
    for(int j = col - 2; j > 0; j--){
      if(map[i][j] > maxi){
        maxi = map[i][j];
        if(!visited[i][j]){
          visited[i][j] = true;
          ans++;
        }
      }
    }

  }

  for(int j = 1; j < col - 1; j++){
    char maxi = map[0][j];
    //top to bottom
    for(int i = 1; i < row - 1; i++){
      if(map[i][j] > maxi){
        maxi = map[i][j];
        if(!visited[i][j]){
          visited[i][j] = true;
          ans++;
        }
      }
    }

    //bottom to top
    maxi = map[row - 1][j];
    for(int i = row - 2; i > 0; i--){
      if(map[i][j] > maxi){
        maxi = map[i][j];
        if(!visited[i][j]){
          visited[i][j] = true;
          ans++;
        }
      }
    }
  }

  cout << ans;
}
