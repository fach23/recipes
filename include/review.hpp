#ifndef RECIPES_REVIEW_HPP
#define RECIPES_REVIEW_HPP

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
    Review(REVIEW_SCORE review_score, const std::string &review_description)
            : review_score_(review_score), review_description_(review_description) {}

    REVIEW_SCORE get_review_score() const { return review_score_; }

    std::string const &get_review_description() const { return review_description_; }

private:
    REVIEW_SCORE review_score_;
    std::string review_description_;
};

class ReviewManager {
public:
    ReviewManager() = default;

    ReviewManager(const std::vector<Review> &reviews)
            : reviews_(reviews) {}

    void add_review(const Review &review) {
        reviews_.push_back(review);

    }

    std::optional<REVIEW_SCORE> get_mean_review_score() const {
        if (reviews_.empty()) {
            return std::nullopt;
        } else {
            double accumulated_review_score{0.0};
            for (const auto &review: reviews_) {
                accumulated_review_score += static_cast<double>(review.get_review_score());
            }
            return static_cast<REVIEW_SCORE>(accumulated_review_score / reviews_.size());
        }
    }

private:
    std::vector<Review> reviews_;
};


#endif // RECIPES_REVIEW_HPP