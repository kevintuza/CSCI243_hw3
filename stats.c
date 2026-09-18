/**
 * @file stats.c
 * @brief Implementation of the summary statistics (see stats.h).
 *        STARTER for Homework 3: contains bugs to find with gdb.
 *
 * @author Kevin Tuza <kat7754@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#include "stats.h"

/**
 * Smallest value in the series
 *
 * @param s a non-empty series
 *
 * @return the minimum value
 */
int stats_min(const Series *s) {
    int m = series_at(s,0);
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) < m) {
            m = series_at(s, i);
        }
    }
    return m;
}

/**
 * Largest value in the series
 *
 * @param s a non-empty series
 *
 * @return the maximum value
 */
int stats_max(const Series *s) {
    int m = series_at(s,0);
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) > m) {
            m = series_at(s, i);
        }
    }
    return m;
}

/**
 * Sum of all values
 *
 * @param s the series
 *
 * @return the sum
 */
long stats_sum(const Series *s) {
    long sum = 0;
    for (int i = 0; i < series_size(s); i++) {
        sum += series_at(s, i);
    }
    return sum;
}

/**
 * Arithmetic mean of the values
 *
 * @param s a non-empty series
 *
 * @return the mean
 */
double stats_mean(const Series *s) {
    return (double) stats_sum(s) / series_size(s);
}

/**
 * Median value is the middle of the sorted values, or the average of middle values when the count is even.
 *
 * @param s a non-empty series
 *
 * @return the median
 */
double stats_median(const Series *s) {
    int n = series_size(s);
    int sorted[SERIES_CAP];
    series_sorted_copy(s, sorted);

    if (n%2 == 0) {
        return (sorted[n / 2-1] + sorted[n / 2]) / 2.0;
    } else {
    return sorted[n / 2];
    }
}

/**
 * Population variance the mean of the squared distances from the mean
 * 
 * @param s     a non-empty series
 * @param mean  previously computed mean of the series
 *
 * @return the variance
 */
double stats_variance(const Series *s, double mean) {
    double acc = 0.0;
    for (int i = 0; i < series_size(s); i++) {
        double diff = series_at(s, i) - mean;
        acc += diff * diff;
    }
    return acc / series_size(s);
}

/**
 * Count values strictly greater than zero
 *
 * @param s the series
 * 
 * @return the number of positive values
 */
int stats_count_positive(const Series *s) {
    int c = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) > 0) c++;
    }
    return c;
}

/**
 * Count values strictly less than zero
 *
 * @param s the series
 *
 * @return the number of negative values
 */
int stats_count_negative(const Series *s) {
    int c = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) < 0) c++;
    }
    return c;
}

/**
 * Coount values equal to zero
 *
 * @param s the series
 *
 * @return the number of zero values
 */
int stats_count_zero(const Series *s) {
    int c = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) == 0) c++;
    }
    return c;
}

/**
 * Most frequently occurring value. When several values tie for most frequent the smallest such value is returned
 *
 * @param s a non-empty series
 *
 * @return the mode
 */
int stats_mode(const Series *s) {
    int n = series_size(s);
    int sorted[SERIES_CAP];
    series_sorted_copy(s, sorted);
    int best_value = sorted[0];
    int best_run = 1;
    int run = 1;
    for (int i = 1; i < n; i++) {
        if (sorted[i] == sorted[i - 1]) {
            run++;
        } else {
            run = 1;
        }
        if (run > best_run) {
            best_run = run;
            best_value = sorted[i];
        }
    }
    return best_value;
}

/**
 * Fill a histogram of the values by magnitude
 *
 * @param s     the series
 * @param counts output array of four bucket counts
 */
void stats_histogram(const Series *s, int counts[4]) {
    counts[0] = counts[1] = counts[2] = counts[3] = 0;
    for (int i = 0; i < series_size(s); i++) {
        int x = series_at(s, i);
        if (x < 0) {
            counts[0]++;
        } else if (x <= 9) {
            counts[1]++;
        } else if (x <= 99) {
            counts[2]++;
        } else {
            counts[3]++;
        }
    }
}
