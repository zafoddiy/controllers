# Controllers
This is a simple project in C that creates 3 UDP clients and a server.
The general logic is that one controller client (driver) sends out a ping to the server.
The server then sends the ping to the other two clients (powerpack and cooling), which send a pong
back to the driver client.
