/*=====================================================================================================
=======================================================================================================
    =                                                                                            =
    =            Proyect:       Práctica 3. Implementación de Funciones Recursivas Primitivas    =
    =            File name:     PRF.hpp                                                          =
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
/*------------------  FUNCTIONS  -----------------*/

#pragma once 

/*------------------------------------------------*/
/*------------------  LIBRARIES  -----------------*/

#include <iostream>
#include <vector>
#include <cassert>

/*------------------------------------------------*/
class PrimitveRecursiveFunction {
    
    public:
        // Builder & Destroyer
        PrimitveRecursiveFunction (void);
        ~PrimitveRecursiveFunction (void);

        // Initial Functions
        int zeroFunction (int x);
        int sucessorFunction (int x);
        int projectionFunction (std::vector<int> vector, int position);

        // Recursive Functions
        int number (int x);
        int predecessor (int x);
        int add (int x, int y);
        int multiplication (int x, int y);
        int pow (int x, int y);
};