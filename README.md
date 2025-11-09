# 🎨 Shapes Drawer

## 📝 Overview

**Shapes Drawer** is a Qt-based desktop application that allows users to **create, manipulate, and visualize geometric shapes** on a canvas. Users can define triangles, squares, and connections between shapes. Each shape displays its name and can be filled with color. Commands can be entered interactively or executed from a script file.

---

## ✨ Features

- Interactive creation of triangles and squares via console commands  
- Batch execution of commands from script files  
- Shapes are filled with color and display their names  
- Connect shapes with lines dynamically  
- Smooth rendering using antialiasing for high-quality visuals  
- Log area displays executed commands and messages for debugging  

---

## 📂 Project Structure

ShapesDrawer/
├─ src/ # Source code
│ ├─ CommandProcessor.h/cpp
│ ├─ CommandConsole.h/cpp
│ ├─ CanvasWidget.h/cpp
│ ├─ Shape.h/cpp
│ ├─ Triangle.h/cpp
│ ├─ Square.h/cpp
│ ├─ ShapeFactory.h/cpp
│ └─ Connection.h/cpp
├─ scripts/ # Example command scripts
│ └─ ex1.txt
├─ ShapesDrawer.pro # Qt project file
└─ README.md


---

## 🚀 Quick Start (Build & Run)

1. Open **Qt Creator**  
2. Open the project file: `ShapesDrawer.pro`  
3. Configure your Desktop Qt kit  
4. Click **Build** (or press `Ctrl+B`)  
5. Click **Run** (or press `Ctrl+R`)  

The application window includes:  
- 🖼 Canvas area for shapes  
- ⌨️ Command console for entering commands  
- 📜 Log area showing executed commands  

---

## 🖋 Usage Instructions

### Creating Shapes via Console

Enter commands in the input field and press **Enter**:

create_triangle -name {t1} -coord_1 {2,3} -coord_2 {5,1} -coord_3 {4,6}
create_square -name {s1} -coord_1 {1,1} -coord_2 {3,1} -coord_3 {3,3} -coord_4 {1,3}
connect -object_name_1 {t1} -object_name_2 {s1}


**Notes:**  
- Use `{}` around names and coordinates  
- Each command must be **single-line**  
- Duplicate names are not allowed  

---

### Executing Script Files

Run multiple commands from a `.txt` file:

execute_file -file_path {scripts/ex1.txt}


- The script file should contain commands in the same format as console input  
- Logs display each command executed and any errors  

---

### Log Area

- Displays executed commands, messages, and errors in real-time  
- Helps debug issues and verify command execution  

---

## 📝 Example Script (`scripts/ex1.txt`)

create_triangle -name {t1} -coord_1 {2,3} -coord_2 {5,1} -coord_3 {4,6}
create_square -name {s1} -coord_1 {1,1} -coord_2 {3,1} -coord_3 {3,3} -coord_4 {1,3}
create_triangle -name {t2} -coord_1 {6,2} -coord_2 {8,1} -coord_3 {7,5}
connect -object_name_1 {t1} -object_name_2 {s1}
connect -object_name_1 {t2} -object_name_2 {s1}


- Creates **two triangles** and **one square**, connecting them  
- Coordinates avoid `(0,0)`  

---

## ⚠️ Known Issues / Limitations

- Shapes must have the correct number of coordinates (`triangle = 3`, `square = 4`)  
- Commands must be **single-line**  
- Shape colors are currently fixed  
- Performance may degrade with a very large number of shapes  
- Connections cannot yet be removed dynamically  

---

## 🎨 Customization

- Change **fill colors** in each shape’s `draw()` using `QPainter::setBrush()`  
- Shape names are drawn at the shape’s center  
- Smooth rendering is enabled via `QPainter::setRenderHint(QPainter::Antialiasing)`  

---
