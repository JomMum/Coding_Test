#include <iostream>
#include <vector>
#include <algorithm>

// 이진 탐색: 정렬된 배열에서 특정 수의 개수 구하기
int main() {
  int n, x; //원소의 개수(n)과 찾으려는 원소의 값(x)
  std::vector<int> vec;
  int result;

  /*  입력 받기  */
  std::cin >> n >> x;
  for(int i=0; i<n; i++) {
    int a;
    std::cin >> a;
    vec.push_back(a);
  }

  //만약 찾으려는 원소가 존재하지 않을 시 (find()의 반환값이 vec.end()일 시 존재하지 않는다)
  if(find(vec.begin(), vec.end(), x) == vec.end()) {
    result = -1;
  }
  else {
    //x를 초과하는 원소의 인덱스 값 - x보다 작은 원소의 인덱스 값 = x 원소의 개수
    result = (upper_bound(vec.begin(), vec.end(), x) - vec.begin()) -           (lower_bound(vec.begin(), vec.end(), x) - vec.begin()); 
  }

  std::cout << result;
}