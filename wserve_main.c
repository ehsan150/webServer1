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
 * @file wserve_main.c
 * @brief header file for the server file of the web server project
 * @author: Seyed Ehsan Mohajerani
 * @Released: July 15 2011
 * @Last Updated: August 15 2011
 * @Refrences:
 * wserve.c
 * @Application Note C/C++ Coding Standard Quantum Leaps, LLC
 *********************************************************************/

#include "wserve.h"

/*start main*/
int main(int argc, char **argv){
	if(argc > 1){
		syntax_control(argc,argv);
	}
	socket_start();
	socket_bind();
	socket_listen();
	accept_connection();
	communication();
	return 0;
}
