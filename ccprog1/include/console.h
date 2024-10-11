/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// Prevent duplicate declarations of this header file's content. ...
#ifndef CONSOLE_H
#define CONSOLE_H

#define COLOR_DEFAULT "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_GREEN "\033[0;32m"
#define COLOR_YELLOW "\033[0;33m"

/** Resets the color of text output in the console using an ANSI escape sequence. */
void resetConsoleColor(void);

/** Sets the color of text output in the console to red using an ANSI escape sequence. */
void setConsoleColorToRed(void);

/** Sets the color of text output in the console to green using an ANSI escape sequence. */
void setConsoleColorToGreen(void);

/** Sets the color of text output in the console to yellow using an ANSI escape sequence. */
void setConsoleColorToYellow(void);

/**
 * Prompts the player to input an integer into the console.
 * @param nLeftPaddingSize The number of spaces to move the console cursor to the right.
 * @returns The first integer value inputted into the console.
 */
int getIntegerInput(int nLeftPaddingSize);

/**
 * Prompts the player to input a character into the console.
 * @param nLeftPaddingSize The number of spaces to move the console cursor to the right.
 * @returns The first character value inputted into the console.
 */
char getCharacterInput(int nLeftPaddingSize);

/** Reads the buffer characters until the end of the line and discards them. */
void clearInputBuffer(void);

// ... Prevent duplicate declarations of this header file's content.
#endif  // CONSOLE_H
