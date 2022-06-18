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

TEST(ParkingLotTest, ThrowsWhenSpaceNotAvailable) {
    ParkingLot p(1);
    (void) p.park();
    ASSERT_THROW(p.park(), std::runtime_error);
}

TEST(ParkingLotTest, ProvidesFirstAvailableSlot) {
    ParkingLot p(5);
    auto slotNo = p.park();
    slotNo = p.park();
    ASSERT_THAT(slotNo, Eq(2));
}

TEST(ParkingLotTest, CanLeaveSlotifOccupied) {
    ParkingLot p(5);
    auto slotNo1 = p.park();
    (void) p.park();
    p.leave(slotNo1);
    ASSERT_THAT(p.checkSlotAvailability(slotNo1), Eq(true));
}
}// namespace test
}// namespace parkinglot
