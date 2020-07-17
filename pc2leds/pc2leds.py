import sys

import serial
from serial.tools import list_ports


def led_manage():
    s = serial.Serial(port_to_use, 9600)
    while True:
        action = input('Choose 0 to LOW and 1 to HIGH the led: ')
        if action not in ['0', '1']:
            break
        s.write(str.encode(action))


if __name__ == '__main__':
    print('Available ports:')
    serial_ports = [x.device for x in list_ports.comports()]
    for port in serial_ports:
        if sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
            if 'USB' not in port:
                continue
        print('  ' + port)
    port_to_use = input('Type port used by Arduino (full path): ').strip()

    if port_to_use not in serial_ports:
        print('Wrong port, make sure to use any of the port from the previous list (e.g.: /dev/ttyUSB0)')
        exit(1)

    led_manage()
