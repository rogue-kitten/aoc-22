#include<iostream>
#include<string>
#include<map>

using namespace std;
#define ll long long
#define mp make_pair


int main(){
  string line, parent;
  map< pair<int, string>, ll> sizeOfDir;
  map< pair<int, string>, pair<int, string> > parentOf;
  int level = 0;
  while(getline(cin, line)){
    if(line[0] == '$'){ //this is a command
      string command;
      if(line.substr(2,2) == "cd"){
        string dir = line.substr(5);
        if(dir[0] !='.'){
          level++;
          parent = dir;
        }
        else level--;
      }
    }
      
    else{ // would be the output when the user does ls
      if(line[0] == 'd'){
        //setting the parent
        parentOf[mp(level+1,line.substr(4))] = mp(level,parent);
      }
      else{
        //adding the files to their resp parent dirs
        ll size = 0;
        for(char x : line){
          if(x >= '0' && x <= '9'){
            size = 10*size + (x - '0');
          }
          else break;
        }
        sizeOfDir[mp(level, parent)] += size;
      }
    }
  }

  map< pair<int, string>, pair<int, string> >::reverse_iterator it;
  for(it = parentOf.rbegin(); it != parentOf.rend(); it++){
    sizeOfDir[it->second] += sizeOfDir[it->first];
  }
  ll ans = 0;

  for(auto x : sizeOfDir){
    cout << x.first.first << " " << x.first.second << " " << x.second << endl;
    if(x.second <= 100000) ans += x.second;
  }

  cout << "ans: " << ans << endl;
}
