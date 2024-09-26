cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
include(../../pico_sdk_import.cmake)

project(my_project)

#initialize the RP-PICO SDK
pico_sdk_init()

#rest of the project
add_executable(simple_adc
	simple_adc.c
)

#Add the pico_stdlib library which aggregates commonly used features
target_link_libraries(simple_adc pico_stdlib hardware_adc)

#You have to enable USB output and disable the UART for print
pico_enable_stdio_usb(simple_adc 1)
pico_enable_stdio_uart(simple_adc 0)

#Create map/bin/hex/uf2 file in addition to ELF
pico_add_extra_outputs(simple_adc)
