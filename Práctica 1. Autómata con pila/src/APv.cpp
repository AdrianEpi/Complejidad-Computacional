/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     main.cpp                                           =
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
* @Date:   2020-10-15 10:00:41
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-15 22:59:58
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/APv.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
APv::APv (void) {
	set_StatesNum(0);
	set_InputFile("");
}

/**
 * @brief      Constructs a new instance.
 *
 * @param[in]  inputFile  The input file
 */
APv::APv (std::string inputFile) {
	set_StatesNum(0);
	set_InputFile(inputFile);
}

/**
 * @brief      Destroys the object.
 */
APv::~APv (void) {
}

/**
 * @brief      Gets the alphabet.
 *
 * @return     The alphabet.
 */
Alphabet APv::get_Alphabet (void) const {
	return alphabet_;
}

/**
 * @brief      Gets the states.
 *
 * @return     The states.
 */
std::vector<State> APv::get_States (void) const {
	return states_;
}

/**
 * @brief      Gets the states number.
 *
 * @return     The states number.
 */
unsigned APv::get_StatesNum (void) const {
	return statesNum_;
}

/**
 * @brief      Gets the initial state.
 *
 * @return     The initial state.
 */
State APv::get_InitialState (void) const {
	return initialState_;
}

/**
 * @brief      Gets the input file.
 *
 * @return     The input file.
 */
std::string APv::get_InputFile (void) const {
	return inputFile_;
}

/**
 * @brief      Gets the stack.
 *
 * @return     The stack.
 */
Stack APv::get_Stack (void) const {
	return stack_;
}

/**
 * @brief      Gets the path.
 *
 * @return     The path.
 */
std::vector<Transition> APv::get_Path (void) const {
	return path_;
}

/**
 * @brief      Sets the alphabet.
 *
 * @param[in]  newAlphabet  The new alphabet
 */
void APv::set_Alphabet (Alphabet newAlphabet) {
	alphabet_ = newAlphabet;
}

/**
 * @brief      Sets the states.
 *
 * @param[in]  newStates  The new states
 */
void APv::set_States (std::vector<State> newStates) {
	states_ = newStates;
}

/**
 * @brief      Sets the states number.
 *
 * @param[in]  newStatesNum  The new states number
 */
void APv::set_StatesNum (unsigned newStatesNum) {
	statesNum_ = newStatesNum;
}

/**
 * @brief      Sets the initial state.
 *
 * @param[in]  newInitialState  The new initial state
 */
void APv::set_InitialState (State newInitialState) {
	initialState_ = newInitialState;
}

/**
 * @brief      Sets the input file.
 *
 * @param[in]  newInputFile  The new input file
 */
void APv::set_InputFile (std::string newInputFile) {
	inputFile_ = newInputFile;
}

/**
 * @brief      Sets the stack.
 *
 * @param[in]  newStack  The new stack
 */
void APv::set_Stack (Stack newStack) {
	stack_ = newStack;
}

/**
 * @brief      Sets the path.
 *
 * @param[in]  newPath  The new path
 */
void APv::set_Path (std::vector<Transition> newPath) {
	path_ = newPath;
}

/**
 * @brief      Creates the states by reading the names from file
 *
 * @param[in]  statesLine  The states line
 */
void APv::generateStates (std::string statesLine) {
	int counter = 0;
	std::string stateName;
	while (counter <= statesLine.length()) {
		if (statesLine[counter] != ' ' && statesLine[counter] != '\n' && statesLine[counter] != '\0') {
			stateName += statesLine[counter];
		}
		else {
			State newState;
			newState.set_StateID(stateName);
			addState(newState);
			stateName = "";
		}
		counter++;
	}
}

/**
 * @brief      Creates the alphabet allowed by the automaton from the file
 *
 * @param[in]  alphabetLine  The alphabet line
 */
void APv::generateAlphabet (std::string alphabetLine) {
	int counter = 0;
	std::string element;
	while (counter <= alphabetLine.length()) {
		if (alphabetLine[counter] != ' ' && alphabetLine[counter] != '\n' && alphabetLine[counter] != '\0') {
			element += alphabetLine[counter];
		}
		else {
			alphabet_.addElement(element);
			element = "";
		}
		counter++;
	}
}

/**
 * @brief      Creates the stack alphabet allowed by the automaton from the file
 *
 * @param[in]  alphabetLine  The alphabet line
 */
void APv::generateStackAlphabet (std::string alphabetLine) {
	int counter = 0;
	std::string element;
	Alphabet tmp;
	while (counter <= alphabetLine.length()) {
		if (alphabetLine[counter] != ' ' && alphabetLine[counter] != '\n' && alphabetLine[counter] != '\0') {
			element += alphabetLine[counter];
		}
		else {
			tmp.addElement(element);
			element = "";
		}
		counter++;
	}
	stack_.set_StackAlphabet(tmp);
}

/**
 * @brief      Adds a state.
 *
 * @param[in]  newState  The new state
 */
void APv::addState (State newState) {
	states_.push_back(newState);
}

/**
 * @brief      Gets the next transitions.
 *
 * @param[in]  aux          The auxiliary state
 * @param[in]  chainSymbol  The chain symbol
 * @param[in]  stackSymbol  The stack symbol
 *
 * @return     The next transitions.
 */
std::vector<Transition> APv::getNextTransitions (State aux, char chainSymbol, char stackSymbol) {
	std::vector<Transition> possibleTransitions;
	for (Transition trans : aux.get_Transitions()) {
		if ((trans.get_ChainSymbol() == chainSymbol) && (trans.get_TopStackSymbol() == stackSymbol)) {
			possibleTransitions.push_back(trans);
		}
	}
	return possibleTransitions;
}

/**
 * @brief      Determines whether the specified identifier is valid state.
 *
 * @param[in]  id    The identifier
 *
 * @return     True if the specified identifier is valid state, False otherwise.
 */
bool APv::isValidState (std::string id) {
	std::string name = "";
	for (int i = 0; i <= id.length(); i++) {
		if (id[i] != ' ' && id[i] != '\n' && id[i] != '\0') {
			name += id[i];
		}
	}
	if (findState(name) != -1) {
		return true;
	}
	return false;
}

/**
 * @brief      Finds a state in the vector.
 *
 * @param[in]  id    The identifier
 *
 * @return     The position of that state in the vectors state.
 */
int APv::findState (std::string id) {
	for (int i = 0; i < get_States().size(); i++) {
		if (states_[i].get_StateID() == id) {
			return i;
		}
	}
	return -1;
}

void APv::tryChain (std::string chain) {

}

bool APv::isChainAccepted (std::string chain, std::string stateID) {

}

/**
 * @brief      Erase the spaces of a given word or line
 *
 * @param[in]  str   The string
 *
 * @return     The string without spaces or special characters
 */
std::string APv::eraseSpaces (std::string str) {
	std::string tmp;
	for (int i = 0; i <= str.length(); i++) {
		if (str[i] != ' ' && str[i] != '\n' && str[i] != '\0') {
			tmp += str[i];
		}
	}
	return tmp;
}

void APv::readData (std::string inputFile) {
	std::ifstream input(inputFile, std::ios::in);
	if (input.fail()) {
		std::cout << std::endl << "Error 404, file not found" << std::endl;
		exit(1);
	}
	else {
		set_InputFile(inputFile);
		std::string sentinel;

		do {	// For erasing all the comments
			getline(input, sentinel);
		} while (sentinel[3] == '#' || sentinel[0] == '#');
		// Generate the states from the first line
		generateStates(sentinel);
		// Generate the automaton alphabet form the second line.
		getline(input, sentinel);
		generateAlphabet(sentinel);

		// Generate the stack alphabet form the second line.
		getline(input, sentinel);
		generateStackAlphabet(sentinel);

		// Search if start state is a valid one. and 
		getline(input, sentinel);
		sentinel = eraseSpaces(sentinel);
		if (isValidState(sentinel)) {
			initialState_.set_StateID(sentinel);
		}
		
		/*while (!input.eof()) {
			getline(input, sentinel);
			std::cout << std::endl << sentinel;
		}*/
	}
	std::cout << std::endl << "ESTADOS: " << states_.size() << " " << states_[0].get_TransitionsNumber();
}
