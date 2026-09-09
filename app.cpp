/*****************************
 * Random Password Generator *
 *      Version 0.1.1        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#include "variables.h"
#include "functions.h"
#include "interface.h"
#include <iostream>
#include <algorithm>

using namespace std;
using namespace display;
using namespace core;

// Function to initialize program variables on initial execution or reset
void app::initVariables() {
    passLength  = 16;
    outputQty   = 10;
    instantOut  = false;
    useSecurity = false;
    useNumbers  = false;
    useSymbols  = false;
    cleanStart  = true;
    modeSelect  = false;
    optionInput.clear();
    omitChars.clear();
    finalPassword.clear();

}

/*
 * This function is the core of Instant mode. It handles running the generator
 * with program defaults or settings from arguments passed at launch. The
 * password(s) are generated directly to the console, then handles wiping the
 * passwords from the console for extra security if opted for
 */
void app::runInstantMode() {
    cout << CONSOLE_CLEAR << flush;

    // Simple program header and optionally activate secondary screen buffer for Security Mode
    if (useSecurity) {
        cout << CONSOLE_BUFF2;
        cout << TEXT_FG_AMBER << "Random Password Generator" << endl;
        cout << "     (Security Mode)" << TEXT_RESET <<endl;
    } else {
        cout << TEXT_FG_AMBER << "Random Password Generator" << TEXT_RESET <<endl;
    }

    // Generate requested number of password suggestions
    for (int i = 1; i <= outputQty; i++) {
        generatePassword();
        showResult(i);
    }

    // Wipe the passwords from the console and restore primary buffer for Security Mode
    if (useSecurity) {
        wipeResults();
        cout << CONSOLE_BUFF1;
    }

    cout << CURSOR_SHOW;
}

/*
 * This function is the core of Interactive Mode. It handles prompting the user for
 * their desired password options, processes the options, generates the password, then
 * handles restarting the program or exiting to console.
 */
void app::runInteractiveMode() {

    // Activate secondary screen buffer
    cout << CONSOLE_BUFF2;

    // Prompt for options on clean start
    if (cleanStart) {
        getLength();
        getUseNumbers();
        getUseSymbols();
        getOmissions();
        cleanStart = false;
    }

    clearScreen();
    cout << endl;

    // Generate amount of passwords specified, default is 10 for Interactive Mode
    for (int i = 1; i <= outputQty; i++) {
        generatePassword();
        showResult(i);
    }

    //Generate more passwords or quit
    restartApp();
}

/*
 * This function prompts user for password length, checks input for validity, then
 * stores it in variable passLength for setting up generator
 */
void app::getLength() {
    clearScreen();
    cout << " Enter desired password length: (8-64)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
    cin >> optionInput;

    if (checkInput(optionInput)) {
        if (stoi(optionInput) >= 8 && stoi(optionInput) <= 64) {
            passLength = stoi(optionInput);
            optionInput.clear();
        } else {
            optionInput.clear();
            getLength();
        }
    } else {
        optionInput.clear();
        getLength();
    }
}

/*
 * This function prompts user whether or not to mix in numbers to result,
 * checks input for validity, then sets appropriate bool flag for
 * setting up generator
 */
void app::getUseNumbers() {
    clearScreen();
    cout << " Mix numbers into output? (Y/N)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
    cin >> optionInput;

    if (optionInput == "Y" || optionInput == "y") {
        useNumbers = true;
        optionInput.clear();
    } else if (optionInput == "N" || optionInput == "n") {
        optionInput.clear();
    } else {
        optionInput.clear();
        getUseNumbers();
    }
}

/*
 * This function prompts user whether or not to mix in symbols to result,
 * checks input for validity, then sets appropriate bool flag for
 * setting up generator
 */
void app::getUseSymbols() {
    clearScreen();
    cout << " Mix symbols into output? (Y/N)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
    cin >> optionInput;

    if (optionInput == "Y" || optionInput == "y") {
        useSymbols = true;
        optionInput.clear();
    } else if (optionInput == "N" || optionInput == "n") {
        optionInput.clear();
    } else {
        optionInput.clear();
        getUseSymbols();
    }
}

/*
 * This function prompts user to enter any characters to omit from
 * the generated result, then stores the entered characters into
 * a string for omissions that the generator will check against the
 * pools of characters, and skip them as a possibility
 */
void app::getOmissions() {
    clearScreen();
    bool omissionsRequested = false;
    cout << " Omit any characters from output? (Y/N)" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
    cin >> optionInput;

    if (optionInput == "Y" || optionInput == "y") {
        omissionsRequested = !omissionsRequested;
        optionInput.clear();
    } else if (optionInput == "N" || optionInput == "n") {
        optionInput.clear();
    } else {
        optionInput.clear();
        getOmissions();
    }

    if (omissionsRequested) {
        clearScreen();
        cout << " Enter any characters to omit from results:" << endl << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
        cin >> omitChars;
    }
}

/*
 * This function asks user if they wish to regenerate the results with the
 * same criteria, restart the program to generate with new criteria, or
 * to quit the program.
 */
void app::restartApp() {
    cout << "\n Enter G to regenerate passwords with same criteria." << endl
    << " Enter R to reset and generate passwords with new criteria." << endl
    << " Enter Q to quit program." << endl
    << TEXT_FG_AMBER << "   " << TEXT_RESET << CURSOR_SHOW;
    cin >> optionInput;

    if (optionInput == "G" || optionInput == "g") {
        optionInput.clear();
        clearScreen();
    } else if (optionInput == "R" || optionInput == "r") {
        optionInput.clear();
        initVariables();
        clearScreen();
    } else if (optionInput == "Q" || optionInput == "q") {
        optionInput.clear();
        programActive = !programActive;
        cout << CONSOLE_BUFF1 << CONSOLE_CLEAR << flush;  // Restore default screen buffer and clean up on program exit
    }
}

// This function checks whether user entered valid positive integer for password length
bool app::checkInput(const string& input) {
    return !input.empty() && all_of(input.begin(), input.end(), [](unsigned char c) {
        return isdigit(c);
    });
}
