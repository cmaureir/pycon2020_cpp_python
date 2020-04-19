import sys
import random
from PySide2.QtWidgets import QApplication, QPushButton, QWidget
from PySide2.QtCore import Slot

class MyWidget(QWidget):
    def __init__(self):
        QWidget.__init__(self)
        self.button = QPushButton("Click me!", self)
        self.button.clicked.connect(self.magic)

    @Slot()
    def magic(self):
        print("Clicked!")

if __name__ == "__main__":
    app = QApplication(sys.argv)

    widget = MyWidget()
    widget.resize(800, 600)
    widget.show()

    sys.exit(app.exec_())
