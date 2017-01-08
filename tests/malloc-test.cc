#include <iostream>
#include <string>
#include <unistd.h>

std::size_t gb = 1024ull*1024*1024;
int main(int ac, char** av) try {
    std::size_t n = std::stoi(av[1])*gb;
    std::cout << "allocating " << n << " bytes (" << double(n)/gb << "GB)..." << std::flush;
    char* p = new char[n];
    std::cout << "Allocated" << std::endl;
    pid_t f = fork();
    if(f == -1) std::perror("fork");
    else if(f == 0) std::cout << "child: fork ok\n";
    else std::cout << "parent: fork ok\n";
} catch(const std::bad_alloc& ba) {
	std::perror("\nmalloc");
}

