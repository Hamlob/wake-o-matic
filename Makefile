all:
	g++ -std=c++17 src/main.cpp -o bin/wakeomatic
	g++ -std=c++17 test/src/mainUnitTests.cpp -o test/bin/unitTests

test:
	chmod +x bin/wakeomatic
	./helloTest

clean:
	$(RM) bin/wakeomatic test/bin/unitTests