#include<bits/stdc++.h>

using namespace std;
#define mp make_pair

bool isPossible(int row, int col, int n, int m){
  return !(row >= n || col >= m || row < 0 || col < 0);
}

int main(){

  string line;
  vector<string> grid;
  while(getline(cin, line)){
    grid.push_back(line);
  }

  int n = grid.size(), m = grid[0].size();
  pair<int, int> end;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(grid[i][j] == 'E') {
        end = mp(i,j);
        grid[i][j] = 'z';
      }
    }
  }
  
  queue<pair<int, pair<int, int>>> q;
  vector<vector<bool>> visited(n, vector<bool>(m,false));
  visited[end.first][end.second] = true;

  q.push(mp(0, end));
  while(!q.empty()){
    int dist = q.front().first;
    int row = q.front().second.first;
    int col = q.front().second.second;
    q.pop();
    
    if(grid[row][col] == 'a') {
      cout << dist;
      return 0;
    }

    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};

    for(int i = 0; i < 4; i++){
      if(isPossible(row + dx[i], col + dy[i], n, m) && !visited[row + dx[i]][col + dy[i]]){
        char prev = grid[row + dx[i]][col + dy[i]] == 'S' ? 'a' : grid[row + dx[i]][col + dy[i]];
        if(grid[row][col] - prev <=1){
          visited[row + dx[i]][col + dy[i]] = true;
          q.push(mp(dist + 1, mp(row + dx[i], col + dy[i])));
        }
      }
    }
  }
  cout << "Not reached" << endl;
}
