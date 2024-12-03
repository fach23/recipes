#include "../include/quantities/volume.hpp"

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

Volume operator "" _ml(const long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::MILLILITER};
}

Volume operator "" _l(const long double value) {
    return Volume{static_cast<double>(value), VOLUME_UNIT::LITER};
}