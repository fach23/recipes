#pragma once

#include <algorithm>
#include <vector>

#include "recipes/base_recipe.hpp"

namespace recipes {

/**
 * @brief Manager for recipes
 */
class RecipeManager {
  public:
    /**
     * @brief Constructor
     */
    RecipeManager() = default;

    /**
     * @brief Adds recipe
     * @param recipe Recipe to be added
     */
    void add_recipe(const BaseRecipe &recipe);

    /**
     * @brief Return recipe by name
     * @param name Name of the recipe
     */
    const BaseRecipe &get_recipe_by_name(const std::string &name) const;

    /**
     * @brief Sorts recipes alphabetically
     */
    void sort_recipes_alphabetically();

    /**
     * @brief Returns recipe names
     */
    void get_recipe_names() const;

  private:
    /// @brief recipes
    std::vector<BaseRecipe> recipes_;
};

} // namespace recipes