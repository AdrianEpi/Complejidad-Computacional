/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 1. Autómata con pila                      =
    =            File name:     main.cpp                                           =
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
* @Date:   2020-10-11 21:44:58
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-17 20:39:33
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/APv.hpp"

/*------------------------------------------------*/

int main (void) {
    /*State n;
    Alphabet a;
    Stack s;
    Transition t;
    a.printAlphabet(std::cout);
    s.printStack(std::cout);
    t.printTransition(std::cout);
    n.printState(std::cout);*/
    APv asd;
    asd.readData("../inputs/APv-2.txt");
    bool tryS = asd.tryChain("01010101", 0);
    std::cout << std::endl << "CADENA" << tryS << std::endl;

}