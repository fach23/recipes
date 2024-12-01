#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "../nutritional_information.hpp"
#include "../unit.hpp"

class BaseIngredient {
public:
    BaseIngredient(std::string name, const QuantityPtr &quantity,
                   const NutritionInformation &nutritional_information)
            : name_(std::move(name)), quantity_(quantity), nutritional_information_(nutritional_information) {}

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
        std::cout << name_ << " ";
        quantity_->display();
        // nutritional_information_.display();
    }

private:
    std::string name_;
    QuantityPtr quantity_;
    NutritionInformation nutritional_information_;
};

class Water : public BaseIngredient {
public:
    Water(const Volume &volume) : BaseIngredient("Water", std::make_shared<Volume>(volume),
                                                 NutritionInformation{Calories{0.0}, Protein{0.0}, Carbohydrates{0.0},
                                                                      Fat{0.0}}) {
    }
};

class Salt : public BaseIngredient {
public:
    Salt(const Weight &weight) : BaseIngredient("Salt", std::make_shared<Weight>(weight),
                                                NutritionInformation{Calories{0.0}, Protein{0.0},
                                                                     Carbohydrates{0.0},
                                                                     Fat{0.0}}) {
    }
};

class WheatFlourType550 : public BaseIngredient {
public:
    WheatFlourType550(const Weight &weight) : BaseIngredient("WheatFlourType550", std::make_shared<Weight>(weight),
                                                             NutritionInformation{Calories{347.0}, Protein{10.6},
                                                                                  Carbohydrates{72.0},
                                                                                  Fat{1.1}}) {
    }
};

class WheatFlourType00 : public BaseIngredient {
public:
    WheatFlourType00(const Weight &weight) : BaseIngredient("WheatFlourType00", std::make_shared<Weight>(weight),
                                                            NutritionInformation{Calories{349.0}, Protein{14.6},
                                                                                 Carbohydrates{69.0},
                                                                                 Fat{1.0}}) {
    }
};

class Yeast : public BaseIngredient {
public:
    Yeast(const Weight &weight) : BaseIngredient("Yeast", std::make_shared<Weight>(weight),
                                                 NutritionInformation{Calories{96.0}, Protein{16.7},
                                                                      Carbohydrates{1.1},
                                                                      Fat{1.2}}) {
    }
};

class Apple : public BaseIngredient {
public:
    Apple(const Pieces &pieces) : BaseIngredient("Apple", std::make_shared<Pieces>(pieces),
                                                 NutritionInformation{Calories{54}, Protein{0.3}, Carbohydrates{14.4},
                                                                      Fat{0.1}}) {
    }

    Apple(const Weight &weight) : BaseIngredient("Apple", std::make_shared<Weight>(weight),
                                                 NutritionInformation{Calories{54}, Protein{0.3}, Carbohydrates{14.4},
                                                                      Fat{0.1}}) {
    }
};

class Banana : public BaseIngredient {
public:
    Banana(const Pieces &pieces) : BaseIngredient("Banana", std::make_shared<Pieces>(pieces),
                                                  NutritionInformation{Calories{96}, Protein{1.0}, Carbohydrates{22.0},
                                                                       Fat{0.2}}) {
    }

    Banana(const Weight &weight) : BaseIngredient("Banana", std::make_shared<Weight>(weight),
                                                  NutritionInformation{Calories{96}, Protein{1.0}, Carbohydrates{22.0},
                                                                       Fat{0.2}}) {
    }
};
