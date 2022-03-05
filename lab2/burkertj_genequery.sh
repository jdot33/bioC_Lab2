#!/bin/bash
#this will search for a gene and output the file(s) that gene is in

echo "Enter the gene to find"
read gene


for i in {0..6}; do
    if [ $(grep -F -c "$gene" expressed_genes_$i.txt) -gt 0 ]
    then
        echo "expressed at time point $i"
    fi
    if [ $(grep -F -c "$gene" suppressed_genes_$i.txt) -gt 0 ]
    then
        echo "suppressed at time point $i"
    fi
    if [ $(grep -F -c "$gene" stationary_genes_$i.txt) -gt 0 ]
    then
        echo "stationary at time point $i"
    fi
done
