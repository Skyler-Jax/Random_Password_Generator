/*****************************
 * Random Password Generator *
 *      Version 0.1.0        *
 *   by Skyler Jax Hansen    *
 *      Sep. 8th, 2026       *
 *****************************/

#include "variables.h"
#include "functions.h"
#include <random>
#include <algorithm>

using namespace std;

void core::generatePassword() {
    // 1. Build the master pool based on user choices
    string masterPool = POOL_LETTERS;
    if (useNumbers) masterPool += POOL_NUMBERS;
    if (useSymbols) masterPool += POOL_SYMBOLS;

    // 2. The Erase-Remove Idiom to strip omitted characters
    if (!omitChars.empty()) {
        masterPool.erase(
            remove_if(masterPool.begin(), masterPool.end(),
                [](char c) { return omitChars.find(c) != string::npos; }),
            masterPool.end()
        );
    }

    // 3. Set up the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, masterPool.length() - 1);

    // 4. Generate the final string
    finalPassword.clear();
    for (int i = 0; i < passLength; ++i) {
        finalPassword += masterPool[distrib(gen)];
    }
}
