/*=======================================================================================
=========================================================================================
    =                                                                              =
    =            Proyect:       Práctica 2. Simulador de Máquina de Turing         =
    =            File name:     main.cpp                                           =
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
/*
* @Author: Adrian Epifanio
* @Date:   2020-10-11 21:44:58
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-10-25 14:09:03
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/turingMachine.hpp"

/*------------------------------------------------*/

/**
 * @brief      Main function of the program
 *
 */
int main (void) {
    TuringMachine test;
    test.readData("../inputs/Ejemplo_MT.txt");
    test.get_Alphabet().printAlphabet(std::cout);
    bool tryX = test.tryChain("011000");
    test.get_Tape().printTape(std::cout);
    std::cout << std::endl << "CADENA " << tryX << std::endl;
}

