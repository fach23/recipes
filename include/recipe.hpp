#ifndef RECIPES_RECIPE_H
#define RECIPES_RECIPE_H

#include <iostream>
#include <vector>
#include <string>
#include <optional>

#include "ingredient.hpp"
#include "review.hpp"

class BaseRecipe {
public:
    BaseRecipe(std::string name, std::string description, const std::vector<BaseIngredient> &ingredients,
               const std::vector<Review> &reviews = {},
               const double portions = 1.0)
            : name_(std::move(name)),
              description_(std::move(description)),
              ingredients_(ingredients),
              review_manager_(reviews),
              portions_(portions) {}

    void scale_quantity(double portions) {
        // Scale the quantities of ingredients
        for (auto &ingredient: ingredients_) {
            ingredient.scale_quantity(portions);
        }
    }


    void add_review(const Review &review) {
        review_manager_.add_review(review);
    }

    void display() const {
        std::cout << "---------------------" << std::endl;
        std::cout << "Recipe: " << name_ << std::endl;
        std::cout << "1) Description: " << description_ << std::endl;
        std::cout << "2) Ingredients:" << std::endl;
        for (const auto &ingredient: ingredients_) {
            std::cout << " - ";
            ingredient.display();
            std::cout << std::endl;
        }
        std::cout << "3) ";
        get_nutrition_information().display();
        if (review_manager_.get_mean_review_score().has_value()) {
            std::cout << "4) Mean review score: " << static_cast<int>(review_manager_.get_mean_review_score().value());
        }

    }

    NutritionInformation get_nutrition_information() const {
        NutritionInformation nutrition_information{};
        for (const auto &ingredient: ingredients_) {
            nutrition_information = nutrition_information + ingredient.get_nutrition_information();
        }
        return nutrition_information;
    }

    virtual ~BaseRecipe() {}

private:
    std::string name_;
    std::string description_;
    std::vector<BaseIngredient> ingredients_;
    std::string author_;
    ReviewManager review_manager_;
    double health_score_;
    double portions_;
};

// RecipeBuilder class for building recipes
class RecipeBuilder {
public:
    RecipeBuilder(std::string name) : name_(std::move(name)) {}

    RecipeBuilder &set_description(std::string description) {
        description_ = std::move(description);
        return *this;
    }

    RecipeBuilder &add_ingredient(const BaseIngredient &ingredient) {
        ingredients_.emplace_back(ingredient);
        return *this;
    }

    RecipeBuilder &add_review(const Review &review) {
        reviews_.push_back(review);
        return *this;
    }

    BaseRecipe build() const {
        return {name_, description_, ingredients_, reviews_};
    }

private:
    std::string name_;
    std::string description_;
    std::vector<BaseIngredient> ingredients_;
    std::vector<Review> reviews_;
};

#endif // RECIPES_RECIPE_H
