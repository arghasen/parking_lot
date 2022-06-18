#pragma once

#include <cstddef>
#include <map>
#include <stdexcept>

namespace parkinglot {
class ParkingLot {
private:
    void initializeSlots() {
        for (size_t i = 1; i <= m_size; ++i) {
            slots[i] = false;
        }
    }
    void checkSizeValidity() const {
        if (m_size <= 0) {
            throw std::length_error("Invalid size specified");
        }
    }

public:
    ParkingLot(size_t size) : m_size(size) {
        checkSizeValidity();

        initializeSlots();
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
        throw std::runtime_error("parking lot is full");
    }

    void leave(int slot) {
        if (slots[slot]) {
            slots[slot] = false;
        } else {
            throw std::runtime_error("cannot leave unparked spot");
        }
    }
    bool checkSlotAvailability(int slotNum) {
        return !slots.at(slotNum);
    }

private:
    size_t m_size;
    std::map<int, bool> slots;
};
}// namespace parkinglot
