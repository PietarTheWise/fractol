<h1 align="center">
  <br>
    Fractol
  <br>
</h1>

<div align="center">
  <a href="https://www.youtube.com/watch?v=A3QtEFnUzeQ" target="_blank" rel="noopener noreferrer">
    <img src="/fractol_gif.gif"></img>
  </a>
</div>

<h3 align="center">Dive into the exciting world of 2D fractals</h3>

<p align="center">
  <a href="#what-it-does">What it does?</a> •
  <a href="#how-to-use">How To Use</a> •
  <a href="#disclaimer">Disclaimer</a>
</p>


## What it does?

* Takes in a parameter on the command line from the following 'mandlebrot set' 'julia set' 'burning ship'.
* You can move forward and backwards into the fractal with your mouse scroll.
* The program zooms into the focus point of your mouse
* With key <kbd>i</kbd> you can enable multithreading, which makes the window bigger and the program faster
* By pressing the key <kbd>p</kbd> you can toggle between different fractals.
* With the multithreading on, there are more fractal options to toggle from.

## How To Use

To clone and run this application, you'll need [Git](https://git-scm.com) and a gcc compiler installed on your computer. Also you need miniLibX graphics library which to my knowledge doesn't work on windows. This has been tested only on MacOs and linux. Run the following commands on the command line:

```bash
# Clone this repository
$ git clone https://github.com/PietarTheWise/fractol.git
# Build the program by typing:
$ make
# in command line

#then run:
$ ./fractol

#note: the program will give you options on the command line, so for instance if you want mandlebrot set type:

$ ./fractol 'mandlebrot set'

```

## DISCLAIMER

<p>
This is a project from the 42 school, which is a school that utilizes peer to peer learning.
We're only given a document that gives us the details of the assignment, therefore each implementation
is unique. Each assignment is tested for crashes and other bugs thoroughly by other peers. Apart from some exceptions, existing
libraries are banned, these projects utilize our self made version of libc called libft.
</p>
