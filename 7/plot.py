import matplotlib.pyplot as plt
import numpy as np

xValues = np.loadtxt("vector.txt", dtype=int, usecols=0)
vectorValues = np.loadtxt("vector.txt", dtype=int, usecols=1)
listValues = np.loadtxt("list_reverse.txt", dtype=int)
dequeValues = np.loadtxt("deque_reverse.txt", dtype=int)

fig, plot = plt.subplots()

plot.set_xlabel(xlabel='Number of elements, N')
plot.set_ylabel(ylabel='Time, ms')
plot.set_title(label='Containers "push_front()" time comparison with -O3 optimization')
plot.grid(which='major', color='grey', linestyle='-')

#plot.plot(xValues, vectorValues, linewidth=1, markeredgewidth=0.3, markeredgecolor='black', marker='o', markersize=6, markevery=30, label='std::vector')
plot.plot(xValues, listValues, linewidth=1, color='orange', markeredgewidth=0.3, markeredgecolor='black', marker='^', markersize=6, markevery=30, label='std::list')
plot.plot(xValues, dequeValues, linewidth=1, color='green', markeredgewidth=0.3, markeredgecolor='black', marker='s', markersize=6, markevery=30, label='std::deque')
plot.legend()

fig.savefig('plot.svg')
plt.show()