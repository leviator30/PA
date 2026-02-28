CC = g++
CCFLAGS = -Wall -Wextra -std=c++17 -O0 -lm

.PHONY: build clean

build: servere colorare compresie criptat oferta

run-p1:
	./servere
run-p2:
	./colorare
run-p3:
	./compresie
run-p4:
	./criptat
run-p5:
	./oferta

p1: servere.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p2: colorare.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p3: compresie.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p4: criptat.cpp
	$(CC) -o $@ $^ $(CCFLAGS)
p5: oferta.cpp
	$(CC) -o $@ $^ $(CCFLAGS)

clean:
	rm -f servere colorare compresie criptat oferta
