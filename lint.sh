#!/bin/sh

echo "Linting source files"
# find ./ \( -name "*.h" -o -name "*.cc" \) -type f | grep -v pb | xargs python cpplint.py --root=Algs-and-DataStructure-Implementations/ --header-guard-prefix=""  --filter=-legal/copyright,-build/include,-whitespace/comments,-readability/streams,-runtime/references,-readability/casting,-runtime/arrays,-runtime/printf

# find ./ \( -name "*.h" -o -name "*.cc" \) -type f | grep -v pb | xargs python cpplint.py --root=Algs-and-DataStructure-Implementations/  --linelength=150 --extensions=cc,h --filter=-legal/copyright,-build/include,-whitespace/comments,-readability/streams,-runtime/references,-readability/casting,-runtime/arrays,-runtime/printf ./*/*

find ./ \( -name "*.h" -o -name "*.cc" \) -type f | grep -v pb | xargs python cpplint.py --verbose=1 --linelength=150 --root=Algs-and-DataStructure-Implementations/ --extensions=h --headers=h --filter=-legal/copyright,-readability/check,+whitespace/todo ./*/*

# python cpplint.py
# --verbose=1
# --exclude_files=.*\.png, .*\.md
# --root=Algs-and-DataStructure-Implementations/
# --linelength=150
# --extensions=cc,h
# --headers=h
# --filter=-build/include,-whitespace/comments,-runtime/references,-readability/casting,-runtime/arrays,-runtime/printf ./*/*
# whitespace/todo

# python cpplint.py --verbose=1 --linelength=150 --root=Algs-and-DataStructure-Implementations/ --extensions=cc,h --headers=h --filter=-legal/copyright,-build/include,-whitespace/comments,-runtime/references,-readability/casting,-runtime/arrays,-runtime/printf ./*/*


# python cpplint.py --verbose=1 --linelength=150 --root=Algs-and-DataStructure-Implementations/ --extensions=cc,h --headers=h --filter=-whitespace/todo ./*/*
# python cpplint.py --verbose=1 --linelength=150 --root=Algs-and-DataStructure-Implementations/ --extensions=cc,h --headers=h --filter=-legal/copyright,-readability/check,+whitespace/todo ./*/*