#include <iostream>
#include <string>

//상하좌우
int main() {
  //동 서 남 북
  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  //시작 위치는 [1, 1]
  int x = 1;
  int y = 1;

  int n; //정사각형 공간의 크기
  std::string str; //문자열

  //문자열 받아오기
  std::cin >> n; //공간 크기
  std::cin.ignore();
  getline(std::cin, str); //계획서

  for(int i=0; i<str.length(); i++) {
    int targetX;
    int targetY;

    //입력한 문자에 맞게 목표 위치 찾기
    switch(str[i]) {
      case 'L':
        targetX = x + dx[1];
        targetY = y + dy[1];
      break;
      case 'R':
        targetX = x + dx[0];
        targetY = y + dy[0];
      break;
      case 'U':
        targetX = x + dx[3];
        targetY = y + dy[3];
      break;
      case 'D':
        targetX = x + dx[2];
        targetY = y + dy[2];
      break;
    }

    //정사각형 공간의 범위를 넘어가지 않았을 시에만 이동 변경 사항 적용
    if((targetX >= 1 && targetX <= n) && 
       (targetY >= 1 && targetY <= n)) {
      x = targetX;
      y = targetY;
    }
  }

  //문제에서는 [세로 좌표, 가로 좌표]의 형태로 출력하라고 나옴
  std::cout << "[" << y << ", " << x << "]";
}