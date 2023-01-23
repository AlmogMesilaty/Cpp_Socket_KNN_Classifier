//Prints the current dis matric and k value
void Settings::execute() {
	m_dio->write("\nThe current KNN parameters are: k = " + c.getK() + ", distance metric = " + c.getDis() + "\n");
	//Cont...
}