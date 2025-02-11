/*=====================================================================================================
=======================================================================================================
    =                                                                                            =
    =            Proyect:       Práctica 3. Implementación de Funciones Recursivas Primitivas    =
    =            File name:     PRF.cpp                                                          =
    =            Author:        Adrián Epifanio Rodríguez Hernández                              =
    =            Date:          12/11/2020                                                       =
    =            Subject:       Complejidad Computacional                                        =
    =            Language:      C++                                                              =
    =            Email:         alu0101158280@ull.edu.es                                         =
    =            Place:         Universidad De La Laguna                                         =
    =                           Escuela Superior de Ingeniería y Tecnología                      =
    =                                                                                            =
=======================================================================================================
=====================================================================================================*/
/*
* @Author: Adrian Epifanio
* @Date:   2020-11-12 20:29:42
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-19 11:38:15
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/PRF.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
PrimitveRecursiveFunction::PrimitveRecursiveFunction (void) {
}

/**
 * @brief      Destroys the object.
 */
PrimitveRecursiveFunction::~PrimitveRecursiveFunction (void) {
}

/**
 * @brief      The zero function
 *
 * @param[in]  x     The number
 *
 * @return     0
 */
int PrimitveRecursiveFunction::zeroFunction (int x) {
	// 	𝑧: 𝑁 → 𝑁
	//  𝑥 ∈ 𝑁 → 𝑧(𝑥) = 0 ∈ 𝑁
	return 0;
}

/**
 * @brief      Calculates the sucessor as a recursive function
 *
 * @param[in]  x     The number
 *
 * @return     The successor of the number
 */
int PrimitveRecursiveFunction::sucessorFunction (int x) {
	// 	𝑠: 𝑁 → 𝑁
	//	𝑥 ∈ 𝑁 → 𝑠(𝑥) = 𝑥 + 1 ∈ 𝑁
	return x + 1;
}

/**
 * @brief      Calculates the projection as a recursive function
 *
 * @param[in]  vector    The vector
 * @param[in]  position  The position
 *
 * @return     The number on the selected position
 */
int PrimitveRecursiveFunction::projectionFunction (std::vector<int> vector, int position) {
	//	𝑃𝑖^𝑛 : 𝑁^𝑛 → 𝑁
	//	(𝑥1, ⋯ 𝑥𝑛) ∈ 𝑁^𝑛 → 𝑃𝑖^𝑛 (𝑥1, ⋯ 𝑥𝑛) = 𝑥𝑖, 𝑛 ≥ 1, 1 ≤ 𝑖 ≤ 𝑛
	assert(vector.size() != 0 && position > 0 && position <= vector.size());
	return vector[position - 1];
}

/**
 * @brief      Calculates the number as a recursive function
 *
 * @param[in]  x     The number
 *
 * @return     The number
 */
int PrimitveRecursiveFunction::number (int x) {
	// n(𝑥) : 𝑁 → 𝑁
	// 𝑥 ∈ 𝑁 → n(𝑥) = x ∈ 𝑁
	std::vector<int> newVector;
	newVector.push_back(x);
	return projectionFunction(newVector, 1);
}

/**
 * @brief      Calculates the predecessor as a recursive function
 *
 * @param[in]  x     The number
 *
 * @return     The predecessor
 */
int PrimitveRecursiveFunction::predecessor (int x) {
	// 	pred: 𝑁 → 𝑁
	//	𝑥 ∈ 𝑁 → pred(𝑥) = 𝑥 - 1 ∈ 𝑁
	if (x == 0) {
		return 0;
	}
	else {
		std::vector<int> newVector;
		newVector.push_back(x - 1);
		return projectionFunction(newVector, 1);
	}
}

/**
 * @brief      Calculates the addition as a recrusive function
 *
 * @param[in]  x     The first number
 * @param[in]  y     The second number
 *
 * @return     The result of the addition
 */
int PrimitveRecursiveFunction::add (int x, int y) {
	// add(𝑥, y) : 𝑁2 → 𝑁
	// 𝑥, y ∈ 𝑁 → add(𝑥, y) = 𝑥 + y ∈ 𝑁
	if (y == 0) {
		return number(x);
	}
	else {
		std::vector<int> newVector;
		newVector.push_back(x);
		newVector.push_back(y);
		newVector.push_back(add(x, predecessor(y)));
		return sucessorFunction(projectionFunction(newVector, 3));
	}
}

/**
 * @brief      Calculates the multiplication as a recrusive function
 *
 * @param[in]  x     The first number
 * @param[in]  y     The second number
 *
 * @return     The result of the multiplication
 */
int PrimitveRecursiveFunction::multiplication (int x, int y) {
	// mult(𝑥, y) : 𝑁m → 𝑁
	// 𝑥, y ∈ 𝑁 → mult(𝑥, y) = 𝑥y ∈ 𝑁
	if (y == 1) {
		return number(x);
	}
	else if (y == 0) {
		return zeroFunction(x);
	}
	else {
		std::vector<int> newVector;
		newVector.push_back(x);
		newVector.push_back(y);
		newVector.push_back(multiplication(x, predecessor(y)));
		return add(x, projectionFunction(newVector, 3));
	}
}

/**
 * @brief      Calculates the pow as a recursive function
 *
 * @param[in]  x     The base
 * @param[in]  y     The exponent
 *
 * @return     The result fo the pow
 */
int PrimitveRecursiveFunction::pow (int x, int y) {
	// pow(𝑥, y) : 𝑁^m → 𝑁
	// 𝑥, y ∈ 𝑁 → pow(𝑥, y) = 𝑥^y ∈ 𝑁
	if (y == 1) {
		return number(x);
	}
	else if (y == 0) {
		return zeroFunction(x);
	}
	else {
		std::vector<int> newVector;
		newVector.push_back(x);
		newVector.push_back(y);
		newVector.push_back(pow(x, predecessor(y)));
		return multiplication(x, projectionFunction(newVector, 3));
	}
}
