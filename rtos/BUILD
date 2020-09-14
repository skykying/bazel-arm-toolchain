# project/BUILD.bazel

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

filegroup(
    name = "rtos",
    srcs = [
        ":api_library",
        ":arch_arm_library",
    ],
)

filegroup(
    name = "api_srcs",
    srcs = glob(["api/*.c",]),
)

cc_library(
    name = "api_hdrs",
    hdrs = glob(["include/api/*.h",]),
    strip_include_prefix = "include/api",
)

cc_library(
    name = "utils_hdrs",
    hdrs = glob(["include/lib/utils/print.h",]),
    strip_include_prefix = "include/lib",
)

cc_library(
    name = "clk_hdrs",
    hdrs = glob(["include/drivers/clocksource/gt.h",]),
    strip_include_prefix = "include/drivers",
)

cc_library(
    name = "api_library",
    srcs =  [":api_srcs",],
    hdrs =  [":api_hdrs",":utils_hdrs",":clk_hdrs",],
    copts = [
        "-mcpu=cortex-a53",
        "-mthumb",
    ],
    strip_include_prefix = "include/api",
    deps = [
            ":api_hdrs",
            ":utils_hdrs",
            ":clk_hdrs",
            ],
)


cc_library(
    name = "arch_arm_library",
    srcs = glob(["arch/arm/*.s",]),
    hdrs = glob(["include/arch/arm/*.s",]),
    linkstatic = 1,
    strip_include_prefix = "include/arch",
)