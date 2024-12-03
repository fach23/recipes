#pragma once

#include <iostream>
#include <vector>
#include <optional>

enum class REVIEW_SCORE {
    NO_STAR = 0,
    ONE_STAR = 1,
    TWO_STARS = 2,
    THREE_STARS = 3,
    FOUR_STARS = 4,
    FIVE_STARS = 5
};

class Review {
public:
    Review(REVIEW_SCORE review_score, std::string review_description = "", std::string review_author = "")
            : review_score_(review_score), review_description_(std::move(review_description)),
              review_author_(review_author) {}

    REVIEW_SCORE get_review_score() const { return review_score_; }

    std::string const &get_review_description() const { return review_description_; }

    std::string const &get_review_author() const { return review_author_; }

private:
    REVIEW_SCORE review_score_;
    std::string review_description_;
    std::string review_author_;
};