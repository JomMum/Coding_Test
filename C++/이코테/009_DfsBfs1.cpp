#include <iostream>

// DFS & BFS: 음료수 얼려 먹기
int ice[1001][1001]; //얼음 틀의 얼음 정보
int n, m; //얼음 틀의 세로(n) 가로(m) 길이
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool findIcecream(int x, int y) {
  //얼음 틀을 벗어났을 시 즉시 반환
  if(x < 0 || x >= m ||
    y < 0 || y >= n)
    return false;
  
  //만약 해당 위치에 얼음이 있다면
  if (ice[x][y] == 0) {
    ice[x][y] = 1; //탐색 완료
    
    // 4방향에 연결된 얼음이 있는지 확인
    for (int i = 0; i < 4; i++) {
      findIcecream(x + dx[i], y + dy[i]);
    }
    return true;
  }
  //만약 해당 위치에 얼음이 없다면
  else {
    return false;
  }
}

int main() {
  int result = 0;

  /* 값 입력받기  */
  std::cin >> n >> m;

  for (int i = 0; i < n; i++) { //세로
    for (int j = 0; j < m; j++) { //가로
      scanf("%1d", &ice[j][i]); //한 줄마다 한 문자만 입력받기 위해선 다음과 같이 작성해야 함
    }
  }

  
  /*  연결된 얼음의 개수 찾기  */
  for (int i = 0; i < n; i++) { //세로 
    for (int j = 0; j < m; j++) { //가로
      //연결된 얼음의 계산이 끝나면 결과값 ++
      if (findIcecream(j, i))
        result++;
    }
  }

  std::cout << result;
}