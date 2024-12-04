#pragma once

#include <iostream>
#include <optional>
#include <vector>

/**
 * @brief Review score
 */
enum class REVIEW_SCORE {
    NO_STAR = 0,
    ONE_STAR = 1,
    TWO_STARS = 2,
    THREE_STARS = 3,
    FOUR_STARS = 4,
    FIVE_STARS = 5
};

/**
 * @brief Review
 */
class Review {
  public:
    /**
     * @brief Constructor
     * @param review_score Review score
     * @param review_description Review description
     * @param review_author Review author
     */
    Review(REVIEW_SCORE review_score, std::string review_description = "",
           std::string review_author = "");

    /**
     * @brief Return review score
     * @return Review score‚
     */
    REVIEW_SCORE get_review_score() const;

    /**
     * @brief Returns review description
     * @return Review description
     */
    std::string const &get_review_description() const;

    /**
     * @brief Retursn review author
     * @return Review author
     */
    std::string const &get_review_author() const;

  private:
    /// @brief Review score
    REVIEW_SCORE review_score_;
    /// @brief Review description
    std::string review_description_;
    /// @brief Review author
    std::string review_author_;
};