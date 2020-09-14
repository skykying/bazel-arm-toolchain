# project/BUILD.bazel

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

filegroup(
    name = "rtos",
    srcs = [
        ":api_library",
        ":arch_library",
    ],
)

cc_library(
    name = "api_library",
    srcs = ["api/*.c"],
    hdrs = ["include/api/*.h"],
    copts = [
        "-mcpu=cortex-a53",
        "-mthumb",
    ],
    includes = ["include"],
)

cc_library(
    name = "arch_library",
    srcs = ["arch/*.c"],
    hdrs = ["include/arch/*.h"],
    copts = [
        "-mcpu=cortex-a53",
        "-mthumb",
    ],
    includes = ["include"],
)
