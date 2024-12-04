#pragma once

/**
 * @brief Base class for nutrition
 */
class BaseNutrition {
  public:
    /**
     * @brief Constructor
     */
    BaseNutrition(double value) : value_(value) {}

    /**
     * @brief Get value
     * @return Value
     * */
    double get_value() const { return value_; }

    /**
     * @brief Operator for adding nutritions
     */
    template <typename T> T operator+(const T &other) const {
        T result(value_ + other.get_value());
        return result;
    }

    /**
     * @brief Destructor
     */
    virtual ~BaseNutrition() {}

  protected:
    /// @brief Value
    double value_;
};
