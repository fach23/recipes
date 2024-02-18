#include <iostream>
#include <vector>
#include <string>
#include "include/nutritional_information.hpp"
#include "include/ingredient.hpp"
#include "include/recipe.hpp"

int main() {
    // Using the generic RecipeBuilder to create a PizzaDoughRecipe
    BaseRecipe pizza_dough_recipe = RecipeBuilder("PizzaDough")
            .set_description("This is a recipe for homemade pizza dough.")
            .add_ingredient(WheatFlourType00(155.0_g))
            .add_ingredient(Water(100.0_ml))
            .add_ingredient(Salt(4.6_g))
            .add_ingredient(Yeast(0.3_g))
            .add_review({REVIEW_SCORE::FIVE_STARS, "The best pizza recipe in the world!"})
            .add_review({REVIEW_SCORE::FOUR_STARS, "The second best pizza recipe in the world!"})
            .build();

    pizza_dough_recipe.scale_quantity(1.0);

    pizza_dough_recipe.display();

    return 0;
}