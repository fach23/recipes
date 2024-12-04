#include "../include/quantities/weight.hpp"

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

Weight operator"" _g(const long double value) {
    return Weight{static_cast<double>(value), WEIGHT_UNIT::GRAM};
}

Weight operator"" _kg(const long double value) {
    return Weight{static_cast<double>(value), WEIGHT_UNIT::KILOGRAM};
}