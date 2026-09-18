/**
 * @file series.h
 * @brief A fixed-capacity sequence of integers, plus a sorted-copy helper.
 *        STARTER for Homework 3: this multi-file program has bugs to find with
 *        gdb. The assignment guarantees at most 1000 values.
 *
 * @author Dr. Abeer Ahmad <abavcs@rit.edu>
 * @course CSCI-243 Homework 3 (Debugging with gdb), supplied starter
 */
#ifndef SERIES_H
#define SERIES_H

#define SERIES_CAP 8   /* the assignment guarantees N <= 1000 values */

/** A sequence of up to SERIES_CAP integers, in insertion order. */
typedef struct {
    int data[SERIES_CAP];
    int count;
} Series;

/**
 * Reset a series to empty.
 * @param s the series to clear
 */
void series_clear(Series *s);

/**
 * Append a value to the end of the series.
 * @param s     the series
 * @param value the value to append
 * @return 1 if the value was appended, 0 if the series was already full
 */
int series_append(Series *s, int value);

/**
 * Report how many values the series holds.
 * @param s the series
 * @return the number of values
 */
int series_size(const Series *s);

/**
 * Return the value at a given index (0-based, in insertion order).
 * @param s     the series
 * @param index the position, 0 .. size-1
 * @return the value stored at that index
 */
int series_at(const Series *s, int index);

/**
 * Copy the series values into dest and sort them in ascending order. dest must
 * have room for series_size(s) integers; the series itself is not modified.
 * @param s    the series
 * @param dest destination array of at least series_size(s) ints
 */
void series_sorted_copy(const Series *s, int *dest);

#endif /* SERIES_H */
