#include <iostream>
#include <string>

//왕실의 나이트
int main() {
  int result = 0;
  std::string answer;
  
  // 우2상, 우2하, 좌2상, 좌2하, 상2우, 하2우, 상2좌, 하2좌
  int dx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
  int dy[8] = {1, -1, 1, -1, 2, -2, 2, -2};

  //행과 열 입력 받기
  std::cin >> answer;

  //행과 열 저장
  int column = answer[0] - 'a' + 1; //열 (a = 1이므로 1을 더해줌)
  int row = answer[1] - '0';        //행

  //이동 결과가 왕실의 정원 범위를 넘지 않았을 시 결과값 ++
  for(int i=0; i<8; i++) {
    if((column + dx[i] >= 1 && column + dx[i] <= 8) &&
       (row + dy[i] >= 1 && row + dy[i] <= 8))
      result++;
  }

  std::cout << result;
}