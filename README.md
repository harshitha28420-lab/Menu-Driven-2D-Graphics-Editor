# Interactive 2D Vector Graphics Workspace

A high-performance, hardware-accelerated 2D vector graphics application engineered using pure C (C99 standard) and linked with the Raylib graphics library. This system deploys a modern, GPU-backed OpenGL rendering pipeline operating at a smooth 60 FPS frame rate, serving as a robust alternative to obsolete, CPU-bound legacy headers like graphics.h.

Designed as a structured mini-project for Advanced C Programming with Generative AI, this software demonstrates low-level data encapsulation, synchronous state-machine event routing, and persistent memory block serialization.

---

## Technical Architecture Highlights

* Hardware-Accelerated Rasterization: Coordinates directly with OpenGL primitives via the Raylib framework to achieve instantaneous shape rendering without processing overhead on the host CPU.
* Input State-Machine Architecture: Utilizes a synchronized state-management system to switch operational modes smoothly based on real-time keyboard and mouse tracking registers.
* Direct Struct Serialization: Avoids intermediate parsing formats like text or JSON by executing raw binary stream transfers (using fwrite and fread) directly between system RAM and the local file system (my_art.dat).
* Real-Time Vertex Projection: Employs a dynamic temporary allocation buffer to display interactive structural guidelines on screen while dragging the mouse, committing the data coordinates to the primary canvas stack only on layout release.

---

## Workspace Layout and Key Assignments

The program interface displays user manual instructions via a top-docked menu layout and monitors active tool parameters through a real-time status tracker on the bottom margin.

| Shortcut Key | Action Type | System Behavior |
| :--- | :--- | :--- |
| 1 | Mode Switch | Set active drawing primitive to Line tool |
| 2 | Mode Switch | Set active drawing primitive to Circle tool |
| 3 | Mode Switch | Set active drawing primitive to Rectangle tool |
| 4 | Mode Switch | Set active drawing primitive to Ellipse tool |
| C | Setup Control | Toggle drawing stroke values sequentially (Red to Blue to Green) |
| S | File Operations | Stream full active matrix arrays to a permanent binary file format (my_art.dat) |
| L | File Operations | Read existing binary stream data to restore layout matrices back to the workspace |
| X | Grid Purge | Wipe workspace memory allocations completely (Reset Viewport) |
| Left Mouse Drag | Canvas Draw | Plot vector geometries interactively matching coordinate points |

---

## Structural Framework Architecture

The system manages dynamic graphic properties using sequential structure layers and explicit enumeration offsets to capture vector parameters inside a fixed static buffer.

// Strongly typed enum tracking selected tool states
typedef enum { 
    SHAPE_LINE, 
    SHAPE_CIRCLE, 
    SHAPE_RECT, 
    SHAPE_ELLIPSE 
} ShapeType;

// Encapsulated struct representing complete geometric identity
typedef struct {
    ShapeType type;  // Shape variant selector
    int x1, y1;      // Spatial coordinate origin
    int x2, y2;      // Terminal boundaries / radius metrics
    Color color;     // Direct RGB byte flag for GPU binding
} Shape;
