#include <Starter/GS_Starter.h>

/**
 * Main function in GSVirtualMachine
 * @param argc Arguments count
 * @param argv Arguments array
 * @return Status number for operation system
 */
int main(GSInt argc, GSChar *argv[]) {
    return Starter::GS_Starter::start(argc, argv);
}
