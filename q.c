/*!
@file       the name of source file is q.c
@author     Najih & DP login: n.hajasheikallaudin
@course     This source file meant for RSE course    
@section    which section of this course are you enrolled in RSE
@tutorial   lab 6
@date       file created on 10/10/2023
@brief      provide a brief explanation about what this source file does:
            This file is contains 6 function definitions be to called by 
            main in qdriver the 6 functions are 
            - size_t read_total_count(void);                                              // reads 1 integer input can checks value of number
            - void read_3_numbers(int *first, int *second, int *third);                   // takes in 3 integer inputs and stores them into the address of first, second and third
            - void swap(int *a, int *b);                                                  // swaps the values in the address where a has the value of b and b has the value of a
            - void sort_3_numbers(int *first, int *second, int *third);                   // sorts the numbers in descending order(from largest to smallest)
            - void maintain_3_largest(int number, int *first, int *second, int *third);   // when another number is added check if the number is bigger then the smallest number and use the sort function to sorts the numbers in descending order(from largest to smallest)

__________________________________________________________________________*/
#include <stdio.h>
#include <stdlib.h>
#include "q.h"

size_t read_total_count(){                                                              // reads 1 integer input can checks if the number
    
    size_t input = 0;
    printf("Please enter the number of integers: ");
    scanf("%zu", &input);                                                               // using %zu which is the recommended format specifier for size_t datatype

    if (input < 3 ){                                                                    // check if input is smaller then 3
        printf("There is no third largest number.\n");
        exit(0);                                                                        // exit the programe (requires to use of #include <stdlib.h>)
    }else{return input;}                                                                // default statement to return input to qdriver.c
}
void read_3_numbers(int *first, int *second, int *third){                               // takes in 3 integer inputs using scanf and stores them into the address of first, second and third
    scanf("%d %d %d", first, second, third);                                            // storing directly inot the addresss stored in first, second, third
}
void swap(int *a, int *b){                                                              // swaps the values in the address where a has the value of b and b has the value of a
    int temp = *a;
    *a = *b;
    *b = temp;
}
void sort_3_numbers(int *first, int *second, int *third){
    /*
    //nested if statement version for sort_3_numbers function
    for (int i =0; i<4; i++){                                                           // using for loop to ensure that all the numbers are in descending order // for loop can be used as the number of inputs taken for this programe is always 3
        if(*first < *second){                              
            swap(first, second);
        }
        else if (*first < *third){
            swap(second, third);
        }
        else if (*second < *third){
            swap(first, third);
        }
    }
    */

    //single line if statement version for sort_3_numbers function
    for (int i =0; i<4; i++){
        (*first < *second) ? swap(first, second) : (*first < *third) ? swap(second, third): (*second < *third) ? swap(first, third) : swap(first, first);
    }
}
void maintain_3_largest(int number, int *first, int *second, int *third){
    //long version      (can be used in other programs with implementation of swap function)
    /*if(*first < number){
        swap(first, third);
        swap(second, third);
        *first = number;
    }
    else if (*second < number) {
        swap(third, second);
        *second = number;
    }
    else if (*third < number){
        *third = number;
    }*/

    //short version      (can be used in this program not requiring swap function)
    int temp_1, temp_2;
    if(*third < number){                                                  // since the values have been sorted previously we can ensure that the smallest value is stored in third. so we can 
        temp_1 = *first;                                                  // shift the values accordingly and use the sort function again to enusure that the values are in descending order
        *first = number;   // number is first

        temp_2 = *second;
        *second = temp_1;  // first is second

        *third = temp_2;   // second is third
    }
    sort_3_numbers(first, second, third);
}
