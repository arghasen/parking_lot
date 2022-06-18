#pragma once

#include <cstddef>

namespace parkinglot {
class ParkingLot {
public:
    ParkingLot() : ParkingLot(0){};

    ParkingLot(size_t size) : m_size(size) {
    }

    size_t size() {
        return m_size;
    }

private:
    size_t m_size;
};
}// namespace parkinglot
