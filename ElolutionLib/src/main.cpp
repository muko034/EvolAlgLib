//============================================================================
// Name        : main.cpp
// Author      : Kuba Ziec
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <random>

using namespace std;

int main() {
	cout << "!!!Hello World :) !!!" << endl; // prints !!!Hello World!!!

//	SomeIndividual prototype;
//	Population population(100, prototype, ...);
//	EvolutionAlg evol(population);
//	evol.start();
//	evol.printResult();

	// Seed with a real random value, if available
	std::random_device rd;

	// Choose a random mean between 1 and 6
	std::default_random_engine e1(rd());
	std::uniform_int_distribution<int> uniform_dist(1, 6);
	int mean = uniform_dist(e1);
	std::cout << "Randomly-chosen mean: " << mean << '\n';

	return 0;
}
