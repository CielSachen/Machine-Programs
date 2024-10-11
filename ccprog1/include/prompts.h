/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// Prevent duplicate declarations of this header file's content. ...
#ifndef PROMPTS_H
#define PROMPTS_H

#include <stdbool.h>

/**
 * Prompts the player to input their preferred merchant ID.
 * @returns An integer value within the range of `0` and `999`.
 */
int promptForPlayerId(void);

/**
 * Prompts the player to input the number of gold coins they want to start with.
 * @returns An integer value greater than `0`.
 */
int promptForInitialBalance(void);

/**
 * Prompts the player to input their desired profit target.
 * @returns An integer value greater than `20`.
 */
int promptForProfitTarget(void);

/**
 * Prompts the player to input a confirmation of their prior decision.
 * @returns `true` if the player confirms or `false` if they do not.
 */
bool promptForConfirmation(void);

/** Prompts the player to press the enter or return key to continue the game. */
void promptForContinuation(void);

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
                       int nRiceMarketPrice, int nSilkMarketPrice, int nGunMarketPrice);

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
                      int nShipSilkCargoAmount, int nShipGunCargoAmount);

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
                         int nShipRiceCargoAmount, int nShipSilkCargoAmount, int nShipGunCargoAmount);

/**
 * Prompts the player to input a confirmation on whether they want to upgrade their ship or not.
 * @param nShipCurrentCargoLimit The current maximum amount of cargo that the ship can carry.
 * @param nPlayerBalance The player's gold coin balance.
 * @returns `true` if the player wants to upgrade or `false` if they do not.
 */
bool promptForShipUpgrade(int nShipCurrentCargoLimit, int nPlayerBalance);

/**
 * Prompts the player to input the ID of the port they want to navigate to.
 * @param cCurrentPortId The current port's ID.
 * @pre @p cCurrentPortId must have a character value of `'T'`, `'M'`, `'P'`, or `'S'`.
 * @returns A character value of `'T'` for Tondo, `'M'` for Manila, `'P'` for Pandakan, `'S'` for Sapa, or `'X'` for
 * returning to the main menu.
 */
char promptForPortId(char cCurrentPortId);

// ... Prevent duplicate declarations of this header file's content.
#endif  // PROMPTS_H
