# u5d - Ultima V Decompilation Project

## Introduction

This is an ongoing decompilation project of Ultima V: Warriors of Destiny.

Inspired by [u4-decompiled](https://github.com/ergonomy-joe/u4-decompiled), I started this project as a personal challenge to better understand the original game and its codebase.

## Goals

- Create a functionally equivalent version of the original game that can run on modern platforms.

- Match as much of the original code (v1.16 for MS-DOS) as possible.

Since the original linker (an unknown version of PLINK86) has not been found, perfect binary matching is currently impossible. Instead, the project focuses on assembly-level semantic matching.

When necessary, disassemblies from other platforms such as FM-TOWNS are also used as references.

## Current Status

### Matching Progress

- `ULTIMA.EXE`: approximately 60% matched
- `*.OVL`: approximately 60% matched

### Playability

The game can boot and is partially playable using the original data files. However, many major and minor bugs still remain, and the game is not yet completable from start to finish.

## Building

### Windows Target

Open `u5win/u5win.slnx` with Visual Studio 2026 and build the solution.

### MS-DOS Target (DJGPP)

Run `make` on a machine with DJGPP installed.

Depending on the environment, you may need to adjust the `CROSS_CC_PREFIX` value in the `Makefile`.

### MS-DOS Target (Original Toolchain)

Run `src\build.bat` on a machine or virtual machine with Microsoft C 5.1 installed.

The compiler installation path is `C:\MSC51`.

Note: executable linking is currently not possible. This target is used only for disassembly matching.