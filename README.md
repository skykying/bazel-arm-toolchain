![Build](https://github.com/d-asnaghi/bazel-arm-none-eabi/workflows/Build/badge.svg)

# Bazel arm-none-eabi-gcc toolchain

The goal of the project is to illustrate how to use a custom ARM embedded toolchain with Bazel.

If this project was useful to you, give it a ⭐️ and I'll keep improving it!

You can follow the post [Bazel for ARM embedded toolchains](https://d-asnaghi.github.io/blog/post/embedded-bazel/) to get more details about this code.

## Use the toolchain from this repo.

To get started with the arm none eabi embedded toolchain,
just add the following to your `WORKSPACE` file

```python
# WORKSPACE

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
git_repository(
    name = "arm_none_eabi",
    remote = "https://github.com/d-asnaghi/bazel-arm-none-eabi.git",
    branch = "master",                  # For the latest version.
    # commit = "<choose a commit>",     # For canonical builds.
)

load("@arm_none_eabi//:deps.bzl", "arm_none_eabi_deps")
arm_none_eabi_deps()
```

And this to your `.bazelrc `
```bash
# .bazelrc

# Target arm-none-eabi toolchain for target builds.
build --crosstool_top=@arm_none_eabi//toolchain

# Target the default cpp compiler for host builds.
build --host_crosstool_top=@bazel_tools//tools/cpp:toolchain
```

Now Bazel will automatically use `arm-none-eabi-gcc` as a compiler

## Integrate the toolchain into your project.

Follow these steps if you want to test this repo before using it to integrate
the toolchain into your local project.

### Bazel

[Install Bazel](https://docs.bazel.build/versions/master/install.html) for your platform. Installing with a package manager is recommended, especially on windows where additional runtime components are needed.

- [Ubuntu Linux](https://docs.bazel.build/versions/master/install-ubuntu.html): `sudo apt install bazel`
- [macOS](https://docs.bazel.build/versions/master/install-os-x.html): `brew install bazel`
- [Windows](https://docs.bazel.build/versions/master/install-windows.html): `choco install bazel`

### Bazelisk

`bazelisk` is a user-friendly launcher for `bazel`. Follow the install instructions in the [Bazelisk repo](https://github.com/bazelbuild/bazelisk)

Use `bazelisk` as you would use `bazel`, this takes care of using the correct Bazel version for each project by using the [.bazelversion](./.bazelversion) file contained in each project.

### Clone the repo

```bash
git clone https://github.com/d-asnaghi/bazel-arm-none-eabi.git
```

### Build

Use this command to build any `project` target (a mock example is provided).

```bash
# build the project
bazelisk build project
```

This will take care of downloading the appropriate toolchain for your OS and compile all the source files specified by the target.

## Folder structure

```bash
├── WORKSPACE
│
├── project
│   ├── BUILD.bazel
│   └── /* SOURCE CODE */
│
└── toolchain
    ├── BUILD.bazel
    └── arm-none-eabi
        ├── darwin
        │   └── /* DARWIN TOOLCHAIN */
        ├── linux
        │   └── /* LINUX TOOLCHAIN  */
        └── ...
            └── /* OTHER TOOLCHAIN  */

```