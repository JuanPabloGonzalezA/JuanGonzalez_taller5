cuerda.gif : datos.txt
	python animacion.py
datos.txt : cuerda.x
	./cuerda.x > datos.txt
cuerda.x : 
	c++ cuerda.cpp -o cuerda.x
clean:
	rm cuerda.gif datos.txt cuerda.x
