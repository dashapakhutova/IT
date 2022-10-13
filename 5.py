import serial
import time
lenghts = {'s':3, 'u':0,'d':0,'l':0}
values = []

def get_connection(port):
    ser = serial.Serial(port,timeout=1)
    return ser

def send(ser,message, mesg_len):
    ser.write(message)
    time.sleep(0.005)
    if mesg_len != 0:
        data = ser.readline()
        result = data.decode()
        result = result.strip()
        return (result)
    
    
if __name__ == '__main__':
    ser = get_connection("COM12")
    while True:
        print("Ввести одну из команд: \nu - включить светодиод, \nd - выключить светодиод, \nauto - включение/выключение светодиода по показаниям датчика, \nrec - включить поточную передачу данных с датчика, \nl - регулировать яркость светодиода в зависимости от освещенности")      
        inp = input()
        if inp == "u" or inp == "d" :
            send(ser, inp.encode(), lenghts[inp])
        elif inp == "auto":
            while True:
                com = "s"
                val = send(ser, com.encode(), lenghts[com])
                if val:
                    val = int(val)
                    print(val)
                    if val > 200:
                        send(ser, 'u'.encode(), 0)
                    else:
                        send(ser, 'd'.encode(), 0)
        elif inp == "rec":
            while True: 
                com = "s"
                val = send(ser, com.encode(), lenghts[com])
                if val:
                    values.append(val)
                print (values)
        elif inp == "l":
            while True: 
                com = "s"
                val = send(ser, com.encode(), lenghts[com])
                if val:
                    val = int(val)
                    print(val)
                    if val > 900:
                        send(ser, 'l'.encode(), 0)
                        brightness = send(ser, '50'.encode(),1)
                    else:
                        send(ser, 'l'.encode(), 0)
                        brightness = send(ser, '255'.encode(),1)
        else:
            print("Неизваестная команда")