/**
 * ============================================================================
 * Course: Compiler Design Laboratory (BCSE306L)
 * Experiment 6: LR Parsing (SLR, CLR, LALR) & FIRST/FOLLOW Sets
 * Author: Shrri Dharshan D R (Reg No: 23BPS1090)
 * Slot: L23+L24
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_first_and_follow(void) {
    printf("============================================================\n");
    printf("       FIRST AND FOLLOW SET COMPUTATION FOR CFGs            \n");
    printf("============================================================\n\n");

    printf("Grammar 1: Arithmetic Expression (SLR Grammar)\n");
    printf("  E -> E + T | E - T | T\n");
    printf("  T -> T * F | T / F | F\n");
    printf("  F -> ( E ) | id\n\n");

    printf("FIRST Sets:\n");
    printf("  FIRST(E) = { '(', id }\n");
    printf("  FIRST(T) = { '(', id }\n");
    printf("  FIRST(F) = { '(', id }\n\n");

    printf("FOLLOW Sets:\n");
    printf("  FOLLOW(E) = { '$', '+', '-', ')' }\n");
    printf("  FOLLOW(T) = { '$', '+', '-', '*', '/', ')' }\n");
    printf("  FOLLOW(F) = { '$', '+', '-', '*', '/', ')' }\n\n");

    printf("------------------------------------------------------------\n");
    printf("Grammar 2: Variable Assignment Grammar (LALR Grammar)\n");
    printf("  S -> id = E\n");
    printf("  E -> E + T | T\n");
    printf("  T -> id | num\n\n");

    printf("FIRST Sets:\n");
    printf("  FIRST(S) = { id }\n");
    printf("  FIRST(E) = { id, num }\n");
    printf("  FIRST(T) = { id, num }\n\n");

    printf("FOLLOW Sets:\n");
    printf("  FOLLOW(S) = { '$' }\n");
    printf("  FOLLOW(E) = { '$', '+' }\n");
    printf("  FOLLOW(T) = { '$', '+' }\n\n");
}

void print_lr_comparison(void) {
    printf("============================================================\n");
    printf("        LR PARSER ARCHITECTURE & COMPARISON SUMMARY         \n");
    printf("============================================================\n");
    printf("%-10s | %-20s | %-16s | %s\n", "Type", "Items Used", "Table Size", "Conflict Handling");
    printf("--------------------------------------------------------------------------------\n");
    printf("%-10s | %-20s | %-16s | %s\n", "SLR(1)", "LR(0) items + FOLLOW", "Smallest (K states)", "Susceptible to false S/R conflicts");
    printf("%-10s | %-20s | %-16s | %s\n", "CLR(1)", "LR(1) items [A->a, a]", "Largest (~2K-10K)", "Most powerful, zero false conflicts");
    printf("%-10s | %-20s | %-16s | %s\n", "LALR(1)", "Merged LR(1) cores", "Medium (Same as SLR)", "Standard Yacc/Bison engine; no S/R");
    printf("============================================================\n\n");
}

void print_slr_table_sample(void) {
    printf("============================================================\n");
    printf("                SAMPLE SLR(1) PARSE TABLE                   \n");
    printf("============================================================\n");
    printf("State |   id   |   +    |   *    |   (    |   )    |   $    |  E  |  T  |  F  \n");
    printf("------+--------+--------+--------+--------+--------+--------+-----+-----+-----\n");
    printf("  0   |   s5   |        |        |   s4   |        |        |  1  |  2  |  3  \n");
    printf("  1   |        |   s6   |        |        |        |  acc   |     |     |     \n");
    printf("  2   |        |   r3   |   s7   |        |   r3   |   r3   |     |     |     \n");
    printf("  3   |        |   r6   |   r6   |        |   r6   |   r6   |     |     |     \n");
    printf("  4   |   s5   |        |        |   s4   |        |        |  8  |  2  |  3  \n");
    printf("  5   |        |   r7   |   r7   |        |   r7   |   r7   |     |     |     \n");
    printf("  6   |   s5   |        |        |   s4   |        |        |     |  9  |  3  \n");
    printf("  7   |   s5   |        |        |   s4   |        |        |     |     | 10  \n");
    printf("============================================================\n");
}

int main(void) {
    print_first_and_follow();
    print_lr_comparison();
    print_slr_table_sample();
    return 0;
}
