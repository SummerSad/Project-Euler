#include <stdio.h>
#include <string.h>

void swap(char s[], int i, int j);

// arrange the string follow a->b->c
void arrange(char s[], int from, int to);

// the "right most" number < the next number
int right_m(char s[]);

// the celing number is the smallest number
// count from right most to the end
// but > right most
int ceiling(char s[]);

//next lexico order
void next(char s[]);
