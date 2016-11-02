#!/bin/tcsh


if ($# != 1) then
    echo "ERROR01: wrong number of arguments"
    exit
endif

set threshold=$argv[1]
set percent=`df | grep 'sda1' | awk '{print $5}' | tr -d %`
echo $threshold and $percent
if ($percent > $threshold) then
    
   echo "the number you gave as an argument is less than the percent"

endif

