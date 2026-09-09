/*****************************
 * Random Password Generator *
 *      Version 0.1.0        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#include "variables.h"
#include "functions.h"
#include "interface.h"
#include <iostream>

using namespace std;

void display::clearScreen() {
    cout << CONSOLE_CLEAR << CURSOR_HIDE << flush;
    drawHeader();
}

void display::drawHeader() {
    cout << TEXT_BG_SLATE;
    cout << TEXT_FG_AMBER;
    cout << " ╭───────────────────────────╮ " << endl;
    cout << " │ ";
    cout << TEXT_FG_MGNTA << "Random Password Generator";
    cout << TEXT_FG_AMBER << " │ " << endl;
    cout << " │   ";
    cout << TEXT_FG_GREEN << "ⓑⓨ🅢ⓚⓨⓛⓔⓡ🅙ⓐⓧ🅗ⓐⓝⓢⓔⓝ🄌🄯⓴㉖";
    cout << TEXT_FG_AMBER << "  │ " << endl;
    cout << " ╰───────────────────────────╯ " << endl;
    cout << TEXT_RESET;
}

void display::showResult(int passwdNumber) {
    if (modeSelect) cout << " ✨";
    cout << TEXT_FG_GREEN << " Password ";
    if (passwdNumber < 10) cout << " ";
    cout << passwdNumber << ": " << TEXT_RESET
    << TEXT_BG_SLATE << finalPassword << TEXT_RESET << endl;
}

void display::wipeResults() {
    cout << TEXT_FG_RED << TEXT_BLINK;
    cout << "\n Record your chosen password," << endl << " then press Enter to wipe results.";
    cout << TEXT_RESET << CURSOR_HIDE;
    cin.get();
    cout << CONSOLE_CLEAR << CURSOR_SHOW << flush;
}
