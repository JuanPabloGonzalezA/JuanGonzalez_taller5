caos.pdf: datos.txt
	python caos.py
datos.txt: caos.x
	./caos.x > datos.txt
caos.x:
	c++ caos.cpp -o caos.x
clean:
	rm caos.pdf datos.txt caos.x
