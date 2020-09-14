package(default_visibility = ["//visibility:public"])

load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "xen_library",
    srcs = glob(["*.c",]),
    hdrs = [
        "//rtos:arch_hdrs",
    ],
    linkstatic = 1,
    copts = [
        "-mcpu=cortex-a53",
        "-mthumb",
    ],
    deps = [
        "//rtos:arch_hdrs",
    ],
)