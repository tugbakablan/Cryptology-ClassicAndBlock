def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a
def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    else:
        gcd, x1, y1 = extended_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return gcd, x, y

result = gcd(3257,1400)
if result == 1:
    print("a) ",extended_gcd(3257, 1400))
    print("b) ",extended_gcd(1400, 3257))
