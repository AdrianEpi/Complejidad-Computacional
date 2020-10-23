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
* @Last Modified time: 2020-10-23 11:30:40
*/
/*------------------  FUNCTIONS  -----------------*/

#include "../include/APv.hpp"

/*------------------------------------------------*/

void menu(APv automaton);
void multichain (APv automaton);

/**
 * @brief      Main function of the program
 *
 */
int main (void) {
    std::string textFile = "";
    std::cout << std::endl << "Bienvenido al simulador de un autómata de pila por vaciado APV";
    std::cout << std::endl << "Por favor introduce el nombre del fichero de entrada con los datos del autómata: ";
    std::cin >> textFile;

    APv automaton;
    automaton.readData(textFile);
    menu(automaton);
}

/**
 * @brief      Prints the menu by console and calls the function that is selected on each moment
 *
 * @param      automaton  The automaton
 */
void menu (APv automaton) {
    int sentinel = 1;
    while (sentinel != 0) {
        std::cout << std::endl <<std::endl << " ---- Menu del Autómata ----";
        std::cout << std::endl << "\t1. Probar una cadena introducida manualmente.";
        std::cout << std::endl << "\t2. Probar conjunto de cadenas introducidas desde fichero.";
        std::cout << std::endl << "\t3. Activar modo traza.";
        std::cout << std::endl << "\t4. Desactivar modo traza.";
        std::cout << std::endl << "\t0. Salir del programa" << std::endl;
        std::cin >> sentinel;
        system("clear");
        bool tryChain;
        std::string chain;
        switch (sentinel) {
            case 0:
                std::cout << std::endl << "Programa finalizado con éxito" << std::endl;
                exit(0);
                break;

            case 1:
                automaton.get_Alphabet().printAlphabet(std::cout);
                std::cout << std::endl << "Introduzca la palabra: ";
                std::cin >> chain;
                if (automaton.get_ShowTrace()) {
                    std::cout << "Estado\t\tEntrada\t\t\tPila\t\t  Acción" << std::endl;
                }
                tryChain = automaton.tryChain(chain, 0, automaton.get_Stack());
                if (tryChain) {
                    std::cout << std::endl << "La cadena introducida pertenece al lenguaje.";
                }
                else {
                    std::cout << std::endl << "La cadena introducida no pertenece al lenguaje.";
                }
                break;

            case 2:
                multichain(automaton);
                break;

            case 3:
                automaton.set_ShowTrace(true);
                break;

            case 4:
                automaton.set_ShowTrace(false);
                break;

        }
    }
}

void multichain (APv automaton) {
    std::vector<std::string> chains;
    std::string inputFile;
    std::cout << std::endl << "Por favor introduce el nombre del fichero de entrada con las cadenas a probar: ";
    std::cin >> inputFile;
    std::ifstream input(inputFile, std::ios::in);
    if (input.fail()) {
        std::cout << std::endl << "Error 404, file not found" << std::endl;
        exit(1);
    }
    else {
        while (!input.eof()) {
            std::string tmp = "";
            getline(input, tmp);
            if (tmp.size() >= 1) {
              tmp.erase(tmp.size() - 1);
              chains.push_back(tmp);
            }
        }
        for (int i = 0; i < chains.size(); i++) {
            if (automaton.get_ShowTrace()) {
                std::cout << "Estado\t\tEntrada\t\t\tPila\t\t  Acción" << std::endl;
            }
            bool tryChain = automaton.tryChain(chains[i], 0, automaton.get_Stack());
            if (tryChain) {
                std::cout << std::endl << "La cadena introducida pertenece al lenguaje.";
            }
            else {
                std::cout << std::endl << "La cadena introducida no pertenece al lenguaje.";
            }
        }
    }
}