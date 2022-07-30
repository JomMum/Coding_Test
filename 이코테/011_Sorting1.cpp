#include <iostream>
#include <algorithm>
#include <vector>

// 정렬: 두 배열의 원소 교체
int main() {
  int n, k; //n: 배열의 원소 개수, k: 바꿔치기 연산 수행 가능 횟수
  std::vector<int> arrA, arrB;
  int result = 0;
  
  std::cin >> n >> k;

  //값 입력받기
  for(int i=0; i<n; i++) {
    int x;
    std::cin >> x;
    arrA.push_back(x);
  }
  for(int i=0; i<n; i++) {
  int x;
  std::cin >> x;
  arrB.push_back(x);
  }

  //두 배열 정렬
  sort(arrA.begin(), arrA.end());
  sort(arrB.begin(), arrB.end());

  //바꿔치기 연산 수행
  for(int i=0; i<k; i++) {
    //arrA의 최솟값이 arrB의 최댓값보다 작을 때에만 바꿔치기 연산 수행
    if(arrA[i] < arrB[arrB.size() - 1 - i])
      std::swap(arrA[i], arrB[arrB.size() - 1 - i]); //A 배열의 최솟값과 B 배열의 최댓값 swap
    //arrA의 최솟값이 arrB의 최댓값보다 클 시에는 다음 반복문에도 마찬가지일 것이므로 반복문 탈출
    else
      break;
  }

  //A 배열의 최댓값 구하기
  for(int i=0; i<arrA.size(); i++) {
    result += arrA[i]; //A 배열의 모든 값 더하기
  }

  std::cout << result;
}