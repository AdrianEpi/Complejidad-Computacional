/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 2. Simulador de Máquina de Turing         =
    =            File name:     transition.hpp                                     =
    =            Author:        Adrián Epifanio Rodríguez Hernández                =
    =            Fecha:         24/10/2020                                         =
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
* @Last Modified time: 2020-10-25 12:26:38
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/transition.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Transition::Transition (void) {
	set_ChainSymbol("");
	set_WriteSymbol("");
	set_NextState("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  auxTransition  The auxiliary transition
 */
Transition::Transition (const Transition& auxTransition) {
	set_ChainSymbol(auxTransition.get_ChainSymbol());
	set_WriteSymbol(auxTransition.get_WriteSymbol());
	set_CurrentState(auxTransition.get_CurrentState());
	set_NextState(auxTransition.get_NextState());
	set_TransitionID(auxTransition.get_TransitionID());
	set_Movement(auxTransition.get_Movement());
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
 * @brief      Gets the write symbol.
 *
 * @return     The write symbol.
 */
std::string Transition::get_WriteSymbol (void) const {
	return writeSymbol_;
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
 * @brief      Gets the movement.
 *
 * @return     The movement.
 */
unsigned Transition::get_Movement (void) const {
	return movement_;
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
 * @brief      Sets the write symbol.
 *
 * @param[in]  newWriteSymbol  The new write symbol
 */
void Transition::set_WriteSymbol (std::string newWriteSymbol) {
	writeSymbol_ = newWriteSymbol;
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
 * @brief      Sets the movement.
 *
 * @param[in]  move  The move
 */
void Transition::set_Movement (unsigned move) {
	movement_ = move;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newTransition  The new transition
 *
 * @return     The result of the assignment
 */
Transition Transition::operator= (const Transition& newTransition) {
	set_CurrentState(newTransition.get_CurrentState());
	set_ChainSymbol(newTransition.get_ChainSymbol());
	set_WriteSymbol(newTransition.get_WriteSymbol());
	set_NextState(newTransition.get_NextState());
	set_TransitionID(newTransition.get_TransitionID());
	set_Movement(newTransition.get_Movement());
	return *this;
}

/**
 * @brief      Equality operator.
 *
 * @param[in]  auxTransition  The auxiliary transition
 *
 * @return     The result of the equality
 */
bool Transition::operator== (const Transition& auxTransition) const {
	if ((get_ChainSymbol() == auxTransition.get_ChainSymbol()) && (get_WriteSymbol() == auxTransition.get_WriteSymbol()) && (get_Movement() == auxTransition.get_Movement()) && (get_NextState() == auxTransition.get_NextState()) && (get_CurrentState() == auxTransition.get_CurrentState()) && (get_TransitionID() == auxTransition.get_TransitionID())) {
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
	if ((get_ChainSymbol() != auxTransition.get_ChainSymbol()) || (get_WriteSymbol() != auxTransition.get_WriteSymbol()) || (get_Movement() != auxTransition.get_Movement()) || (get_NextState() != auxTransition.get_NextState()) || (get_CurrentState() != auxTransition.get_CurrentState()) || (get_TransitionID() != auxTransition.get_TransitionID())) {
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
	os << "(" << get_CurrentState() << ", " << get_ChainSymbol() << ", " << get_NextState() << ", " << get_WriteSymbol() << ", ";
	switch (movement_) {
		case 0:
			os << "S";
			break;

		case 1:
			os << "L";
			break;

		case 2:
			os << "R";
			break;		
	}
	os << ")" << std::endl; 
}

