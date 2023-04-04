all:
	g++ -std=c++17 src/main.cpp -o bin/wakeomatic

clean:
	$(RM) bin/wakeomatic