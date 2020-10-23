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
* @Last Modified time: 2020-10-23 09:13:58
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/transition.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Transition::Transition (void) {
	set_ChainSymbol("");
	set_TopStackSymbol("");
	set_NextState(" ");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  auxTransition  The auxiliary transition
 */
Transition::Transition (const Transition& auxTransition) {
	set_ChainSymbol(auxTransition.get_ChainSymbol());
	set_TopStackSymbol(auxTransition.get_TopStackSymbol());
	set_InsertStackSymbol(auxTransition.get_InsertStackSymbol());
	set_CurrentState(auxTransition.get_CurrentState());
	set_NextState(auxTransition.get_NextState());
	set_TransitionID(auxTransition.get_TransitionID());
}

/**
 * @brief      Destroys the object.
 */
Transition::~Transition (void) {
}

/**
 * @brief      Gets the transition id.
 *
 * @return     The transition id.
 */
int Transition::get_TransitionID (void) const {
	return transitionID_;
}

/**
 * @brief      Gets the chain symbol.
 *
 * @return     The chain symbol.
 */
std::string Transition::get_ChainSymbol (void) const {
	return chainSymbol_;
}

/**
 * @brief      Gets the top stack symbol.
 *
 * @return     The top stack symbol.
 */
std::string Transition::get_TopStackSymbol (void) const {
	return topStackSymbol_;
}

/**
 * @brief      Gets the insert stack symbol.
 *
 * @return     The insert stack symbol.
 */
std::vector<std::string> Transition::get_InsertStackSymbol (void) const {
	return insertStackSymbol_;
}

/**
 * @brief      Gets the current state.
 *
 * @return     The current state.
 */
std::string Transition::get_CurrentState (void) const {
	return currentState_;
}

/**
 * @brief      Gets the next state.
 *
 * @return     The next state.
 */
std::string Transition::get_NextState (void) const {
	return nextState_;
}

/**
 * @brief      Sets the transition id.
 *
 * @param[in]  newID  The new id
 */
void Transition::set_TransitionID (int newID) {
	transitionID_ = newID;
}

/**
 * @brief      Sets the chain symbol.
 *
 * @param[in]  newChainSymbol  The new chain symbol
 */
void Transition::set_ChainSymbol (std::string newChainSymbol) {
	chainSymbol_ = newChainSymbol;
}

/**
 * @brief      Sets the top stack symbol.
 *
 * @param[in]  newTopStackSymbol  The new top stack symbol
 */
void Transition::set_TopStackSymbol (std::string newTopStackSymbol) {
	topStackSymbol_ = newTopStackSymbol;
}

/**
 * @brief      Sets the insert stack symbol.
 *
 * @param[in]  newInsertStackSymbol  The new insert stack symbol
 */
void Transition::set_InsertStackSymbol (std::vector<std::string> newInsertStackSymbol) {
	insertStackSymbol_ = newInsertStackSymbol;
}

/**
 * @brief      Sets the current state.
 *
 * @param[in]  newCurrentState  The new current state
 */
void Transition::set_CurrentState (std::string newCurrentState) {
	currentState_ = newCurrentState;
}

/**
 * @brief      Sets the next state.
 *
 * @param[in]  newNextState  The new next state
 */
void Transition::set_NextState (std::string newNextState) {
	nextState_ = newNextState;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newTransition  The new transition
 *
 * @return     The result of the assignment
 */
Transition Transition::operator= (const Transition& newTransition) {
	set_ChainSymbol(newTransition.get_ChainSymbol());
	set_TopStackSymbol(newTransition.get_TopStackSymbol());
	set_InsertStackSymbol(newTransition.get_InsertStackSymbol());
	set_NextState(newTransition.get_NextState());
	set_TransitionID(newTransition.get_TransitionID());
}

/**
 * @brief      Equality operator.
 *
 * @param[in]  auxTransition  The auxiliary transition
 *
 * @return     The result of the equality
 */
bool Transition::operator== (const Transition& auxTransition) const {
	if ((get_ChainSymbol() == auxTransition.get_ChainSymbol()) && (get_TopStackSymbol() == auxTransition.get_TopStackSymbol()) && (get_InsertStackSymbol() == auxTransition.get_InsertStackSymbol()) && (get_NextState() == auxTransition.get_NextState()) && (get_CurrentState() == auxTransition.get_CurrentState()) && (get_TransitionID() == auxTransition.get_TransitionID())) {
		return true;
	}
	return false;
}

/**
 * @brief      Inequality operator.
 *
 * @param[in]  auxTransition  The auxiliary transition
 *
 * @return     The result of the inequality
 */
bool Transition::operator!= (const Transition& auxTransition) const {
	if ((get_ChainSymbol() != auxTransition.get_ChainSymbol()) || (get_TopStackSymbol() != auxTransition.get_TopStackSymbol()) || (get_InsertStackSymbol() != auxTransition.get_InsertStackSymbol()) || (get_NextState() != auxTransition.get_NextState()) || (get_CurrentState() != auxTransition.get_CurrentState()) || (get_TransitionID() != auxTransition.get_TransitionID())) {
		return true;
	}
	return false;
}

/**
 * @brief      Less-than comparison operator.
 *
 * @param[in]  auxTransition  The auxiliary transition
 *
 * @return     The result of the less-than comparison
 */
bool Transition::operator< (const Transition& auxTransition) const {
	if (get_TransitionID() <= auxTransition.get_TransitionID()) {
		return true;
	}
	return false;
}

/**
 * @brief      Prints a transition.
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& Transition::printTransition (std::ostream& os) const {
	os << "(" << get_CurrentState() << ", " << get_ChainSymbol() << ", " << get_TopStackSymbol() << ", " << get_NextState() << ", ";
	for (int i = 0; i < insertStackSymbol_.size(); i++) {
		os << insertStackSymbol_[i];
	}
	os << ")" << std::endl; 
}

