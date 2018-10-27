#include "types.h"
#include "user.h"

int main(){
	int p[2];
	char *argv[2];
	argv[0]="wc";
	argv[1]=0;

	pipe(p);
	if(!fork()){
		close(0);
		dup(p[0]);
		close(p[0]);
		close(p[1]);
		exec("./wc",argv);
	}
	else{
		close(p[0]);
		write(p[1], "hello world\n",12);
		close(p[1]);
		wait();
	}
	exit();
}
