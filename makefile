main: lowerBoundAComputation.cpp
	gcc lowerBoundAComputation.cpp -lstdc++ -std=c++11 -O3 -o lowerBoundAComputation -lm

clean:
	rm -f lowerBoundAComputation
