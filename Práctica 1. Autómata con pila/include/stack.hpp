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
        std::stack<char> stack_; // The stack where the elements will be stored
        unsigned size_;                 // The stack's size
        Alphabet alphabet_;             // The alphabet recognized by the stack

    public:
        // Builders & Destroyer
        Stack (void);
        ~Stack (void);

        // Getters & Setters
        std::stack<char> get_Stack (void) const;
        unsigned get_StackSize (void) const;
        Alphabet get_StackAlphabet (void) const;

        void set_Stack (std::stack<char> newStack);
        void set_StackSize (unsigned size);
        void set_StackAlphabet (Alphabet newAlphabet);

        // Functions
        bool isEmpty (void);
        char top (void);
        void pop (void);
        void push (char element);

        // Write
        std::ostream& printStack (std::ostream& os);

};