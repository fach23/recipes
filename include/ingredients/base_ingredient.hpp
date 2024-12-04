#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "nutritions/nutritional_information.hpp"
#include "quantities/quantities.hpp"

namespace recipes {

/**
 * @brief Base class for ingredient
 */
class BaseIngredient {
  public:
    /**
     * @brief Constructor
     * @param name Name
     * @param quantity Quantity
     * @param nutritional_information Nutritional information
     */
    BaseIngredient(std::string name, const QuantityPtr &quantity,
                   const NutritionalInformation &nutritional_information);
    /**
     * @brief Scales quantity
     */
    void scale_quantity(double portions) const;

    /**
     * @brief Returns the name
     * @return Name
     */
    std::string const &get_name() const;

    /**
     * @brief Returns the quantity
     * @return Quantity
     */
    IQuantity const &get_quantity() const;

    /**
     * @brief Returns the nutritional information
     * @return Nutritional information
     */
    NutritionalInformation const &get_nutritional_information() const;

    /**
     * @brief Display
     */
    void display() const;

  private:
    /// @brief Name
    std::string name_;
    /// @brief Quantitiy
    QuantityPtr quantity_;
    /// @brief Nutritional information
    NutritionalInformation nutritional_information_;
};

} // namespace recipes