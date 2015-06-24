/*
 *  node.h
 *  
 * Shuwen Ruan, B00510391
 * Login: sruan
 * CSCI2132: Assignment 5
 *
 *header file
 *for node struct
 */
 struct node {
      char character;
      struct node *left;
      struct node *right;
 };
 struct node *tree;
 
