from kivy.app import App

from kivy.uix.button import Button


class FirstKivy(App):

    def build(self):

        return Button(text="Hello Shivam.....!")


FirstKivy().run()
