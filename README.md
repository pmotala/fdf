# fdf - @WeThinkCode_
A simple application, that uses a graphics library, in this case [Minilibx][3], to display a wireframe from a given map.

### TOC
* [What is fdf?](#what-is-fdf)
* [What is in the Project?](#what-is-in-the-project)
* [The Mechanics behind it all?](#the-mechanics-behind-it-all)
* [How do I use the application?](#how-do-i-use-the-library)

### What is libft?
[fdf][1] is an individual project at [WeThinkCode_][2] that requires us to programme a little application that depends on a graphics library, to display wireframe diagrams of a given map. The programme could include advanced features like height differentiation, rotation, as well as perspective wireframe rendering and so forth. 

### What is in the Project?

Take a look in the [Project instructions][1]. The project has 2 sections:

1.  **Main Programme:** A basic programme that can display a 3D respresentation of a map, in the form of a wireframe.
2.  **Bonus Additions:** Adding more features at your discretion, including features like rotation, and color, zooming, and panning.

### The Mechanics behind it all?

The goal is to create a program called fdf from the source files, and use that to render out the maps I'm given.

To create that library, after downloading/cloning this project, **cd** into the project, copy all the files from the sub folders to the root directory and finally, call make:

	git clone https://github.com/pmotala/fdf
	cd fdf
	make

You should see a *fdf* file and some object files (.o).


Now to clean up (removing the .o files and the .c files from the root), call the function:
	make clean

### How do I use the programme?

You have to tell the file where your map file resides, for example:

`fdf maps/elem.fdf`

`fdf` is the name of programme you've compiled. 
`maps/elem.fdf` is the directory to your map file.

you can find map files here: [Maps][4].

Enjoy.

[1]: https://github.com/pmotala/fdf/blob/master/document/fdf.en.pdf "Libft PDF"
[2]: https://www.wethinkcode.co.za "WeThinkCode_"
[3]: https://github.com/dannywillems/minilibx "Minilibx"
[4]: https://github.com/pmotala/fdf/blob/master/maps/