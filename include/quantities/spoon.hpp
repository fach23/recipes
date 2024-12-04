#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "i_quantity.hpp"

namespace recipes {

/// @brief Enum describing the spoon unit
enum class SPOON_UNIT {
    TEA_SPOON, // DEFAULT
    TABLE_SPOON
};

/**
 * @brief Converts unit to string
 * @return String describing the unit
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
    Spoons(unsigned long long value, SPOON_UNIT unit);

    /**
     * @brief Scales quantity
     * @param portions Portions
     */
    void scale_quantity(double portions) override;

    /**
     * @brief Displays quantity
     */
    void display() const override;

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

} // namespace recipes