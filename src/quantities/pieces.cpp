#include "../include/quantities/pieces.hpp"

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

Pieces operator "" _piece(const unsigned long long value) {
    return Pieces{value, PIECE_UNIT::PIECE};
}