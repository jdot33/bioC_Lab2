#!/bin/bash
#this will calibrate and cluster microarray data

echo "Enter the number of genes to analyze (0-6118)"
read gene_num


for i in {0..6}; do
    ./preprocessing_exe microarray/red_$i.dat microarray/red_background_$i.dat microarray/green_$i.dat microarray/green_background_$i.dat log_ratio_$i.dat $gene_num
    cp log_ratio_$i.dat log_ratio_input.dat 
    ./kmeans_exe $gene_num stationary_genes_$i.txt suppressed_genes_$i.txt expressed_genes_$i.txt > ./summary_$i.txt

    wc -l < suppressed_genes_$i.txt >> ./summary_$i.txt
    wc -l < stationary_genes_$i.txt >> ./summary_$i.txt
    wc -l < expressed_genes_$i.txt >> ./summary_$i.txt
done

