//---------------------------------------------- SCHOOL RELATED HEADERS ----------------------------------------------//

/**
 * This is to certify that this project is my own work, based on my personal efforts in studying
 * and applying the concepts learned. I have constructed the functions and their respective
 * algorithms and corresponding code by myself. The program was run, tested, and debugged by
 * my own efforts. I further certify that I have not copied in part or whole or otherwise
 * plagiarized the work of other students and/or persons.
 *
 *                                   Louis Raphael V. Panaligan, DLSU ID# 12413372
 */

/**
 * Description: Contains the source code for my CCPROG1 machine program "Tides of Manila: A
 *              Merchant's Quest."
 * Programmed by: Louis Raphael V. Panaligan
 * Last modified: 2024-10-11
 * Version: 1.0.0
 * Acknowledgements:
 *  - https://www.geeksforgeeks.org/generating-random-number-range-c/
 *  - https://www.theurbanpenguin.com/4184-2/
 */

//--------------------------------------------------------------------------------------------------------------------//

/**
 * Tides of Manila: A Merchant's Quest is a turn-based CLI-based game.
 * Copyright (C) 2024  Louis Raphael V. Panaligan
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"
#include "prompts.h"
#include "text_graphics.h"
#include "trading.h"

#define MAXIMUM_PLAYER_TURNS 30

int main(void) {
  // Declare all player and ship properties and set their default and initial values.
  int nPlayerId;
  int nPlayerInitialBalance;
  int nPlayerProfitTarget;
  int nPlayerBalance;
  int nPlayerProfit = 0;
  char cCurrentPortId = 'M';
  int nPlayerTurns = 0;
  int nShipCargoLimit = TIER_ONE_SHIP_CARGO_LIMIT;
  int nShipCoconutCargoAmount = 0;
  int nShipRiceCargoAmount = 0;
  int nShipSilkCargoAmount = 0;
  int nShipGunCargoAmount = 0;

  // Seed the pseudorandom number generation.
  srand(time(NULL));

  printf("\n");

  // Print out the GPL-3 license notice for terminal interactions.
  printf("Tides of Manila: A Merchant's Quest  Copyright (C) 2024  Louis Raphael V. Panaligan\n");
  printf("This program comes with ABSOLUTELY NO WARRANTY.\n");
  printf("This is free software, and you are welcome to redistribute it under certain conditions.\n");

  printGameStartScreen();

  nPlayerId = promptForPlayerId();

  printf("\n");

  nPlayerInitialBalance = promptForInitialBalance();
  nPlayerBalance = nPlayerInitialBalance;

  printf("\n");

  nPlayerProfitTarget = promptForProfitTarget();

  // Allow the player to quit before exhausting all of their turns.
  bool bPlayerIsQuitting = false;

  while (nPlayerTurns < MAXIMUM_PLAYER_TURNS && !bPlayerIsQuitting) {
    // Declare and set the market prices at the start of every turn.
    int nCoconutMarketPrice;
    int nRiceMarketPrice;
    int nSilkMarketPrice;
    int nGunMarketPrice;

    switch (cCurrentPortId) {
      case 'T': {
        nCoconutMarketPrice = generateRandomPrice(MINIMUM_TONDO_COCONUT_PRICE, MAXIMUM_TONDO_COCONUT_PRICE);
        nRiceMarketPrice = generateRandomPrice(MINIMUM_TONDO_RICE_PRICE, MAXIMUM_TONDO_RICE_PRICE);
        nSilkMarketPrice = generateRandomPrice(MINIMUM_TONDO_SILK_PRICE, MAXIMUM_TONDO_SILK_PRICE);
        nGunMarketPrice = generateRandomPrice(MINIMUM_TONDO_GUN_PRICE, MAXIMUM_TONDO_GUN_PRICE);

        break;
      }
      case 'M': {
        nCoconutMarketPrice = generateRandomPrice(MINIMUM_MANILA_COCONUT_PRICE, MAXIMUM_MANILA_COCONUT_PRICE);
        nRiceMarketPrice = generateRandomPrice(MINIMUM_MANILA_RICE_PRICE, MAXIMUM_MANILA_RICE_PRICE);
        nSilkMarketPrice = generateRandomPrice(MINIMUM_MANILA_SILK_PRICE, MAXIMUM_MANILA_SILK_PRICE);
        nGunMarketPrice = generateRandomPrice(MINIMUM_MANILA_GUN_PRICE, MAXIMUM_MANILA_GUN_PRICE);

        break;
      }
      case 'P': {
        nCoconutMarketPrice = generateRandomPrice(MINIMUM_PANDAKAN_COCONUT_PRICE, MAXIMUM_PANDAKAN_COCONUT_PRICE);
        nRiceMarketPrice = generateRandomPrice(MINIMUM_PANDAKAN_RICE_PRICE, MAXIMUM_PANDAKAN_RICE_PRICE);
        nSilkMarketPrice = generateRandomPrice(MINIMUM_PANDAKAN_SILK_PRICE, MAXIMUM_PANDAKAN_SILK_PRICE);
        nGunMarketPrice = generateRandomPrice(MINIMUM_PANDAKAN_GUN_PRICE, MAXIMUM_PANDAKAN_GUN_PRICE);

        break;
      }
      case 'S': {
        nCoconutMarketPrice = generateRandomPrice(MINIMUM_SAPA_COCONUT_PRICE, MAXIMUM_SAPA_COCONUT_PRICE);
        nRiceMarketPrice = generateRandomPrice(MINIMUM_SAPA_RICE_PRICE, MAXIMUM_SAPA_RICE_PRICE);
        nSilkMarketPrice = generateRandomPrice(MINIMUM_SAPA_SILK_PRICE, MAXIMUM_SAPA_SILK_PRICE);
        nGunMarketPrice = generateRandomPrice(MINIMUM_SAPA_GUN_PRICE, MAXIMUM_SAPA_GUN_PRICE);

        break;
      }
    }

    // Loop back into the main menu screen after exiting other screens unless the player quits.
    bool bPlayerIsNavigating = false;

    while (!bPlayerIsNavigating && !bPlayerIsQuitting) {
      nPlayerProfit = nPlayerProfitTarget * (nPlayerBalance - nPlayerInitialBalance) / 100;

      int nShipTotalCargoAmount =
        nShipCoconutCargoAmount + nShipRiceCargoAmount + nShipSilkCargoAmount + nShipGunCargoAmount;

      printMainScreen(nPlayerTurns, cCurrentPortId, nPlayerId, nPlayerBalance, nPlayerProfit, nPlayerProfitTarget,
                      nShipTotalCargoAmount, nShipCargoLimit, nShipCoconutCargoAmount, nShipRiceCargoAmount,
                      nShipSilkCargoAmount, nShipGunCargoAmount, nCoconutMarketPrice, nRiceMarketPrice,
                      nSilkMarketPrice, nGunMarketPrice);

      char cChosenActionId =
        promptForActionId(nShipTotalCargoAmount, nShipCargoLimit, nPlayerBalance, nCoconutMarketPrice, nRiceMarketPrice,
                          nSilkMarketPrice, nGunMarketPrice);

      // Print out the main screen for all the other game screens.
      if (cChosenActionId != 'Q') {
        printMainScreen(nPlayerTurns, cCurrentPortId, nPlayerId, nPlayerBalance, nPlayerProfit, nPlayerProfitTarget,
                        nShipTotalCargoAmount, nShipCargoLimit, nShipCoconutCargoAmount, nShipRiceCargoAmount,
                        nShipSilkCargoAmount, nShipGunCargoAmount, nCoconutMarketPrice, nRiceMarketPrice,
                        nSilkMarketPrice, nGunMarketPrice);
      }

      if (cChosenActionId == 'B' || cChosenActionId == 'S') {
        char cChosenCargoId = promptForCargoId(
          cChosenActionId, nPlayerBalance, nShipCoconutCargoAmount, nRiceMarketPrice, nSilkMarketPrice, nGunMarketPrice,
          nShipCoconutCargoAmount, nShipRiceCargoAmount, nShipSilkCargoAmount, nShipGunCargoAmount);

        if (cChosenCargoId != 'X') {
          printf("\n");

          int nCargoAmount = promptForCargoAmount(
            cChosenActionId, cChosenCargoId, nPlayerBalance, nCoconutMarketPrice, nRiceMarketPrice, nSilkMarketPrice,
            nGunMarketPrice, nShipCoconutCargoAmount, nShipRiceCargoAmount, nShipSilkCargoAmount, nShipGunCargoAmount);

          printf("\n");

          bool bPlayerHasConfirmed = promptForConfirmation();

          if (bPlayerHasConfirmed) {
            if (cChosenCargoId == 'C') {
              tradeCargo(cChosenActionId, cChosenCargoId, &nPlayerBalance, nCoconutMarketPrice, nCargoAmount,
                         &nShipCoconutCargoAmount);
            } else if (cChosenCargoId == 'R') {
              tradeCargo(cChosenActionId, cChosenCargoId, &nPlayerBalance, nRiceMarketPrice, nCargoAmount,
                         &nShipRiceCargoAmount);
            } else if (cChosenCargoId == 'S') {
              tradeCargo(cChosenActionId, cChosenCargoId, &nPlayerBalance, nSilkMarketPrice, nCargoAmount,
                         &nShipSilkCargoAmount);
            } else {
              tradeCargo(cChosenActionId, cChosenCargoId, &nPlayerBalance, nGunMarketPrice, nCargoAmount,
                         &nShipGunCargoAmount);
            }

            promptForContinuation();
          }
        }
      } else if (cChosenActionId == 'U') {
        bool bPlayerIsUpgrading = promptForShipUpgrade(nShipCargoLimit, nPlayerBalance);

        if (bPlayerIsUpgrading) {
          if (nShipCargoLimit == TIER_ONE_SHIP_CARGO_LIMIT) {
            upgradeShip(&nPlayerBalance, TIER_TWO_SHIP_UPGRADE_COST, &nShipCargoLimit, TIER_TWO_SHIP_CARGO_LIMIT);
          } else if (nShipCargoLimit == TIER_TWO_SHIP_CARGO_LIMIT) {
            upgradeShip(&nPlayerBalance, TIER_THREE_SHIP_UPGRADE_COST, &nShipCargoLimit, TIER_THREE_SHIP_CARGO_LIMIT);
          } else {
            upgradeShip(&nPlayerBalance, TIER_FOUR_SHIP_UPGRADE_COST, &nShipCargoLimit, TIER_FOUR_SHIP_CARGO_LIMIT);
          }

          promptForContinuation();
        }
      } else if (cChosenActionId == 'N') {
        char cChosenPortId = promptForPortId(cCurrentPortId);

        if (cChosenActionId != 'X') {
          printf("\n");

          bool bPlayerHasConfirmed = promptForConfirmation();

          if (bPlayerHasConfirmed) {
            if (cChosenPortId != 'X') {
              printNavigationScreen(cCurrentPortId, nPlayerTurns);

              promptForContinuation();

              cCurrentPortId = cChosenPortId;
              nPlayerTurns++;
              bPlayerIsNavigating = true;
            }
          }
        }
      } else {
        bPlayerIsQuitting = true;
      }
    }
  }

  printGameEndScreen(nPlayerProfit, nPlayerProfitTarget, nPlayerBalance, nPlayerTurns);

  return 0;
}
