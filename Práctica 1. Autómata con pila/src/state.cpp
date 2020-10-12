/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     state.cpp                                          =
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
* @Date:   2020-10-12 09:00:34
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-12 21:12:52
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/state.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
State::State (void) {
	set_StateID("");
	set_TransitionsNumber(0);	
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  newState  The new state
 */
State::State (const State& newState) {
	set_StateID(newState.get_StateID());
	set_TransitionsNumber(newState.get_TransitionsNumber());
	set_Transitions(newState.get_Transitions());
}

/**
 * @brief      Destroys the object.
 */
State::~State (void) {
}

/**
 * @brief      Gets the state id.
 *
 * @return     The state id.
 */
std::string State::get_StateID (void) const {
	return id_;
}

/**
 * @brief      Gets the transitions number.
 *
 * @return     The transitions number.
 */
unsigned State::get_TransitionsNumber (void) const {
	return transitionsNumber_;
}

/**
 * @brief      Gets the transitions.
 *
 * @return     The transitions.
 */
std::set<Transition> State::get_Transitions (void) const {
	return transitions_;
}

/**
 * @brief      Sets the state id.
 *
 * @param[in]  id    The new value
 */
void State::set_StateID (std::string id) {
	id_ = id;
}

/**
 * @brief      Sets the transitions number.
 *
 * @param[in]  transitionsNumber  The transitions number
 */
void State::set_TransitionsNumber (unsigned transitionsNumber) {
	transitionsNumber_ = transitionsNumber;
}

/**
 * @brief      Sets the transitions.
 *
 * @param[in]  transitions  The transitions
 */
void State::set_Transitions (std::set<Transition> transitions) {
	transitions_ = transitions;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newState  The new state
 *
 * @return     The result of the assignment
 */
State& State::operator= (const State& newState) {
	set_StateID(newState.get_StateID());
	set_TransitionsNumber(newState.get_TransitionsNumber());
	set_Transitions(newState.get_Transitions());
	return *this;
}

/**
 * @brief      Inequality operator.
 *
 * @param[in]  auxState  The auxiliary state
 *
 * @return     The result of the inequality
 */
bool State::operator!= (const State& auxState) const {
	if ((get_StateID() != auxState.get_StateID()) && (get_Transitions() != auxState.get_Transitions())) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief      Equality operator.
 *
 * @param[in]  auxState  The auxiliary state
 *
 * @return     The result of the equality
 */
bool State::operator== (const State& auxState) const {
	if ((get_StateID() == auxState.get_StateID()) && (get_Transitions() == auxState.get_Transitions())) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief      Less-than comparison operator.
 *
 * @param[in]  auxState  The auxiliary state
 *
 * @return     The result of the less-than comparison
 */
bool State::operator< (const State& auxState) const {
	if (get_StateID() < auxState.get_StateID()) {
		return true;
	}
	else {
		return false;
	}
}

/**
 * @brief      Adds a transition.
 *
 * @param[in]  newTransition  The new transition
 */
void State::addTransition (const Transition& newTransition) {
	if (transitions_.find(newTransition) == transitions_.end()) {
		transitionsNumber_++;
		transitions_.insert(newTransition);
	}
}

/**
 * @brief      Prints a state.
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& State::printState (std::ostream& os) const {
	os << std::endl << "ID -> " << get_StateID() << std::endl;
	os << "Transitions ammount -> " << get_TransitionsNumber() << std::endl;
	os << "Transitions -> { ";
	std::set<Transition>::iterator it = transitions_.begin();
	for (; it != transitions_.end(); it++) {
		os << " ";
		it -> printTransition(os);
	}
	os << " }" << std::endl;
}