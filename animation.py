import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

# --- config ---
path = "out.dat"   # your file
n = 18               # matrix side length (set correctly!)
interval_ms = 100     # animation speed

# --- load ---
# Each line has n*n values like: "1 -1 1 ...".
frames_1d = np.loadtxt(path, dtype=np.int8)   # shape: (num_frames, n*n) OR (n*n,) if only 1 line

print(frames_1d.shape)

# if frames_1d.ndim == 1:
#     frames_1d = frames_1d[None, :]  # make it (1, n*n)

num_frames, frame_size = frames_1d.shape
# assert frame_size == n * n, f"Expected {n*n} values per line, got {frame_size}. Fix n."

# # reshape to (num_frames, n, n)
frames = frames_1d.reshape(num_frames, n, n)
print(frames.shape)

# --- plot ---
fig, ax = plt.subplots()
im = ax.imshow(frames[0], origin="lower", interpolation="nearest")
ax.set_title("frame 0")
# plt.colorbar(im, ax=ax)

# For spins ±1, fix color scale so it doesn't auto-jump
im.set_clim(-1, 1)

def update(k):
    im.set_data(frames[k])
    ax.set_title(f"frame {k}")
    return (im,)

ani = FuncAnimation(fig, update, frames=num_frames, interval=interval_ms, blit=False)
plt.show()
