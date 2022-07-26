#include <iostream>

//거스름돈
int main() {
  int cost = 1260;
  int count = 0;

  int money[4] = {500, 100, 50, 10};

  for (int i = 0; i < 4; i++) {
    count++;          //동전 개수 ++
    cost %= money[i]; //가장 큰 값부터 나눠나감

    //만약 전부 거슬러줬을 시 반환
    if (cost == 0)
      break;
  }

  std::cout << count;
}