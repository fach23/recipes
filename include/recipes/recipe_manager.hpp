#pragma once

#include <algorithm>
#include <vector>

#include "recipes/base_recipe.hpp"

/**
 * @brief Manager for recipes
 */
class RecipeManager {
  public:
    RecipeManager() = default;

    void add_recipe(const BaseRecipe &recipe) { recipes_.push_back(recipe); }

    const BaseRecipe &get_recipe_by_name(const std::string &name) const {
        auto it = std::find_if(std::begin(recipes_), std::end(recipes_),
                               [&](const BaseRecipe &recipe) { return recipe.get_name() == name; });
        if (it != recipes_.end()) {
            return *it;
        } else {
            // TODO:
            return *it;
        }
    }

    void sort_recipes_alphabetically() {
        std::sort(recipes_.begin(), recipes_.end(),
                  [](const BaseRecipe &lhs, const BaseRecipe &rhs) {
                      return lhs.get_name() < rhs.get_name();
                  });
    }

    void get_recipe_names() const {
        for (const auto &recpie : recipes_) {
            std::cout << recpie.get_name() << std::endl;
        }
    }

  private:
    /// @brief recipes
    std::vector<BaseRecipe> recipes_;
};
