/*****************************
 * Random Password Generator *
 *      Version 0.1.3        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#pragma once

#include <string>

using namespace std;

/************************
 * Namespace & Function *
 *     Declarations     *
 ************************/
namespace app {
    void initVariables();                   // Handles initializing program variables
    void runInstantMode();                  // Handles instant console output
    void runInteractiveMode();              // Handles step-by-step console prompts
    bool checkInput(const string& input);   // Checks whether user entered valid positive integer for password length
}

namespace core {
    void generatePassword();                // The Mersenne Twister logic
}

namespace input {
    void getLength();                       // Prompt user for desired password length
    void getUseNumbers();                   // Prompt user whether or not to use numbers
    void getUseSymbols();                   // Prompt user whether or not to use symbols
    void getOmissions();                    // Prompt user for any characters to omit
    void getRestart();                      // Prompt user to regenerate, restart program, or quit
}

namespace display {
    void clearScreen();                     // Handles clearing the screen and redrawing key elements
    void drawHeader();                      // Draws program header on screen
    void showResult(int passwdNumber);      // Prints the final generated password
    void wipeResults();                     // Wipe results from console for security
}
