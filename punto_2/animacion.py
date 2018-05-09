import matplotlib.pyplot as plt
import numpy as np
from matplotlib.animation import FuncAnimation

uxt=np.loadtxt('datos.txt')
x=np.linspace(0,100,101)
# First set up the figure, the axis, and the plot element we want to animate
fig = plt.figure()
ax = plt.axes(xlim=(0, 100), ylim=(-1, 1))
line, = ax.plot([], [], lw=2)

# initialization function: plot the background of each frame
def init():
    line.set_data([], [])
    return line,

# animation function.  This is called sequentially
def animate(i):
    x = np.linspace(0, 2, 1000)
    y = np.sin(2 * np.pi * (x - 0.01 * i))
    line.set_data(x, y)
    return line,
anim = animation.FuncAnimation(fig, animate, init_func=init,frames=20, interval=20, blit=True)
plt.show()
#plt.savefig('cuerda.gif')
