#pragma once

#include "base_nutrition.hpp"

/**
 * @brief Strong type for calories
 */
class Calories : public BaseNutrition {
public:
    /**
     * @brief Constructor
     * @param value Value
     */
    explicit Calories(double value) : BaseNutrition(value) {}
};
