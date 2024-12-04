#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "ingredients/base_ingredient.hpp"
#include "reviews/review.hpp"
#include "reviews/review_manager.hpp"

/// @brief Enum describing the category
enum class CATEGORY { SOUP, DESSERT };

class BaseRecipe {
  public:
    BaseRecipe(std::string name, std::string description,
               const std::vector<BaseIngredient> &ingredients, const double portion_quantity = 1.0,
               std::string author = "-", const std::vector<Review> &reviews = {})
        : name_(std::move(name)), description_(std::move(description)), ingredients_(ingredients),
          portion_quantity_(portion_quantity), author_(author), review_manager_(reviews) {}

    void scale_quantity(double portion_quantity) {
        // Scale the quantities of ingredients
        for (auto &ingredient : ingredients_) {
            ingredient.scale_quantity(portion_quantity);
        }
        portion_quantity_ = portion_quantity;
    }

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

    const std::string &get_name() const { return name_; }

    NutritionalInformation get_nutrition_information() const {
        NutritionalInformation nutrition_information{};
        for (const auto &ingredient : ingredients_) {
            nutrition_information = nutrition_information + ingredient.get_nutrition_information();
        }
        return nutrition_information;
    }

  private:
    std::string name_;
    std::string description_;
    std::vector<BaseIngredient> ingredients_;
    double portion_quantity_;
    std::string author_;
    ReviewManager review_manager_;
    double health_score_;
};