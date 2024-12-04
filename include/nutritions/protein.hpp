#pragma once

#include "base_nutrition.hpp"

namespace recipes {

/**
 * @brief Strong type for protein
 */
class Protein : public BaseNutrition {
  public:
    /**
     * @brief Constructor
     * @param value Value
     */
    explicit Protein(double value) : BaseNutrition(value) {}
};

} // namespace recipes