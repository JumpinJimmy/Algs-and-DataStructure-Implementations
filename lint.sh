#!/bin/bash
#James Robert DeVore
#######################################################################
#                   L I N T  S O U R C E  F I L E S
#                     using Google's cpplinty.py
#----------------------------------------------------------------------
# TODO(jdevore): expand this script to allow for user specified filters & file types for lint
#----------------------------------------------------------------------
# python cpplint.py
# --verbose=1
# --exclude_files=.*\.png, .*\.md
# --root=Algs-and-DataStructure-Implementations/
# --linelength=150
# --extensions=cc
# --headers=h
# --filter=-legal/copyright,-readability/check,+whitespace/todo,-build/header_guard
#----------------------------------------------------------------------
UB_STYLE_SPAD=$(printf '%0.1s' "-"{1..30})
UB_STYLE_LPAD=$(printf '%0.1s' "-"{1..60})

function print_banner() {
    echo -e "\n${UB_STYLE_LPAD}\n${UB_STYLE_SPAD}"
    echo -e $1
    echo -e "${UB_STYLE_SPAD}\n${UB_STYLE_LPAD}"
}

#######################################################################
#         R U N  C P P L I N T  w/  F I L E S  V I A  `find`
#----------------------------------------------------------------------
function run_lint() {
    print_banner "Linting Source Files"
    find ./ \( -name "*.h" -o -name "*.cc" \) -type f | grep -v pb | xargs python cpplint.py --verbose=1 --linelength=150 --root=Algs-and-DataStructure-Implementations/ --extensions=cc --headers=h --filter=-legal/copyright,-readability/check,+whitespace/todo,-build/header_guard ./*/*
}


# Start
run_lint
