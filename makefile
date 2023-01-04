
output: client.out server.out

client.out: tcpClient.o
			g++ tcpClient.o -o client.out

server.out: tcpServer.o VectorDistances.o TypedVector.o Knn.o
			g++ tcpServer.o VectorDistances.o TypedVector.o Knn.o -o server.out

tcpClient.o: tcpClient.cpp
	g++ -std=c++11 -g -c tcpClient.cpp

tcpServer.o: tcpServer.cpp
	g++ -std=c++11 -g -c tcpServer.cpp

VectorDistances.o: VectorDistances.cpp
	g++ -std=c++11 -g -c VectorDistances.cpp

TypedVector.o: TypedVector.cpp
	g++ -std=c++11 -g -c TypedVector.cpp

Knn.o: Knn.cpp
	g++ -std=c++11 -g -c Knn.cpp

clean:
	rm -f *.o client.out server.out