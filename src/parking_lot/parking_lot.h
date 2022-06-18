#pragma once

#include <cstddef>
#include <map>
#include <stdexcept>

namespace parkinglot {
class ParkingLot {
public:
    ParkingLot(size_t size) : m_size(size) {
        if (m_size <= 0) {
            throw std::length_error("Invalid size specified");
        }

        for (size_t i = 1; i <= m_size; ++i) {
            slots[i] = false;
        }
    }

    size_t size() {
        return m_size;
    }

    int park() {
        for (auto &slot: slots) {
            if (!slot.second) {
                slot.second = true;
                return slot.first;
            }
        }
    }

private:
    size_t m_size;
    std::map<int, bool> slots;
};
}// namespace parkinglot
