#!/bin/tcsh

#checking arguments
if ($# > 2 || $# < 2) then
    echo "ERROR 01: Wrong number of arguments given"
    echo "usage: ./rename.sh [file to be change] [filetypes you wan to to chenge into]"
    exit
endif

#saving args into variables
set before=$argv[1]
set after=$argv[2]

#search all files that match arg1
set filesBefore=`ls *.$before`

#echo $before + $after
#echo $filesBefore
#echo "------"

#iterate through each file
foreach file ($filesBefore)
    #check if file exists, if its readable and writable and then perform substiution
    if (-f $file) then
	#echo "$file is a file! " 
	if ((-w $file) && (-r $file)) then
	    #echo "and it is writable&readable!"
	    set sedscript="s/.$before/.$after/"
	    #echo $sedscript
	    set newfile=`echo $file | sed $sedscript`
	    mv $file $newfile
	    echo "$file has been renamed with $newfile"
	endif
    endif
end
