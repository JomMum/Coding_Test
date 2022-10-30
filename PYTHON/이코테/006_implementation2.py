n = int(input())
result = 0

# 시 계산
for i in range(n + 1):
    # 분 계산
    for j in range(60):
        # 초 계산
        for k in range(60):
            if '3' in str(i) + str(j) + str(k):
                result += 1
                continue

print(result)
