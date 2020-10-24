/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 2. Simulador de Máquina de Turing         =
    =            File name:     transition.hpp                                     =
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

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <vector>

/*------------------------------------------------*/

/**
 * @brief      This class describes a transition, a transition is made from the current state
 *             to the next state. The chainSymbol and the writesymbol are needed to make the
 *             the transition. 
 */
class Transition {

    private:
        // Attributes
        int transitionID_;          // The identifier of the transition
        std::string chainSymbol_;   // The needed chain symbol
        std::string writeSymbol_;   // The symbol that is going to be written in the tape
        std::string currentState_;  // The current state's name
        std::string nextState_;     // The next state's name
        unsigned movement_;         // The movemente thats going to make the tape after transition
                                    // 0 -> Stay (S)
                                    // 1 -> Left (L)
                                    // 2 -> Right (R)                      

    public:
        // Builders & Destroyer
        Transition (void);
        Transition (const Transition& auxTransition);
        ~Transition (void);

        // Getters & Setters
        int get_TransitionID (void) const;
        std::string get_ChainSymbol (void) const;
        std::string get_WriteSymbol (void) const;
        std::string get_CurrentState (void) const;
        std::string get_NextState (void) const;
        unsigned get_Movement (void) const;

        void set_TransitionID (int newID);
        void set_ChainSymbol (std::string newChainSymbol);
        void set_WriteSymbol (std::string newWriteSymbol);
        void set_CurrentState (std::string newCurrentState);
        void set_NextState (std::string newNextState);
        void set_Movement (unsigned move);

        // Operators Overload
        Transition operator= (const Transition& newTransition);
        bool operator== (const Transition& auxTransition) const;
        bool operator!= (const Transition& auxTransition) const;
        bool operator< (const Transition& auxTransition) const;

        // Write
        std::ostream& printTransition (std::ostream& os) const;

};