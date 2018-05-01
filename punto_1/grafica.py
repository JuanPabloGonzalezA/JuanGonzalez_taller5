import numpy as np
import matplotlib.pyplot as plt

N=510;

datos = np.loadtxt('datos.txt').reshape((N,N,3))#(x,y,en 0 V en 1 Ex en 2 Ey)
print datos[:,:,2]

