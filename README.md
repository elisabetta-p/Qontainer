
## Table of contents
1. [Qontainer](#qontainer)
2. [Model](#model)
3. [View](#view)
    1. [Advanced search](#search)
    2. [Adding content](#add)
4. [Compiling and Executing](#compiling)
5. [Special Thanks](#thanks)

<a name="qontainer"></a>
# Qontainer 
`Qontainer` is a C++ application made for my object-oriented programming course at the University of Padua (*Università degli studi di Padova*). 
It consists in a class hierarchy that represents a simple reality of Multimedia Content, which concretises as Videos and Audios, which also derive in Songs, Podcasts, Films and Episodes. 
Realised within the Qt framework, the GUI is also completely written in C++. I've used a simplified version of the MVC design pattern, using only the Model and View version.
<a name="model">
## Model 
This comprehends the Multimedia Content hierarchy: the whole hierarchy is handled through a polymorphic template container, inside the class `container.h`. This class has the purpose of implementing a whole new container class without using the standard ones, such as `std::vector`or `std::list`. 

Another essential part of this project is the possibility of saving inside a `.txt` file through *serialization* and reading the content of the file and creating the objects inside the model through *deserialization*. This is made possible through the `database` class, which handles the loading and the saving of the/on file, calling the appropriate functions `serializza` and `deserializza`. The serialization function is virtual, so that it can behave differently according to the dynamic type of the element inside the `container`. 
<a name="view">
## View 
Despite working in the Qt framework, the view was not made using *Qt Designer*, but instead using C++, just like the model. 
Since there was the need to have multiple windows opening according to different events, the windows are handled by the `qontainer`  class, which opens and closes them as it is fit, deleting any garbage that might linger on the window. 
### The Main Window
![The Main Window](https://i.ibb.co/TvNxVsr/Main-Window.png)

On the Main Window you can see all the content you have inside your `container`, and you can either search something to see the details (through the *Ricerca Avanzata*) button, or add some new content (through the *Aggiungi contenuto* button).
<a name="search">
### Advanced Search
![Advanced Search](https://i.ibb.co/6wmmY5X/Ricerca-Avanzata.png)

The search can be done through the Title (*Titolo*), Author (*Autore*) and Year (*Anno di uscita*) fields. Is accepts both uppercase and lowercase characters. Once you've searched the content you need to find, you can either edit it (*modifica*), visualise its details (*visualizza*), or delete it (*elimina*).
The search also matches partial strings: for example, if you're searching for the *Iron Man* movies, you can just type in the Title field (*titolo*) "iron man", "iron", "i", or any letter or partial (but consecutive) string that is contained inside the result string "iron man".
![research result](https://i.ibb.co/pyXbKWS/Risultato-Ricerca.png)

If you need to visualise it (through the *Visualizza* button), you will see every field that object has:
![visualising the object](https://i.ibb.co/LND1qBm/Visualizzazione.png)

Or, you can also edit whichever field you need to edit (clicking on *Modifica* on the Advanced Search window):
![Modifying the contents](https://i.ibb.co/5YB7Npg/Modifica.png)
<a name="add">
### Adding content
If you need to add content to your application, you can do it through the *Aggiungi contenuto* button on the main window. You will be taken to this window, where you will need to specify the type of the content you need to insert. 
![Adding content](https://i.ibb.co/QbfLvtY/Aggiunta1.png)

Once you've chosen to add a Podcast, for example, the specific fields for podcasts will appear on screen:
![Adding a podcast](https://i.ibb.co/NSpXsyJ/Aggiunta2.png)

Afterwards, the new object gets created once you click on the *Aggiungi* button. This creates a `ContenutoMultimediale*`, with the dynamic type `podcast`, and inserts it into the `container`.
<a name="compiling">
## Compiling and executing
You will need to have `qmake` installed on your computer. The steps to compiling and executing this application are, once you're inside the folder where the project is located, respectively `qmake` and then `make`.
<a name="thanks">
### Special thanks:
To [Federico Rispo](https://github.com/federicorispo), for your patience and support! 
