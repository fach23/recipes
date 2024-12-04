#include "../include/quantities/pieces.hpp"

namespace recipes {

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

Pieces::Pieces(unsigned long long value, PIECE_UNIT unit) : value_(value), unit_(unit) {}

void Pieces::scale_quantity(double portions) { value_ *= portions; }

void Pieces::display() const { std::cout << value_ << to_string(unit_); }

Pieces operator"" _piece(const unsigned long long value) {
    return Pieces{value, PIECE_UNIT::PIECE};
}

} // namespace recipes