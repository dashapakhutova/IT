import paho.mqtt.client as mqtt_client
import random
import time
import serial as sr

UNIQUE_ID = 999
port = "COM8"
ser = sr.Serial(port, 9600)
        
### функция включения светодиода при падении значений датчика

### тестовая функция для записи на ардуино
def write(data):       
    print(f"recieved command {data}")
    if (data == "1"):
        ser.write("1".encode())
        time.sleep(2)
    if (data =="0"):
        ser.write("0".encode())
        time.sleep(2)

def on_message(client, data, message):
    data = float(message.payload.decode("utf-8"))
    topic = message.topic
    if data < 30.0:
        write('1')
    else:
        write('0')
    print(f"Topic: {topic}")
    print(f"Message: {data}")
    print()
    


broker = "broker.emqx.io"
client = mqtt_client.Client(f"lab_{random.randint(10000, 99999)}")
client.on_message = on_message

try:
    client.connect(broker)
except Exception:
    print("Failed to connect")
    ser.close()
    exit()    

client.loop_start()
print("Connected")    
 #задание 1
client.subscribe('esp8266-ACAC/range')

time.sleep(600)
client.disconnect()
client.loop_stop()
print("Stop communication")
