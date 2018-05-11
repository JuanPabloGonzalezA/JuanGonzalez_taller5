import matplotlib.pyplot as plt
import numpy as np

datos=np.loadtxt('datos.txt')#columna 1 p2 columna 2 q2
plt.plot(datos[:,0],datos[:,1])
plt.xlabel(r'$p_2$')
plt.ylabel(r'$q_2$')
plt.title(r'$q_2 \ \mathrm{vs.}\ p_2$')
plt.savefig('caos.pdf')
