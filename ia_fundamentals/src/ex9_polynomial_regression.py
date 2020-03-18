import numpy as np
import matplotlib
from matplotlib import pyplot as plot

# import tkinter
matplotlib.use('TkAgg')

# First dataset
x1 = np.array(range(1, 14))
y1 = np.array([2, 8, 8, 18, 25, 21, 32, 44, 32, 48, 61, 45, 62])

# Second dataset
x2 = np.array(range(1, 14))
y2 = np.array([0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144])

deg1 = np.polyfit(x1, y1, 1)
print(deg1)
f1 = np.poly1d(deg1)

deg2 = np.polyfit(x1, y1, 2)
print(deg2)
f2 = np.poly1d(deg2)

deg3 = np.polyfit(x1, y1, 3)
print(deg3)
f3 = np.poly1d(deg3)
print(f3)

print(f1(x1))
print(f2(x1))
print(f3(x1))

plot.plot(
    x1, y1, 'o',
    x1, f1(x1),
    x1, f2(x1),
    x1, f3(x1)
)
plot.show()
