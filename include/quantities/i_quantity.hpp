#pragma once

#include <iostream>
#include <memory>
#include <string>

namespace recipes {

class IQuantity;
/// @brief Pointer to quantity
using QuantityPtr = std::shared_ptr<IQuantity>;

/**
 * @brief Virtual base class for quantity
 */
class IQuantity {
  public:
    /**
     * @brief Scales quantity
     * @param portions Portions
     */
    virtual void scale_quantity(double portions) = 0;

    /**
     * @brief Displays quantity
     */
    virtual void display() const = 0;

    /**
     * @brief Destructor
     */
    virtual ~IQuantity() = default;
};

} // namespace recipes