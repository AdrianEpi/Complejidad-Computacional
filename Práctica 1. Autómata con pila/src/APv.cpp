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
* @Last Modified time: 2020-10-17 20:37:02
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
 * @brief      Creates the states, alphabet or stack alphabet depending on mode
 *
 * @param[in]  textLine  The text line
 * @param[in]  mode      The mode
 */
void APv::dataSaver (std::string textLine, int mode) {
	int counter = 0;
	std::string aux;
	Alphabet tmp;
	State newState;
	while (counter <= textLine.length()) {
		if (textLine[counter] != ' ' && textLine[counter] != '\n' && textLine[counter] != '\0') {
			aux += textLine[counter];
		}
		else {
			switch (mode) {
				case 0: // Case States
					newState.set_StateID(aux);
					addState(newState);
					break;

				case 1:	// Case automaton Alphabet
					alphabet_.addElement(aux);
					break;

				case 2:	// Case stack Alphabet
					tmp.addElement(aux);
					break;

				default:
					std::cout << "Error, mode not avalaible";
					exit(1);
					break;
			}	
			aux = "";
		}
		counter++;
	}
	if (mode == 2) {
		stack_.set_StackAlphabet(tmp);
	}
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
std::vector<Transition> APv::getNextTransitions (State aux, std::string chainSymbol, std::string stackSymbol) {
	std::vector<Transition> possibleTransitions;
	for (Transition trans : aux.get_Transitions()) {
		if ((trans.get_ChainSymbol() == chainSymbol) && (trans.get_TopStackSymbol() == stackSymbol)) {
			possibleTransitions.push_back(trans);
		}
	}
	return possibleTransitions;
}


/**
 * @brief      Determines if the given data is a valid data.
 *
 * @param[in]  data  The data
 * @param[in]  mode  The mode
 *
 * @return     True if valid data, False otherwise.
 */
bool APv::isValidData (std::string data, int mode) {
	switch (mode) {
		case 0:
			if (findState(data) != -1) {
				return true;
			}
			return false;
			break;

		case 1:
			if (get_Alphabet().isInAlphabet(data) || data == ".") {
				return true;
			}
			return false;
			break;

		case 2:
			if (get_Stack().get_StackAlphabet().isInAlphabet(data) || data == ".") {
				return true;
			}
			return false;
			break;

		default:
			std::cout << std::endl << "Error, not mode avalaible";
			break;
	}
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

bool APv::tryChain (std::string chain, int currentState) {
	if ((chain == "") && (stack_.get_StackSize() == 0)) {
		return true;
	}
	else {
		std::string symbol = "";
		std::vector<Transition> possibleTransitions;
		symbol = chain[0];
		for (int i = 0; i < states_[currentState].get_TransitionsNumber(); i++) {
			if ((states_[currentState].get_Transitions()[i].get_ChainSymbol() == symbol) || (states_[currentState].get_Transitions()[i].get_ChainSymbol() == ".")) {
				if ((states_[currentState].get_Transitions()[i].get_TopStackSymbol() == stack_.top()) || (states_[currentState].get_Transitions()[i].get_TopStackSymbol() == ".")) {
					possibleTransitions.push_back(states_[currentState].get_Transitions()[i]);
				}
			}
		}
		if (possibleTransitions.size() == 0) {
			return false;
		}
		else {		
			for (int i = 0; i < possibleTransitions.size(); i++) {
				bool test = false;
				int nextState = findState(possibleTransitions[i].get_NextState());
				std::string newChain = "";
				if (possibleTransitions[i].get_TopStackSymbol() != ".") {
					stack_.pop();
				}

				if (possibleTransitions[i].get_InsertStackSymbol()[0] != ".") {
					for (int j = 0; j < possibleTransitions[i].get_InsertStackSymbol().size(); j++) {
						stack_.push(possibleTransitions[i].get_InsertStackSymbol()[j]);
					}
				}
				if (possibleTransitions[i].get_ChainSymbol() != ".") {
					for (int i = 1; i < chain.length(); i++) {
						newChain += chain[i];
					}
				}
				else {
					newChain = chain;
				}
				test = tryChain(newChain, nextState);
				if (test == true) {
					path_.push_back(possibleTransitions[i]);
					return true;
				}
			}
			return false;
		}

	}
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

/**
 * @brief      Generates and inserts a transition on the right state
 *
 * @param[in]  str   The string with the transition data
 */
void APv::generateTransition (std::string str) {
	Transition newTransition;
	std::string tmp = "";
	int counter = 0;
	int elementCounter = 0;
	std::vector<std::string> stackSymbols;
	while (counter <= str.length()) {
		if ((str[counter] != ' ' && str[counter] != '\n' && str[counter] != '\0')) {
			tmp += str[counter];
		}
		else {
			switch (elementCounter) {
				case 0:
					if (isValidData(tmp, 0)) {
						newTransition.set_CurrentState(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid current state for transition";
						exit(1);
					}
					break;

				case 1:
					if (isValidData(tmp, 1)) {
						newTransition.set_ChainSymbol(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid alphabet element for transition";
						exit(1);
					}
					break;

				case 2:
					if (isValidData(tmp, 2)) {
						newTransition.set_TopStackSymbol(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid stack symbol for transition";
						exit(1);
					}
					break;

				case 3:
					if (isValidData(tmp, 0)) {
						newTransition.set_NextState(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid nextState for transition";
						exit(1);
					}
					break;

				case 4:
					if (isValidData(tmp, 2)) {
						stackSymbols.push_back(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid insertStackSymbol for transition";
						exit(1);
					}
					break;

				default:
					std::cout <<std::endl << "Error while generate transitions";
					exit(1);
					break;
			}
			tmp = "";
			if (elementCounter < 4) {
				elementCounter++;
			}
		}
		counter++;
	}
	newTransition.set_InsertStackSymbol(stackSymbols);
	int pos = findState(newTransition.get_CurrentState());
	states_[pos].addTransition(newTransition);
	//newTransition.printTransition(std::cout);
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
		dataSaver(sentinel, 0);
		// Generate the automaton alphabet form the second line.
		getline(input, sentinel);
		dataSaver(sentinel, 1);

		// Generate the stack alphabet form the second line.
		getline(input, sentinel);
		dataSaver(sentinel, 2);

		// Search if start state is a valid one. and sets it
		getline(input, sentinel);
		sentinel = eraseSpaces(sentinel);
		if (isValidData(sentinel, 0)) {
			initialState_.set_StateID(sentinel);
		}

		// Search if start stack element is a valid one. and sets it
		getline(input, sentinel);
		sentinel = eraseSpaces(sentinel);
		if (isValidData(sentinel, 2)) {
			stack_.push(sentinel);
		}
		
		// Transitions generations
		while (!input.eof()) {
			getline(input, sentinel);
			generateTransition(sentinel);
		}
	}
}
