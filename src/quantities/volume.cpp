#include "../include/quantities/volume.hpp"

namespace recipes {

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

Volume::Volume(double value, VOLUME_UNIT unit) : value_(value), unit_(unit) {}

void Volume::scale_quantity(double portions) { value_ *= portions; }

void Volume::display() const { std::cout << value_ << to_string(unit_); }

Volume operator"" _ml(const long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::MILLILITER};
}

Volume operator"" _l(const long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::LITER};
}

} // namespace recipes