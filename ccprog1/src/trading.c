/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "trading.h"

#include <stdlib.h>

#include "text_graphics.h"

/**
 * Generates a random price within the provided maximum and minimum prices.
 * @param nMinimumPrice The minimum allowed price.
 * @param nMaximumPrice The maximum allowed price.
 * @returns An integer value within the range of `nMinimumPrice` and `nMaximumPrice`.
 */
int generateRandomPrice(int nMinimumPrice, int nMaximumPrice) {
  return rand() % (nMaximumPrice - nMinimumPrice + 1) + nMinimumPrice;
}

/**
 * Subtracts or adds the cargo's cost to the player's balance and cargo to the ship's storage based on the transaction
 * type and prints out the game's transaction screen.
 * @param cTransactionType The type of transaction made.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param cCargoId The ID of the cargo to trade.
 * @pre @p cCargoId must have a character value of `'C'`, `'R'`, `'S'`, or `'G'`.
 * @param[out] nPlayerBalance The player's gold coin balance.
 * @param nCargoPrice The price of the cargo.
 * @param nCargoAmount The amount of cargo to trade.
 * @param[out] nShipCargoAmount The amount of cargo carried by the ship.
 */
void tradeCargo(char cTransactionType, char cCargoId, int *nPlayerBalance, int nCargoPrice, int nCargoAmount,
                int *nShipCargoAmount) {
  if (cTransactionType == 'B') {
    *nPlayerBalance -= (nCargoPrice * nCargoAmount);
    *nShipCargoAmount += nCargoAmount;
  } else {
    *nPlayerBalance += (nCargoPrice * nCargoAmount);
    *nShipCargoAmount -= nCargoAmount;
  }

  printTransactionScreen(cTransactionType, cCargoId, nCargoAmount, nCargoPrice);
}

/**
 * Subtracts the ship upgrade cost from the player's balance, sets the upgraded ship cargo limit, and prints out the
 * game's ship upgrade screen to the console.
 * @param[out] nPlayerBalance The player's gold coin balance.
 * @param nShipUpgradeCost The price of upgrading the ship.
 * @param[out] nShipCurrentCargoLimit The current maximum amount of cargo that the ship can carry.
 * @param nShipNewCargoLimit The upgraded maximum amount of cargo that the ship can carry.
 */
void upgradeShip(int *nPlayerBalance, int nShipUpgradeCost, int *nShipCurrentCargoLimit, int nShipNewCargoLimit) {
  *nPlayerBalance -= nShipUpgradeCost;

  int nShipOldCargoLimit = *nShipCurrentCargoLimit;

  *nShipCurrentCargoLimit = nShipNewCargoLimit;

  printShipUpgradeScreen(nShipNewCargoLimit - nShipOldCargoLimit, nShipUpgradeCost);
}
