# Random Password Generator
Linux terminal utility to quickly generate random passwords

<img width="754" height="545" alt="image" src="https://github.com/user-attachments/assets/c220d86e-ac45-4b53-a626-8d8377c25f4a" />

*  Provides two modes of interaction, Interactive Mode with a friendly interface or Instant Mode for direct output using arguments.
*  Provides options for:
  *  Configuring password length.
  *  Adjusting password complexity.
  *  Requesting a single password or a batch of many to choose from.
  *  Stipulating which characters to omit from all generated passwords for that oddball site that requires complexity yet refuses certain characters.
  *  Providing a Secure Mode that wipes console buffer and scroll-back after generation.
 
# How To Use
## Interactive Mode
Executing the binary without any CLI arguments starts the program in Interactive Mode. This mode uses the terminal's alternate screen buffer,
and passwords will be cleared and unavailable in scroll-back when the program is exited.

In this mode, the program will:
1. Prompt user for desired password length, 8 to 64 characters supported.
2. Prompt user for whether or not to include numbers in generated output.
3. Prompt user for whether or not to include symbols in generated output.
    Mixed-case alphabet characters are always used.
4. Prompt user for any specific characters to omit from generated output.

Interactive Mode will always generate a batch of 10 passwords for the given criteria. Once the passwords are generated the user has three options:
*  Enter 'G' to regenerate a new batch of passwords.
*  Enter 'R' to reset and regenerate a new batch with new criteria.
*  Enter 'Q' to quit the program and return to the terminal.

## Instant Mode
Executing the binary with CLI arguments triggers instant mode for fast, more granular control.

Available arguments are:
*  -?, --help     - Displays all arguments and how to use them.
*  -i, --instant  - Instantly generate a batch of ten 16-character passwords with mixed complexity.
*  -l, --length   - Define the length of the generated password(s).
*  -n, --numbers  - Tell the generator to mix in digits in the generated password(s).
*  -s, --symbols  - Tell the generator to mix in symbols in the generated password(s).
*  -o, --omit     - Tell the generator which, if any, characters to not use.
*  -q, --quantity - Specify the batch size of passwords to generate.
*  -S, --security - Will use the console's alternate buffer, and will prompt the user to select/record a password before clearing the screen and returning to the primary buffer.

**Instant mode example, no arguments, scroll-back remains**
<img width="448" height="794" alt="image" src="https://github.com/user-attachments/assets/f55931e8-7bff-4724-8b41-e9dd975a2f81" />

**Instant mode example, Secure Mode enabled, no scroll-back remains**
<img width="427" height="414" alt="image" src="https://github.com/user-attachments/assets/0205eea9-b207-444c-9900-aec08e489d4c" />
