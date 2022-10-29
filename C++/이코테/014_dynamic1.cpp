#include <iostream>
#include <vector>

//다이나믹 프로그래밍: 개미 전사
int main() {
  int n; //식량창고의 개수
  int memo[100]; //식량창고 값에 대해 저장
  std::vector<int> vec;

  /*  입력 받기  */
  std::cin >> n;
  for(int i=0; i<n; i++) {
    int x;
    std::cin >> x;
    vec.push_back(x);
  }

  memo[0] = vec[0]; //첫 번째 값 메모
  memo[1] = std::max(vec[0], vec[1]); //첫 번째와 두 번째 중, 효율이 좋은 식량창고 인덱스를 메모

  for(int i=2; i<n; i++) {
    //한 칸 전 식량창고 or 현재 식량창고 + 두 칸 전 식량창고 중 효율 좋은 식량창고 인덱스를 메모
    memo[i] = std::max(memo[i-1], memo[i-2] + vec[i]);
  }

  //위를 반복하여 가장 효율 좋은 식량창고의 총 값이 n-1에 저장됨
  std::cout << memo[n-1];
}