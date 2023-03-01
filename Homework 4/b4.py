def extendedEuclid(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        gcd, x1, y1 = extendedEuclid(b, a % b)
        x = y1
        y = x1 - y1 * (a // b)
        return (gcd, x, y)

def modInverse(a, m):
    gcd, x, y = extendedEuclid(a, m)
    if gcd != 1:
        return -1 
    else:
        return (x % m + m) % m 
