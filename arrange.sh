#!/bin/bash
# Usage : sh arrange.sh ./Week{number}

mkdir -p $1/Combine;

for i in `ls -d $1/*`; do 
    for j in `ls -d $i/*`; do 
        for k in `ls -d $j/*`; do
            dirpath="$k";
            if [[ ${k} == *"Combine"* ]]; then
                continue;
            fi
            arr=(${dirpath//// });
            mkdir -p $1/Combine/${arr[3]};
            if [ ${arr[4]} != "input.txt" ]; then
                cp $k $1/Combine/${arr[3]}/"${arr[2]}_${arr[4]}";
            fi
        done
    done
done
