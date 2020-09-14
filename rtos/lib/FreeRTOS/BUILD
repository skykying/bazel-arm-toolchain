package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

filegroup(
    name = "rtos_srcs",
    srcs = glob([
        "*.c",
        "portable/GCC/ARM_CA7/*.c",
        "portable/MemMang/heap_1.c",
        "portable/GCC/ARM_CA7/*.S",
    ]),
)

cc_library(
    name = "rtos_hdrs",
    hdrs = glob(["include/*.h",]),
    strip_include_prefix = "include",
)


cc_library(
    name = "rtos_port_hdrs",
    hdrs = glob([
        "portable/GCC/ARM_CA7/*.h"
    ]),
    strip_include_prefix = "portable/GCC/ARM_CA7",
)

cc_library(
    name = "rtos_library",
    srcs = [":rtos_srcs",],
    hdrs = [
        ":rtos_hdrs",
        ":rtos_port_hdrs",
        "//rtos:rtos_config",
        "//rtos:api_hdrs",
        "//rtos:driver_hdrs",
        "//rtos:libs_hdrs",
        "//rtos:arch_hdrs",
    ],
    linkstatic = 1,
    copts = [
        "-mcpu=cortex-a7",
        "-mthumb",
    ],
    deps = [
        ":rtos_port_hdrs",
        ":rtos_hdrs",
        "//rtos:rtos_config",
        "//rtos:api_hdrs",
        "//rtos:driver_hdrs",
        "//rtos:libs_hdrs",
        "//rtos:arch_hdrs",
    ],
)
