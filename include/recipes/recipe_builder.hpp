#pragma once

#include <iostream>
#include <optional>
#include <string>
#include <vector>

#include "recipes/base_recipe.hpp"
#include "reviews/review.hpp"

namespace recipes {

/**
 * @brief Class for building recipes
 */
class RecipeBuilder {
  public:
    /**
     * @brief Constructor
     * @param name Name
     */
    RecipeBuilder(std::string name);

    /**
     * @brief Sets description
     * @param description Description
     */
    RecipeBuilder &set_description(std::string description);

    /**
     * @brief Adds ingredient
     * @param ingredient Ingredient
     */
    RecipeBuilder &add_ingredient(const BaseIngredient &ingredient);

    /**
     * @brief Sets portion quantity
     * @param portion_quantity Portional quantity
     */
    RecipeBuilder &set_portion_quantity(double portion_quantity);
    /**
     * @brief Sets author
     * @param author Author
     */
    RecipeBuilder &set_author(std::string author);

    /**
     * @brief Adds review
     * @param review Review
     */
    RecipeBuilder &add_review(const Review &review);

    /**
     * @brief Builds recipe
     */
    BaseRecipe build() const;

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
    /// @brief Reviews
    std::vector<Review> reviews_;
};

} // namespace recipes