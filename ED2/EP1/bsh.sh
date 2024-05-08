#!/bin/bash

LC_NUMERIC=en_US.UTF-8

N=100
OUTPUT=AVG

if [ $# -ge 1 ]; then
    N=$1
fi

if [ $# == 2 ]; then
    OUTPUT=$2
fi

FILES=("arq.txt")
MODES=("VO" "ABB" "TR" "ARB" "A23")
TIPES=("F" "L" "SR" "VD")
TMP=$(mktemp)

echo "" > results.txt


for file in "${FILES[@]}"; do
    for mode in "${MODES[@]}"; do
        for tipe in "${TIPES[@]}"; do
            echo -n "${mode} ${file}: "
            ./bsh2.sh ${mode} ${file} ${tipe} ${N} ${OUTPUT}
            done
    done
    echo ""
done

rm "${TMP}"