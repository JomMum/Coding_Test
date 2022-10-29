#include <iostream>
#include <vector>
#include <algorithm>

// 이진 탐색: 떡볶이 떡 만들기
int main() {
  int n, m; //떡의 개수(n)과 떡의 길이(m)
  std::vector<int> dduk;
  int result = 0;

  /*  입력 받기  */
  std::cin >> n >> m;
  for(int i=0; i<n; i++) {
    int x;
    std::cin >> x;
    dduk.push_back(x);
  }

  std::sort(dduk.begin(), dduk.end()); //떡을 길이별로 정렬
  
  int start = 0;                 //떡의 시작 길이 저장
  int end = dduk[dduk.size()-1]; //가장 긴 떡의 끝 길이 저장
  int mid;                       //가장 긴 떡의 중간 길이 저장

  /*  이진 탐색 수행  */
  while(start <= end) { //시작점과 끝점이 같아질 때까지(모든 길이를 탐색할 때까지) 반복
    int total = 0;           //잘린 떡의 총 길이
    mid = (start + end) / 2; //중간 길이 초기화

    //잘린 떡의 총 길이 저장
    for(int i=0; i<dduk.size(); i++) {
      if(dduk[i] - mid > 0) //만약 해당 떡이 목표 길이(중간 길이)보다 길 시
        total += dduk[i] - mid; //자른 값을 저장
    }

    if(total < m) //만약 잘린 떡의 총 길이가 목표 길이보다 작을 시
    {
      end = mid - 1; //끝값 재조정
    }
    else if(total > m) //만약 잘린 떡의 총 길이가 목표 길이보다 클 시
    {
      result = mid; //목표 길이와 일치하지 않으면 해당 값을 반환
      start = mid + 1; //시작값 재조정
    }
    else //만약 잘린 떡의 총 길이가 목표 길이와 일치할 시
    {
      result = mid; //해당 값 반환
      break;
    }
  }

  std::cout << result;
}