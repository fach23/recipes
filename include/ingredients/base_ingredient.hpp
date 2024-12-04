#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "nutritions/nutritional_information.hpp"
#include "quantities/quantities.hpp"

class BaseIngredient {
  public:
    BaseIngredient(std::string name, const QuantityPtr &quantity,
                   const NutritionalInformation &nutritional_information)
        : name_(std::move(name)), quantity_(quantity),
          nutritional_information_(nutritional_information) {}

    void scale_quantity(double portions) const { quantity_->scale_quantity(portions); }

    std::string const &get_name() const { return name_; }

    IQuantity const &get_quantity() const { return *quantity_; }

    NutritionalInformation const &get_nutrition_information() const {
        return nutritional_information_;
    }

    void display() const {
        std::cout << name_ << " ";
        quantity_->display();
        // nutritional_information_.display();
    }

  private:
    std::string name_;
    QuantityPtr quantity_;
    NutritionalInformation nutritional_information_;
};