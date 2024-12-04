#pragma once

#include "reviews/review.hpp"
namespace recipes {

/**
 * @brief Review manager‚
 */
class ReviewManager {
  public:
    /**
     * @brief Constructor
     */
    ReviewManager() = default;

    /**
     * @brief Constructor
     * @param reviews Reviews to be added
     */
    ReviewManager(const std::vector<Review> &reviews);

    /**
     * @brief Adds review
     * @param review Review to be added
     */
    void add_review(const Review &review);

    /**
     * @brief Returns mean review score
     * @return Mean review score
     */
    std::optional<REVIEW_SCORE> get_mean_review_score() const;

  private:
    /// @brief Reviews
    std::vector<Review> reviews_;
};

} // namespace recipes