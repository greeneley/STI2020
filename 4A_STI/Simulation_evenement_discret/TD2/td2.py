class congruences_linaire:
    def __init__(self, x_0, a, c, m, N):
        self.x_0 = x_0
        self.a = a
        self.c = c
        self.m = m
        self.N = N

    def entier_aleatoire(self):
        X = []
        X.append(self.x_0)
        for n in range(1, self.N):
            X.append((self.a * X[n - 1] + self.c) % self.m)
        return X

    def valeur_aleatoire(self):
        X = []
        R = []
        X.append(self.x_0)
        for n in range(1, self.N):
            X.append((self.a * X[n - 1] + self.c) % self.m)
            R.append(X[n] / self.m)
        return R
