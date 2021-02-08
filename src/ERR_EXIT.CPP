//********************************************************************
//  ERR_EXIT.CPP - Semi-standard error handler
//
//  Copyright (c) 1995-1996 Daniel D. Miller <derelict@netcom.com>
//  Copyright (c) 2021 Robert Riebisch <rr@bttr-software.de>
//
//  Usage of the works is permitted under the terms of the 0-clause
//  BSD license. See `LICENSE.TXT' for details.
//********************************************************************

#include <stdio.h>
#include <stdlib.h>  //  exit()
#include "err_exit.hpp"
// #include <memcheck.h>

/*****************  ERROR CODES AND CONSTANTS  *******************/
char *errmsg[] = {
"Usage: INTERIM ",
"Out of memory",
"Unable to open INTERRUP.A for reading\n"
"You may need to set LIST_DIR in INTSUM.INI",
"Unable to open file for reading",
"Unable to open file for writing",
"Invalid data format",
"USAGE message is too long",
"\nForward search failed ",
"\nUnable to open configuration file",
"\nUnable to open debugging output file",
"\nReverse search failed ",
"This program requires MSDOS 3.0 or later",
NULL } ;

//*******************************************************************
void error_exit(int err_code, char* errstr)
   {
   puts("") ;
   if (errstr == NULL)
      puts(errmsg[err_code]) ;
   else
      printf("%s: %s\n", errstr, errmsg[err_code]) ;
   exit(err_code) ;
   }

