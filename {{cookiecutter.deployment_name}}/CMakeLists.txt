#####
# '{{cookiecutter.deployment_name}}' Deployment:
#
# This registers the '{{cookiecutter.deployment_name}}' deployment to the build system. 
# Custom components that have not been added at the project-level should be added to 
# the list below.
#
#####

# Deployment is only compatible with the Zephyr platform
restrict_platforms(Zephyr)

###
# Topology and Components
###
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Top/")

# Add custom components to this specific deployment here
# add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/MyComponent/")


set(SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/Stub.cpp")
set(MOD_DEPS ${FPRIME_CURRENT_MODULE}/Top app)

register_fprime_deployment()

FILE(GLOB app_sources Main.cpp)
target_sources(app PRIVATE ${app_sources})
target_link_libraries(app PRIVATE {{cookiecutter.deployment_name}}_Top)
