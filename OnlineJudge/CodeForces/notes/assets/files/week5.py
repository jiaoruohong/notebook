#%%
import numpy as np
import scipy.stats as st

import matplotlib.pyplot as plt
import seaborn as sns

sns.set_palette("Paired")


#%%
def poisson(lam=5, T=60, f_size=[20, 10]):
    t = [0]
    trans = lambda x, y, z: x - (1 / y) * np.log(z)
    while t[-1] <= T:
        u = np.random.uniform()
        t.append(trans(t[-1], lam, u))

    dist = "./assets/poisson.png"

    plt.figure(figsize=(f_size[0], f_size[1]))
    plt.title("Poisson: lambda = " + str(lam) + ", T = " + str(T))
    plt.xlabel("Time")
    plt.ylabel("N(t)")

    plt.plot(t)
    plt.savefig(dist)

    plt.show()


#%%
if __name__ == "__main__":
    poisson(lam=0.5, T=60)

#%%
