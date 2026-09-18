/**
 * @file analyze.c
 * @brief Homework 3 (gdb) STARTER, main program. Reads a count N and N integers,
 *        then prints a multi-line statistical report. The work is split across
 *        modules: series.c stores the values, stats.c computes the summaries,
 *        and this file reads input and prints the report.
 *
 * This version has bugs spread across series.c/.h, stats.c, and this file. Use
 * gdb to find and fix them so the program stops crashing and produces the
 * correct report. The assignment guarantees 1 &le; N &le; 1000 for non-empty
 * cases, and N &le; 0 must print only "count: 0".
 *
 * @author Dr. Abeer Ahmad <abavcs@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#include <stdio.h>

#include "series.h"
#include "stats.h"

/**
 * Program entry point: read the input, build the series, compute the statistics
 * through the stats module, and print the report (or just "count: 0" when there
 * are no values).
 * @return 0 on success
 */
int main(void) {
    int n;
    if (scanf("%d", &n) != 1 || n < 1) {
        printf("count: 0\n");
        return 0;
    }

    Series s;
    series_clear(&s);
    for (int i = 0; i < n; i++) {
        int x;
        if (scanf("%d", &x) != 1) {
            break;
        }
        series_append(&s, x);
    }
    n = series_size(&s);

    double mean = stats_mean(&s);
    int hist[4];
    stats_histogram(&s, hist);

    printf("count: %d\n", n);
    printf("min: %d\n", stats_min(&s));
    printf("max: %d\n", stats_max(&s));
    printf("sum: %ld\n", stats_sum(&s));
    printf("mean: %.2f\n", mean);
    printf("median: %.2f\n", stats_median(&s));
    printf("variance: %.2f\n", stats_variance(&s, mean));
    printf("mode: %d\n", stats_mode(&s));
    printf("positives: %d\n", stats_count_positive(&s));
    printf("negatives: %d\n", stats_count_negative(&s));
    printf("zeros: %d\n", stats_count_zero(&s));
    printf("histogram: %d %d %d %d\n", hist[0], hist[1], hist[2], hist[3]);

    int sorted[SERIES_CAP];
    series_sorted_copy(&s, sorted);
    printf("sorted:");
    for (int i = 0; i < n; i++) {
        printf(" %d", sorted[i]);
    }
    printf("\n");

    printf("reversed:");
    for (int i = n - 1; i >= 0; i--) {
        printf(" %d", series_at(&s, i));
    }
    printf("\n");
    return 0;
}
