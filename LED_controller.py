import pyfirmata

comport='COM7'

board=pyfirmata.Arduino(comport)

led_pins = {
    1: board.get_pin('d:8:o'),
    2: board.get_pin('d:9:o'),
    3: board.get_pin('d:10:o'),
    4: board.get_pin('d:11:o'),
    5: board.get_pin('d:12:o'),
    6: board.get_pin('d:13:o')
}


def light_LED(hand_sign_id):
    led_pins[hand_sign_id].write(1)


