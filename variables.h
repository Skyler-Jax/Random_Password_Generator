/*****************************
 * Random Password Generator *
 *      Version 0.1.1        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#pragma once

#include <string>

using namespace std;

/****************************
 * Global Program Variables *
 ****************************/
inline int passLength;          // Default length
inline int outputQty;           // How many passwords to generate
inline bool instantOut;         // Flag to output suitable passwords in Instant Mode if no other arguments called
inline bool useSecurity;        // Wipe generated passwords from console after CLI Instant Mode
inline bool useNumbers;         // Use the numbers pool for password generation
inline bool useSymbols;         // Use the symbols pool for password generation
inline bool programActive;      // Program loop enabled
inline bool cleanStart;         // If loop is starting clean or regenerating
inline bool modeSelect;         // Bool flag to set output for Interactive Mode or CLI Instant Mode
inline string optionInput;      // Option entered by user
inline string omitChars;        // Characters to ban
inline string finalPassword;    // The generated output

/*******************
 * Character Pools *
 *******************/
inline const string POOL_LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline const string POOL_NUMBERS = "0123456789";
inline const string POOL_SYMBOLS = "`~!@#$%^&*()-_+={}?<>,.";
