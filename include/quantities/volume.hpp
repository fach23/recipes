#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "i_quantity.hpp"

/// @brief Enum describing the volume unit
enum class VOLUME_UNIT {
    MILLILITER, // DEFAULT
    LITER
};

/**
 * @brief Converts unit to string
 * @return std::string String describing the unit
 */
std::string to_string(VOLUME_UNIT unit);

/**
 * @brief Volume class‚
 */
class Volume : public IQuantity {
public:
    /**
     * @brief Constructor
     * @param value Value
     * @param unit Unit
     */
    Volume(double value, VOLUME_UNIT unit)
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
    VOLUME_UNIT unit_;
};

/// @brief Literal operator for representing volume values in mililiters
Volume operator "" _ml(long double value);

/// @brief Literal operator for representing volume values in liters
Volume operator "" _l(long double value);