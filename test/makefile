CFLAGS = -std=c++17 -O2

k9_sniffer: main.cpp
	g++ -o test_program main.cpp

.PHONY: test clean

test: k9_sniffer
	./test_program 

clean:
	rm -f test_program