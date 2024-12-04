#pragma once

#include "base_nutrition.hpp"

/**
 * @brief Strong type for fat
 */
class Fat : public BaseNutrition {
  public:
    /**
     * @brief Constructor
     * @param value Value
     */
    explicit Fat(double value) : BaseNutrition(value) {}
};