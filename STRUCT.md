webserv/
├── include/
│   ├── Server.hpp
│   ├── Config.hpp
│   ├── HTTP/
│   │   ├── Request.hpp
│   │   ├── Response.hpp
│   │   ├── Parser.hpp
│   │   └── Status.hpp
│   ├── Utils/
│   │   ├── Logger.hpp
│   │   └── FileUtils.hpp
│   ├── CGI/
│   │   └── CGIHandler.hpp
│   └── (c/ or cpp/ if you want to separate)
├── src/
│   ├── main.cpp
│   ├── Server.cpp
│   ├── Config.cpp
│   ├── HTTP/
│   │   ├── Request.cpp
│   │   ├── Response.cpp
│   │   ├── Parser.cpp
│   │   └── Status.cpp
│   ├── Utils/
│   │   ├── Logger.cpp
│   │   └── FileUtils.cpp
│   ├── CGI/
│   │   └── CGIHandler.cpp
│   └── ...
├── config/
│   └── default.conf
├── www/
│   └── (static files)
├── Makefile
└── README.md