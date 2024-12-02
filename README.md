<div align="center">
	<picture>
		<img src="https://github.com/ayogun/42-project-badges/blob/main/badges/minitalkm.png" alt="42 The Minitalk school project with a bonus badge.">
	</picture>  

<p><a href="https://www.hive.fi/en/curriculum">Hive (42 School Network)</a> core curriculum project</p>  
<h1>Minitalk</h1>  

</div>

Minitalk is a C programming project that uses Unix signals to create a basic messaging system. It allows two programs, a "client" and a "server," to communicate by sending messages encoded as signals.

<div align="center">
	<picture>
		<img src="https://github.com/ipersids/ipersids/blob/main/assets/hive-repo-assets/minitalk.gif" alt="42 The Minitalk school project gif." height="480">
	</picture> 
</div>

#### Core topics:
1. Signals in Unix systems.  
	* Using functions from `<signal.h>`: `sigemptyset()`, `sigaddset()`, `sigaction()`, `getpid()`, and `kill()`.  
	* Working with `pause()` and `usleep()` for handling signals effectively.   
2. Bitwise operations.  
	* Encoding and decoding integers or characters into binary for signal-based messaging.   
3. Dynamic memory management.  
	* Using `malloc()` and `free()` to create a dynamic buffer.  
	* Implementing a custom version of `realloc()` for efficient memory management.   
4. Error handling.  
	* Designing an error-handling system that uses `exit()` with unique error codes for various potential issues.  
	* Ensures the program is easier to debug.  

### Project structure:
```css
hive-core-minitalk/
│
├── ft-printf/					# Static library for custom ft_printf()
│   ├── ft_printf.c
│   ├── ft_printf.h
│   ├── ...
│   └── Makefile
│
├── include/minitalk_utils.h	# Header files
├── src/
│   ├── minitalk-utils/			# Support functions
│   │   ├── ft_realloc.c
│   │   ├── kill_safe.c
│   │   └── sigaction_init.c
│   ├── client.c				# Client programme
│   └── server.c				# Server programme
│
├── test/
│   └── minitalk_test.sh		# Bash script for testuing
│
├── Makefile					# Building project tool
├── README.md					# Instractions
├── .gitignore
└── LICENSE
```  
### Where to start
1. Clone the repository.
```bash
git clone https://github.com/ipersids/hive-core-minitalk.git
cd hive-core-minitalk
```

2. **Build the programme.**    
Use the Makefile to compile the source files, the `libftprintf` static library, and create the "server" and "client" executables.  
```sh
make all
```
Other commands:   
- `make all` will build static library and two programmes `./server` and `./client`.  
- `make clean` will remove all .o' files from the directory.  
- `make fclean` will remove all .o' and executable files.  
- `make re` will trigger the `fclean` command and rebuild the mandatory functions.  

3. Run the Server.  
Execute the `./server` file in the terminal. It will display the `PID` number, which is required to use the `./client` program.  

4. Run the Client.
Open a second terminal and run the `./client` program as follows:  
```bash
./client <PID> <message>
# Example: ./client 89456 Hello!
```
______________  
Developed by **Julia Persidskaia**.    
[LinkedIn](https://www.linkedin.com/in/iuliia-persidskaia/)  