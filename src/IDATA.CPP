//********************************************************************
//  IDATA.CPP - Global data for INTSUM application
//
//  Copyright (c) 1995-1996 Daniel D. Miller <derelict@netcom.com>
//  Copyright (c) 2021 Robert Riebisch <rr@bttr-software.de>
//
//  Usage of the works is permitted under the terms of the 0-clause
//  BSD license. See `LICENSE.TXT' for details.
//********************************************************************

#include <stdio.h>   //  FILE*
#include "intsum.hpp"
// #include <memcheck.h>

//********************************************************************
//  size of data buffers
const long BFR_SIZE = 32000LU ;

//  size of reverse read must be smaller than size of normal
//  read, so we are assured of finding current-line in our search.
//lint -e528
const long REV_SIZE = 10000LU ;

//lint -e528
const int LOOP_FOREVER = 1 ;

//********************************************************************
char rdtemp[UNDERSHOOT] ;

//********************************************************************
//  used by one-line message functions and partial screen-clear
//********************************************************************
char spaces[121] =
   "                                        "
   "                                        "
   "                                        " ; //  120 spaces

//********************************************************************
//lint -e528
const unsigned last_ref_char = sizeof(sum_conv) - 1 ;
//lint -e528
const unsigned isl_lines = (unsigned) (BFR_SIZE / sizeof(int_sum_line)) ;

//*****************************************************************
refs ref ;  //  reference-file data struct

//*****************************************************************
//  list-file data struct
//*****************************************************************
lists list ;

//lint -e528
const unsigned list_lines = (unsigned) (BFR_SIZE / sizeof(lines)) ;

FILE* lfile ;  //  make this global so scrolling fcns can get to it.

//*****************************************************************
searchs search ;  //  string-search data struct

//*****************************************************************
//  raw-data read buffer
//*****************************************************************
char* readptr ;

//*****************************************************************
//  misc data strings
//*****************************************************************
char tempstr[128] ;  //  scratchpad string
char oldstr[128] ;   //  used by reverse_search routines
char inipath[64] ;
char inidrive[4] ;
char ilpath[64] ;
char ildrive[4] ;

//*****************************************************************
//  display structs
//*****************************************************************
vidptr ivideo = { DATA_TOP_ROW } ;

unsigned window_rows ;  //  data lines, not counting header

FILE* index ;
//*****************************************************************
//  screen text
//*****************************************************************
char* header =
   "INT AH AL                     Description                     Press F1 for help " ;
char* dividerd =
   "様曜様僕曜様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様" ;
char* list_header =
   "                              Description                     Press F1 for help " ;
char* list_dividerd =
   "様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様" ;

