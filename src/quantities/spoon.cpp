#include "../include/quantities/spoon.hpp"

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

Spoons operator"" _tea_spoon(const unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TEA_SPOON};
}

Spoons operator"" _table_spoon(const unsigned long long value) {
    return Spoons{value, SPOON_UNIT::TABLE_SPOON};
}
