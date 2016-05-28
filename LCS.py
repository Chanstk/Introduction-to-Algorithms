
def LCS_LENGTH(X, Y):
    m = len(X)
    n = len(Y)
    c = []
    b = []
    for i in range((m + 1)):
        c.append([0] * (n + 1))
        b.append([0] * (n + 1))
    for i in range(m + 1)[1:]:
        for j in range(n + 1)[1:]:
            if X[i - 1] == Y[j - 1]:
                c[i][j] = c[i - 1][j - 1] + 1
                b[i][j] = 'c'
            elif c[i - 1][j] >= c[i][j - 1]:
                c[i][j] = c[i - 1][j]
                b[i][j] = 'u'
            else:
                c[i][j] = c[i][j - 1]
                b[i][j] = 'l'
    return b, c


def printLCS(b, X, i, j):
    if i == 0 or j == 0:
        return
    if b[i][j] == 'c':
        printLCS(b, X, i - 1, j - 1)
        print X[i - 1]
    elif b[i][j] == 'u':
        printLCS(b, X, i - 1, j)
    else:
        printLCS(b, X, i, j - 1)


def main():
    X = ['A', 'B', 'C', 'B', 'D', 'A', 'B']
    Y = ['B', 'D', 'C', 'A', 'B', 'A']
    b, c = LCS_LENGTH(X, Y)
    printLCS(b, X, len(X), len(Y))
if __name__ == '__main__':
    main()
