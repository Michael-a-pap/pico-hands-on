cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
include(pico_sdk_import.cmake)

project(my_project)

#initialize the RP-PICO SDK
pico_sdk_init()

#rest of the project
add_executable(usb_print
	usb_print.c
)

#Add the pico_stdlib library which aggregates commonly used features
target_link_libraries(usb_print pico_stdlib)

#You have to enable USB output and disable the UART for print
pico_enable_stdio_usb(usb_print 1)
pico_enable_stdio_uart(usb_print 0)

#Create map/bin/hex/uf2 file in addition to ELF
pico_add_extra_outputs(usb_print)
