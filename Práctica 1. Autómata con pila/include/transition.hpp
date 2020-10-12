/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     transition.hpp                                     =
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

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>

/*------------------------------------------------*/

class Transition {

    private:
        // Attributes
        char chainSymbol_;                      // The needed chain symbol
        char topStackSymbol_;                   // The needed top stack symbol
        std::vector<char> insertStackSymbol_;   // The symbols that are going to be inserted in stack
        std::string nextState_;                 // The next state's name

    public:
        // Builders & Destroyer
        Transition (void);
        Transition (const Transition& auxTransition);
        ~Transition (void);

        // Getters & Setters
        char get_ChainSymbol (void) const;
        char get_TopStackSymbol (void) const;
        std::vector<char> get_InsertStackSymbol (void) const;
        std::string get_NextState (void) const;

        void set_ChainSymbol (char newChainSymbol);
        void set_TopStackSymbol (char newTopStackSymbol);
        void set_InsertStackSymbol (std::vector<char> newInsertStackSymbol);
        void set_NextState (std::string newNextState);

        // Operators Overload
        Transition operator= (const Transition& newTransition);
        bool operator== (const Transition& auxTransition) const;
        bool operator!= (const Transition& auxTransition) const;
        bool operator< (const Transition& auxTransition) const;

        // Functions
        std::ostream& printTransition (std::ostream& os) const;

};