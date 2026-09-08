/*****************************
 * Random Password Generator *
 *      Version 0.0.1        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#include "variables.h"
#include "functions.h"
#include "CLI11.hpp"

using namespace app;
using namespace core;
using namespace display;

int main(int argc, char** argv) {

    if (argc == 1) {
        programActive = true;
        initVariables();
        while (programActive) runInteractiveMode();
        return 0;
    } else {
        CLI::App rpg{"Random Password Generator"};
        rpg.add_option("-l,--length", passLength, "Length of password (1-64 characters)");
        rpg.add_flag("-n,--numbers", useNumbers, "Include numbers, Yes/No (Default is no)");
        rpg.add_flag("-s,--symbols", useSymbols, "Include symbols, Yes/No (Default is no)");
        rpg.add_option("-o,--omit", omitChars, "Characters to exclude (Default is none)");
        rpg.add_option("-q,--quantity", outputQty, "Amount to generate (Default is 10)");

        initVariables();

        CLI11_PARSE(rpg, argc, argv);

        //generatePassword();
        //cout << finalPassword << endl;
        for (int i = 0; i >= outputQty; i++) {
            generatePassword();
            showResult(i);
        }

        return 0;
    }
}
