#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "i_quantity.hpp"

/// @brief Enum describing the spoon unit
enum class SPOON_UNIT {
    TEA_SPOON, // DEFAULT
    TABLE_SPOON
};

/**
 * @brief Converts unit to string
 * @return std::string String describing the unit
 */
std::string to_string(SPOON_UNIT unit);

/**
 * @brief Spoons class‚‚
 */
class Spoons : public IQuantity {
  public:
    /**
     * @brief Constructor
     * @param value Value
     * @param unit Unit
     */
    Spoons(unsigned long long value, SPOON_UNIT unit) : value_(value), unit_(unit) {}

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
    SPOON_UNIT unit_;
};

/// @brief Literal operator for representing spoon values in tea spoons
Spoons operator"" _tea_spoon(unsigned long long value);

/// @brief Literal operator for representing spoon values in table spoons
Spoons operator"" _table_spoon(unsigned long long value);