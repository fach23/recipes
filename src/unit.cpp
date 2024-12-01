#include "../include/unit.hpp"

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

std::string to_string(const VOLUME_UNIT unit) {
    switch (unit) {
        case VOLUME_UNIT::MILLILITER: {
            return "ml";
        }
        case VOLUME_UNIT::LITER: {
            return "l";
        }
        default: {
            return "-";
        }
    }
}

std::string to_string(const ENERGY_UNIT unit) {
    switch (unit) {
        case ENERGY_UNIT::KILOCALORIE: {
            return "kcal";
        }
        case ENERGY_UNIT::KILOJOULE: {
            return "kJ";
        }
        default: {
            return "-";
        }
    }
}

std::string to_string(const PIECE_UNIT unit) {
    switch (unit) {
        case PIECE_UNIT::PIECE: {
            return "piece";
        }
        case PIECE_UNIT::DOZEN: {
            return "dozen";
        }
        default: {
            return "-";
        }
    }
}

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

Weight operator "" _g(const long double value) {
    // Assume pounds for the literal without a suffix
    return Weight{static_cast<double>(value), WEIGHT_UNIT::GRAM};
}

Weight operator "" _kg(const long double value) {
    return Weight{static_cast<double>(value), WEIGHT_UNIT::KILOGRAM};
}

Volume operator "" _ml(const long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::MILLILITER};
}

Volume operator "" _l(const long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::LITER};
}

Pieces operator "" _piece(const unsigned long long value) {
    return Pieces{value, PIECE_UNIT::PIECE};
}

Spoons operator "" _tea_spoon(const unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TEA_SPOON};
}

Spoons operator "" _table_spoon(const unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TABLE_SPOON};
}

unsigned long long operator "" _pinch(const unsigned long long value) {
    return value;
}

Energy operator "" _kcal(const long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOCALORIE};
}

Energy operator "" _kj(const long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOJOULE};
}

