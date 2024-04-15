// ======================================================================
// \title  Main.cpp
// \brief main program for the F' application. Intended for CLI-based systems (Linux, macOS)
//
// ======================================================================
// Used to access topology functions
#include <{{cookiecutter.deployment_name}}/Top/{{cookiecutter.deployment_name}}TopologyAc.hpp>
#include <{{cookiecutter.deployment_name}}/Top/{{cookiecutter.deployment_name}}Topology.hpp>

// Used for logging
#include <Os/Log.hpp>

// Instantiate a system logger that will handle Fw::Logger::logMsg calls
Os::Log logger;

const struct device *serial = DEVICE_DT_GET(DT_NODELABEL(cdc_acm_uart0));

/**
 * \brief execute the program
 *
 * This F´ program is designed to run using the Zephyr platform
 * 
 * @return: 0 on success, something else on failure
 */
int main()
{
    Fw::Logger::logMsg("Program Started\n");

    // Object for communicating state to the reference topology
    {{cookiecutter.deployment_name}}::TopologyState inputs;
    inputs.dev = serial;
    inputs.uartBaud = 115200;

    // Setup topology
    {{cookiecutter.deployment_name}}::setupTopology(inputs);

    while(true)
    {
        rateDriver.cycle();
        k_usleep(1);
    }

    return 0;
}
