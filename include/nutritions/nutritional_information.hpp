#pragma once

#include <iostream>

#include "calories.hpp"
#include "carbohydrates.hpp"
#include "fat.hpp"
#include "protein.hpp"

/**
 * @brief Nutritional information per 100 gr
 */
class NutritionalInformation {
  public:
    /**
     * @brief Constructor
     * @param calories
     * @param protein
     * @param carbohydrates
     * @param fat
     */
    NutritionalInformation(Calories calories = Calories(0.0), Protein protein = Protein(0.0),
                           Carbohydrates carbohydrates = Carbohydrates(0.0), Fat fat = Fat(0.0))
        : calories_(calories), protein_(protein), carbohydrates_(carbohydrates), fat_(fat) {}

    // Overload + operator
    NutritionalInformation operator+(const NutritionalInformation &other) const {
        NutritionalInformation result(calories_ + other.calories_, protein_ + other.protein_,
                                      carbohydrates_ + other.carbohydrates_, fat_ + other.fat_);
        return result;
    }

    /**
     * @brief Returns calories
     * @return Calories
     */
    Calories get_calories() const { return calories_; }

    /**
     * @brief Returns protein
     * @return Protein
     */
    Protein get_protein() const { return protein_; }

    /**
     * @brief Returns carbohydrates
     * @return Carbohydrates
     */
    Carbohydrates get_carbohydrates() const { return carbohydrates_; }

    /**
     * @brief Returns fat
     * @return Fat
     */
    Fat get_fat() const { return fat_; }

    /**
     * @brief Displays nutrition information
     */
    void display() const {
        std::cout << "Nutritional Information:\n"
                  << " - Calories: " << calories_.get_value() << " kcal\n"
                  << " - Protein: " << protein_.get_value() << " g\n"
                  << " - Carbohydrates: " << carbohydrates_.get_value() << " g\n"
                  << " - Fat: " << fat_.get_value() << " g\n";
    }

  private:
    /// @brief Calories
    Calories calories_;
    /// @brief Protein
    Protein protein_;
    /// @brief Carbohydrates
    Carbohydrates carbohydrates_;
    /// @brief Fat
    Fat fat_;
};
