# Created by Gabor Gyorgy (github: gygabor)
# Copyright: Green Fox Academy

from tkinter import *

class Display:
    def __init__(self):
        self.root = Tk()

    def create_canvas(self, **kwargs):
        self.canvas = Canvas(self.root, kwargs)
        self.canvas.pack()

    def create_line(self, *args, **kwargs):
        self.line = self.canvas.create_line(args, kwargs)
        return self.line

    def create_arc(self, *args, **kwargs):
        self.arc = self.canvas.create_arc(args, kwargs)
        return self.arc

    def create_image(self, *args, **kwargs):
        self.image = self.canvas.create_image(args, kwargs)
        return self.image

    def create_oval(self, *args, **kwargs):
        self.oval = self.canvas.create_oval(args, kwargs)
        return self.oval

    def create_polygon(self, *args, **kwargs):
        self.polygon = self.canvas.create_polygon(args, kwargs)
        return self.polygon

    def create_rectangle(self, *args, **kwargs):
        self.rectangle = self.canvas.create_rectangle(args, kwargs)
        return self.rectangle

    def create_text(self, *args, **kwargs):
        self.text = self.canvas.create_text(args, kwargs)
        return self.text

    def create_bitmap(self, *args, **kwargs):
        self.bitmap = self.canvas.create_bitmap(args, kwargs)
        return self.bitmap

    def create_window(self, *args, **kwargs):
        self.window = self.canvas.create_window(args, kwargs)
        return self.window

    def show(self):
        self.root.mainloop()

display = Display()

def create_canvas(**kwargs):
    display.create_canvas(**kwargs)

def create_line(*args, **kwargs):
    line = display.create_line(*args, **kwargs)
    return line

def create_arc(*args, **kwargs):
    arc = display.create_arc(*args, **kwargs)
    return arc

def create_image(*args, **kwargs):
    image = display.create_image(*args, **kwargs)
    return image

def create_oval(*args, **kwargs):
    oval = display.create_oval(*args, **kwargs)
    return oval

def create_polygon(*args, **kwargs):
    polygon = display.create_polygon(*args, **kwargs)
    return polygon

def create_rectangle(*args, **kwargs):
    rectangle = display.create_rectangle(*args, **kwargs)
    return rectangle

def create_text(*args, **kwargs):
    text = display.create_text(*args, **kwargs)
    return text

def create_bitmap(*args, **kwargs):
    bitmap = display.create_bitmap(*args, **kwargs)
    return bitmap

def create_window(*args, **kwargs):
    window = display.create_window(*args, **kwargs)
    return window

def show():
    display.show()
