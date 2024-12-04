#include "nutritions/nutritional_information.hpp"

NutritionalInformation::NutritionalInformation(Calories calories, Protein protein,
                                               Carbohydrates carbohydrates, Fat fat)
    : calories_(calories), protein_(protein), carbohydrates_(carbohydrates), fat_(fat) {}

NutritionalInformation
NutritionalInformation::operator+(const NutritionalInformation &other) const {
    NutritionalInformation result(calories_ + other.calories_, protein_ + other.protein_,
                                  carbohydrates_ + other.carbohydrates_, fat_ + other.fat_);
    return result;
}

Calories NutritionalInformation::get_calories() const { return calories_; }

Protein NutritionalInformation::get_protein() const { return protein_; }

Carbohydrates NutritionalInformation::get_carbohydrates() const { return carbohydrates_; }

Fat NutritionalInformation::get_fat() const { return fat_; }

void NutritionalInformation::display() const {
    std::cout << "Nutritional Information:\n"
              << " - Calories: " << calories_.get_value() << " kcal\n"
              << " - Protein: " << protein_.get_value() << " g\n"
              << " - Carbohydrates: " << carbohydrates_.get_value() << " g\n"
              << " - Fat: " << fat_.get_value() << " g\n";
}