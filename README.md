# AP_AA

Advanced programming 2022-23 course assignments by Ariel Oscar and Almog Mesilaty.

## Ex.4

### Description

Implementing a server and a clients program that use the K-nearst-neighbors (KNN) algorithm in c++.
The server listens nonstop to new clients, and communicte with each client in this format:
  1. The server sends a menu to the client, with 6 options to choose: 1-5 and 8. After compliting an option the server will send the menu again.
  2. Clicking 1- Upload command: The server asks the client for 2 files: classified file and Unclassified file, each are filled with vectors. The client has to enter      the local path of each file, and will get an "upload complete" message each time.
  3. Clicking 2- Setting command: The server will asks for 2 parameters:
      -K: The number of the closest distances.
      -Distance: The type of distance calculation.
     The client has to enter valid option, otherwise an "invalid" message wiil be sent. The default parameters are: K=5 and distance=AUC.
  4. Clicking 3- Classify command: The server classifies the types of all the Unclassified vectors.
  5. Clicking 4- Display command: The server sends the types that were classifies in classify command. If the data has'nt been classified or the client has'nt upload      files, the server will send a request to go back to step 1 or 3.
  6. Clicking 5- Download command: the client has to enter a local path. The server creates a csv file with the classified data and saves it in the desiered path.
  7. Clicking 8- Exit Command: The conection between the client and the server is cut. The server keeps listening to new clients while the client stops running.
 
 
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


