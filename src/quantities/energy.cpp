#include "quantities/energy.hpp"

namespace recipes {

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

Energy::Energy(double value, ENERGY_UNIT unit) : value_(value), unit_(unit) {}

void Energy::scale_quantity(double portions) { value_ *= portions; }

void Energy::display() const { std::cout << value_ << to_string(unit_); }

Energy operator"" _kcal(const long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOCALORIE};
}

Energy operator"" _kj(const long double value) {
    return Energy{static_cast<double>(value), ENERGY_UNIT::KILOJOULE};
}

} // namespace recipes