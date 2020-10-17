/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     APv.hpp                                            =
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
#include "stack.hpp"
#include "state.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <fstream>

#include <set>
#include <cstring>

/*------------------------------------------------*/

class APv {

    private:
        // Attributes
        Alphabet alphabet_;             // The alphabet recognized by the automaton
        std::vector<State> states_;     // The vector of all the states of the automaton
        unsigned statesNum_;            // The ammount of states that the automaton has
        State initialState_;            // The idientifier of the initial state
        std::string inputFile_;         // The input file name
        Stack stack_;                   // The stack used by the state
        std::vector<Transition> path_;  // The path that the automaton follows to know if the given chain is recognized or not by the automaton

    public:
        // Builders & Destroyer
        APv (void);
        APv (std::string inputFile);
        ~APv (void);

        // Getters & Setters
        Alphabet get_Alphabet (void) const;
        std::vector<State> get_States (void) const;
        unsigned get_StatesNum (void) const;
        State get_InitialState (void) const;
        std::string get_InputFile (void) const;
        Stack get_Stack (void) const;
        std::vector<Transition> get_Path (void) const;

        void set_Alphabet (Alphabet newAlphabet);
        void set_States (std::vector<State> newStates);
        void set_StatesNum (unsigned newStatesNum);
        void set_InitialState (State newInitialState);
        void set_InputFile (std::string newInputFile);
        void set_Stack (Stack newStack);
        void set_Path (std::vector<Transition> newPath);

        // Functions
        void dataSaver (std::string textLine, int mode); // Modes: 0 -> state, 1 -> automaton alphabet, 2 -> stack alphabet
        void addState (State newState);
        std::vector<Transition> getNextTransitions (State aux, std::string chainSymbol, std::string stackSymbol);
        int findState (std::string id);
        bool isValidData (std::string element, int mode); // Modes: 0 -> state, 1 -> automaton alphabet, 2 -> stack alphabet
        bool tryChain (std::string chain, int currentState);
        bool isChainAccepted (std::string chain, std::string stateID);
        std::string eraseSpaces (std::string str);
        void generateTransition (std::string str);

        // Read & Write
        void readData (std::string inputFile);

};