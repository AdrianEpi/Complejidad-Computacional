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
* @Last Modified time: 2020-10-25 10:30:20
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
 * @brief      Gets the accepted states.
 *
 * @return     The accepted states.
 */
std::vector<int> TuringMachine::get_AcceptedStates (void) const {
	return acceptedStates_;
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
 * @brief      Gets the tape.
 *
 * @return     The tape.
 */
Tape TuringMachine::get_Tape (void) const {
	return tape_;
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
 * @brief      Sets the accepted states.
 *
 * @param[in]  newAcceptedStates  The new accepted states
 */
void TuringMachine::set_AcceptedStates (std::vector<int> newAcceptedStates) {
	acceptedStates_ = newAcceptedStates;
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

/**
 * @brief      Sets the tape.
 *
 * @param[in]  newTape  The new tape
 */
void TuringMachine::set_Tape (Tape newTape) {
	tape_ = newTape;
}

/**
 * @brief      Stores the data
 *
 * @param[in]  textLine  The text line
 * @param[in]  mode      The mode
 */
void TuringMachine::dataSaver (std::string textLine, int mode) { // Modes: 0 -> state, 1 -> automaton alphabet, 2 -> tape alphabet, 3 -> accepted states
	int counter = 0;
	std::string aux;
	Alphabet tmp;
	State newState;
	while (counter <= textLine.length()) {
		if ((textLine[counter] != ' ') && (textLine[counter] != '\n') && (textLine[counter] != '\0')) {
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

				case 2:	// Case tape Alphabet
					tmp.addElement(aux);
					break;

				case 3: // Case accepted states
					if (findState(aux) != -1) {
						acceptedStates_.push_back(findState(aux));
					}
					else {
						std::cout << std::endl << "Error, trying to set an non existing accepted state" << std::endl;
						exit(1);
					}
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
		tape_.set_TapeAlphabet(tmp);
	}
}

/**
 * @brief      Adds a state.
 *
 * @param[in]  newState  The new state
 */
void TuringMachine::addState (State newState) {
	states_.push_back(newState);
}

/**
 * @brief      Finds a state in the vector.
 *
 * @param[in]  id    The identifier
 *
 * @return     The position of that state in the vectors state.
 */
int TuringMachine::findState (std::string id) {
	for (int i = 0; i < get_States().size(); i++) {
		if (states_[i].get_StateID() == id) {
			return i;
		}
	}
	return -1;
}

/**
 * @brief      Determines if valid data.
 *
 * @param[in]  element  The element
 * @param[in]  mode     The mode
 *
 * @return     True if valid data, False otherwise.
 */
bool TuringMachine::isValidData (std::string element, int mode) { // Modes: 0 -> state, 1 -> automaton alphabet
	switch (mode) {
		case 0:
			if (findState(element) != -1) {
				return true;
			}
			return false;
			break;

		case 1:
			if (get_Alphabet().isInAlphabet(element) || element == ".") {
				return true;
			}
			return false;
			break;

		case 2:
			if (tape_.get_TapeAlphabet().isInAlphabet(element) || element == ".") {
				return true;
			}
			return false;
			break;

		default:
			std::cout << std::endl << "Error, not validData mode avalaible";
			exit(1);
			break;
	}
}

/**
 * @brief      Erase the spaces of a given word or line
 *
 * @param[in]  str   The string
 *
 * @return     The string without spaces or special characters
 */
std::string TuringMachine::eraseSpaces (std::string str) {
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
 * @param[in]  id    The transition identifier
 */
void TuringMachine::generateTransition (std::string str, int id) {
	Transition newTransition;
	std::string tmp = "";
	int counter = 0;
	int elementCounter = 0;
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
						std::cout << "------" << tmp << "-----";
						std::cout << std::endl << "Error, not valid alphabet element for transition";
						exit(1);
					}
					break;

				case 2:
					if (isValidData(tmp, 0)) {
						newTransition.set_NextState(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid nextState for transition";
						exit(1);
					}
					break;

				case 3:
					if (isValidData(tmp, 2)) {
						newTransition.set_WriteSymbol(tmp);
					}
					else {
						std::cout << std::endl << "Error, not valid write symbol for transition";
						exit(1);
					}
					break;

				case 4:
					if (tmp == "S") {
						newTransition.set_Movement(0);
					}

					else if (tmp == "L") {
						newTransition.set_Movement(1);
					}

					else if (tmp == "R") {
						newTransition.set_Movement(2);
					}

					else {
						std::cout << std::endl << "Error, not valid movement for transition" << std::endl;
						exit(1);
					}
					break;

				default:
					std::cout <<std::endl << "Error while generate transitions";
					exit(1);
					break;
			}
			tmp = "";
			elementCounter++;
		}
		counter++;
	}
	newTransition.set_TransitionID(id);
	int pos = findState(newTransition.get_CurrentState());
	states_[pos].addTransition(newTransition);
	newTransition.printTransition(std::cout);
}

void TuringMachine::readData (std::string inputFile) {
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
		// Generate the states from the first line (0)
		dataSaver(sentinel, 0);
		// Generate the automaton alphabet form the second line (1).
		getline(input, sentinel);
		dataSaver(sentinel, 1);
		// Generate the tape alphabet form the second line.
		getline(input, sentinel);
		dataSaver(sentinel, 2);
		// Search if start state is a valid one and sets it
		getline(input, sentinel);
		sentinel = eraseSpaces(sentinel);
		if (isValidData(sentinel, 0)) {
			initialState_.set_StateID(sentinel);
		}
		// Search if blank element is a valid one and sets it
		getline(input, sentinel);
		sentinel = eraseSpaces(sentinel);
		if (get_Alphabet().isInAlphabet(sentinel)) {
			tape_.set_BlankSymbol(sentinel);
		}
		// Accepted states
		getline(input, sentinel);
		dataSaver(sentinel, 3);
		// Transitions generations
		int transitionCounter = 1;
		while (!input.eof()) {
			getline(input, sentinel);
			generateTransition(sentinel, transitionCounter);
			transitionCounter++;
		}
	}
}
