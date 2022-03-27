#!/usr/bin/env bash

# Since Cargo workspaces seems to interfere with linking the s-expr-formatter library, 
# I have written this shell script to test all projects

set -e

cd lexer && cargo test
cd ../parser && cargo test
cd ../codegen && cargo test
cd s-expr-formatter && swift test
cd ../../cli && cargo test
