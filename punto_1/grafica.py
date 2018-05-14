import numpy as np
import matplotlib.pyplot as plt

N=510;
xl=np.linspace(-1,1,100)
yl=np.ones(100)*0.5

datos = np.loadtxt('datos.txt').reshape((N,N,3))#(x,y,en 0 V en 1 Ex en 2 Ey)
plt.imshow(datos[:,:,0],extent=[-2.5,2.5,-2.5,2.5],cmap='hot')
plt.colorbar()
plt.xlim(-2.5,2.5)
plt.ylim(-2.5,2.5)
plt.title('Potencial placas [V] y lineas de campo electrico')
plt.streamplot(np.linspace(-2.5,2.5,510),np.linspace(-2.5,2.5,510),datos[:,:,1],datos[:,:,2])
plt.savefig('placas.pdf')

