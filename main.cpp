#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){

	const char* short_options = "havn::";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"author",no_argument,NULL,'a'},
		{"version",no_argument,NULL,'v'},
		{"number",optional_argument,NULL,'n'},
		{NULL,0,NULL,0}
	};
	
	int option_index;
	int rez = getopt_long(argc, argv, short_options, 
			long_options, &option_index);
	int count_h = 0;
	int count_a = 0;
	int count_v = 0;
	int count_n = 0;
	string author_name = "Leonid Lozko";
	float version = 1.01;
	int number = 10;

	while (rez!=-1){
		switch(rez){
			case 'h': {
				if (not count_h) {
					puts("Arguments:\n"
					"-h, --help - display help\n"
					"-a, --author - display author name\n"
					"-v, --version - display current program version\n"
					"-n, --number - display 10 or number in argument \n");
					count_h++;
				};
				break;
			};

			case 'a': {
				if (not count_a) {	  
					cout << "Author: " << author_name << endl;
					count_a++;
				};
				break;
			};

			case 'v': {
				if (not count_v) {
					printf("Version: %.2f \n", version);
					count_v++;
				};
				break;
			};

			case 'n': {
				if (not count_n) {
					if (optarg) {
						number = atoi(optarg);
					};
					printf("Number: %d \n", number);
					count_n++;
				};
				break;
			};

			case '?': {
				//printf("Unknown argument: %d \n", optopt);
				break;
			};

			default: {	
				break;
			};
		};
		rez = getopt_long(argc, argv, short_options, 
				long_options, &option_index);
	};

	if (count_h) {
		printf("Arg: Help \n");
	};

	if (count_a) {
		printf("Arg: Author \n");
	};
	
	if (count_v) {
		printf("Arg: Version \n");
	};

	if (count_n) {
		printf("Arg: Number \n");
	};

	return 0;
};

