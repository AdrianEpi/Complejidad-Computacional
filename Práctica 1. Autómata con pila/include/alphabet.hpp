/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     alphabet.hpp                                       =
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
#include <set>

/*------------------------------------------------*/

/**
 * @brief      This class describes an alphabet for the stack automaton.
 */
class Alphabet {

    private:
        // Attributes
        std::set<std::string> alphabet_;    // The set of the characters or elements for the alphabet

    public:
        // Builders & Destroyer
        Alphabet (void);
        ~Alphabet (void);

        // Getters & Setters
        std::set<std::string> get_Alphabet (void) const;
        void set_Alphabet (std::set<std::string> newAlphabet);

        // Operatos Overload
        Alphabet& operator= (const Alphabet& newAlphabet);

        // Functions
        void addElement (std::string newElement);
        int getSize (void) const;
        bool isInAlphabet (std::string element);

        // Write
        std::ostream& printAlphabet (std::ostream& os) const;

};