# AP_AA

Advanced programming 2022-23 course assignments by Ariel Oscar and Almog Mesilaty.

## Ex.4

### Description

Implementing a serever and a clients program that use the K-nearst-neighbors (KNN) algorithm in c++.
The server listens nonstop to new clients, and communicte with each client in this format:
  1. Throught the command line the client sends to the server, through a socket:
      - Accuracy level (K)
      - Vector that have already been classified, using for comparison
      - Distance function
  2. The server takes the classified file and the port number from the argv.
  3. Through the socket the server gets the k, vector and type of distance from the client.
  4. The serever calculate the classification  according to the client specification, and sends the answer back to the client.
  5. If the client send '-1' to the server, the server closes the client socket, but keeps listening to the client. 
  6. In a case of invalid input of the client, the server send an "invalid input" message.
 
Classes:
  1. VectorDistances - abstract class contains different distance functions.
  2. TypedVector - vector of data, type of current vector and latest distance calculated.
  3. Knn - abstract calss contains all the functions that are needed to find calculate the user vector type.
 
### Executing the program

```
make
./server.out <port>
./client.out <ip> <port>
```

### Dependencies

Vector class
Thread
Algotithm library
string class
regex
socket API
All from c++ standard library

## Constants

Using Macros to eccess IP, PORT and file that are given throught command line.
Function MinkowskiDistance uses a constant P with current value of 2.
Main uses define to access command line arguments without the use of magic numbers.

## Optimization

We used select algorithm to afficientlly find the k-nearst vector in time cost of O(n), then we are able to find and  
sort only the k nearst elements, which gives us a total time cost of O(klogk).


