/*****************************
 * Random Password Generator *
 *      Version 0.1.3        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#include "variables.h"
#include "functions.h"
#include "interface.h"
#include <iostream>

using namespace std;
using namespace app;
using namespace display;

/*
 * This function prompts user for password length, checks input for validity, then
 * stores it in variable passLength for setting up generator
 */
void input::getLength() {

    // Flag(s) used by function
    bool getInput = true;

    // Run routine to get valid input from user
    while (getInput) {
        clearScreen();
        cout << " Enter desired password length: (8-64)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        cin >> optionInput;

        // Check input and disable routine if valid
        if (checkInput(optionInput) && stoi(optionInput) >= 8 && stoi(optionInput) <= 64) {
            passLength = stoi(optionInput);
            getInput = !getInput;
        }

        // Clear the input option string for next use
        optionInput.clear();
    }
}

/*
 * This function prompts user whether or not to mix in numbers to result,
 * checks input for validity, then sets appropriate bool flag for
 * setting up generator
 */
void input::getUseNumbers() {

    // Flag(s) used by function
    bool getInput = true;

    // Run routine to get valid input from user
    while (getInput) {
        clearScreen();
        cout << " Mix numbers into output? (Y/N)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        cin >> optionInput;

        // Check input and disable routine if valid
        if (optionInput == "Y" || optionInput == "y") {
            useNumbers = true;
            getInput = !getInput;
        } else if (optionInput == "N" || optionInput == "n") {
            getInput = !getInput;
        }

        // Clear the input option string for next use
        optionInput.clear();
    }
}

/*
 * This function prompts user whether or not to mix in symbols to result,
 * checks input for validity, then sets appropriate bool flag for
 * setting up generator
 */
void input::getUseSymbols() {

    // Flag(s) used by function
    bool getInput = true;

    // Run routine to get valid input from user
    while (getInput) {
        clearScreen();
        cout << " Mix symbols into output? (Y/N)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        cin >> optionInput;

        // Check input and disable routine if valid
        if (optionInput == "Y" || optionInput == "y") {
            useSymbols = true;
            getInput = !getInput;
        } else if (optionInput == "N" || optionInput == "n") {
            getInput = !getInput;
        }

        // Clear the input option string for next use
        optionInput.clear();
    }
}

/*
 * This function prompts user to enter any characters to omit from
 * the generated result, then stores the entered characters into
 * a string for omissions that the generator will check against the
 * pools of characters, and skip them as a possibility
 */
void input::getOmissions() {

    // Flag(s) used by function
    bool omissionsRequested = false;
    bool getInput = true;

    // Run routine to get valid input from user
    while (getInput) {
        clearScreen();
        cout << " Omit any characters from output? (Y/N)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        cin >> optionInput;

        // Check input and disable routine if valid
        if (optionInput == "Y" || optionInput == "y") {
            omissionsRequested = !omissionsRequested;
            getInput = !getInput;
        } else if (optionInput == "N" || optionInput == "n") {
            getInput = !getInput;
        }

        // Clear the input option string for next use
        optionInput.clear();
    }

    // Prompt for characters to omit from generation
    if (omissionsRequested) {
        clearScreen();
        cout << " Enter any characters to omit from results:" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        getline(cin >> ws, omitChars);
    }
}

/*
 * This function asks user if they wish to regenerate the results with the
 * same criteria, restart the program to generate with new criteria, or
 * to quit the program.
 */
void input::getRestart() {

    // Flag(s) used by function
    bool getInput = true;

    // Run routine to get valid input from user
    while (getInput) {
        cout << "\n Enter G to regenerate passwords with same criteria." << endl
        << " Enter R to reset and generate passwords with new criteria." << endl
        << " Enter Q to quit program." << endl
        << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        cin >> optionInput;

        // Check input and disable routine if valid
        if (optionInput == "G" || optionInput == "g") {
            getInput = !getInput;
            clearScreen();
        } else if (optionInput == "R" || optionInput == "r") {
            getInput = !getInput;
            initVariables();
            clearScreen();
        } else if (optionInput == "Q" || optionInput == "q") {
            getInput = !getInput;
            programActive = !programActive;
            cout << CONSOLE_BUFF1 << CONSOLE_CLEAR << flush;  // Restore default screen buffer and clean up on program exit
        }

        // Clear the input option string for next use
        optionInput.clear();
    }
}
