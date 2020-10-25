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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 
#include "alphabet.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <vector>
#include <cassert>
#define MAX_SIZE 200

/*------------------------------------------------*/

class Tape {

    private:
        // Attributes
        std::vector<std::string> tape_;     // The tape
        unsigned readHead_;                 // The position of the reading head in the vector
        unsigned writeHead_;                // The position of the writing head in the vector
        Alphabet tapeAlphabet_;             // The alphabet recognized by the tape
        std::string blankSymbol_;            // The symbol that is going to represent a blank in the tape
        unsigned tapeSize_;

    public:
        // Builders & Destroyer
        Tape (void);
        ~Tape (void);

        // Getters & Setters
        std::vector<std::string> get_Tape (void) const;
        unsigned get_ReadHead (void) const;
        unsigned get_WriteHead (void) const;
        Alphabet get_TapeAlphabet (void) const;
        std::string get_BlankSymbol (void) const;
        unsigned get_TapeSize (void) const;

        void set_Tape (std::vector<std::string> newTape);
        void set_ReadHead (unsigned newReadHead);
        void set_WriteHead (unsigned newWriteHead);
        void set_TapeAlphabet (Alphabet newTapeAlphabet);
        void set_BlankSymbol (std::string newBlankSymbol);
        void set_TapeSize (unsigned size);

        // Functions
        void introduceWord (std::vector<std::string> word);
        void moveLeft (void);
        void moveRight (void);
        void writeSymbol (std::string symbol);
        std::string readSymbol (void) const;

        // Write
        std::ostream& printTape (std::ostream& os) const;
};