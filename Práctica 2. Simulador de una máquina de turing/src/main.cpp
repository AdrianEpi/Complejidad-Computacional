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
* @Last Modified time: 2020-10-24 19:12:34
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/turingMachine.hpp"

/*------------------------------------------------*/

/**
 * @brief      Main function of the program
 *
 */
int main (void) {
    /*std::string textFile = "";
    std::cout << std::endl << "Bienvenido al simulador de un autómata de pila por vaciado TuringMachine";
    std::cout << std::endl << "Por favor introduce el nombre del fichero de entrada con los datos del autómata: ";
    std::cin >> textFile;*/
    /*Tape test;
    std::vector<std::string> word;
    std::string a = "a";
    Alphabet newAlphabet;
    newAlphabet.addElement(a);
    test.set_TapeAlphabet(newAlphabet);
    for (int i = 0; i < 10; i++)
        word.push_back(a);
    test.introduceWord(word);
    test.printTape(std::cout);*/
    TuringMachine test;
    test.readData("../inputs/Ejemplo_MT.txt");
    test.get_Alphabet().printAlphabet(std::cout);
    test.get_Tape().printTape(std::cout);
}

