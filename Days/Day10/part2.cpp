#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

void renderSig(int reg, int &crt){
  if(crt == 40){
    cout << endl;
    crt = 0;
  }
  if(crt == reg - 1 || crt == reg || crt == reg + 1)
    cout << "#";
  else cout << " ";
}

int main(){
  string temp;
  int reg = 1, crt = 0;
  renderSig(reg,crt);
  while(getline(cin, temp)){
    if(temp == "noop"){
      crt++;
    } 
  else {
      int x = stoi(temp.substr(5));
      crt++;
      renderSig(reg, crt);
      crt++;
      reg += x;
    }
    renderSig(reg, crt);
  }
}
