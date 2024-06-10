#include <iostream>
#include <unistd.h>  // Para fork()

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        std::cerr << "Fork fallido" << std::endl;
        return 1;
    } else if (pid == 0) {
        std::cout << "Hola desde el proceso hijo" << std::endl;
    } else {
        std::cout << "Hola desde el proceso padre" << std::endl;
    }

    return 0;
}