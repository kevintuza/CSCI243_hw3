/**
 * @file series.c
 * @brief Implementation of the fixed-capacity integer series (see series.h).
 *        STARTER for Homework 3: contains a bug to find with gdb.
 *
 * @author Dr. Abeer Ahmad <abavcs@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#include "series.h"

void series_clear(Series *s) {
    s->count = 0;
}

int series_append(Series *s, int value) {
    s->data[s->count] = value;
    s->count++;
    return 1;
}

int series_size(const Series *s) {
    return s->count;
}

int series_at(const Series *s, int index) {
    return s->data[index];
}

void series_sorted_copy(const Series *s, int *dest) {
    for (int i = 0; i < s->count; i++) {
        dest[i] = s->data[i];
    }
    /* insertion sort, ascending */
    for (int i = 1; i < s->count; i++) {
        int key = dest[i];
        int j = i - 1;
        while (j >= 0 && dest[j] > key) {
            dest[j + 1] = dest[j];
            j--;
        }
        dest[j + 1] = key;
    }
}
