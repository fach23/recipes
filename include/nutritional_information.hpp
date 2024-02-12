#ifndef RECIPES_NUTRITIONAL_INFORMATION_H
#define RECIPES_NUTRITIONAL_INFORMATION_H

#include <iostream>
#include <vector>
#include <string>

class BaseNutrition {
public:
    BaseNutrition(double value) : value_(value) {}

    double get_value() const { return value_; }

    template <typename T>
    T operator+(const T &other) const {
        T result(value_ + other.get_value());
        return result;
    }

    virtual ~BaseNutrition() {}

protected:
    double value_;
};


// Strong type for calories
class Calories : public BaseNutrition {
public:
    explicit Calories(double value) : BaseNutrition(value) {}

};

// Strong type for protein
class Protein : public BaseNutrition {
public:
    explicit Protein(double value) : BaseNutrition(value) {}
};

// Strong type for sugar
class Sugar : public BaseNutrition {
public:
    explicit Sugar(double value) : BaseNutrition(value) {}
};

// Strong type for carbohydrates
class Carbohydrates : public BaseNutrition {
public:
    explicit Carbohydrates(double value) : BaseNutrition(value) {}
};


// Strong type for fat
class Fat : public BaseNutrition {
public:
    explicit Fat(double value) : BaseNutrition(value) {}
};

// per 100 gr
class NutritionInformation {
public:

    NutritionInformation(Calories calories = Calories(0.0), Protein protein = Protein(0.0),
                         Carbohydrates carbohydrates = Carbohydrates(0.0), Fat fat = Fat(0.0))
            : calories_(calories), protein_(protein), carbohydrates_(carbohydrates), fat_(fat) {}

    // Overload + operator
    NutritionInformation operator+(const NutritionInformation &other) const {
        NutritionInformation result(calories_ + other.calories_, protein_ + other.protein_,
                                    carbohydrates_ + other.carbohydrates_, fat_ + other.fat_);
        return result;
    }

    // Getters for nutrition information
    Calories get_calories() const { return calories_; }

    Protein get_protein() const { return protein_; }

    Carbohydrates get_carbohydrates() const { return carbohydrates_; }

    Fat get_fat() const { return fat_; }

    void display() const {
        std::cout << "Nutritional Information:\n"
                  << " - Calories: " << calories_.get_value() << " kcal\n"
                  << " - Protein: " << protein_.get_value() << "g\n"
                  << " - Carbohydrates: " << carbohydrates_.get_value() << "g\n"
                  << " - Fat: " << fat_.get_value() << "g\n";

    }

private:
    Calories calories_;
    Protein protein_;
    Carbohydrates carbohydrates_;
    Fat fat_;
};


#endif // RECIPES_NUTRITIONAL_INFORMATION_H
