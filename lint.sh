#!/bin/sh

echo "Linting source files"
find ./ \( -name "*.h" -o -name "*.cc" \) -type f | grep -v pb | xargs python cpplint.py --root=Algs-and-DataStructure-Implementations/ --header-guard-prefix="" --filter=-legal/copyright,-build/include,-whitespace/comments,-readability/streams,-runtime/references,-readability/casting,-runtime/arrays,-runtime/printf
