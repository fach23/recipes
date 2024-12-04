#include "../include/quantities/spoon.hpp"

namespace recipes {

std::string to_string(const SPOON_UNIT unit) {
    switch (unit) {
    case SPOON_UNIT::TEA_SPOON: {
        return "tea spoon";
    }
    case SPOON_UNIT::TABLE_SPOON: {
        return "table spoon";
    }
    default: {
        return "-";
    }
    }
}

Spoons::Spoons(unsigned long long value, SPOON_UNIT unit) : value_(value), unit_(unit) {}

void Spoons::scale_quantity(double portions) { value_ *= portions; }

void Spoons::display() const { std::cout << value_ << to_string(unit_); }

Spoons operator"" _tea_spoon(const unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TEA_SPOON};
}

Spoons operator"" _table_spoon(const unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TABLE_SPOON};
}

} // namespace recipes