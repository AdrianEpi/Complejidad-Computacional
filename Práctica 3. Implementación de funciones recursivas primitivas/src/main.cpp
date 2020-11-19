/*=====================================================================================================
=======================================================================================================
    =                                                                                            =
    =            Proyect:       Práctica 3. Implementación de Funciones Recursivas Primitivas    =
    =            File name:     main.cpp                                                         =
    =            Author:        Adrián Epifanio Rodríguez Hernández                              =
    =            Date:          12/11/2020                                                       =
    =            Subject:       Complejidad Computacional                                        =
    =            Language:      C++                                                              =
    =            Email:         alu0101158280@ull.edu.es                                         =
    =            Place:         Universidad De La Laguna                                         =
    =                           Escuela Superior de Ingeniería y Tecnología                      =
    =                                                                                            =
=======================================================================================================
=====================================================================================================*/
/*
* @Author: Adrian Epifanio
* @Date:   2020-11-12 20:09:53
* @Last Modified by:   Adrian Epifanio
* @Last Modified time: 2020-11-19 11:29:05
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/PRF.hpp"

/*------------------------------------------------*/

int main (void) {
    int base, exp;
    std::cout << std::endl << "Introduce the base of the pow number: ";
    std::cin >> base;
    std::cout << std::endl << "Introduce the exponent of the pow number: ";
    std::cin >> exp;
	PrimitveRecursiveFunction pow;
	std::cout <<std::endl << pow.pow(base, exp) << std::endl;
}