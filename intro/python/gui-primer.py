## Learning Objectives:
##
## A GUI is a big piece of code that interacts with the screen.
##
## This program is a very small example of how one can use the Python language to interact with a screen.
## Now you can imagine that a GUI can be written in Python.

import tkinter as tk

window = tk.Tk()

message = tk.Label(window, text="Hello and Welcome to CS Summer Challenge 2020!")
message.pack()

# TODO add a button?

window.mainloop()
