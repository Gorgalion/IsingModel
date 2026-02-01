import numpy as np
import matplotlib.pyplot as plt

# Read the data from out.dat
data = np.loadtxt('out.dat')

# Assuming data has at least two columns
if data.shape[1] < 2:
    print("Error: out.dat must have at least two columns")
    exit(1)

# Plot the first column
plt.figure(figsize=(10, 6))

plt.subplot(1, 3, 1)
plt.plot(data[:, 0])
plt.title('First Column')
plt.xlabel('Index')
plt.ylabel('Value')

# Plot the second column
plt.subplot(1, 3, 2)
plt.plot(data[:, 1])
plt.title('Second Column')
plt.xlabel('Index')
plt.ylabel('Value')

# Plot the absolute value of the second column
plt.subplot(1, 3, 3)
plt.plot(np.abs(data[:, 1])/18**2)
plt.title('Absolute of Second Column')
plt.xlabel('Index')
plt.ylabel('Value')

plt.tight_layout()
plt.show()