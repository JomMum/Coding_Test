n = int(input())
plans = input().split()

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
move_types = ['L', 'R', 'U', 'D']

result_x = 1
result_y = 1

# 이동 계획 확인
for plan in plans:
    for i in range(len(move_types)):
        if plan == move_types[i]:
            # 해당 방향으로 이동
            nx = result_x + dx[i]
            ny = result_y + dy[i]
            # 범위를 벗어나지 않으면 해당 좌표 저장
            if nx >= 1 and nx <= n and ny >= 1 and nx <= n:
                result_x, result_y = nx, ny

print(result_y, result_x)