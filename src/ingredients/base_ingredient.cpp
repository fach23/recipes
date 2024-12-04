
#include "ingredients/base_ingredient.hpp"

BaseIngredient::BaseIngredient(std::string name, const QuantityPtr &quantity,
                               const NutritionalInformation &nutritional_information)
    : name_(std::move(name)), quantity_(quantity),
      nutritional_information_(nutritional_information) {}

void BaseIngredient::scale_quantity(double portions) const { quantity_->scale_quantity(portions); }

std::string const &BaseIngredient::get_name() const { return name_; }

IQuantity const &BaseIngredient::get_quantity() const { return *quantity_; }

NutritionalInformation const &BaseIngredient::get_nutritional_information() const {
    return nutritional_information_;
}

void BaseIngredient::display() const {
    std::cout << name_ << " ";
    quantity_->display();
    // nutritional_information_.display();
}
