#pragma once

#include "base_nutrition.hpp"

namespace recipes {

/**
 * @brief Strong type for carbohydrates
 */
class Carbohydrates : public BaseNutrition {
  public:
    /**
     * @brief Constructor
     * @param value Value
     */
    explicit Carbohydrates(double value) : BaseNutrition(value) {}
};

} // namespace recipes