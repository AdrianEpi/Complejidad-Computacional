/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     transition.hpp                                     =
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
* @Date:   2020-10-12 20:18:21
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-12 20:40:45
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/transition.hpp"

/*------------------------------------------------*/

Transition::Transition (void) {
	set_ChainSymbol(' ');
	set_TopStackSymbol(' ');
	set_NextState(" ");
}

Transition::Transition (const Transition& auxTransition) {
	set_ChainSymbol(auxTransition.get_ChainSymbol());
	set_TopStackSymbol(auxTransition.get_TopStackSymbol());
	set_InsertStackSymbol(auxTransition.get_InsertStackSymbol());
	set_NextState(auxTransition.get_NextState());
}

Transition::~Transition (void) {
}

char Transition::get_ChainSymbol (void) const {
	return chainSymbol_;
}

char Transition::get_TopStackSymbol (void) const {
	return topStackSymbol_;
}

std::vector<char> Transition::get_InsertStackSymbol (void) const {
	return insertStackSymbol_;
}

std::string Transition::get_NextState (void) const {
	return nextState_;
}

void Transition::set_ChainSymbol (char newChainSymbol) {
	chainSymbol_ = newChainSymbol;
}

void Transition::set_TopStackSymbol (char newTopStackSymbol) {
	topStackSymbol_ = newTopStackSymbol;
}

void Transition::set_InsertStackSymbol (std::vector<char> newInsertStackSymbol) {
	insertStackSymbol_ = newInsertStackSymbol;
}

void Transition::set_NextState (std::string newNextState) {
	nextState_ = newNextState;
}

Transition Transition::operator= (const Transition& newTransition) {
	set_ChainSymbol(newTransition.get_ChainSymbol());
	set_TopStackSymbol(newTransition.get_TopStackSymbol());
	set_InsertStackSymbol(newTransition.get_InsertStackSymbol());
	set_NextState(newTransition.get_NextState());
}

bool Transition::operator== (const Transition& auxTransition) const {
	if ((get_ChainSymbol() == auxTransition.get_ChainSymbol()) && (get_TopStackSymbol() == auxTransition.get_TopStackSymbol()) && (get_InsertStackSymbol() == auxTransition.get_InsertStackSymbol()) && (get_NextState() == auxTransition.get_NextState())) {
		return true;
	}
	return false;
}

bool Transition::operator!= (const Transition& auxTransition) const {
	if ((get_ChainSymbol() != auxTransition.get_ChainSymbol()) || (get_TopStackSymbol() != auxTransition.get_TopStackSymbol()) || (get_InsertStackSymbol() != auxTransition.get_InsertStackSymbol()) || (get_NextState() != auxTransition.get_NextState())) {
		return true;
	}
	return false;
}

bool Transition::operator< (const Transition& auxTransition) const {
	if (get_ChainSymbol() <= auxTransition.get_ChainSymbol()) {
		return true;
	}
	return false;
}

std::ostream& Transition::printTransition (std::ostream& os) const {
	os << "Transition: (" << get_ChainSymbol() << ", " << get_NextState() << ", " << get_ChainSymbol() << ", ";
	for (int i = 0; i < insertStackSymbol_.size(); i++) {
		os << insertStackSymbol_[i];
	}
	os << ")" << std::endl; 
}

