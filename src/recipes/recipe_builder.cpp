#include "recipes/recipe_builder.hpp"

RecipeBuilder::RecipeBuilder(const std::string name) : name_(std::move(name)) {}

RecipeBuilder &RecipeBuilder::set_description(const std::string description) {
    description_ = std::move(description);
    return *this;
}

RecipeBuilder &RecipeBuilder::add_ingredient(const BaseIngredient &ingredient) {
    ingredients_.emplace_back(ingredient);
    return *this;
}

RecipeBuilder &RecipeBuilder::set_portion_quantity(const double portion_quantity) {
    portion_quantity_ = portion_quantity;
    return *this;
}

RecipeBuilder &RecipeBuilder::set_author(const std::string author) {
    author_ = std::move(author);
    return *this;
}

RecipeBuilder &RecipeBuilder::add_review(const Review &review) {
    reviews_.push_back(review);
    return *this;
}

BaseRecipe RecipeBuilder::build() const {
    return {name_, description_, ingredients_, portion_quantity_, author_, reviews_};
}