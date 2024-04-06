/*!
@file       the name of source file is q.h
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   lab 7
@date       file created on 20/10/2023
@brief      provide a brief explanation about what this source file does:
            This file is contains 5 function declaraction be to called by 
            main in qdriver.
            the void sawp function here is only used for file test2.c.
__________________________________________________________________________*/

size_t read_total_count(void);                                              // reads 1 integer input can checks if the number is smaller then 3
void read_3_numbers(int *first, int *second, int *third);                   // takes in 3 integer inputs and stores them into the address of first, second and third
void swap(int *a, int *b);                                                  // swaps the values in the address where a has the value of b and b has the value of a
void sort_3_numbers(int *first, int *second, int *third);                   // sorts the numbers in descending order(from largest to smallest)
void maintain_3_largest(int number, int *first, int *second, int *third);   // when another number is added check if the number is bigger then the smallest number and use the sort function to sorts the numbers in descending order(from largest to smallest)
