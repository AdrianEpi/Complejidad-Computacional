/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 2. Simulador de Máquina de Turing         =
    =            File name:     turingMachine.cpp                                  =
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
* @Date:   2020-10-15 10:00:41
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-24 12:50:19
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/turingMachine.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
TuringMachine::TuringMachine (void) {
	set_StatesNum(0);
	set_InputFile("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  inputFile  The input file
 */
TuringMachine::TuringMachine (std::string inputFile) {
	set_StatesNum(0);
	set_InputFile(inputFile);
}

/**
 * @brief      Destroys the object.
 */
TuringMachine::~TuringMachine (void) {
}

/**
 * @brief      Gets the alphabet.
 *
 * @return     The alphabet.
 */
Alphabet TuringMachine::get_Alphabet (void) const {
	return alphabet_;
}

/**
 * @brief      Gets the states.
 *
 * @return     The states.
 */
std::vector<State> TuringMachine::get_States (void) const {
	return states_;
}

/**
 * @brief      Gets the states number.
 *
 * @return     The states number.
 */
unsigned TuringMachine::get_StatesNum (void) const {
	return statesNum_;
}

/**
 * @brief      Gets the initial state.
 *
 * @return     The initial state.
 */
State TuringMachine::get_InitialState (void) const {
	return initialState_;
}

/**
 * @brief      Gets the input file.
 *
 * @return     The input file.
 */
std::string TuringMachine::get_InputFile (void) const {
	return inputFile_;
}

/**
 * @brief      Sets the alphabet.
 *
 * @param[in]  newAlphabet  The new alphabet
 */
void TuringMachine::set_Alphabet (Alphabet newAlphabet) {
	alphabet_ = newAlphabet;
}

/**
 * @brief      Sets the states.
 *
 * @param[in]  newStates  The new states
 */
void TuringMachine::set_States (std::vector<State> newStates) {
	states_ = newStates;
}

/**
 * @brief      Sets the states number.
 *
 * @param[in]  newStatesNum  The new states number
 */
void TuringMachine::set_StatesNum (unsigned newStatesNum) {
	statesNum_ = newStatesNum;
}

/**
 * @brief      Sets the initial state.
 *
 * @param[in]  newInitialState  The new initial state
 */
void TuringMachine::set_InitialState (State newInitialState) {
	initialState_ = newInitialState;
}

/**
 * @brief      Sets the input file.
 *
 * @param[in]  newInputFile  The new input file
 */
void TuringMachine::set_InputFile (std::string newInputFile) {
	inputFile_ = newInputFile;
}
