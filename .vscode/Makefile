
output: server.out

server.out: TcpServer.o VectorDistances.o TypedVector.o Knn.o
			g++ tcpServer.o VectorDistances.o TypedVector.o Knn.o -o server.out

TcpServer.o: tcpServer.cpp
	g++ -std=c++11 -g -c TcpServer.cpp

VectorDistances.o: VectorDistances.cpp
	g++ -std=c++11 -g -c VectorDistances.cpp

TypedVector.o: TypedVector.cpp
	g++ -std=c++11 -g -c TypedVector.cpp

Knn.o: Knn.cpp
	g++ -std=c++11 -g -c Knn.cpp

clean:
	rm -f *.o client.out server.out