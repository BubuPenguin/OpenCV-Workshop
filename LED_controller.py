import serial
import time

# Define the serial port name (replace with your Arduino's port)

serial_port = "COM6"  # Windows example
# serial_port = "/dev/ttyUSB0"  # Linux example

# Open the serial port (adjust baud rate as needed)
ser = serial.Serial(serial_port, baudrate=9600, timeout=1)

def light_LED(hand_sign_id):
    # Create a command to set the digital pin based on hand_sign_id
    command = f"DigitalWrite {hand_sign_id+2}\n"
    ser.write(command.encode())  # Encode and send the command