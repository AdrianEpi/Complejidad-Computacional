/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 2. Simulador de Máquina de Turing         =
    =            File name:     tape.hpp                                           =
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
* @Date:   2020-10-24 12:45:19
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-24 14:19:01
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/tape.hpp"

/*------------------------------------------------*/


/**
 * @brief      Constructs a new instance.
 */
Tape::Tape (void) {
	tape_.resize(MAX_SIZE);
	set_ReadHead(MAX_SIZE / 2);
	set_WriteHead(MAX_SIZE / 2);
	set_TapeSize(MAX_SIZE);
	set_BlankSymbol(".");
}

/**
 * @brief      Destroys the object.
 */
Tape::~Tape (void) {
}

/**
 * @brief      Gets the tape.
 *
 * @return     The tape.
 */
std::vector<std::string> Tape::get_Tape (void) const {
	return tape_;
}

/**
 * @brief      Gets the read head.
 *
 * @return     The read head.
 */
unsigned Tape::get_ReadHead (void) const {
	return readHead_;
}

/**
 * @brief      Gets the write head.
 *
 * @return     The write head.
 */
unsigned Tape::get_WriteHead (void) const {
	return writeHead_;
}

/**
 * @brief      Gets the tape alphabet.
 *
 * @return     The tape alphabet.
 */
Alphabet Tape::get_TapeAlphabet (void) const {
	return tapeAlphabet_;
}

/**
 * @brief      Gets the blank symbol.
 *
 * @return     The blank symbol.
 */
std::string Tape::get_BlankSymbol (void) const {
	return blankSymbol_;
}

/**
 * @brief      Gets the tape size.
 *
 * @return     The tape size.
 */
unsigned Tape::get_TapeSize (void) const {
	return tapeSize_;
}

/**
 * @brief      Sets the tape.
 *
 * @param[in]  newTape  The new tape
 */
void Tape::set_Tape (std::vector<std::string> newTape) {
	tape_ = newTape;
}

/**
 * @brief      Sets the read head.
 *
 * @param[in]  newReadHead  The new read head
 */
void Tape::set_ReadHead (unsigned newReadHead) {
	readHead_ = newReadHead;
}

/**
 * @brief      Sets the write head.
 *
 * @param[in]  newWriteHead  The new write head
 */
void Tape::set_WriteHead (unsigned newWriteHead) {
	writeHead_ = newWriteHead;
}

/**
 * @brief      Sets the tape alphabet.
 *
 * @param[in]  newTapeAlphabet  The new tape alphabet
 */
void Tape::set_TapeAlphabet (Alphabet newTapeAlphabet) {
	tapeAlphabet_ = newTapeAlphabet;
}

/**
 * @brief      Sets the blank symbol.
 *
 * @param[in]  newBlankSymbol  The new blank symbol
 */
void Tape::set_BlankSymbol (std::string newBlankSymbol) {
	blankSymbol_ = newBlankSymbol;
}

/**
 * @brief      Sets the tape size.
 *
 * @param[in]  newSize  The new size
 */
void Tape::set_TapeSize (unsigned newSize) {
	tapeSize_ = newSize;
}

/**
 * @brief      Resizes the tape and introduces ne new word
 *
 * @param[in]  word  The word
 */
void Tape::introduceWord (std::vector<std::string> word) {
	tape_.resize(get_TapeSize());
	set_ReadHead(get_TapeSize() / 2);
	set_WriteHead(get_TapeSize() / 2);
	for (int i = 0; i < tape_.size(); i++) {
		tape_[i] = get_BlankSymbol();
	}
	bool longWord = false;
	for (int i = 0; i < word.size(); i++) {
		assert(tapeAlphabet_.isInAlphabet(word[i]));
		if (writeHead_ >= get_TapeSize()) {
			tape_.push_back(word[i]);
			longWord = true;
		}
		else {
			tape_[writeHead_] = word[i];
		}
		writeHead_++;
	}
	set_WriteHead(get_TapeSize() / 2);
	if (longWord) {
		for (int i = 0; i < get_TapeSize() / 2; i++) {
			tape_.push_back(get_BlankSymbol());
		}
	}
	set_TapeSize(tape_.size());
}

/**
 * @brief      Moves the read and write heads one position to the left
 */
void Tape::moveleft (void) {
	if (writeHead_ == 0 || readHead_ == 0) {
		std::cout << std::endl << "Error, position -1 unavalaible." << std::endl;
		exit(1);
	}
	writeHead_--;
	readHead_--;
}

/**
 * @brief      Moves the read and write heads one position to the right
 */
void Tape::moveRight (void) {
	if (writeHead_ == get_TapeSize() - 1 || readHead_ == get_TapeSize() - 1) {
		tape_.push_back(get_BlankSymbol());
		set_TapeSize(get_TapeSize() + 1);
	}
	writeHead_++;
	readHead_++;
}

/**
 * @brief      Writes a symbol on the tape at the writeHead's position.
 *
 * @param[in]  symbol  The symbol
 */
void Tape::writeSymbol (std::string symbol) {
	assert(tapeAlphabet_.isInAlphabet(symbol));
	tape_[writeHead_] = symbol;
}

/**
 * @brief      Reads the symbol of tape at the readHead's position.
 *
 * @return     The symbol
 */
std::string Tape::readSymbol (void) const {
	return tape_[readHead_];
}

/**
 * @brief      Prints the tape.
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& Tape::printTape (std::ostream& os) const {
	bool started = false;
	os << std::endl << "Tape -> ";
	for (int i = 0; i < get_TapeSize(); i++) {
		if (tape_[i] != get_BlankSymbol()) {
			started = true;
			os << tape_[i] << " ";
		}
		if (started == true && tape_[i] == get_BlankSymbol()) {
			break;
		}
	}
	return os;
}
