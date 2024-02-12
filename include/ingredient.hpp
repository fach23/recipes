#ifndef RECIPES_INGREDIENT_H
#define RECIPES_INGREDIENT_H

#include <iostream>
#include <vector>
#include <string>

#include "nutritional_information.hpp"
#include "unit.hpp"

class BaseIngredient {
public:
    BaseIngredient(const std::string &name, const QuantityPtr &quantity,
                   const NutritionInformation &nutritional_information)
            : name_(name), quantity_(quantity), nutritional_information_(nutritional_information) {}

    void scale_quantity(double portions) const {
        quantity_->scale_quantity(portions);
    }

    std::string const &get_name() const {
        return name_;
    }

    BaseQuantity const &get_quantity() const {
        return *quantity_;
    }

    NutritionInformation const &get_nutrition_information() const {
        return nutritional_information_;
    }

    void display() const {
        std::cout << name_ << std::endl;
        quantity_->display();
        // nutritional_information_.display();
    }

private:
    std::string name_;
    QuantityPtr quantity_;
    NutritionInformation nutritional_information_;
};

class Apfel : public BaseIngredient {
public:
    Apfel(const Pieces &pieces) : BaseIngredient("Apfel", std::make_shared<Pieces>(pieces),
                                                 NutritionInformation{Calories{54}, Protein{0.3}, Carbohydrates{14.4},
                                                                      Fat{0.1}}) {
    }

    Apfel(const Weight &weight) : BaseIngredient("Apfel", std::make_shared<Weight>(weight),
                                                 NutritionInformation{Calories{54}, Protein{0.3}, Carbohydrates{14.4},
                                                                      Fat{0.1}}) {
    }
};

class Banane : public BaseIngredient {
public:
    Banane(const Pieces &pieces) : BaseIngredient("Banane", std::make_shared<Pieces>(pieces),
                                                  NutritionInformation{Calories{96}, Protein{1.0}, Carbohydrates{22.0},
                                                                       Fat{0.2}}) {
    }

    Banane(const Weight &weight) : BaseIngredient("Banane", std::make_shared<Weight>(weight),
                                                  NutritionInformation{Calories{96}, Protein{1.0}, Carbohydrates{22.0},
                                                                       Fat{0.2}}) {
    }
};

#endif // RECIPES_INGREDIENT_H
