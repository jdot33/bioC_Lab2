#!/bin/bash
#Author: Joel Burkert
#02/08/2022

echo "Enter Concentration Level (00 or 05)"
read con_lvl

exit_state="exit_state ${?}"
dirname="Directory_does_not_exist"

if [ "$con_lvl" == "00" ]; then
    dirname="ERP00"
elif [ "$con_lvl" == "05" ]; then
    dirname="ERP05"  
fi

if [ ! -d ./$dirname ]; then
    echo "Invalid Input - directory does not exist"
else    
    echo "Calculating correlation on ./$dirname"
    file_count=$(ls ./$dirname | wc -l) # without the $() this prints the wc -l
    #echo $file_count

    #remove old file so we dont have a huge file with old and new data.
    if [ -e ./EEG_DATA/conc_corr_$dirname.csv ];
    then
        rm ./EEG_DATA/conc_corr_$dirname.csv
    fi

    if [ "$con_lvl" == "00" ]; then
        #for some reason {0..$file_count} does not work... ask about this!!!!
        for i in {1..59}
        do
            this_file=./$dirname/$dirname$i.txt
            let next_index=$i+1
            next_file=./$dirname/$dirname$next_index.txt
            corr_results=$(~/bin/corr_test $this_file $next_file)

            echo "epoch_${i}_vs_epoch_$next_index, $corr_results"  >> ./EEG_DATA/conc_corr_$dirname.csv

        done
    elif [ "$con_lvl" == "05" ]; then
        #for some reason {0..$file_count} does not work... ask about this!!!!
        for i in {1..59}
        do
            this_file=./$dirname/$dirname.$i.txt
            let next_index=$i+1
            next_file=./$dirname/$dirname.$next_index.txt
            corr_results=$(~/bin/corr_test $this_file $next_file)

            echo "epoch_${i}_vs_epoch_$next_index, $corr_results"  >> ./EEG_DATA/conc_corr_$dirname.csv

        done  
    fi
fi
