/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "console.h"

#include <stdio.h>

/** Resets the color of text output in the console using an ANSI escape sequence. */
void resetConsoleColor(void) { printf(COLOR_DEFAULT); }

/** Sets the color of text output in the console to red using an ANSI escape sequence. */
void setConsoleColorToRed(void) { printf(COLOR_RED); }

/** Sets the color of text output in the console to green using an ANSI escape sequence. */
void setConsoleColorToGreen(void) { printf(COLOR_GREEN); }

/** Sets the color of text output in the console to yellow using an ANSI escape sequence. */
void setConsoleColorToYellow(void) { printf(COLOR_YELLOW); }

/**
 * Prompts the player to input an integer into the console.
 * @param nLeftPaddingSize The number of spaces to move the console cursor to the right.
 * @returns The first integer value inputted into the console..
 */
int getIntegerInput(int nLeftPaddingSize) {
  int nPlayerResponse;

  printf("\n");

  printf("%*c%% ", nLeftPaddingSize, ' ');
  scanf(" %d", &nPlayerResponse);

  return nPlayerResponse;
}

/**
 * Prompts the player to input a character into the console.
 * @param nLeftPaddingSize The number of spaces to move the console cursor to the right.
 * @returns The first character value inputted into the console.
 */
char getCharacterInput(int nLeftPaddingSize) {
  char cPlayerResponse;

  printf("\n");

  printf("%*c%% ", nLeftPaddingSize, ' ');
  scanf(" %c", &cPlayerResponse);

  return cPlayerResponse;
}

/** Reads the buffer characters until the end of the line and discards them. */
void clearInputBuffer(void) { while ((getchar()) != '\n'); }
