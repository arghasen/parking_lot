#include "parking_lot/parking_lot.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;
namespace parkinglot {
namespace test {
TEST(ParkingLotTest, CanCreateEmptyParkingLot) {
    parkinglot::ParkingLot p;
    ASSERT_THAT(p.size(), Eq(0));
}

TEST(ParkingLotTest, CanCreateParkingLotWithSize) {
    parkinglot::ParkingLot p(5);
    ASSERT_THAT(p.size(), Eq(5));
}
}// namespace test
}// namespace parkinglot
