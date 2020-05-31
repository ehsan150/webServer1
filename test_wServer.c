/***********************************************************************
* Copyright (C) 2011 Seyed Ehsan Mohajerani
*
* This program is free software: you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*********************************************************************
* @file test_wServer.c
* @brief header file for the server file of the web server project
* @author: Seyed Ehsan Mohajerani
* @Released: May 29 2020
* @Last Updated: May 29 2020
* http://shoe.bocks.com/net/
* http://www.pythonprasanna.com/Papers%20and%20Articles/Sockets/udpserver.c
* Application Note C/C++ Coding Standard Quantum Leaps, LLC
*
* Run with XXXXXXXXXXXXX
* @Application Note C/C++ Coding Standard Quantum Leaps, LLC
*********************************************************************/
#include <stdio.h>
#include <assert.h>
#include <inttypes.h>
#include <time.h>   //For random integer generator
#include <stdlib.h> //For random integer generator
#include "theft.h"
#include "theft_types.h"
#include "wServer.h"

//Pre-configurations and run testsets
void start_test(void){
    printf("******Test started \n");
    srand(time(NULL)); //Initialize random integer generator
    testSet("client connection test \n");
    printf("******Test ended \n");
    }
int makeRandInt (int maxValue){
    int r = rand()%maxValue; //Generate a random integer between 0 and maxValue
    return r;
    }
void propCheck(bool (*property)(), int n){
    int passed = 0;
    int failed = 0;
    int total = 0;
    for (total ; total < n; ++total){
        int r = makeRandInt(255);
        printf("Testing number %d is %d \n", total,r);
        propIsTrue = (property(n)==true ) ;
        if (propIsTrue) {
            passed++;
            printf("Testing number %d is true \n", total);
            }
        else{
            printf("Testing number %d is false \n", total);
            break;
            }
        }
    printf("Total number of tests is: %d \n", total);
    printf("Number of passed tests is: %d \n", passed);
    printf("Number of failed tests is: %d \n", failed);
    }

//Testsets
void testSet(char *test1){
    printf("\n client connection test \n");
    propCheck (property_client_connection_check,100);
    printf("\n Send receive test \n");
    propCheck (property_send_receive_check,100);
    printf("\n Stop connection test \n");
    propCheck (property_stop_connection_check,100);
    }
bool property_client_connection_check(void){
    printf("Test property_client_connection_check is correct \n");
    return 0;
    }

bool property_send_receive_check(void){
    printf("Test property_send_receive_check is correct \n");
    return 0;
    }

bool property_stop_connection_check(void){
    printf("Test property_stop_connection_check is correct \n");
    return 0;
    }

//static enum theft_trial_res prop_encoded_and_decoded_data_should_match(struct theft *t, void *arg1) {
  //  struct buffer *input = (struct buffer *)arg1;
    // [compress & uncompress input, compare output & original input]
    // return THEFT_TRIAL_PASS, FAIL, SKIP, or ERROR
    //}