all: bin/ipynb2py bin/py2ipynb

bin/ipynb2py: ipynb2py.c
	gcc -o bin/ipynb2py -g src/ipynb2py.c lib/cJSON.c -lm

bin/py2ipynb: py2ipynb.c
	gcc -o bin/py2ipynb -g src/py2ipynb.c lib/cJSON.c -lm
