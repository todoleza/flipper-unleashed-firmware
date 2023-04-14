#!/bin/sh

source scripts/toolchain/fbtenv.sh
set -ex

dirname=$(ls -d  dist/f7-C/f7-update-*/)
dirname=$(basename "$dirname")

scripts/storage.py send dist/f7-C/$dirname /ext/update/$dirname
