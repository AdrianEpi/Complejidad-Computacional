/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 2. Simulador de Máquina de Turing         =
    =            File name:     turingMachine.hpp                                  =
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
#include "state.hpp"
#include "alphabet.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <cstring>

/*------------------------------------------------*/

class TuringMachine {

    private:
        // Attributes
        Alphabet alphabet_;             // The alphabet recognized by the automaton
        std::vector<State> states_;     // The vector of all the states of the automaton
        unsigned statesNum_;            // The ammount of states that the automaton has
        State initialState_;            // The idientifier of the initial state
        std::string inputFile_;         // The input file name
        //Tape tape_;                     // The turing machine tape

    public:
        // Builders & Destroyer
        TuringMachine (void);
        TuringMachine (std::string inputFile);
        ~TuringMachine (void);

        // Getters & Setters
        Alphabet get_Alphabet (void) const;
        std::vector<State> get_States (void) const;
        unsigned get_StatesNum (void) const;
        State get_InitialState (void) const;
        std::string get_InputFile (void) const;
        //Tape get_Tape (void) const;

        void set_Alphabet (Alphabet newAlphabet);
        void set_States (std::vector<State> newStates);
        void set_StatesNum (unsigned newStatesNum);
        void set_InitialState (State newInitialState);
        void set_InputFile (std::string newInputFile);
        //void set_Tape (Tape newTape);

        // Functions
       

        // Read & Write
        

};