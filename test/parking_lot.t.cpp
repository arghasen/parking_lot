#include "parking_lot/parking_lot.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using testing::Eq;
namespace parkinglot {
namespace test {
TEST(ParkingLotTest, CannotCreateEmptyParkingLot) {

    ASSERT_THROW(ParkingLot(0), std::length_error);
}

TEST(ParkingLotTest, CanCreateParkingLotWithSize) {
    ParkingLot p(5);
    ASSERT_THAT(p.size(), Eq(5));
}

TEST(ParkingLotTest, CanParkWhenSpaceAvailable) {
    ParkingLot p(5);
    auto slotNo = p.park();
    ASSERT_THAT(slotNo, Eq(1));
}

}// namespace test
}// namespace parkinglot
