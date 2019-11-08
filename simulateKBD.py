import keyboard

import websocket
try:
    import thread
except ImportError:
    import _thread as thread
import time


def on_message(ws, message):
    if message == "center_click":
        keyboard.press_and_release('SpaceBar')
    print(message)


def on_error(ws, error):
    print(error)


def on_close(ws):
    print("### closed ###")


def on_open(ws):
    ws.send("Hello")


if __name__ == "__main__":
    websocket.enableTrace(True)
    ws = websocket.WebSocketApp("ws://192.168.31.74",
                                on_message=on_message,
                                on_error=on_error,
                                on_close=on_close)
    ws.on_open = on_open
    ws.run_forever()
