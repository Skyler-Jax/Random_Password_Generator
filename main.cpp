/*****************************
 * Random Password Generator *
 *      Version 0.1.0        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#include <iostream>
#include "variables.h"
#include "functions.h"
#include "CLI11.hpp"

using namespace app;
using namespace core;
using namespace display;

int main(int argc, char** argv) {

    // Initialize program variables
    initVariables();

    /*
     * If no arguments were passed on program launch, set up the
     * program for Interactive Mode. Otherwise, continue in
     * Instant Mode by processing the arguments, generating the
     * passwords per arguments entered, displaying the passwords,
     * and optionally wiping the passwords from the console before
     * exiting the program.
     */
    if (argc == 1) {
        // Activates Interactive Mode loop
        programActive = true;

        // Sets generator output for fancy Interactive Mode display
        modeSelect = true;

        // Remain in Interactive Mode loop until quitting is selected
        while (programActive) runInteractiveMode();
        return 0;
    } else {
        // Set up CLI11 with program arguments
        CLI::App rpg{"Random Password Generator"};
        rpg.add_option("-l,--length", passLength, "Length of password (1-64 characters)");
        rpg.add_flag("-n,--numbers", useNumbers, "Include numbers in output (Default is no)");
        rpg.add_flag("-s,--symbols", useSymbols, "Include symbols in output (Default is no)");
        rpg.add_option("-o,--omit", omitChars, "Characters to exclude (Default is none)");
        rpg.add_option("-q,--quantity", outputQty, "Amount to generate (Default is 10)");
        rpg.add_flag("-w,--wipe", useSecurity, "Wipe results after generation (Default is disabled)");

        // Parse the arguments and set relevant variables
        CLI11_PARSE(rpg, argc, argv);

        // Run generator in Instant Mode
        runInstantMode();

        return 0;
    }
}
