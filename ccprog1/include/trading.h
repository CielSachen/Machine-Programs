/**
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

// Prevent duplicate declarations of this header file's content. ...
#ifndef TRADING_H
#define TRADING_H

// Allow this header file to be accessed by the C++ testing library. ...
#ifdef __cplusplus
extern "C" {
#endif  // __cplusplus

#define TIER_ONE_SHIP_CARGO_LIMIT 75
#define TIER_TWO_SHIP_CARGO_LIMIT 150
#define TIER_THREE_SHIP_CARGO_LIMIT 225
#define TIER_FOUR_SHIP_CARGO_LIMIT 300

#define TIER_TWO_SHIP_UPGRADE_COST 1000
#define TIER_THREE_SHIP_UPGRADE_COST 1750
#define TIER_FOUR_SHIP_UPGRADE_COST 2500

#define MINIMUM_TONDO_COCONUT_PRICE 4
#define MAXIMUM_TONDO_COCONUT_PRICE 24
#define MINIMUM_TONDO_RICE_PRICE 1
#define MAXIMUM_TONDO_RICE_PRICE 20
#define MINIMUM_TONDO_SILK_PRICE 48
#define MAXIMUM_TONDO_SILK_PRICE 68
#define MINIMUM_TONDO_GUN_PRICE 70
#define MAXIMUM_TONDO_GUN_PRICE 95

#define MINIMUM_MANILA_COCONUT_PRICE 3
#define MAXIMUM_MANILA_COCONUT_PRICE 18
#define MINIMUM_MANILA_RICE_PRICE 5
#define MAXIMUM_MANILA_RICE_PRICE 20
#define MINIMUM_MANILA_SILK_PRICE 24
#define MAXIMUM_MANILA_SILK_PRICE 39
#define MINIMUM_MANILA_GUN_PRICE 65
#define MAXIMUM_MANILA_GUN_PRICE 84

#define MINIMUM_PANDAKAN_COCONUT_PRICE 2
#define MAXIMUM_PANDAKAN_COCONUT_PRICE 12
#define MINIMUM_PANDAKAN_RICE_PRICE 4
#define MAXIMUM_PANDAKAN_RICE_PRICE 14
#define MINIMUM_PANDAKAN_SILK_PRICE 22
#define MAXIMUM_PANDAKAN_SILK_PRICE 32
#define MINIMUM_PANDAKAN_GUN_PRICE 90
#define MAXIMUM_PANDAKAN_GUN_PRICE 103

#define MINIMUM_SAPA_COCONUT_PRICE 9
#define MAXIMUM_SAPA_COCONUT_PRICE 14
#define MINIMUM_SAPA_RICE_PRICE 1
#define MAXIMUM_SAPA_RICE_PRICE 6
#define MINIMUM_SAPA_SILK_PRICE 17
#define MAXIMUM_SAPA_SILK_PRICE 22
#define MINIMUM_SAPA_GUN_PRICE 204
#define MAXIMUM_SAPA_GUN_PRICE 301

/**
 * Generates a random price within the provided maximum and minimum prices.
 * @param nMinimumPrice The minimum allowed price.
 * @param nMaximumPrice The maximum allowed price.
 * @returns An integer value within the range of `nMinimumPrice` and `nMaximumPrice`.
 */
int generateRandomPrice(int nMinimumPrice, int nMaximumPrice);

/**
 * Subtracts or adds the cargo's cost to the player's balance and cargo to the ship's storage based on the transaction
 * type and prints out the game's transaction screen.
 * @param cTransactionType The type of transaction made.
 * @pre @p cTransactionType must have a character value of either `'B'` or `'S'`.
 * @param cCargoId The ID of the traded cargo.
 * @pre @p cCargoId must have a character value of `'C'`, `'R'`, `'S'`, or `'G'`.
 * @param[out] nPlayerBalance The player's gold coin balance.
 * @param nCargoPrice The price of the cargo.
 * @param nCargoAmount The amount of cargo to trade.
 * @param[out] nShipCargoAmount The amount of cargo carried by the ship.
 */
void tradeCargo(char cTransactionType, char cCargoId, int *nPlayerBalance, int nCargoPrice, int nCargoAmount,
                int *nShipCargoAmount);

/**
 * Subtracts the ship upgrade cost from the player's balance, sets the upgraded ship cargo limit, and prints out the
 * game's ship upgrade screen to the console.
 * @param[out] nPlayerBalance The player's gold coin balance.
 * @param nShipUpgradeCost The price of upgrading the ship.
 * @param[out] nShipCurrentCargoLimit The current maximum amount of cargo that the ship can carry.
 * @param nShipNewCargoLimit The upgraded maximum amount of cargo that the ship can carry.
 */
void upgradeShip(int *nPlayerBalance, int nShipUpgradeCost, int *nShipCurrentCargoLimit, int nShipNewCargoLimit);

// ... Allow this header file to be accessed by the C++ testing library.
#ifdef __cplusplus
}
#endif  // __cplusplus

// ... Prevent duplicate declarations of this header file's content.
#endif  // TRADING_H
