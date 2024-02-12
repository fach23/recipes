#include "../include/unit.hpp"

Weight operator "" _g(long double value) {
    // Assume pounds for the literal without a suffix
    return Weight{static_cast<double>(value), WEIGHT_UNIT::GRAM};
}

Weight operator "" _kg(long double value) {
    return Weight{static_cast<double>(value), WEIGHT_UNIT::KILOGRAM};
}

Volume operator "" _ml(long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::MILLILITER};
}

Volume operator "" _l(long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::LITER};
}

Pieces operator "" _piece(unsigned long long value) {
    return Pieces{value, PIECE_UNIT::PIECE};
}

Spoons operator "" _tea_spoon(unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TEA_SPOON};
}

Spoons operator "" _table_spoon(unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TABLE_SPOON};
}

unsigned long long operator "" _pinch(unsigned long long value) {
    return value;
}

Energy operator "" _kcal(long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOCALORIE};
}

Energy operator "" _kj(long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOJOULE};
}

