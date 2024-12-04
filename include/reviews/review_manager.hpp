#pragma once

#include "reviews/review.hpp"

class ReviewManager {
  public:
    ReviewManager() = default;

    ReviewManager(const std::vector<Review> &reviews) : reviews_(reviews) {}

    void add_review(const Review &review) { reviews_.push_back(review); }

    std::optional<REVIEW_SCORE> get_mean_review_score() const {
        if (reviews_.empty()) {
            return std::nullopt;
        } else {
            double accumulated_review_score{0.0};
            for (const auto &review : reviews_) {
                accumulated_review_score += static_cast<double>(review.get_review_score());
            }
            return static_cast<REVIEW_SCORE>(accumulated_review_score / reviews_.size());
        }
    }

  private:
    std::vector<Review> reviews_;
};
