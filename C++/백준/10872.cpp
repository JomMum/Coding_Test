#include <iostream>

//10872 팩토리얼
int factorial(int value) {
  //종료조건: 값이 1 이하일 시
  if(value <= 1)
    return 1;

  //정의: 현재 값에서부터 1까지의 곱을 반환
  return value * factorial(value-1);
}

int main() {
  int num;

  std::cin >> num;
  std::cout << factorial(num);
}