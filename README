This project contains several subdirectories with useful examples of how system tap can help you while debugging your own device drivers.



### Callgraph

Under callgraph a simple timer (that prints a counter) is implemented. Once the driver is compiled (make under the driver path), 

	$ cd stap/callgraph/driver/
	stap/callgraph/driver$ make

	There is only need to execute the debug script, to see the output

	stap/callgraph# bash ./debug.sh birria.ko 20
	     0 swapper/5(0): -> my_timer_callback
	    16 swapper/5(0): <- 0xffffffff810744f6
	     0 swapper/5(0): -> my_timer_callback
	    18 swapper/5(0): <- 0xffffffff810744f6


Adapt it for your necessities



### Printing



Same example as the callgraph one. In this occasion the value of an internal variable to the driver is shown to the user.
The changes just affect to the Systemtap script.

### Variables

This small script prints the arguments and local variables of a system function using $$locals and $$vars.

### Signal


Simple design that checks for sending signals. Other probes are checked_ignored (whose return value indicates if it was accepted or nor, $return).

### Timer 


A simple timer using jiffies. One may consider about taking us or ns as the time unit. In that case

	· timer_s
	· timer_ms
	· timer_us
	· timer_ns
	· timer_hz (number of probes per second)

can do the trick. In this example we just print the hour and the timer frequenzy (how often an interrupt from the timer is received).

### iTop 


This version guess the total number of cores in the current machine. Once this is done, it monitorizes a particular process and in which CPU it is running (check for possible scheduling failures).

	stap itop.stp -g -c "sleep 10"  4961
	stap itop.stp -g -c "sleep 10"  firefox

	Output:

	Process: firefox              TID: 4961
	cpu	samples
	value |-------------------------------------------------- count
	    0 |                                                   0
	    1 |                                                   0
	    2 |@                                                  1
	    3 |                                                   0
	    4 |                                                   0


	Total...................................:    10 secs.
	ncpu=0x8
