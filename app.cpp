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
#include <algorithm>

using namespace std;
using namespace input;
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
 * This function is the core of Instant Mode. It handles running the generator
 * with program defaults or settings from arguments passed at launch. The
 * password(s) are generated directly to the console, then handles wiping the
 * passwords from the console for extra security if opted for
 */
void app::runInstantMode() {
    cout << CONSOLE_CLEAR << flush;

    // Simple program header and optionally activate secondary screen buffer for Security Mode
    if (useSecurity) {
        cout << CONSOLE_BUFF2;
        cout << TEXT_FG_AMBER << " Random Password Generator" << endl;
        cout << "      (Security Mode)" << TEXT_RESET <<endl;
    } else {
        cout << TEXT_FG_AMBER << " Random Password Generator" << TEXT_RESET <<endl;
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

    // Sets generator output for fancy Interactive Mode display
    modeSelect = true;

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

    // Generate more passwords or quit
    getRestart();
}

// This function checks whether user entered valid positive integer for password length
bool app::checkInput(const string& input) {
    return !input.empty() && all_of(input.begin(), input.end(), [](unsigned char c) {
        return isdigit(c);
    });
}
