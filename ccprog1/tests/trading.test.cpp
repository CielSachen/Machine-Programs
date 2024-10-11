#include "trading.h"

#include <gtest/gtest.h>

#define TEST_REPEAT_COUNT 100
#define TEST_PLAYER_BALANCE 100
#define TEST_CARGO_ID 'C'
#define TEST_CARGO_AMOUNT 1
#define TEST_CARGO_PRICE 25
#define TEST_SHIP_CARGO_LIMIT 5
#define TEST_SHIP_UPGRADED_CARGO_LIMIT 10
#define TEST_SHIP_UPGRADE_COST 50

TEST(PriceGeneratorTest, IsGreaterThanOrEqualToMinimum) {
  for (int count = 0; count < TEST_REPEAT_COUNT; count++) {
    int random_price = generateRandomPrice(0, 100);

    EXPECT_GE(random_price, 0);
  }
}

TEST(PriceGeneratorTest, IsLessThanOrEqualToMaximum) {
  for (int count = 0; count < TEST_REPEAT_COUNT; count++) {
    int random_price = generateRandomPrice(0, 100);

    EXPECT_LE(random_price, 100);
  }
}

bool is_negative(int number) { return number < 0; }

TEST(PriceGeneratorTest, HandlesNegativeIntegers) {
  for (int count = 0; count < TEST_REPEAT_COUNT; count++) {
    int random_price = generateRandomPrice(-100, 0);

    if (random_price != 0) {
      EXPECT_PRED1(is_negative, random_price);
    }
  }
}

TEST(CargoTradingTest, SubtractsCostFromBalance) {
  int player_balance = TEST_PLAYER_BALANCE;
  int ship_cargo_amount = 0;
  // Defined by a precondition.
  char transaction_type = 'B';

  tradeCargo(transaction_type, TEST_CARGO_ID, &player_balance, TEST_CARGO_PRICE, TEST_CARGO_AMOUNT, &ship_cargo_amount);

  EXPECT_EQ(player_balance, 75);
}

TEST(CargoTradingTest, AddsProfitToBalance) {
  int player_balance = TEST_PLAYER_BALANCE;
  int ship_cargo_amount = 1;
  // Defined by a precondition.
  char transaction_type = 'S';

  tradeCargo(transaction_type, TEST_CARGO_ID, &player_balance, TEST_CARGO_PRICE, TEST_CARGO_AMOUNT, &ship_cargo_amount);

  EXPECT_EQ(player_balance, 125);
}

TEST(CargoTradingTest, AddsCargoToStorage) {
  int player_balance = TEST_PLAYER_BALANCE;
  int ship_cargo_amount = 0;
  // Defined by a precondition.
  char transaction_type = 'B';

  tradeCargo(transaction_type, TEST_CARGO_ID, &player_balance, TEST_CARGO_PRICE, TEST_CARGO_AMOUNT, &ship_cargo_amount);

  EXPECT_EQ(ship_cargo_amount, 1);
}

TEST(CargoTradingTest, SubtractsCargoFromStorage) {
  int player_balance = TEST_PLAYER_BALANCE;
  int ship_cargo_amount = 1;
  // Defined by a precondition.
  char transaction_type = 'S';

  tradeCargo(transaction_type, TEST_CARGO_ID, &player_balance, TEST_CARGO_PRICE, TEST_CARGO_AMOUNT, &ship_cargo_amount);

  EXPECT_EQ(ship_cargo_amount, 0);
}

TEST(ShipUpgradeTest, SubtractsCostFromBalance) {
  int player_balance = TEST_PLAYER_BALANCE;
  int ship_cargo_limit = TEST_SHIP_CARGO_LIMIT;

  upgradeShip(&player_balance, TEST_SHIP_UPGRADE_COST, &ship_cargo_limit, TEST_SHIP_UPGRADED_CARGO_LIMIT);

  EXPECT_EQ(player_balance, 50);
}

TEST(ShipUpgradeTest, IncreasesCargoLimit) {
  int player_balance = TEST_PLAYER_BALANCE;
  int ship_cargo_limit = TEST_SHIP_CARGO_LIMIT;

  upgradeShip(&player_balance, TEST_SHIP_UPGRADE_COST, &ship_cargo_limit, TEST_SHIP_UPGRADED_CARGO_LIMIT);

  EXPECT_EQ(ship_cargo_limit, 10);
}
