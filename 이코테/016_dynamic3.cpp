#include <iostream>
#include <vector>

//다이나믹 프로그래밍: 효율적인 화폐 구성
int main() {
  int n, m; //화폐의 종류(n)와 가치의 합(m)
  std::vector<int> vec;
  int memo[10001];
  int result = 0;

  /*  입력 받기  */
  std::cin >> n >> m;
  for(int i=0; i<n; i++) {
    int x;
    std::cin >> x;
    vec.push_back(x);
  }

  memo[0] = 0;
  for(int i=0; i<n; i++) { //화폐 개수만큼 반복
    for(int j=vec[i]; j <= m; j++) { //목표 금액만큼 반복
      if(memo[j-vec[i]] != 10001) //(i - k원을 만드는 방법이 존재할 시)
        //해당 금액 or 해당 금액 - 특정 화폐(k) 중 최솟값을 선택
        memo[j] = std::min(memo[j], memo[j - vec[i]] +1);
    }
  }

  //만약 해당 금액을 만들 수 없을 시 -1 출력
  if(memo[m] == 10001)
    std::cout << -1;
  //만약 해당 금액을 만들 수 있을 시 화폐의 최솟값 출력
  else
    std::cout << memo[m];
}