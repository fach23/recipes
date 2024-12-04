#pragma once

#include <iostream>
#include <memory>
#include <string>

#include "i_quantity.hpp"

/// @brief Enum describing the weight unit
enum class WEIGHT_UNIT {
    GRAM, // DEFAULT
    KILOGRAM
};

/**
 * @brief Converts unit to string
 * @return String describing the unit
 */
std::string to_string(WEIGHT_UNIT unit);

/**
 * @brief Weight class
 */
class Weight : public IQuantity {
  public:
    /**
     * @brief Constructor
     * @param value Value
     * @param unit Unit
     */
    Weight(double value, WEIGHT_UNIT unit);

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
    WEIGHT_UNIT unit_;
};

/// @brief Literal operator for representing weight values in grams
Weight operator"" _g(long double value);

/// @brief Literal operator for representing weight values in kilograms
Weight operator"" _kg(long double value);