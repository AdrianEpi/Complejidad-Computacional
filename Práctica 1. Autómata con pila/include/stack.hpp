/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     stack.hpp                                          =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 
#include "alphabet.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <stack>
#include <cassert>

/*------------------------------------------------*/

/**
 * @brief      This class describes a stack for an automaton.
 */
class Stack {

    private:
        // Attributes
        std::stack<std::string> stack_; // The stack where the elements will be stored
        unsigned size_;                 // The stack's size
        Alphabet alphabet_;             // The alphabet recognized by the stack

    public:
        // Builders & Destroyer
        Stack (void);
        ~Stack (void);

        // Getters & Setters
        std::stack<std::string> get_Stack (void) const;
        unsigned get_StackSize (void) const;
        Alphabet get_StackAlphabet (void) const;

        void set_Stack (std::stack<std::string> newStack);
        void set_StackSize (unsigned size);
        void set_StackAlphabet (Alphabet newAlphabet);

        // Operators overload
        Stack& operator= (const Stack& newStack);

        // Functions
        bool isEmpty (void);
        std::string top (void);
        void pop (void);
        void push (std::string element);

        // Write
        std::ostream& printStack (std::ostream& os);

};