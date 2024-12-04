#include "reviews/review_manager.hpp"

ReviewManager::ReviewManager(const std::vector<Review> &reviews) : reviews_(reviews) {}

void ReviewManager::add_review(const Review &review) { reviews_.push_back(review); }

std::optional<REVIEW_SCORE> ReviewManager::get_mean_review_score() const {
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