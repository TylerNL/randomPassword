passwordGen: passwordGen.cpp
	g++ -o passwordGen passwordGen.cpp

clean:
	rm -f *.o passwordGen
