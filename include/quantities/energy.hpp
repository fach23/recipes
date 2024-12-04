#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "i_quantity.hpp"

namespace recipes {

/// @brief Enum describing the energy unit
enum class ENERGY_UNIT {
    KILOCALORIE, // DEFAULT
    KILOJOULE
};

/**
 * @brief Converts unit to string
 * @return std::string String describing the unit
 */
std::string to_string(ENERGY_UNIT unit);

/**
 * @brief Energy class
 */
class Energy : public IQuantity {
  public:
    /**
     * @brief Constructor
     * @param value Value
     * @param unit Unit
     */
    Energy(double value, ENERGY_UNIT unit);

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
    double value_;
    /// @brief Unit
    ENERGY_UNIT unit_;
};

/// @brief Literal operator for representing energy values in kilocalories
Energy operator"" _kcal(long double value);

/// @brief Literal operator for representing energy values in kilojoules‚‚
Energy operator"" _kj(long double value);

} // namespace recipes