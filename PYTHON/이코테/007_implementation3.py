position = input()

x_types = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
dx = [2, 2, -2, -2, 1, -1, 1, -1]
dy = [1, -1, 1, -1, 2, 2, -2, -2]

result = 0

# 현재 좌표 구하기
for i in range(len(x_types)):
    if x_types[i] in position[0]:
        x_position = i + 1
y_position = int(position[1])

# 이동 가능한 경우의 수 구하기
for i in range(len(dx)):
    nx = x_position + dx[i]
    ny = y_position + dy[i]
    # 범위를 벗어나지 않았을 시 이동 가능
    if nx >= 1 and nx <= len(x_types) and ny >= 1 and ny <= len(x_types):
        result += 1

print(result)