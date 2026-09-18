/**
 * @file stats.c
 * @brief Implementation of the summary statistics (see stats.h).
 *        STARTER for Homework 3: contains bugs to find with gdb.
 *
 * @author Dr. Abeer Ahmad <abavcs@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#include "stats.h"

int stats_min(const Series *s) {
    int m = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) < m) {
            m = series_at(s, i);
        }
    }
    return m;
}

int stats_max(const Series *s) {
    int m = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) > m) {
            m = series_at(s, i);
        }
    }
    return m;
}

long stats_sum(const Series *s) {
    long sum = 0;
    for (int i = 0; i < series_size(s); i++) {
        sum += series_at(s, i);
    }
    return sum;
}

double stats_mean(const Series *s) {
    return (double) stats_sum(s) / series_size(s);
}

double stats_median(const Series *s) {
    int n = series_size(s);
    int sorted[SERIES_CAP];
    series_sorted_copy(s, sorted);
    return sorted[n / 2];
}

double stats_variance(const Series *s, double mean) {
    double acc = 0.0;
    for (int i = 0; i < series_size(s); i++) {
        double diff = series_at(s, i) - mean;
        acc += diff * diff;
    }
    return acc / series_size(s);
}

int stats_count_positive(const Series *s) {
    int c = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) > 0) c++;
    }
    return c;
}

int stats_count_negative(const Series *s) {
    int c = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) < 0) c++;
    }
    return c;
}

int stats_count_zero(const Series *s) {
    int c = 0;
    for (int i = 0; i < series_size(s); i++) {
        if (series_at(s, i) == 0) c++;
    }
    return c;
}

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
