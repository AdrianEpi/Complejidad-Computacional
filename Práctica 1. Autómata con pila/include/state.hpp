/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     state.hpp                                          =
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
#include "transition.hpp"

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <set>

/*------------------------------------------------*/

/**
 * @brief      This class describes a state of the automaton.
 */
class State {

    private:
        // Attributes   
        std::string id_;                       // The identifier of the state 0, 1, 2, 3...
        unsigned transitionsNumber_;        // The ammount of transitions for the state
        std::set<Transition> transitions_;  // The set of transitions of the state

    public:
        // Builders & destroyer
        State (void);
        State (const State& newSate);
        ~State (void);

        // Getters & Setters
        std::string get_SateID (void) const;
        unsigned get_TransitionsNumber (void) const;
        std::set<Transition> get_Transitions (void) const;

        void set_SateID (std::string id);
        void set_TransitionsNumber (unsigned transitionsNumber);
        void set_Transitions (std::set<Transition> transitions);

        // Operatoros Overload
        State& operator= (const State& newState);
        bool operator!= (const State& auxState) const;
        bool operator== (const State& auxState) const;
        bool operator< (const State& auxState) const;

        // Functions
        void addTransition (const Transition& newTransition);

        // Write
        std::ostream& printState (std::ostream& os) const;
};