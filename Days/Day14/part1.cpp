#include<iostream>
#include<string>
#include<unordered_map>
#include<chrono>

using namespace std;
using namespace std::chrono;

int main(){
  auto start = high_resolution_clock::now();
  string line;
  unordered_map<int, unordered_map<int, bool>> grid;
  int maxY = -1e9;
  while(getline(cin, line)){
    int i = 0, prevX = 0, prevY = 0;
    while(i < line.length()){
      while(!isdigit(line[i])) i++;
      int x = 0, y = 0;
      while(isdigit(line[i])){
        x = 10*x + line[i] - '0';
        i++;
      }
      i++;
      while(isdigit(line[i])){
        y = 10*y + line[i] - '0';
        i++;
      }
      grid[x][y] = true;
      if(prevX && prevY){
        if(prevX == x){
          for(int i = min(prevY,y); i <= max(prevY, y); i++){
            grid[x][i] = true;
          }
        }
        else{
          for(int i = min(prevX,x); i <= max(prevX, x); i++){
            grid[i][y] = true;
          }
        }
      }
      prevX = x;
      prevY = y;
      maxY = max(y, maxY);
    }
  }
  int x = 500, y = 0;
  int grains = 0;

  while(grid.find(x) != grid.end()){
    if(y == maxY) break;
    //check down
    if(grid[x].find(y + 1) == grid[x].end()){
      y++;
      continue;
    }
    //check down left
    if(grid.find(x-1) == grid.end()) break;

    if(grid[x-1].find(y+1) == grid[x-1].end()){
      x--;
      y++;
      continue;
    }

    //check down left
    if(grid.find(x+1) == grid.end()) break;

    if(grid[x+1].find(y+1) == grid[x+1].end()){
      x++;
      y++;
      continue;
    }

    //set the sand to this position if there is no else to go
    grid[x][y] = true;
    grains++;
    x = 500;
    y = 0;
  }
  cout << grains << endl;
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time:" << duration.count() << " microseconds";
    
}
