
output: server.out client.out

client.out: tcpClient.o VectorDistances.o TypedVector.o Knn.o CLI.o DataManager.o Command.o UploadCommand.o SettingsCommand.o ClassifyCommand.o DisplayCommand.o DownloadCommand.o ExitCommand.o StandardIO.o SocketIO.o InputValidator.o StringMethods.o DefaultIO.o
	g++ tcpClient.o VectorDistances.o TypedVector.o Knn.o CLI.o DataManager.o Command.o UploadCommand.o SettingsCommand.o ClassifyCommand.o DisplayCommand.o DownloadCommand.o ExitCommand.o StandardIO.o SocketIO.o InputValidator.o StringMethods.o DefaultIO.o -o client.out

server.out: TcpServer.o VectorDistances.o TypedVector.o Knn.o CLI.o DataManager.o Reader.o Command.o UploadCommand.o SettingsCommand.o ClassifyCommand.o DisplayCommand.o DownloadCommand.o ExitCommand.o StandardIO.o SocketIO.o InputValidator.o StringMethods.o DefaultIO.o
	g++ TcpServer.o VectorDistances.o TypedVector.o Knn.o CLI.o DataManager.o Reader.o Command.o UploadCommand.o SettingsCommand.o ClassifyCommand.o DisplayCommand.o DownloadCommand.o ExitCommand.o StandardIO.o SocketIO.o InputValidator.o StringMethods.o DefaultIO.o -o server.out

TcpServer.o: TcpServer.cpp
	g++ -std=c++11 -g -c TcpServer.cpp

VectorDistances.o: VectorDistances.cpp
	g++ -std=c++11 -g -c VectorDistances.cpp

TypedVector.o: TypedVector.cpp
	g++ -std=c++11 -g -c TypedVector.cpp

Knn.o: Knn.cpp
	g++ -std=c++11 -g -c Knn.cpp

CLI.o: CLI.cpp
	g++ -std=c++11 -g -c CLI.cpp

DataManager.o: DataManager.cpp
	g++ -std=c++11 -g -c DataManager.cpp

Command.o: Command.cpp
	g++ -std=c++11 -g -c Command.cpp

UploadCommand.o: UploadCommand.cpp
	g++ -std=c++11 -g -c UploadCommand.cpp

SettingsCommand.o: SettingsCommand.cpp
	g++ -std=c++11 -g -c SettingsCommand.cpp

ClassifyCommand.o: ClassifyCommand.cpp
	g++ -std=c++11 -g -c ClassifyCommand.cpp

DisplayCommand.o: DisplayCommand.cpp
	g++ -std=c++11 -g -c DisplayCommand.cpp

DownloadCommand.o: DownloadCommand.cpp
	g++ -std=c++11 -g -c DownloadCommand.cpp

ExitCommand.o: ExitCommand.cpp
	g++ -std=c++11 -g -c ExitCommand.cpp

StandardIO.o: StandardIO.cpp
	g++ -std=c++11 -g -c StandardIO.cpp

SocketIO.o: SocketIO.cpp
	g++ -std=c++11 -g -c SocketIO.cpp

InputValidator.o: InputValidator.cpp
	g++ -std=c++11 -g -c InputValidator.cpp

StringMethods.o: StringMethods.cpp
	g++ -std=c++11 -g -c StringMethods.cpp

DefaultIO.o: DefaultIO.cpp
	g++ -std=c++11 -g -c DefaultIO.cpp

Reader.o: Reader.cpp
	g++ -std=c++11 -g -c Reader.cpp

clean:
	rm -f *.o client.out server.out
