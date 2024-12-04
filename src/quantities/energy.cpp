#include "quantities/energy.hpp"

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

Energy operator"" _kcal(const long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOCALORIE};
}

Energy operator"" _kj(const long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOJOULE};
}
