import serial
import time
from Adafruit_IO import *
from tinydb import TinyDB, Query
from private import aio_key

db = TinyDB('data_buffer.json')
#table = db.table('table_name', cache_size=30)
db.purge()
query = Query()
aio = Client(aio_key)

def get_current_data():
    data = db.all()
    max = 0
    for item in data:
        if item['time'] > max:
            max = item['time']
    print("Max time = ", max)
    print("# items = ",len(data))
    # delete all items where time <= max
    db.remove(query.time <= max)
    return data

# microbit = serial.Serial('COM5', 115200)
microbit = serial.Serial('COM5', 9600)
id = 1;
flag = 1;
while True:
    if flag == 10:
        flag = 1
    while (microbit.inWaiting()==0):
        pass
    value = microbit.readline()
    if not value:
        continue
    value = value.decode("utf-8") # convert from bytes to string type
    value = value.strip()
    id, value = id, value
    if len(value) == 0 or value == "0":
        continue    
    record = {"time": int(time.time()), "id":id, "value":value}
    print("push", record)
    db.insert(record)
    id = id + 1
    flag = flag + 1

    if flag == 10:
        data = get_current_data()
        for item in data:
            aio.send('testing_waterlevel3', item['value'])
            print(item)
    # time.sleep(15)

   
