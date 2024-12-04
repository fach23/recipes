#include "reviews/review.hpp"

Review::Review(const REVIEW_SCORE review_score, const std::string review_description,
               const std::string review_author)
    : review_score_(review_score), review_description_(std::move(review_description)),
      review_author_(review_author) {}

REVIEW_SCORE Review::get_review_score() const { return review_score_; }

std::string const &Review::get_review_description() const { return review_description_; }

std::string const &Review::get_review_author() const { return review_author_; }