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

    void start_test(void){
        printf("Test started \n");
        srand(time(NULL)); //Initialize random integer generator
        testing("client connection test");
        }
    void testing(char *test1){
    printf("client connection test", i);
    propcheck (property_client_connection_check,100);

    }


    void propcheck(bool (*property)(), int n){
        for (int i = 1; i < n; ++i){
            int r = makeRandInt(255);
            printf("Testing number %d is %d \n", i,r);
            propistrue = (property(n)==true ) ;
            if (propistrue) {
                printf("Testing number %d is true \n", i);
                }
            else{
                printf("Testing number %d is false \n", i);
                break;
                }
            }
        }

    int makeRandInt (int maxValue){
        int r = rand()%maxValue; //Generate a random integer between 0 and maxValue
        return r;
        }

    bool property_client_connection_check(void){
        printf("Test property_client_connection_check is correct \n");
        return 0;
        }


    //static enum theft_trial_res prop_encoded_and_decoded_data_should_match(struct theft *t, void *arg1) {
      //  struct buffer *input = (struct buffer *)arg1;
        // [compress & uncompress input, compare output & original input]
        // return THEFT_TRIAL_PASS, FAIL, SKIP, or ERROR
        //}