import matplotlib.pyplot as plt
import numpy as np
import matplotlib.animation as anm

uxt=np.loadtxt('datos.txt')
x=np.linspace(0,100,101)

fig = plt.figure()
ax = fig.add_subplot(111)
ax.set(xlabel=r'$x$',ylabel=r'$u(x,t)$',title='Cuerda vibrando',ylim=(-1,1),xlim=(0,100))
datos, = ax.plot(x,uxt[0,:])

def iteracion(i):
	datos.set_ydata(uxt[i,:])

gif = anm.FuncAnimation(fig, iteracion,frames=101, interval=50)
gif.save('cuerda.gif')
