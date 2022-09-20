#!/usr/bin/env python
from http.server import SimpleHTTPRequestHandler
from socketserver import TCPServer


port = 8020
server_address = ('localhost', port)
print(f"Running on port {port}")
httpd = TCPServer(server_address, SimpleHTTPRequestHandler)
httpd.serve_forever()
