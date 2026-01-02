import numpy as np
import matplotlib.pyplot as plt

# Read the data from out.dat
data = np.loadtxt('out.dat')

# Assuming data has at least two columns
if data.shape[1] < 2:
    print("Error: out.dat must have at least two columns")
    exit(1)


# plt.plot(data[:, 0])
# plt.plot(data[:, 1])
plt.plot(np.abs(data[:, 1]))
plt.show()
