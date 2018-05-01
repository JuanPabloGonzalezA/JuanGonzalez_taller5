placas.pdf : datos.txt
	python grafica.py
datos.txt : placas.x
	./placas.x > datos.txt
placas.x:
	c++ placas.cpp -o placas.x
clean :
	rm placas.pdf datos.txt placas.x
