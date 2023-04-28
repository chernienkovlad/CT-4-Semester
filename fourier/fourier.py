from scipy.fft import fft, fftfreq
import numpy as np
import matplotlib.pyplot as plt

N = 680
dt = 1/100
t = np.linspace(0.0, N*dt, N)
f = np.sin(3.0 * 2.0*np.pi * t) + 0.5 * np.sin(2.0 * 2.0*np.pi * t)
f_f = fft(f)
t_f = fftfreq(N, dt)[0:N//2]

plt.plot(t_f, 2.0/N * np.abs(f_f[0:N//2]))
plt.grid()
plt.show()