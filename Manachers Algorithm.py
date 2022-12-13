def manacherAlg(s:str) -> str:
    T = '#'.join('^{}$'.format(s))
    n = len(T)

    P = [0]*n
    C = 0
    R = 0

    for i in range(1, n-1):
        P[i] = (R > i) and min(R-i, P[2*C - i])

        while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
            P[i] += 1

        if i + P[i] > R:
            C = i
            R = i + P[i]
        
    maxLen, cenIdx = max((n, i) for i, n in enumerate(P))

    return s[(cenIdx - maxLen)//2:(cenIdx + maxLen)//2]

s = "babad"
val = manacherAlg(s)
print(val)
