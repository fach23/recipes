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
                           Carbohydrates carbohydrates = Carbohydrates(0.0), Fat fat = Fat(0.0));

    // Overload + operator
    NutritionalInformation operator+(const NutritionalInformation &other) const;
    /**
     * @brief Returns calories
     * @return Calories
     */
    Calories get_calories() const;

    /**
     * @brief Returns protein
     * @return Protein
     */
    Protein get_protein() const;

    /**
     * @brief Returns carbohydrates
     * @return Carbohydrates
     */
    Carbohydrates get_carbohydrates() const;

    /**
     * @brief Returns fat
     * @return Fat
     */
    Fat get_fat() const;

    /**
     * @brief Displays nutrition information
     */
    void display() const;

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
