#include <iostream>
#include <queue>
#include <utility>

// DFS & BFS: 미로 탈출

int maze[201][201];
int n, m; //미로의 가로 길이(n)와 세로 길이(m)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int findExit(int x, int y) {
  std::queue<std::pair<int, int>> q;
  q.push({x, y});

  while(!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();

    //현재 위치로부터 4방향 위치 확인
    for(int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      //만약 목표 위치가 미로의 범위를 벗어났을 시 즉시 반환
      if(nx < 0 || nx >= n ||
        ny < 0 || ny >= m)
        continue;
        
      //만약 목표 위치가 용이 있는 위치일 시 즉시 반환
      if(maze[nx][ny] == 0)
        continue;

      //만약 목표 위치가 용이 없는 위치일 시
      if(maze[nx][ny] == 1) {
        maze[nx][ny] = maze[x][y] + 1; //다음 위치에 지금까지의 이동 거리를 저장
        q.push({nx, ny}); //다음 위치로 이동
      }
    }
  }

  //목표 위치에 저장된 지금까지의 이동 거리를 반환
  return maze[n-1][m-1];
}

int main() {
  /*  입력 받기  */
  std::cin >> n >> m;

  for(int i=0; i<n; i++) { //가로
    for(int j=0; j<m; j++) { //세로
      scanf("%1d", &maze[i][j]);
    }
  }

  /* 최단 거리 구하기 */
  std::cout << findExit(0, 0);
}