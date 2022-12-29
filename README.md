# AP_AA

Advanced programming 2022-23 course assignments by Ariel Oscar and Almog Mesilaty.

## Ex.1 part 2

### Description

Implementing K-nearst-neighbors (KNN) algorithm in c++.
  1. Throught the command line the user specifies:
      - Accuracy level (K)
      - Vector that have already been classified, using for comparison
      - Distance function
  2. The program takes the classified file and parse it into vectors with type attribut.
  3. User inputs a vector and the program prints the vector type according to the user specification (see 1).
  4. The program awaits for a different vector from the user.
 
Classes:
  1. VectorDistances - abstract class contains different distance functions.
  2. TypedVector - vector of data, type of current vector and latest distance calculated.
  3. Knn - abstract calss contains all the functions that are needed to find calculate the user vector type.
 
### Executing the program

```
make
./ex.1_p2
```

### Dependencies

Vector class
Algotithm library
string class

 All from c++ standard library

## Constants

Function MinkowskiDistance uses a constant P with current value of 2.
Main uses define to access command line arguments without the use of magic numbers.

## Optimization

We used select algorithm to afficientlly find the k-nearst vector in time cost of O(n), then we are able to find and  
sort only the k nearst elements, which gives us a total time cost of O(klogk).


