# WORKSPACE
workspace(name = "arm_none_eabi")

load(":deps.bzl", "arm_none_eabi_deps")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository", "new_git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive", "http_file")
load("@rules_foreign_cc//:workspace_definitions.bzl", "rules_foreign_cc_dependencies")

arm_none_eabi_deps()
rules_foreign_cc_dependencies()