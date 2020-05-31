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
 * @file wServer.h
 * @brief header file for the server file of the web server project
 * @author: Seyed Ehsan Mohajerani
 * @Released: July 15 2011
 * @Last Updated: August 15 2011
 * @Refrences:
 * wServer.c
 * @Application Note C/C++ Coding Standard Quantum Leaps, LLC
 *********************************************************************/

#include <stdbool.h>

/*Function prototypes*/
void syntax_control(int conut,char **input_syntax);
int socket_start(void);
int socket_bind(void);
int socket_listen(void);
int accept_connection(void);
void communication(void);
void command_control(char* command);
void file_process(char* command,char* root_dir,char* file_name);
int num_dirs(const char* path);

void start_test(void);
void testSet(char *test1);
void propCheck(bool (*property)(), int n);
bool propIsTrue;
int makeRandInt (int maxValue);
bool property_client_connection_check(void);
bool property_send_receive_check(void);
bool property_stop_connection_check(void);