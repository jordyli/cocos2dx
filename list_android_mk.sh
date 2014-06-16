#!/bin/sh
dirs=("Classes" "MSLib" "sqlite")
for dir in ${dirs[@]}
do
    for file in `find $1/$dir -name '*.cpp' -or -name '*.c'`;
    do
        echo "$dir/$file \\" | sed -e "s/.*\/\//                   ..\/..\//g"
    done
done