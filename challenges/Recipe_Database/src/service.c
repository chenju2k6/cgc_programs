/*

Author: Steve Wood <swood@cromulence.co>

Copyright (c) 2014 Cromulence LLC

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

*/
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "libcgc.h"
#include "cgc_stdlib.h"
#include "cgc_service.h"


Recipe_Type *cgc_recipe_book=0;

int main(int cgc_argc, char *cgc_argv[]) {
    

int fdin = open(cgc_argv[1],O_RDONLY);
close(0);
dup2(fdin, 0);
cgc_size_t size;
char buffer[10];
int command;
char buffer1[100];
char buffer2[100];


    // loop forever receiving command strings from STDIN.
    while (1) {

        cgc_print_main_menu();

        size=cgc_getline(buffer, sizeof(buffer));

        // ignore that a blank line was entered
        if (size==0)
            continue;

        command=cgc_atoi(buffer);

        switch (command) {


            case 1:

                cgc_new_recipe(&cgc_recipe_book);
                break;

            case 2:

                cgc_find_recipe(cgc_recipe_book);
                break;

            case 3:

                cgc_print_all_tagged(cgc_recipe_book);
                break;

            case 4:

                cgc_print_shopping_list(cgc_recipe_book);
                break;
            case 5:

                cgc__terminate(0);
                break;

            default:

                cgc_printf("Invalid command\n");


        } // switch

      
    }  // while(1)
close(fdin);
 
}  // main  

