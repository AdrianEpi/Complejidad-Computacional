/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     stack.cpp                                          =
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
* @Date:   2020-10-12 15:52:04
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-23 09:15:17
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/stack.hpp"

/*------------------------------------------------*/

/**
 * @brief      Constructs a new instance.
 */
Stack::Stack (void) {
	set_StackSize(0);
}

/**
 * @brief      Destroys the object.
 */
Stack::~Stack (void) {
}

/**
 * @brief      Gets the stack.
 *
 * @return     The stack.
 */
std::stack<std::string> Stack::get_Stack (void) const {
	return stack_;
}

/**
 * @brief      Gets the stack size.
 *
 * @return     The stack size.
 */
unsigned Stack::get_StackSize (void) const {
	return size_;
}

/**
 * @brief      Gets the stack alphabet.
 *
 * @return     The stack alphabet.
 */
Alphabet Stack::get_StackAlphabet (void) const {
	return alphabet_;
}

/**
 * @brief      Sets the stack.
 *
 * @param[in]  newStack  The new stack
 */
void Stack::set_Stack (std::stack<std::string> newStack) {
	stack_ = newStack;
}

/**
 * @brief      Sets the stack size.
 *
 * @param[in]  size  The size
 */
void Stack::set_StackSize (unsigned size) {
	size_ = size;
}

/**
 * @brief      Sets the stack alphabet.
 *
 * @param[in]  newAlphabet  The new alphabet
 */
void Stack::set_StackAlphabet (Alphabet newAlphabet) {
	alphabet_ = newAlphabet;
}

/**
 * @brief      Assignment operator.
 *
 * @param[in]  newStack  The new stack
 *
 * @return     The result of the assignment
 */
Stack& Stack::operator= (const Stack& newStack) {
	set_StackSize(newStack.get_StackSize());
	set_Stack(newStack.get_Stack());
	set_StackAlphabet(newStack.get_StackAlphabet());
	return *this;
}

/**
 * @brief      Determines if the stack is empty.
 *
 * @return     True if empty, False otherwise.
 */
bool Stack::isEmpty (void) {
	if (get_StackSize() == 0) {
		return true;
	}
	return false;
}

/**
 * @brief      Shows the top element form the stack.
 *
 * @return     The top element of the stack
 */
std::string Stack::top (void) {
	if (isEmpty()) {
		return "";
	}
	return stack_.top();
}

/**
 * @brief      Deletes the top element form the stack.
 */
void Stack::pop (void) {
	if (!isEmpty()) {
		stack_.pop();
		size_--;
	}
}

/**
 * @brief      Pushs an element into the stack
 *
 * @param[in]  element  The element
 */
void Stack::push (std::string element) {
	stack_.push(element);
	size_++;
}

/**
 * @brief      Prints a stack.
 *
 * @param      os    The output stream
 *
 * @return     The output stream
 */
std::ostream& Stack::printStack (std::ostream& os) {
	Stack tmpStack = *this;
	while(!tmpStack.isEmpty()) {
		os << tmpStack.top();
		tmpStack.pop();
	}
}
