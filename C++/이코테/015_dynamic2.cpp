#include <iostream>
#include <vector>

//다이나믹 프로그래밍: 1로 만들기
int main() {
  int x;
  int memo[30001];

  std::cin >> x;

  for(int i=2; i<=x; i++) {
    //현재 수에서 1을 뺀 경우
    memo[i] = memo[i - 1] + 1;

    //현재 수가 2로 나눠떨어지는 경우
    //1을 뺀 값 or 2로 나눈 값 중 최솟값을 저장
    if(i % 2 == 0)
      memo[i] = std::min(memo[i], memo[i/2]+1);
    
    //현재 수가 3으로 나눠떨어지는 경우
    //1을 뺀 값 or 3으로 나눈 값 중 최솟값을 저장
    if(i % 3 == 0)
      memo[i] = std::min(memo[i], memo[i/3]+1);
    
    //현재 수가 5로 나눠떨어지는 경우
    //1을 뺀 값 or 5로 나눈 값 중 최솟값을 저장
    if(i % 5 == 0)
      memo[i] = std::min(memo[i], memo[i/5]+1);
  }

  std::cout << memo[x];
}