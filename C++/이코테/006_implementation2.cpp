#include <iostream>

//시각
bool check(int hour, int min, int sec) {
  // **n % 10은 1의 자리 수를 찾는 방법,
  //   n / 10은 10의 자리 수를 찾는 방법이다**
  if(hour % 10 == 3 ||
    min / 10 == 3 || min % 10 == 3 ||
    sec / 10 == 3 || sec % 10 == 3)
    return true;
  return false;
}

int main() {
  int hour, result;

  //시간 입력 받기
  std::cin >> hour;

  //hour시 59분 59초까지 세야 하므로, 조건은 i <= hour
  for(int i=0; i <= hour; i++) {
    for(int j=0; j<60; j++) {
      for(int k=0; k<60; k++) {
        if(check(i, j, k)) //현재 시각을 매개변수로 전달
          result++;
      }
    }
  }

  std::cout << result;
}