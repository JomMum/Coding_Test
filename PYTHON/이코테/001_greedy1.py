n = int(input())
coin_types = [500, 100, 50, 10]
result = 0

for coin in coin_types:
    result += n // coin
    n %= coin

print(result)