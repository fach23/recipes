#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "i_quantity.hpp"

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
    Energy(double value, ENERGY_UNIT unit)
            : value_(value), unit_(unit) {}

    /**
     * @brief Scales quantity
     * @param portions Portions
     */
    void scale_quantity(double portions) override {
        value_ *= portions;
    }

    /**
     * @brief Displays quantity
     */
    void display() const override {
        std::cout << value_ << to_string(unit_);
    }

private:
    /// @brief Value
    double value_;
    /// @brief Unit
    ENERGY_UNIT unit_;
};

/// @brief Literal operator for representing energy values in kilocalories
Energy operator "" _kcal(long double value);

/// @brief Literal operator for representing energy values in kilojoules‚‚
Energy operator "" _kj(long double value);