#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "all.h"
//#include "comm.h"

int main(int argc,char *argv[])
{
        int opt;
        int read_enable = 0;
        int show_enable = 0;
        int create_enable = 0;
        int file_enable = 0;
        int del_enable = 0;
        int cp_enable = 0;
        int link_enable = 0;
        int offset = 0, size = 0;
        int mode= 0;
        char *filename = NULL;
        optind = 0;
        while((opt=getopt(argc,argv,"hqro:l:cfdps:"))!= -1) {
           switch(opt) {
                case 'h':
                        help();
                        break;
                case 'q':
                        show_enable=1;
                        break;
                case 'r':
                        read_enable = 1;
                        break;
                case 'o':
                        offset = atoi(optarg);
                        break;
                case 'l':
                        size = atoi(optarg);
                        break;
                case 'c':
                        create_enable = 1;
                        break;
                case 'f':
                        file_enable = 1;
                        break;
                case 'd':
                        del_enable = 1;
                        break;
                case 'p':
                        cp_enable = 1;
						break;
                case 's':
                        link_enable = 1;
                        break;
                default:
                        printf("invalid option %c", (char)optopt);
                        break;
                }
	}

        filename = argv[optind];
        if(show_enable)
        {
        	show(filename);
	}
       if (read_enable)
       {
       		read_able(filename,offset,size);
	} 
	if(create_enable)
	 {
		if(argv[optind+1]!=NULL){
		mode = atoi(argv[optind+ 1]);
		}
  		create(filename,mode,file_enable);
	 }
	 if(del_enable)
	{
		del(filename); 
	} 
	if(cp_enable==1)
	{
		cp(filename,argv[optind+1]);
	}
	if(link_enable)
	{
		link_able(filename,argv[optind+ 1]);
	} 
	return 0;
}
