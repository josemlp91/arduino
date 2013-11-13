#!/usr/bin/python -tt
#
# Copyright (C) 2010-2012, Fabian Affolter <fabian@affolter-engineering.ch>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

import os
import sys
import serial
import time
import signal
from gi.repository import Gtk

PORT = 'COM7'
SPEED = 9600

class UI:
    def __init__(self):
        self.builder = Gtk.Builder()
        self.builder.add_from_file(os.path.join(os.getcwd(), 'data/arduino-led.ui'))
        self.window = self.builder.get_object('dialog1')
        self.aboutdialog = self.builder.get_object('aboutdialog1')
        self.bt_exit = self.builder.get_object('bt_exit')
        self.tbt_state = self.builder.get_object('tbt_state')
        self.imagemenuitem5 = self.builder.get_object('imagemenuitem5')
        self.imagemenuitem10 = self.builder.get_object('imagemenuitem10')

        self.window.connect('delete-event', self.quit)
        self.tbt_state.connect('toggled', self.on_button_toggled)
        self.bt_exit.connect('clicked', self.quit)
        self.imagemenuitem5.connect('activate', self.quit)
        self.imagemenuitem10.connect('activate', self.show_aboutdialog)
        self.window.show()

    def on_button_toggled(self, button):
        if button.get_active():
            state = ['1', 'on']
            button.set_label(state[1].upper())
            self.send_command(state[0])
        else:
            state = ['0', 'off']
            button.set_label(state[1].upper())
            self.send_command(state[0])
        #print 'Button was turned: ', state[1]

    def show_aboutdialog(self, *args):
        self.aboutdialog.run()
        self.aboutdialog.hide()

    def quit(self, *args):
        Gtk.main_quit()

    def send_command(self, val):
        connection = serial.Serial( PORT, 
                                    SPEED,
                                    timeout=0,
                                    stopbits=serial.STOPBITS_TWO
                                    )
        connection.write(val)
        connection.close()

if __name__ == '__main__':
    signal.signal(signal.SIGINT, signal.SIG_DFL)
    signal.signal(signal.SIGTERM, signal.SIG_DFL)
    ui = UI()
    Gtk.main()
