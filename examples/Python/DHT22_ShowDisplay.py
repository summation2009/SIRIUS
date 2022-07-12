
from machine import Pin,I2C
import machine
import ssd1306
import dht    
import time
 
i2c = I2C(scl=Pin(22), sda=Pin(21))      #Init i2c
oled=ssd1306.SSD1306_I2C(128,64,i2c,0x3c) 
 
TH=Pin(27, Pin.IN)
d=dht.DHT22(TH)           
 
while True:
    d.measure()       #Measurement of temperature and humidity
    t=d.temperature() #Read Celsius temperature
    h=d.humidity()    #Read relative humidity
    print('Temperature=', t, 'C', 'Humidity=', h, '%')
    
    time.sleep(1)                #Delay of 1 second
    oled.fill(0)
    oled.text("Temperature",20,10)
    oled.text(str(t),40,20)
    oled.text("*C", 80,20)
    
    oled.text("Humidity",30,40)
    oled.text(str(h),40,55)
    oled.text("%", 80,55)
    
    oled.show()   
