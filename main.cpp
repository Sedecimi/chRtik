#include <stdio.h>
#include <string.h>

/*-------------------*/

void show_help(){
	FILE *file;
	file = fopen("./README","r");
	int c;
	while((c=getc(file)) != EOF){
		putchar(c);
	}
	fclose(file);
}

void start_server(char* cfg){
}

void start_client(char* serv_ip){
}

void server_cfg(char* cfg_path){
}

void registration(char* serv_ip){
}

int parse_args(int argc, char* argv[]){
	if(argc < 2){
		fprintf(stderr,"Take an arguments or use --help\n");
		return argc;
	}
	bool hs=true;
	for(int i = 1; i < argc; i++){
		if(argv[i][0]=='-'){
			if((!strcmp(argv[i], "--help")||!strcmp(argv[i],"-h"))&&hs){
				show_help();
				hs=!hs;
			}
			if(!strcmp(argv[i], "-s")){
				fprintf(stdout, "Start as server\n");
				start_server(argv[i++]);
			}
			if(!strcmp(argv[i], "--server-cfg")){
				fprintf(stdout, "Let's configure a server!\n");
				server_cfg(argv[i++]);
			}
			if(!strcmp(argv[i], "-c")){
				fprintf(stdout, "Start as client\n");
				start_client(argv[i++]);
			}
			if(!strcmp(argv[i], "-r")){
				fprintf(stdout, "Start a registration\n");
				registration(argv[i++]);
			}
		}
		else{
			fprintf(stderr, "Wrong arguments\n");
			if(hs)
				show_help();
			return 0;
		}
	}
	return 0;
}

int main(int argc, char* argv[]){
	parse_args(argc, argv);
	return argc;
}

