#include<iostream>
#include<fstream>
#include<set>
#include<vector>

using namespace std;
#define mp make_pair


void checkTailPos(pair<int, int>&head, pair<int, int> &tail){
  //both are at the same position
  if(head == tail){
    return;
  }

  //both are adjacent on the same row/col
  else if(head.first == tail.first && abs(head.second - tail.second) == 1){
    return;
  }
  else if(head.second == tail.second && abs(head.first - tail.first) == 1){
    return;
  }

  // both are on the same row/col, with a dist of 2.
  else if(head.first == tail.first){
    if(tail.second > head.second){
      tail = mp(tail.first, tail.second - 1);
      return;
    }
    else {
      tail = mp(tail.first, tail.second + 1);
      return;
    }
  }
  else if(head.second == tail.second){
    if(tail.first > head.first){
      tail = mp(tail.first - 1, tail.second);
      return;
    }
    else{
      tail = mp(tail.first + 1, tail.second);
      return;
    }
  }

  //if they are at adjacent diagonals
  else if(abs(head.first - tail.first) == 1 && abs(head.second - tail.second) == 1){
    return;
  }

  //non adjacent 
  else if(abs(head.first - tail.first) == 1){
    if(tail.second > head.second){
      tail = mp(head.first, tail.second - 1);
      return;
    }
    else{
      tail = mp(head.first, tail.second + 1);
      return;
    }
  }
  else if(abs(head.second - tail.second) == 1){
    if(tail.first > head.first){
      tail = mp(tail.first - 1, head.second);
      return;
    }
    else{
      tail = mp(tail.first + 1, head.second);
      return;
    }
  }
  // we need to move in along a diagonal which is the closest to the head.
  else {
    int x[4] = {1,1,-1,-1};
    int y[4] = {1,-1,1,-1};
    for(int i = 0; i < 4; i++){
      if(abs(tail.first + x[i] - head.first) == 1 && abs(tail.second + y[i] - head.second) == 1){
        tail = mp(tail.first + x[i], tail.second + y[i]);
        return;
      }
    }
  }
 }

int main(){
  set<pair<int, int>> tailPos;
  vector<pair<int, int>> rope;
  // initialising the rope.
  for(int i = 0; i < 10; i++){
    rope.push_back(mp(0,0));
  }
  tailPos.insert(mp(0,0));
  string line;
  while(getline(cin, line)){
    char direction =line[0];
    int steps = 0;
    for(int i = 2; i < line.length(); i++){
      steps = 10*steps + (line[i] - '0');
    }
    if(direction == 'U'){
      while(steps > 0){
        rope[0] = mp(rope[0].first, rope[0].second + 1);
        steps--;
        for(int i = 1; i < 10; i++){
          checkTailPos(rope[i-1], rope[i]);
        }
        tailPos.insert(rope[9]);
      }
    }
    else if(direction == 'D'){
      while(steps > 0){
        rope[0] = mp(rope[0].first, rope[0].second - 1);
        steps--;
        for(int i = 1; i < 10; i++){
          checkTailPos(rope[i-1], rope[i]);
        }
        tailPos.insert(rope[9]);
      }
    }
    else if(direction == 'R'){
      while(steps > 0){
        rope[0] = mp(rope[0].first + 1, rope[0].second);
        steps--;
        for(int i = 1; i < 10; i++){
          checkTailPos(rope[i-1], rope[i]);
        }
        tailPos.insert(rope[9]);
      }
    }
    else if(direction == 'L'){
      while(steps > 0){
        rope[0] = mp(rope[0].first - 1, rope[0].second);
        steps--;
        for(int i = 1; i < 10; i++){
          checkTailPos(rope[i-1], rope[i]);
        }
        tailPos.insert(rope[9]);
      }
    }
  }
  cout << tailPos.size();
}

