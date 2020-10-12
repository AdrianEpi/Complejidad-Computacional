/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     alphabet.cpp                                       =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         11/10/2020                                         =
    =            Subject:       Complejidad Computacional                          =
    =            Language:      C++                                                =
    =            Email:         alu0101158280@ull.edu.es                           =
    =            Place:         Universidad De La Laguna                           =
    =                           Escuela Superior de Ingeniería y Tecnología        =
    =                                                                              =
=========================================================================================
=======================================================================================*/
/*
* @Author: Adrian Epifanio
* @Date:   2020-10-11 21:44:49
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-12 16:03:42
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/alphabet.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Alphabet::Alphabet (void) {
}

/**
 * @brief      Destroys the object.
 */
Alphabet::~Alphabet (void) {
}

/**
 * @brief      Gets the alphabet.
 *
 * @return     The alphabet.
 */
std::set<std::string> Alphabet::get_Alphabet (void) const {
	return alphabet_;
}

/**
 * @brief      Sets the alphabet.
 *
 * @param[in]  newAlphabet  The new alphabet
 */
void Alphabet::set_Alphabet (std::set<std::string> newAlphabet) {
	alphabet_ = newAlphabet;
}

/**
 * @brief      Adds an element.
 *
 * @param[in]  newElement  The new element
 */
void Alphabet::addElement (std::string newElement) {
	alphabet_.insert(newElement);
}

/**
 * @brief      Assignment operator.
 *
 * @param      newAlphabet  The new alphabet
 *
 * @return     The result of the assignment
 */
Alphabet& Alphabet::operator= (const Alphabet& newAlphabet) {
	alphabet_ = newAlphabet.get_Alphabet();
}

/**
 * @brief      Gets the size.
 *
 * @return     The size.
 */
int Alphabet::getSize (void) const {
	std::set<std::string>::iterator it = alphabet_.begin();
	int size;
	for (; it != alphabet_.end(); it++) {
		size++;
	}
	return size;
}

/**
 * @brief      Prints an alphabet.
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& Alphabet::printAlphabet (std::ostream& os) const {
	int aux;    // Auxiliar counter for move by the set
	std::set<std::string>::iterator it = alphabet_.begin();
	os << "{";
	for (; it != alphabet_.end(); it++) {   // Special "for" of c++11
		os << *it;
		aux++;
		if (aux < getSize()) {
			os << ", ";
		}
	}
	os << "}" << std::endl;
}
