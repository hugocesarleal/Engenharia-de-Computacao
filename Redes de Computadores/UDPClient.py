from socket import *
serverName = 'localhost'
serverPort = 12000
clientSocket = socket(AF_INET, SOCK_DGRAM)
message = input('Informe a palavra: ')
clientSocket.sendto(message.encode(),(serverName, serverPort))
modifiedMessage, serverAddres = clientSocket.recvfrom(2048)
print(modifiedMessage.decode())
clientSocket.close()