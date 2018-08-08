import asyncio
import websockets
from datetime import datetime,timedelta
from random import randint
import sys
Maxint=31
Minint=18
temperature =25
#correctvalue = []
ac_temperature= 25

url='ws://flyops:flypassWORD@jarvis.qaperf.flytxt.com:31987/websocketPath'
testurl='ws://flyops:flypassWORD@node1.qaperf.flytxt.com:8090/websocketPath'

async def hello():
    async with websockets.connect(url) as websocket:
        for i in range(int(sys.argv[1])):       
            sensor_value=randint(Minint,Maxint+1)
            ac_room_no=1
            datee = datetime.now().strftime("%d-%m-%Y")
            #airconditionerid=916633854924
            airconditionerid=911000400000
            
            #airconditionerid=916763697266
            
            name = str(sensor_value)+","+str(ac_room_no)+","+str(datee)+","+str(airconditionerid)
            print(name)
            await asyncio.sleep(int(sys.argv[2]))
            await websocket.send(name)
       

asyncio.get_event_loop().run_until_complete(hello())
