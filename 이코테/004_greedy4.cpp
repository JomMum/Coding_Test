#include <iostream>
#include <algorithm>
#include <vector>

//모험가 길드
int n;
std::vector<int> fear;
int result = 0; //편성된 총 팀 수
int count = 0;  //현재 팀에 포함된 모험가 수

int main() {
  //값 받아오기
  std::cin >> n;
  for(int i=0; i<n; i++) {
    //모험가의 공포도를 fear 벡터에 저장
    int x;
    std::cin >> x;
    fear.push_back(x);
  }
  
  //오름차순 정렬
  std::sort(fear.begin(), fear.end());

  for(int i=0; i< fear.size(); i++)
  {
    count++; //팀원 수 ++

    //만약 해당 모험가의 공포도가 현재 편성된 팀원의 수와 같을 시
    if(fear[i] <= count) {
      result++; //편성된 팀 수 ++
      count = 0; //팀원 수 초기화
    }
  }

  std::cout << result;
}