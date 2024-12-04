#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "i_quantity.hpp"

/// @brief Enum describing the piece unit
enum class PIECE_UNIT {
    PIECE, // DEFAULT
    DOZEN
};

/**
 * @brief Converts unit to string
 * @return std::string String describing the unit
 */
std::string to_string(PIECE_UNIT unit);

/**
 * @brief Pieces class
 */
class Pieces : public IQuantity {
  public:
    /**
     * @brief Constructor
     * @param value Value
     * @param unit Unit
     */
    Pieces(unsigned long long value, PIECE_UNIT unit) : value_(value), unit_(unit) {}

    /**
     * @brief Scales quantity
     * @param portions Portions
     */
    void scale_quantity(double portions) override { value_ *= portions; }

    /**
     * @brief Displays quantity
     */
    void display() const override { std::cout << value_ << to_string(unit_); }

  private:
    /// @brief Value
    unsigned long long value_;
    /// @brief Unit
    PIECE_UNIT unit_;
};

/// @brief Literal operator for representing piece values in pieces
Pieces operator"" _piece(unsigned long long value);