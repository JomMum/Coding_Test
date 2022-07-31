#include <iostream>

//2292 벌집
int main() {
  int target;
  int maxNum = 1; //해당 벌집 라인의 최대 값 (시작값은 1)
  int result = 0;
  
  std::cin >> target;

  while(true) {
    result++; //라인을 넘을 때마다 거리 ++

    //만약 목적지가 해당 벌집 라인에 속해 있을 시 반환
    if(target <= maxNum) {
      break;
    }

    maxNum += 6 * result; //벌집 라인의 최대값 = 6 * 거리
  }

  std::cout << result;
}