/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// Prevent duplicate declarations of this header file's content. ...
#ifndef TEXT_GRAPHICS_H
#define TEXT_GRAPHICS_H

#define MAX_PRINT_WIDTH 156

/** Prints out a pre-formatted separator line to the console. */
void printSeparator(void);

/** Prints out the game's start screen, which contains the game's title, to the console. */
void printGameStartScreen(void);

/**
 * Prints out the game's main menu screen, which contains statistics about the player and their ship and the port's
 * cargo market prices, to the console.
 * @param nPlayerTurns The number of turns the player has exhausted.
 * @pre @p nPlayerTurns must have a positive integer value less than or equal to `29`.
 * @param cPortId The port's ID.
 * @pre @p cPortId must have a character value of either `'T'`, `'M'`, `'P'`, or `'S'`.
 * @param nPlayerId The player's merchant ID.
 * @param nPlayerBalance The player's gold coin balance.
 * @param nPlayerProfit The player's profit percentage.
 * @param nPlayerProfitTarget The player's target profit percentage.
 * @param nShipTotalCargoAmount The total amount of cargo carried by the ship.
 * @param nShipCargoLimit The maximum amount of cargo that the ship can carry.
 * @param nShipCoconutCargoAmount The amount of coconut cargo carried by the ship.
 * @param nShipRiceCargoAmount The amount of rice cargo carried by the ship.
 * @param nShipSilkCargoAmount The amount of silk cargo carried by the ship.
 * @param nShipGunCargoAmount The amount of gun cargo carried by the ship.
 * @param nCoconutMarketPrice The market price of coconuts.
 * @param nRiceMarketPrice The market price of rice.
 * @param nSilkMarketPrice The market price of silk.
 * @param nGunMarketPrice The market price of guns.
 */
void printMainScreen(int nPlayerTurns, char cPortId, int nPlayerId, int nPlayerBalance, int nPlayerProfit,
                     int nPlayerProfitTarget, int nShipTotalCargoAmount, int nShipCargoLimit,
                     int nShipCoconutCargoAmount, int nShipRiceCargoAmount, int nShipSilkCargoAmount,
                     int nShipGunCargoAmount, int nCoconutMarketPrice, int nRiceMarketPrice, int nSilkMarketPrice,
                     int nGunMarketPrice);

/**
 * Prints out the game's transaction screen, which contains the name of the cargo that the player traded and the number
 * of gold coins the player has spent or earned, to the console.
 * @param cTransactionType The type of transaction made.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param cCargoId The ID of the traded cargo.
 * @pre @p cCargoId must have a character value of either `'C'`, `'R'`, `'S'`, or `'G'`.
 * @param nCargoAmount The amount of cargo to trade.
 * @param nCargoPrice The price of the cargo.
 */
void printTransactionScreen(char cTransactionType, char cCargoId, int nCargoAmount, int nCargoPrice);

/**
 * Prints out the game's ship upgrade screen, which contains the number of additional cargo spaces the ship has received
 * and gold coins the player has spent, to the console.
 * @param nShipCargoLimitIncrease The amount of additional cargo space the ship has gotten.
 * @param nShipUpgradeCost The price of the ship upgrade.
 */
void printShipUpgradeScreen(int nShipCargoLimitIncrease, int nShipUpgradeCost);

/**
 * Prints out the game's navigation screen, which contains the new port the player navigated to and the new day count,
 * to the console.
 * @param cPortId The port's ID.
 * @pre @p cPortId must have a character value of either `'T'`, `'M'`, `'P'`, or `'S'`.
 * @param nPlayerTurns The number of turns the player has exhausted.
 * @pre @p nPlayerTurns must have a a 2-digit positive integer value.
 */
void printNavigationScreen(char cPortID, int nPlayerTurns);

/**
 * Prints out the game's end screen, which contains the player's final statistics, to the console.
 * @param nPlayerFinalProfit The player's final profit percentage.
 * @param nPlayerProfitTarget The player's target profit percentage.
 * @param nPlayerFinalBalance The player's final gold coin balance.
 * @param nPlayerFinalTurns The number of turns the player has exhausted.
 */
void printGameEndScreen(int nPlayerFinalProfit, int nPlayerProfitTarget, int nPlayerFinalBalance,
                        int nPlayerFinalTurns);

// ... Prevent duplicate declarations of this header file's content.
#endif  // TEXT_GRAPHICS_H
