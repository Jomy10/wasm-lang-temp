#!/usr/bin/env sh

# Since Cargo workspaces seems to interfere with linking the s-expr-formatter library, 
# I have written this shell script to test all projects

set -e

cd tree-sitter && ./test.sh
cd ../compiler && cargo test
cd s-expr-formatter && swift test
cd ..
