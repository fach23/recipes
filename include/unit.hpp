#ifndef RECIPES_UNIT_HPP
#define RECIPES_UNIT_HPP

#include <iostream>
#include <string>
#include <memory>

enum class WEIGHT_UNIT {
    GRAM, // DEFAULT
    KILOGRAM
};

std::string to_string(WEIGHT_UNIT unit);

enum class VOLUME_UNIT {
    MILLILITER, // DEFAULT
    LITER
};

std::string to_string(VOLUME_UNIT unit);

enum class ENERGY_UNIT {
    KILOCALORIE, // DEFAULT
    KILOJOULE
};

std::string to_string(ENERGY_UNIT unit);

enum class PIECE_UNIT {
    PIECE, // DEFAULT
    DOZEN
};

std::string to_string(PIECE_UNIT unit);

enum class SPOON_UNIT {
    TEA_SPOON, // DEFAULT
    TABLE_SPOON
};

std::string to_string(SPOON_UNIT unit);

class PINCH_UNIT {

};

class BaseQuantity;

using QuantityPtr = std::shared_ptr<BaseQuantity>;

class BaseQuantity {
public:
    virtual void display() const = 0;

    virtual void scale_quantity(double portions) = 0;

    virtual ~BaseQuantity() = default;
};

class Weight : public BaseQuantity {
public:
    Weight(double value, WEIGHT_UNIT unit)
            : value_(value), unit_(unit) {}

    void scale_quantity(double portions) override {
        value_ *= portions;
    }

    void display() const override {
        std::cout << value_ << to_string(unit_);
    }

private:
    double value_;
    WEIGHT_UNIT unit_;
};

class Volume : public BaseQuantity {
public:
    Volume(double value, VOLUME_UNIT unit)
            : value_(value), unit_(unit) {}

    void scale_quantity(double portions) override {
        value_ *= portions;
    }

    void display() const override {
        std::cout << value_ << to_string(unit_);
    }

private:
    double value_;
    VOLUME_UNIT unit_;
};

class Pieces : public BaseQuantity {
public:
    Pieces(unsigned long long value, PIECE_UNIT unit)
            : value_(value), unit_(unit) {}

    void scale_quantity(double portions) override {
        value_ *= portions;
    }

    void display() const override {
        std::cout << value_ << to_string(unit_);
    }

private:
    unsigned long long value_;
    PIECE_UNIT unit_;
};

class Spoons : public BaseQuantity {
public:
    Spoons(unsigned long long value, SPOON_UNIT unit)
            : value_(value), unit_(unit) {}

    void scale_quantity(double portions) override {
        value_ *= portions;
    }

    void display() const override {
        std::cout << value_ << to_string(unit_);
    }

private:
    unsigned long long value_;
    SPOON_UNIT unit_;
};

class Energy : public BaseQuantity {
public:
    Energy(double value, ENERGY_UNIT unit)
            : value_(value), unit_(unit) {}

    void scale_quantity(double portions) override {
        value_ *= portions;
    }

    void display() const override {
        std::cout << value_ << to_string(unit_);
    }

private:
    double value_;
    ENERGY_UNIT unit_;
};

Weight operator "" _g(long double value);

Weight operator "" _kg(long double value);

Volume operator "" _ml(long double value);

Volume operator "" _l(long double value);

Energy operator "" _kcal(long double value);

Energy operator "" _kj(long double value);

Pieces operator "" _piece(unsigned long long value);

Spoons operator "" _tea_spoon(unsigned long long value);

Spoons operator "" _table_spoon(unsigned long long value);

unsigned long long operator "" _pinch(unsigned long long value);

#endif // RECIPES_UNIT_HPP
