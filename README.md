# Controllers
This is a simple project in C that creates 3 UDP clients and a server.
The general logic is that one controller client (driver) sends out a ping to the server.
The server then sends the ping to the other two clients (powerpack and cooling), which send a pong
back to the driver client.
# File structure
/
├── build
├── include
│   └── controllers.h
├── lib
│   ├── controllers
│   │   ├── CMakeLists.txt
│   │   ├── ping.c
│   │   └── pong.c
│   ├── server
│   │   ├── CMakeLists.txt
│   │   └── processing.c
│   └── shared
│       ├── CMakeLists.txt
│       ├── errors.c
│       └── socket_setup.c
└── src
    ├── CMakeLists.txt
    ├── cooling.c
    ├── drive.c
    ├── powerpack.c
    └── server.c
