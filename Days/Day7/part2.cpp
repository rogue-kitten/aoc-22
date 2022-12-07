
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
  string line;
  vector<string> path;
  unordered_map<string, int> size;
  while(getline(cin, line)){
    if(line[0] == '$'){ //this is a command
      if(line.substr(2,2) == "cd"){
        if(line.substr(5) == "..") path.pop_back();
        else path.push_back(line.substr(5));
      }
    }
    else if(line[0] != 'd'){ //this would be a file
      int fileSize = 0;
      for(char x : line){
        if(x >= '0' && x <= '9'){
          fileSize = 10*fileSize + (x - '0');
        }
        else break;
      }
      // we need to add the size of this file to all the directories in the path
      string currPath = "";
      for(string dir : path){
        currPath += ('/' + dir);
        size[currPath] += fileSize;
    }
  }
 }
 int maxUsed = 70000000 - 30000000;
 int systemSize = size["//"];
 cout << systemSize << endl;
 int minFileSize = systemSize - maxUsed;
 int ans = 1e9;
 for(auto x : size){
   if(x.second >= minFileSize)
     ans = min(ans, x.second);
 }
 cout << ans;
}
