#include <iostream>

//10870 피보나치
int fibonacci(int value) {
  //종료조건: 0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다
  //        => 2 이하일 경우 반환값은 해당 값과 같다
  if(value < 2)
    return value;
  
  //정의: Fn = Fn-1 + Fn-2
  return fibonacci(value - 1) + fibonacci(value - 2);
}

int main() {
  int num;

  std::cin >> num;
  std::cout << fibonacci(num);
}