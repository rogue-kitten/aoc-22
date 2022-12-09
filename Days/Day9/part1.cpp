#include<iostream>
#include<fstream>
#include<set>

using namespace std;
#define mp make_pair

set<pair<int, int>> tailPos;

void checkTailPos(pair<int, int>&head, pair<int, int> &tail){
  //both are at the same position
  if(head == tail){
    tailPos.insert(tail);
    return;
  }

  //both are adjacent on the same row/col
  else if(head.first == tail.first && abs(head.second - tail.second) == 1){
    tailPos.insert(tail);
    return;
  }
  else if(head.second == tail.second && abs(head.first - tail.first) == 1){
    tailPos.insert(tail);
    return;
  }

  // both are on the same row/col, with a dist of 2.
  else if(head.first == tail.first){
    if(tail.second > head.second){
      tail = mp(tail.first, tail.second - 1);
      tailPos.insert(tail);
      return;
    }
    else {
      tail = mp(tail.first, tail.second + 1);
      tailPos.insert(tail);
      return;
    }
  }
  else if(head.second == tail.second){
    if(tail.first > head.first){
      tail = mp(tail.first - 1, tail.second);
      tailPos.insert(tail);
      return;
    }
    else{
      tail = mp(tail.first + 1, tail.second);
      tailPos.insert(tail);
      return;
    }
  }

  //if they are at adjacent diagonals
  else if(abs(head.first - tail.first) == 1 && abs(head.second - tail.second) == 1){
    tailPos.insert(tail);
    return;
  }

  //non adjacent 
  else if(abs(head.first - tail.first) == 1){
    if(tail.second > head.second){
      tail = mp(head.first, tail.second - 1);
      tailPos.insert(tail);
      return;
    }
    else{
      tail = mp(head.first, tail.second + 1);
      tailPos.insert(tail);
      return;
    }
  }
  else if(abs(head.second - tail.second) == 1){
    if(tail.first > head.first){
      tail = mp(tail.first - 1, head.second);
      tailPos.insert(tail);
      return;
    }
    else{
      tail = mp(tail.first + 1, head.second);
      tailPos.insert(tail);
      return;
    }
  }
 }

int main(){
  pair<int, int> tail, head; // x and y coordinates of the tail and the head
  tail = mp(0, 0);
  tailPos.insert(tail);
  head = mp(0,0);
  string line;
  while(getline(cin, line)){
    char direction =line[0];
    int steps = 0;
    for(int i = 2; i < line.length(); i++){
      steps = 10*steps + (line[i] - '0');
    }
    if(direction == 'U'){
      while(steps > 0){
        head = mp(head.first, head.second + 1);
        steps--;
        checkTailPos(head, tail);
      }
    }
    else if(direction == 'D'){
      while(steps > 0){
        head = mp(head.first, head.second - 1);
        steps--;
        checkTailPos(head, tail);
      }
    }
    else if(direction == 'R'){
      while(steps > 0){
        head = mp(head.first + 1, head.second);
        steps--;
        checkTailPos(head, tail);
      }
    }
    else if(direction == 'L'){
      while(steps > 0){
        head = mp(head.first - 1, head.second);
        steps--;
        checkTailPos(head, tail);
      }
    }
  }
  cout << tailPos.size();
}
