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
            .add_ingredient(Apfel(1.0_kg))
            .add_ingredient(Banane(5_piece))
            .add_review({REVIEW_SCORE::FIVE_STARS, "The best pizza recipe in the world!"})
            .add_review({REVIEW_SCORE::FOUR_STARS, "The second best pizza recipe in the world!"})
            .build();

    pizza_dough_recipe.display();



    return 0;
}