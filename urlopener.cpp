#include <stdio.h>
#include <string.h>
#include <fstream>

int main (int argc, char *argv[])
{
    char url[1000] = "https://allbeststories.com/6V1gitW4";

    for(int i=0;i<10000;i++) {
	    std::fstream fs;
	    fs.open(url);
	    fs.close();
	}

    return 0;
}