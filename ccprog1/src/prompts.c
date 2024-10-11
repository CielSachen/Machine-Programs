/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "prompts.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

#include "console.h"
#include "trading.h"

/**
 * Prompts the player to input their preferred merchant ID.
 * @returns An integer value within the range of `0` and `999`.
 */
int promptForPlayerId(void) {
  int nLeftPaddingSize = 56;

  printf("%*cEnter your preferred merchant code (0 - 999)\n", nLeftPaddingSize, ' ');

  int nPlayerId;
  // If the merchant ID the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    nPlayerId = getIntegerInput(nLeftPaddingSize);

    if (nPlayerId < 0 || nPlayerId > 999) {
      setConsoleColorToRed();
      printf("%*cPlease only enter an integer within the range of 0 - 999!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return nPlayerId;
}

/**
 * Prompts the player to input the number of gold coins they want to start with.
 * @returns An integer value greater than `0`.
 */
int promptForInitialBalance(void) {
  int nLeftPaddingSize = 57;

  printf("%*cEnter your preferred initial balance (> 0)\n", nLeftPaddingSize, ' ');

  int nPlayerInitialBalance;
  // If the initial balance the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    nPlayerInitialBalance = getIntegerInput(nLeftPaddingSize);

    if (nPlayerInitialBalance < 1) {
      setConsoleColorToRed();
      printf("%*cPlease only enter an integer greater than 0!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return nPlayerInitialBalance;
}

/**
 * Prompts the player to input their desired profit target.
 * @returns An integer value greater than `20`.
 */
int promptForProfitTarget(void) {
  int nLeftPaddingSize = 62;

  printf("%*cEnter your target profit (> 20)\n", nLeftPaddingSize, ' ');

  int nPlayerProfitTarget;
  // If the profit target the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    nPlayerProfitTarget = getIntegerInput(nLeftPaddingSize);

    if (nPlayerProfitTarget < 20) {
      setConsoleColorToRed();
      printf("%*cPlease only enter an integer greater than or equal to 20!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return nPlayerProfitTarget;
}

/**
 * Prompts the player to input a confirmation of their prior decision.
 * @returns `true` if the player confirms or `false` if they do not.
 */
bool promptForConfirmation(void) {
  int nLeftPaddingSize = 67;

  printf("%*cAre you sure? [Y / N]\n", nLeftPaddingSize, ' ');

  char cPlayerHadConfirmed;
  // Repeatedly make the player input a 'y' or 'n' until it's valid.
  bool bInputIsValid = false;

  do {
    cPlayerHadConfirmed = toupper(getCharacterInput(nLeftPaddingSize));

    if (cPlayerHadConfirmed != 'Y' && cPlayerHadConfirmed != 'N') {
      setConsoleColorToRed();
      printf("%*cPlease only enter one of the provided character options!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  if (cPlayerHadConfirmed == 'Y') {
    return true;
  } else {
    return false;
  }
}

/** Prompts the player to press the enter or return key to continue the game. */
void promptForContinuation(void) {
  int nLeftPaddingSize = 62;

  printf("%*cEnter any character to continue\n", nLeftPaddingSize, ' ');

  getCharacterInput(nLeftPaddingSize);

  clearInputBuffer();
}

/**
 * Prompts the player to input the ID of the action they want to do.
 * @param nShipTotalCargoAmount The total amount of cargo carried by the ship.
 * @param nShipCargoLimit The maximum amount of cargo that the ship can carry.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 * @returns A character value of `'B'` for the buy screen, `'S'` for the sell screen, `'U'` for the ship upgrade screen,
 * `'N'` for the navigation screen, or `'Q'` for quitting the game.
 */
char promptForActionId(int nShipTotalCargoAmount, int nShipCargoLimit, int nPlayerBalance, int nCoconutMarketPrice,
                       int nRiceMarketPrice, int nSilkMarketPrice, int nGunMarketPrice) {
  int nLeftPaddingSize = 65;

  printf("%*cWhat would you like to do?\n", nLeftPaddingSize, ' ');

  // Print out all viable action ID choices.
  if (nShipTotalCargoAmount < nShipCargoLimit || nPlayerBalance >= nCoconutMarketPrice ||
      nPlayerBalance >= nRiceMarketPrice || nPlayerBalance >= nSilkMarketPrice || nPlayerBalance >= nGunMarketPrice)
    printf("%*c‣ [B] Buy Cargo\n", nLeftPaddingSize, ' ');

  if (nShipTotalCargoAmount > 0) printf("%*c‣ [S] Sell Cargo\n", nLeftPaddingSize, ' ');

  if (nShipCargoLimit < TIER_FOUR_SHIP_CARGO_LIMIT &&
      ((nShipCargoLimit == 75 && nPlayerBalance >= TIER_TWO_SHIP_UPGRADE_COST) ||
       (nShipCargoLimit == 150 && nPlayerBalance >= TIER_THREE_SHIP_UPGRADE_COST) ||
       (nShipCargoLimit == 225 && nPlayerBalance >= TIER_FOUR_SHIP_UPGRADE_COST))) {
    printf("%*c‣ [U] Upgrade Ship\n", nLeftPaddingSize, ' ');
  }

  printf("%*c‣ [N] Navigate To a Different Port\n", nLeftPaddingSize, ' ');

  printf("\n");

  printf("%*c‣ [Q] Quit Game\n", nLeftPaddingSize, ' ');

  char cChosenActionId;
  // If the action ID the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    cChosenActionId = toupper(getCharacterInput(nLeftPaddingSize));

    if (cChosenActionId != 'B' && cChosenActionId != 'S' && cChosenActionId != 'U' && cChosenActionId != 'N' &&
        cChosenActionId != 'Q') {
      setConsoleColorToRed();
      printf("%*cPlease only enter one of the provided character options!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenActionId == 'B' && nShipTotalCargoAmount == nShipCargoLimit) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough storage to buy more cargo!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenActionId == 'B' && (nPlayerBalance <= nCoconutMarketPrice || nPlayerBalance <= nRiceMarketPrice ||
                                          nPlayerBalance <= nSilkMarketPrice || nPlayerBalance <= nGunMarketPrice)) {
      setConsoleColorToRed();
      printf("%*cYou can't afford to buy any cargo!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenActionId == 'S' && nShipTotalCargoAmount == 0) {
      setConsoleColorToRed();
      printf("%*cYou have no cargo to sell!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenActionId == 'U' && nShipCargoLimit == TIER_FOUR_SHIP_CARGO_LIMIT) {
      setConsoleColorToRed();
      printf("%*cYour ship is already in the highest tier!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenActionId == 'U' && ((nShipCargoLimit == 75 && nPlayerBalance < TIER_TWO_SHIP_UPGRADE_COST) ||
                                          (nShipCargoLimit == 150 && nPlayerBalance < TIER_THREE_SHIP_UPGRADE_COST) ||
                                          (nShipCargoLimit == 225 && nPlayerBalance < TIER_FOUR_SHIP_UPGRADE_COST))) {
      setConsoleColorToRed();
      printf("%*cYou can't afford to upgrade your ship!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return cChosenActionId;
}

/**
 * Prompts the player to input the ID of the cargo they want to trade.
 * @param cTransactionType The type of transaction to make.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 * @param nShipCoconutCargoAmount The amount of coconut cargo carried by the ship.
 * @param nShipRiceCargoAmount The amount of rice cargo carried by the ship.
 * @param nShipSilkCargoAmount The amount of silk cargo carried by the ship.
 * @param nShipGunCargoAmount The amount of gun cargo carried by the ship.
 * @returns A character value of `'C'` for coconut, `'R'` for rice, `'S'` for silk, `'G'` for gun, or `'X'` for
 * returning to the main menu.
 */
char promptForCargoId(char cTransactionType, int nPlayerBalance, int nCoconutMarketPrice, int nRiceMarketPrice,
                      int nSilkMarketPrice, int nGunMarketPrice, int nShipCoconutCargoAmount, int nShipRiceCargoAmount,
                      int nShipSilkCargoAmount, int nShipGunCargoAmount) {
  int nLeftPaddingSize = 64;

  // Print out the correct prompt.
  if (cTransactionType == 'B') {
    printf("%*cWhat would you like to buy?\n", nLeftPaddingSize, ' ');
  } else {
    printf("%*cWhat would you like to sell?\n", nLeftPaddingSize, ' ');
  }

  // Print out all viable cargo ID choices.
  if (cTransactionType == 'B') {
    if (nPlayerBalance > nCoconutMarketPrice) printf("%*c‣ [C] Coconut\n", nLeftPaddingSize, ' ');

    if (nPlayerBalance > nRiceMarketPrice) printf("%*c‣ [R] Rice\n", nLeftPaddingSize, ' ');

    if (nPlayerBalance > nSilkMarketPrice) printf("%*c‣ [S] Silk\n", nLeftPaddingSize, ' ');

    if (nPlayerBalance > nGunMarketPrice) printf("%*c‣ [G] Gun\n", nLeftPaddingSize, ' ');
  } else {
    if (nShipCoconutCargoAmount > 0) printf("%*c‣ [C] Coconut\n", nLeftPaddingSize, ' ');

    if (nShipRiceCargoAmount > 0) printf("%*c‣ [R] Rice\n", nLeftPaddingSize, ' ');

    if (nShipSilkCargoAmount > 0) printf("%*c‣ [S] Silk\n", nLeftPaddingSize, ' ');

    if (nShipGunCargoAmount > 0) printf("%*c‣ [G] Gun\n", nLeftPaddingSize, ' ');
  }

  printf("\n");

  printf("%*c‣ [X] Return To Main Menu\n", nLeftPaddingSize, ' ');

  char cChosenCargoId;
  // If the cargo ID the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    cChosenCargoId = toupper(getCharacterInput(nLeftPaddingSize));

    if (cChosenCargoId != 'C' && cChosenCargoId != 'R' && cChosenCargoId != 'S' && cChosenCargoId != 'G' &&
        cChosenCargoId != 'X') {
      setConsoleColorToRed();
      printf("%*cPlease only enter one of the provided character options!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cChosenCargoId == 'C' && nPlayerBalance < nCoconutMarketPrice) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy a coconut!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cChosenCargoId == 'R' && nPlayerBalance < nRiceMarketPrice) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy rice!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cChosenCargoId == 'S' && nPlayerBalance < nSilkMarketPrice) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy silk!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cChosenCargoId == 'G' && nPlayerBalance < nGunMarketPrice) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy a gun!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cChosenCargoId == 'C' && nShipCoconutCargoAmount == 0) {
      setConsoleColorToRed();
      printf("%*cYou do not have any coconuts to sell!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cChosenCargoId == 'R' && nShipRiceCargoAmount == 0) {
      setConsoleColorToRed();
      printf("%*cYou do not have any rice to sell!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cChosenCargoId == 'S' && nShipSilkCargoAmount == 0) {
      setConsoleColorToRed();
      printf("%*cYou do not have any silk to sell!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cChosenCargoId == 'G' && nShipGunCargoAmount == 0) {
      setConsoleColorToRed();
      printf("%*cYou do not have any guns to sell!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return cChosenCargoId;
}

/**
 * Prompts the player to input the amount of cargo they want to trade.
 * @param cTransactionType The type of transaction to make.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param cCargoId The ID of the traded cargo.
 * @pre @p cCargoId must have a character value of `'C'`, `'R'`, `'S'`, or `'G'`.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 * @param nShipCoconutCargoAmount The amount of coconut cargo carried by the ship.
 * @param nShipRiceCargoAmount The amount of rice cargo carried by the ship.
 * @param nShipSilkCargoAmount The amount of silk cargo carried by the ship.
 * @param nShipGunCargoAmount The amount of gun cargo carried by the ship.
 * @returns An integer value greater than `0`.
 */
int promptForCargoAmount(char cTransactionType, char cCargoId, int nPlayerBalance, int nCoconutMarketPrice,
                         int nRiceMarketPrice, int nSilkMarketPrice, int nGunMarketPrice, int nShipCoconutCargoAmount,
                         int nShipRiceCargoAmount, int nShipSilkCargoAmount, int nShipGunCargoAmount) {
  int nLeftPaddingSize = 57;

  // Print out the correct prompt.
  if (cTransactionType == 'B') {
    printf("%*cEnter the amount of cargo you want to buy\n", nLeftPaddingSize, ' ');
  } else {
    printf("%*cEnter the amount of cargo you want to sell\n", nLeftPaddingSize, ' ');
  }

  int nCargoAmount;
  // If the profit target the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    nCargoAmount = getIntegerInput(nLeftPaddingSize);

    if (cTransactionType == 'B' && cCargoId == 'C' && nPlayerBalance < (nCargoAmount * nCoconutMarketPrice)) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy %d coconuts!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cCargoId == 'R' && nPlayerBalance < (nCargoAmount * nRiceMarketPrice)) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy %d rice!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cCargoId == 'S' && nPlayerBalance < (nCargoAmount * nSilkMarketPrice)) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy %d silk!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'B' && cCargoId == 'G' && nPlayerBalance < (nCargoAmount * nGunMarketPrice)) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to buy %d guns!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cCargoId == 'C' && nShipCoconutCargoAmount < nCargoAmount) {
      setConsoleColorToRed();
      printf("%*cYou do not have %d coconuts to sell!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cCargoId == 'R' && nShipRiceCargoAmount < nCargoAmount) {
      setConsoleColorToRed();
      printf("%*cYou do not have %d rice to sell!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cCargoId == 'S' && nShipSilkCargoAmount < nCargoAmount) {
      setConsoleColorToRed();
      printf("%*cYou do not have %d silk to sell!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else if (cTransactionType == 'S' && cCargoId == 'G' && nShipGunCargoAmount < nCargoAmount) {
      setConsoleColorToRed();
      printf("%*cYou do not have %d guns to sell!\n", nLeftPaddingSize, ' ', nCargoAmount);
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return nCargoAmount;
}

/**
 * Prompts the player to input a confirmation on whether they want to upgrade their ship or not.
 * @param nShipCurrentCargoLimit The current maximum amount of cargo that the ship can carry.
 * @param nPlayerBalance The player's gold coin balance.
 * @returns `true` if the player wants to upgrade or `false` if they do not.
 */
bool promptForShipUpgrade(int nShipCurrentCargoLimit, int nPlayerBalance) {
  int nLeftPaddingSize = 57;

  printf("%*cDo you want to upgrade your ship? [Y / N]\n", nLeftPaddingSize, ' ');

  // Print out the correct ship upgrade details.
  if (nShipCurrentCargoLimit == TIER_ONE_SHIP_CARGO_LIMIT) {
    printf(
      "%*c• Cost: %d\n"
      "%*c• New Cargo Capacity: %d\n",
      nLeftPaddingSize, ' ', TIER_TWO_SHIP_UPGRADE_COST, nLeftPaddingSize, ' ', TIER_TWO_SHIP_CARGO_LIMIT);
  } else if (nShipCurrentCargoLimit == TIER_TWO_SHIP_CARGO_LIMIT) {
    printf(
      "%*c• Cost: %d\n"
      "%*c• New Cargo Capacity: %d\n",
      nLeftPaddingSize, ' ', TIER_THREE_SHIP_UPGRADE_COST, nLeftPaddingSize, ' ', TIER_THREE_SHIP_CARGO_LIMIT);
  } else {
    printf(
      "%*c• Cost: %d\n"
      "%*c• New Cargo Capacity: %d\n",
      nLeftPaddingSize, ' ', TIER_FOUR_SHIP_UPGRADE_COST, nLeftPaddingSize, ' ', TIER_FOUR_SHIP_CARGO_LIMIT);
  }

  char cPlayerIsUpgrading;
  // Repeatedly make the player input a Y or N until it's valid.
  bool bInputIsValid = false;

  do {
    cPlayerIsUpgrading = toupper(getCharacterInput(nLeftPaddingSize));

    if (cPlayerIsUpgrading != 'Y' && cPlayerIsUpgrading != 'N') {
      setConsoleColorToRed();
      printf("%*cPlease only enter one of the provided character options!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if ((nShipCurrentCargoLimit == TIER_ONE_SHIP_CARGO_LIMIT && nPlayerBalance < TIER_TWO_SHIP_UPGRADE_COST) ||
               (nShipCurrentCargoLimit == TIER_TWO_SHIP_CARGO_LIMIT && nPlayerBalance < TIER_THREE_SHIP_UPGRADE_COST) ||
               (nShipCurrentCargoLimit == TIER_THREE_SHIP_CARGO_LIMIT &&
                nPlayerBalance < TIER_FOUR_SHIP_UPGRADE_COST)) {
      setConsoleColorToRed();
      printf("%*cYou do not have enough gold coins to upgrade your ship!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  if (cPlayerIsUpgrading == 'Y') {
    return true;
  } else {
    return false;
  }
}

/**
 * Prompts the player to input the ID of the port they want to navigate to.
 * @param cCurrentPortId The current port's ID.
 * @pre @p cCurrentPortId must have a character value of `'T'`, `'M'`, `'P'`, or `'S'`.
 * @returns A character value of `'T'` for Tondo, `'M'` for Manila, `'P'` for Pandakan, `'S'` for Sapa, or `'X'` for
 * returning to the main menu.
 */
char promptForPortId(char cCurrentPortId) {
  int nLeftPaddingSize = 64;

  printf("%*cWhere would you like to go?\n", nLeftPaddingSize, ' ');

  // Print out all viable port ID choices.
  if (cCurrentPortId != 'T') printf("%*c‣ [T] Tondo \n", nLeftPaddingSize, ' ');

  if (cCurrentPortId != 'M') printf("%*c‣ [M] Manila \n", nLeftPaddingSize, ' ');

  if (cCurrentPortId != 'P') printf("%*c‣ [P] Pandakan\n", nLeftPaddingSize, ' ');

  if (cCurrentPortId != 'S') printf("%*c‣ [S] Sapa\n", nLeftPaddingSize, ' ');

  printf("\n");

  printf("%*c‣ [X] Return To Main Menu\n", nLeftPaddingSize, ' ');

  char cChosenPortId;
  // If the port ID the player provided is invalid, repeatedly make the player input a new one until it's valid.
  bool bInputIsValid = false;

  do {
    cChosenPortId = toupper(getCharacterInput(nLeftPaddingSize));

    if (cChosenPortId != 'T' && cChosenPortId != 'M' && cChosenPortId != 'P' && cChosenPortId != 'S' &&
        cChosenPortId != 'X') {
      setConsoleColorToRed();
      printf("%*cPlease only enter one of the provided character options!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenPortId == 'T' && cCurrentPortId == 'T') {
      setConsoleColorToRed();
      printf("%*cYou are already in the port of Tondo!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenPortId == 'M' && cCurrentPortId == 'M') {
      setConsoleColorToRed();
      printf("%*cYou are already in the port of Manila!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenPortId == 'P' && cCurrentPortId == 'P') {
      setConsoleColorToRed();
      printf("%*cYou are already in the port of Pandakan!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else if (cChosenPortId == 'S' && cCurrentPortId == 'S') {
      setConsoleColorToRed();
      printf("%*cYou are already in the port of Sapa!\n", nLeftPaddingSize, ' ');
      resetConsoleColor();
    } else {
      bInputIsValid = true;
    }

    clearInputBuffer();
  } while (!bInputIsValid);

  return cChosenPortId;
}
