#include "../include/quantities/weight.hpp"

namespace recipes {

std::string to_string(const WEIGHT_UNIT unit) {
    switch (unit) {
    case WEIGHT_UNIT::GRAM: {
        return "g";
    }
    case WEIGHT_UNIT::KILOGRAM: {
        return "kg";
    }
    default: {
        return "-";
    }
    }
}

Weight::Weight(const double value, const WEIGHT_UNIT unit) : value_(value), unit_(unit) {}

void Weight::scale_quantity(const double portions) { value_ *= portions; }

void Weight::display() const { std::cout << value_ << to_string(unit_); }

Weight operator"" _g(const long double value) {
    return Weight{static_cast<double>(value), WEIGHT_UNIT::GRAM};
}

Weight operator"" _kg(const long double value) {
    return Weight{static_cast<double>(value), WEIGHT_UNIT::KILOGRAM};
}

} // namespace recipes