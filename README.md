# Error Handling
The error_handling.png file contains the diagram for a proposed error handling system architecture implementation.
The general idea is that upon receiving errors, the restarts, timeouts and disable commands are sent over a feedback
loop. The user restarts are sent level by level, depending on the desired restart. This diagram should provide ample
amount of error handling to catch any sort of issues with controllers.

# Controllers
This is a simple project in C that creates 3 UDP clients and a server.
The general logic is that one controller client (driver) sends out a ping to the server.
The server then sends the ping to the other two clients (powerpack and cooling), which send a pong
back to the driver client.
This project was made on Ubuntu and has not been tested on other operating systems. Due to certain
implementations being linux specific, this is likely not going to work on Windows.
## File structure
The general structure for the files follow such that the controllers are easily accessible and
adding new ones is intuitive. The "src" folder contains the primary controller declarations as
well as the server declaration.
The "lib" folder contains all of the libraries needed for the project to work. This is in turn split
into three other directories. The controllers library handles all of the possible code needed for
controllers, whereas the server directory pertains only for the server. This is because controllers
are in their simplest form, clients in this UDP server-client implementation. The shared directory
is for code that can be applied for both the server and the client (such as socket manipulation and error
handling).
## Usage
Run the server executable first ("src" directory within "build"), after which the three controller 
executables can be run in any order.
The server and drive time out after 10 seconds if they do not receive a datagram on their first readings.
