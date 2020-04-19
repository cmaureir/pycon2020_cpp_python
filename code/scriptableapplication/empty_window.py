import sys
from PySide2.QtWidgets import QMainWindow, QApplication, QLabel

# Qt Application
app = QApplication()

# Empty window
window = QMainWindow()

# Adding a label
label = QLabel("Hello", window)

# Showing the window
window.show()

# Start application loop
sys.exit(app.exec_())
