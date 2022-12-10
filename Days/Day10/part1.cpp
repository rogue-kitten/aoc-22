#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void checkSig(int cycle,int reg, int &sigStr){

  for(int i = 20; i <= 2200; i+=40){
    if(i == cycle){
      sigStr += (cycle*reg);
      return;
    }
  }
}

int main(){
  string temp;
  int reg = 1, cycle = 1, sigStr = 0;
  while(getline(cin, temp)){
    if(temp == "noop"){
      cycle++;
    } 
    else {
      int x = stoi(temp.substr(5));
      cycle++;
      checkSig(cycle,reg, sigStr); 
      cycle++;
      reg += x;
    }
    checkSig(cycle,reg, sigStr);
  }
  cout << sigStr;
}
