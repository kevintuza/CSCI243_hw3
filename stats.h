/**
 * @file stats.h
 * @brief Summary statistics over a Series of integers (see series.h).
 *        STARTER for Homework 3 (the bugs are in stats.c, not here).
 *
 * @author Dr. Abeer Ahmad <abavcs@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#ifndef STATS_H
#define STATS_H

#include "series.h"

/**
 * Smallest value in the series.
 * @param s a non-empty series
 * @return the minimum value
 */
int stats_min(const Series *s);

/**
 * Largest value in the series.
 * @param s a non-empty series
 * @return the maximum value
 */
int stats_max(const Series *s);

/**
 * Sum of all values.
 * @param s the series
 * @return the sum (as a long, to avoid int overflow)
 */
long stats_sum(const Series *s);

/**
 * Arithmetic mean (average) of the values.
 * @param s a non-empty series
 * @return the mean
 */
double stats_mean(const Series *s);

/**
 * Median value: the middle of the sorted values, or the average of the two
 * middle values when the count is even.
 * @param s a non-empty series
 * @return the median
 */
double stats_median(const Series *s);

/**
 * Population variance: the mean of the squared distances from the mean.
 * @param s    a non-empty series
 * @param mean the previously computed mean of the series
 * @return the variance
 */
double stats_variance(const Series *s, double mean);

/**
 * Count values strictly greater than zero.
 * @param s the series
 * @return the number of positive values
 */
int stats_count_positive(const Series *s);

/**
 * Count values strictly less than zero.
 * @param s the series
 * @return the number of negative values
 */
int stats_count_negative(const Series *s);

/**
 * Count values equal to zero.
 * @param s the series
 * @return the number of zero values
 */
int stats_count_zero(const Series *s);

/**
 * Most frequently occurring value. When several values tie for most frequent,
 * the smallest such value is returned.
 * @param s a non-empty series
 * @return the mode
 */
int stats_mode(const Series *s);

/**
 * Fill a 4-bucket histogram of the values by magnitude:
 * counts[0] = values &lt; 0, counts[1] = 0..9, counts[2] = 10..99,
 * counts[3] = 100 and above.
 * @param s      the series
 * @param counts output array of four bucket counts
 */
void stats_histogram(const Series *s, int counts[4]);

#endif /* STATS_H */
