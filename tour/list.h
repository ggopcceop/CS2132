/*
 *  list.h
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 4
 *
 */
struct node {
    double x, y;
    struct node *next;
};
struct node *tour, *nodes;
