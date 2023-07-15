# Solution 1
dic = {
    1:"I", 4:"IV", 5:"V", 9:"IX", 10:"X", 40:"XL", 50:"L", 90:"XC", 100:"C", 400:"CD", 500:"D", 900:"CM", 1000:"M"
}

def convert(n):
    if n == 0: return ""
    m = max([x for x in dic if x <= n])
    return dic[m] + convert(n - m)

print(convert(int(input())))

# Solution 2
roman = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
arabic = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
n = int(input())
res = ''
for i in range(len(roman)):
    while n >= arabic[i]:
        n -= arabic[i]
        res += roman[i]
print(res)

# Solution 3
d = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}
n = int(input())
for i in d:
    if n // i != 0:
        print(d[i]*(n // i), end='')
        n %= i