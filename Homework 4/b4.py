def extended_euclid(a, m):
    s, t, r = 0, 1, m
    old_s, old_t, old_r = 1, 0, a
    while r != 0:
        q = old_r // r
        old_r, r = r, old_r - q * r
        old_s, s = s, old_s - q * s
        old_t, t = t, old_t - q * t
    if old_r == 1:
        return old_s % m
    else:
        return None

