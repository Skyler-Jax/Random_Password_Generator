/*****************************
 * Random Password Generator *
 *      Version 0.0.1        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#pragma once

#include <string>

using namespace std;

/********************************
 * Terminal Interface Constants *
 ********************************/
inline const string TEXT_FG_MGNTA   = "\033[38;5;207m"; // Console output escape code for magenta colored characters
inline const string TEXT_FG_BLUE    = "\033[38;5;69m";  // Console output escape code for blue colored characters
inline const string TEXT_FG_GREEN   = "\033[38;5;46m";  // Console output escape code for green colored characters
inline const string TEXT_FG_YELLW   = "\033[38;5;226m"; // Console output escape code for yellow colored characters
inline const string TEXT_FG_AMBER   = "\033[38;5;208m"; // Console output escape code for amber colored characters
inline const string TEXT_FG_RED     = "\033[38;5;196m"; // Console output escape code for red colored characters
inline const string TEXT_BG_SLATE   = "\033[48;5;236m"; // Console output escape code for gray colored background
inline const string TEXT_BLINK      = "\033[5m";        // Console output escape code for blinking test
inline const string TEXT_RESET      = "\033[0m";        // Console output escape code for resetting formatting
inline const string CONSOLE_BUFF1   = "\033[?1049l";    // Console output escape code for setting default screen buffer
inline const string CONSOLE_BUFF2   = "\033[?1049h";    // Console output escape code for setting alternate screen buffer
inline const string CONSOLE_CLEAR   = "\033[2J\033[H";  // Console output escape code for clearing the screen
inline const string CURSOR_HIDE     = "\033[?25l";      // Console output escape code for hiding the cursor
inline const string CURSOR_SHOW     = "\033[?25h";      // Console output escape code for showing the cursor
