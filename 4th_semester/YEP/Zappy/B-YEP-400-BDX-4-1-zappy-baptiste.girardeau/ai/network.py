import socket
import select
import time

class ZappyAI:
    def __init__(self, host, port, team_name):
        self.host = host
        self.look = []
        self.inventory = {'food': 10, "linemate": 0, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0}
        self.port = port
        self.connected_number = 0
        self.life = 1260
        self.level = 1
        self.bouffe = 9
        self.command_queue = 0
        self.team_name = team_name
        self.gamemode = 0 #0 = survie ;1 = minerais; 2 = incantation
        self.socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    def connect(self):
        try:
            self.socket.connect((self.host, self.port))
            #print("Connexion au serveur réussie.")
            self.receive_message()
            self.socket.sendall(f"{self.team_name}\n".encode())
            self.receive_message()
        except socket.error as e:
            print(f"Erreur de connexion: {e}")

    def send_command(self, command):
        self.command_queue += 1
        #print(f"command sent {command}")
        try:
            self.socket.sendall(f"{command}\n".encode())
        except socket.error as e:
            print(f"Erreur d'envoi de commande: {e}")
            return None

    def receive_message(self):
        buffer = ""
        response = ""
        try:
            ready = select.select([self.socket], [], [], 0.1)
            while True:
                ready = select.select([self.socket], [], [], 0.1)
                if ready[0]:
                    response += self.socket.recv(1024).decode()
                else:
                    return response if response else None
        except socket.error as e:
            print(f"Erreur de réception de message: {e}")
            return None
