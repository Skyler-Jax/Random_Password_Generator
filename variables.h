/*****************************
 * Random Password Generator *
 *      Version 0.0.1        *
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
inline bool useNumbers;         // Complexity flag
inline bool useSymbols;         // Complexity flag
inline bool programActive;      // Program loop enabled
inline bool cleanStart;         // If loop is starting clean or regenerating
inline string optionInput;      // Option entered by user
inline string omitChars;        // Characters to ban
inline string finalPassword;    // The generated output

/*******************
 * Character Pools *
 *******************/
inline const string POOL_LETTERS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline const string POOL_NUMBERS = "0123456789";
inline const string POOL_SYMBOLS = "`~!@#$%^&*()-_+={}?<>,.";
