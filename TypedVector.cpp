#include "TypedVector.hpp"

/**
 * Constructor
 * @param newType
 * @param newVector
 */
TypedVector::TypedVector(string newType, vector<float> newVector) {
	distance = 0.0;
	type = newType;
	vec = newVector;
}
/**
 * Default constructor
 */
TypedVector::TypedVector() {
	distance = 0.0;
}
/**
 * Copy constructor
 * @param other
 */
TypedVector::TypedVector(const TypedVector& other) {
	distance = other.getDistance();
	type = other.getType();
	vec = other.getVector();
}
//Getters
/**
 * @return distance
 */
float TypedVector::getDistance() const { return distance; }
/**
 * @return type
 */
string TypedVector::getType() const { return type; }
/**
 * @return vec
 */
vector<float> TypedVector::getVector() const { return vec; }

//Setter
/**
 * Setting a new distance
 * @param newDistance
 */
void TypedVector::setDistance(float newDistance) { distance = newDistance; }

/**
 * @return attr vector size
 */
int TypedVector::size() const { return vec.size(); }
