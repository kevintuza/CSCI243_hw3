/**
 * @file series.c
 * @brief Implementation of the fixed-capacity integer series (see series.h).
 *        STARTER for Homework 3: contains a bug to find with gdb.
 *
 * @author Kevin Tuza <kat7754@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#include "series.h"

/**
 * Reset a series to empty
 *
 8 @param s the series to clear
 */
void series_clear(Series *s) {
    s->count = 0;
}

/**
 * Append a value to the end of the series
 *
 * @param s     the series
 * @param value the value to append
 *
 * @return 1 if the value was appended, 0 if the series was already full
 */
int series_append(Series *s, int value) {
    if (s->count >= SERIES_CAP){
        return 0;
    }
    s->data[s->count] = value;
    s->count++;
    return 1;
}

/**
 * Report how many values the series holds
 *
 * @param s the series
 *
 * @return the number of values
 */
int series_size(const Series *s) {
    return s->count;
}

/**
 * Return the value at a given index, insertion order
 *
 * @param s     the series
 * @param index the position, 0...size - 1
 *
 * @return the value stored at that index
 */
int series_at(const Series *s, int index) {
    return s->data[index];
}

/**
 * Copy the series values into dest and sort them in ascending order
 *
 * @param s     the series
 * @param dest  destination array of at least series_size ints
 */
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
