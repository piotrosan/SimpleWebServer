# SimpleWebServer
C++ simple server working on port 8080

# For tests
echo -e "YourSerialData" | socat - TCP4:localhost:8080
netstat -tuln | grep :8080
