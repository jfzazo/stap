#!/bin/bash
# Jose Fernando Zazo 
function check_return {
	if [ $? -ne 0 ]
	  then
		return -1
	fi
}

if [ $# -eq 0 ]
  then
	echo ""	
	echo "Usage mode:"
	echo "-----------"
	echo "   ./debug.sh <driver_name> [time]"
	echo ""	
	echo "Where"
	echo "        - <driver_name> it may be a path to the driver actually"
	echo "        - [time] is optional and it is expressed in seconds"
	return -1
fi

#Remove path and extension
fullname=$(basename $1)
name="${fullname%.*}"

#Copy to the current linux sources so stap can obtain the debug symbols
# https://sourceware.org/bugzilla/show_bug.cgi?id=14596
# https://sourceware.org/bugzilla/show_bug.cgi?id=17073
cp $1 /lib/modules/`uname -r`/$name.ko; check_return
insmod $1; check_return

#Execute according the options
if [ $# -eq 1 ]
  then
	stap callgraph.stp $name
  else 
	stap callgraph.stp $name -c "sleep $2"
fi

#Clean the system
rmmod $name.ko
rm /lib/modules/`uname -r`/$name.ko
