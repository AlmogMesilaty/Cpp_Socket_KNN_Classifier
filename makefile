
output: main.o VectorDistances.o TypedVector.o Knn.o
	g++ main.o VectorDistances.o TypedVector.o Knn.o -o ex.1_p2

main.o: main.cpp
	g++ -std=c++11 -g -c main.cpp

VectorDistances.o: VectorDistances.cpp
	g++ -std=c++11 -g -c VectorDistances.cpp

TypedVector.o: TypedVector.cpp
	g++ -std=c++11 -g -c TypedVector.cpp

Knn.o: Knn.cpp
	g++ -std=c++11 -g -c Knn.cpp

clean:
	rm -f *.o ex.1_p2
