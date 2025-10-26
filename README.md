<h1 align="center">
	🌀 fract-ol
</h1>

<p align="center">
	<b><i>Exploring the beauty of mathematical fractals</i></b><br>
</p>

<h3 align="center">
	<a href="#-about">About</a>
	<span> · </span>
	<a href="#-features">Features</a>
	<span> · </span>
	<a href="#-usage">Usage</a>
	<span> · </span>
	<a href="#-controls">Controls</a>
</h3>

---

## 💡 About

> _This project is about creating graphically beautiful fractals._

Fract'ol is a 42 project that explores the world of fractals using the MinilibX graphics library. It renders mesmerizing mathematical patterns like the Mandelbrot set, Julia sets, and other fractal formations in real-time.

This project introduces students to:
- Computer graphics and pixel manipulation
- Complex numbers and mathematical functions
- Event handling and user interaction
- Performance optimization in graphical applications

## 🚀 Features

- **Multiple Fractal Types**: 
  - Mandelbrot set
  - Julia sets with dynamic parameters
  - Burning Ship fractal
  - Additional custom fractals
- **Interactive Controls**: Zoom, pan, and modify parameters in real-time
- **Smooth Rendering**: Optimized calculations for better performance
- **Color Cycling**: Dynamic color palettes and shifting
- **High Precision**: Support for deep zoom levels

## 🛠️ Usage

### Requirements

The project is written in C and uses the MinilibX library. It requires:

- **`gcc` compiler**
- **Make**
- **X11** (on Linux) for graphical window management
- **MinilibX** library (included in the project)

### Instructions

**1. Compiling the project**

To compile, run:

```shell
$ make
```

This will:
- Compile the custom `libft` library
- Set up MinilibX
- Build the fractol executable

**2. Running the program**

After compilation, run the executable with specific fractal parameters:

```shell
$ ./fractol mandelbrot
$ ./fractol julia -0.4 +0.6
$ ./fractol celtic
```

## 🎮 Controls

- **Mouse Scroll**: Zoom in/out at cursor position
- **Arrow Keys**: Pan around the fractal
- **Mouse Movement**: (For Julia sets) Modify parameters in real-time
- **C**: Change color palette
- **R**: Reset view to initial state
- **ESC**: Close the program

### Project Structure

- [`src/`](https://github.com/handyman0/42-fract-ol/tree/main/src) - Main source files
- [`include/`](https://github.com/handyman0/42-fract-ol/tree/main/include) - Header files
- [`libft/`](https://github.com/handyman0/42-fract-ol/tree/main/libft) - Custom Libft library with additional math functions
- [`minilibx-linux/`](https://github.com/handyman0/42-fract-ol/tree/main/minilibx-linux) - MinilibX graphics library for Linux
- [`Makefile`](https://github.com/handyman0/42-fract-ol/blob/main/Makefile) - Build configuration

### Technical Details

- Uses **complex number mathematics** for fractal calculations
- Implements **optimized iteration algorithms** for performance
- Features **smooth color gradients** and **dynamic coloring**
- Supports **real-time parameter modification**
- Includes **custom Libft extensions** for mathematical operations

---

<p align="center">
	<em>Discover the infinite complexity of finite mathematics</em>
</p>
