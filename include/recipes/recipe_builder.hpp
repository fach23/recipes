#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "recipes/base_recipe.hpp"
#include "reviews/review.hpp"

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

    RecipeBuilder &set_portion_quantity(double portion_quantity) {
        portion_quantity_ = portion_quantity;
        return *this;
    }

    RecipeBuilder &set_author(std::string author) {
        author_ = std::move(author);
        return *this;
    }

    RecipeBuilder &add_review(const Review &review) {
        reviews_.push_back(review);
        return *this;
    }

    BaseRecipe build() const {
        return {name_, description_, ingredients_, portion_quantity_, author_, reviews_};
    }

  private:
    std::string name_;
    std::string description_;
    std::vector<BaseIngredient> ingredients_;
    double portion_quantity_;
    std::string author_;
    std::vector<Review> reviews_;
};
