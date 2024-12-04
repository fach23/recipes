#include "ingredients/ingredients.hpp"
#include "recipes/recipe_builder.hpp"
#include "recipes/recipe_manager.hpp"

using namespace recipes;

int main() {
    // use the generic RecipeBuilder to create a PizzaDoughRecipe
    BaseRecipe pizza_dough_recipe =
        RecipeBuilder("PizzaDough")
            .set_description("This is a recipe for homemade pizza dough.")
            .add_ingredient(WheatFlourType00(155.0_g))
            .add_ingredient(Water(100.0_ml))
            .add_ingredient(Salt(4.6_g))
            .add_ingredient(Yeast(0.3_g))
            .set_portion_quantity(1.0)
            .set_author("Fabian Christ")
            .add_review({REVIEW_SCORE::FIVE_STARS, "The best pizza recipe in the world!"})
            .add_review({REVIEW_SCORE::FOUR_STARS, "The second best pizza recipe in the world!"})
            .build();
    pizza_dough_recipe.scale_quantity(2.0);
    pizza_dough_recipe.display();

    // use the generic RecipeBuilder to create a DattelSouce
    BaseRecipe dattel_sauce_recipe =
        RecipeBuilder("DattelSauce")
            .set_description("This is a recipe for homemade dattel sauce.")
            .add_ingredient(Salt(4.6_g))
            .set_portion_quantity(1.0)
            .set_author("Fabian Christ")
            .add_review({REVIEW_SCORE::FIVE_STARS, "The best dattel sauce in the world!"})
            .add_review({REVIEW_SCORE::FOUR_STARS, "The second best dattel sauce in the world!"})
            .build();
    dattel_sauce_recipe.display();

    // fill recipe manager with recipes
    RecipeManager recipe_manager;
    recipe_manager.add_recipe(pizza_dough_recipe);
    recipe_manager.add_recipe(dattel_sauce_recipe);
    recipe_manager.sort_recipes_alphabetically();
    recipe_manager.get_recipe_names();

    return 0;
}