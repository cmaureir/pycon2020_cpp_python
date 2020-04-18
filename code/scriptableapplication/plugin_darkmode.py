from PySide2.QtWidgets import QAction

isDarkMode = False

def changeMode():
    global isDarkMode
    text_edit = mainWindow.getTextEdit()

    if isDarkMode:
        mainWindow.setStyleSheet("background-color: #e8e8e7; color: black;")
        text_edit.setStyleSheet("background-color: white;")
        isDarkMode = False
    else:
        mainWindow.setStyleSheet("background-color: #31363b; color: white;")
        text_edit.setStyleSheet("background-color: gray;")
        isDarkMode = True

tool_bar = mainWindow.getToolBar()
action = QAction("Dark Mode")
tool_bar.addAction(action)
action.triggered.connect(changeMode)
