#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "ingredients/base_ingredient.hpp"
#include "reviews/review.hpp"
#include "reviews/review_manager.hpp"

namespace recipes {

/// @brief Enum describing the category
enum class CATEGORY { SOUP, DESSERT };

class BaseRecipe {
  public:
    /**
     * @brief Constructor
     * @param name Name
     * @param description Description
     * @param ingredients Ingredients
     * @param portion_quantity Portion quantity
     * @param author Author
     * @param reviews Reviews
     */
    BaseRecipe(std::string name, std::string description,
               const std::vector<BaseIngredient> &ingredients, const double portion_quantity = 1.0,
               std::string author = "-", const std::vector<Review> &reviews = {})
        : name_(std::move(name)), description_(std::move(description)), ingredients_(ingredients),
          portion_quantity_(portion_quantity), author_(author), review_manager_(reviews) {}

    /**
     * @brief Scales quantity
     * @param portion_quantity Portion quantity
     */
    void scale_quantity(double portion_quantity) {
        for (auto &ingredient : ingredients_) {
            ingredient.scale_quantity(portion_quantity);
        }
        portion_quantity_ = portion_quantity;
    }

    /**
     * @brief Displays recipe
     */
    void display() const {
        std::cout << "---------------------" << std::endl;
        std::cout << "Recipe: " << name_ << std::endl;
        std::cout << "1) Description: " << description_ << std::endl;
        std::cout << "2) Ingredients:" << std::endl;
        for (const auto &ingredient : ingredients_) {
            std::cout << " - ";
            ingredient.display();
            std::cout << std::endl;
        }
        std::cout << "3) ";
        get_nutrition_information().display();
        if (review_manager_.get_mean_review_score().has_value()) {
            std::cout << "4) Mean review score: "
                      << static_cast<int>(review_manager_.get_mean_review_score().value())
                      << std::endl;
        }

        std::cout << "5) Portions: " << portion_quantity_ << std::endl;
        std::cout << "6) Author: " << author_ << std::endl;
    }

    /**
     * @brief Returns name
     * @return Name
     */
    const std::string &get_name() const { return name_; }

    /**
     * @brief Returns nutritonal information
     * @return NutritionalInformation
     */
    NutritionalInformation get_nutrition_information() const {
        NutritionalInformation nutritional_information{};
        for (const auto &ingredient : ingredients_) {
            nutritional_information =
                nutritional_information + ingredient.get_nutritional_information();
        }
        return nutritional_information;
    }

  private:
    /// @brief Name
    std::string name_;
    /// @brief Description
    std::string description_;
    /// @brief Ingredients
    std::vector<BaseIngredient> ingredients_;
    /// @brief Portion quantity
    double portion_quantity_;
    /// @brief Author
    std::string author_;
    /// @brief Review manager
    ReviewManager review_manager_;
    /// @brief Health score
    double health_score_;
};

} // namespace recipes