#include <iostream>

// 1이 될 때까지
int main() {
  int n = 17;
  int k = 4;
  int count = 0;

  // 1이 아닐 시 반환
  while (n != 1) {
    //만약 k로 나누어 떨어지면 나누기
    if (n % k == 0)
      n /= k;
    //만약 아닐 시 1 빼기
    else
      n--;

    //횟수 ++
    count++;
  }

  std::cout << count;
}