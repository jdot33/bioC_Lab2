#!/bin/bash
#Author: Joel Burkert
#02/08/2022

echo "Enter Concentration Level (00 or 05)"
read con_lvl

if [ "$con_lvl" == "00" ]; then
    cat ./ERP00/* > ./EEG_DATA/catted_input.dat
elif [ "$con_lvl" == "05" ]; then
    cat ./ERP05/* > ./EEG_DATA/catted_input.dat
fi

~/bin/stats_test ./EEG_DATA/catted_input.dat > ./EEG_DATA/catted_histogram.txt 

echo "file saved in ~/bioC_Lab2/Lab1/EEG_DATA/catted_histogram.txt"