<a name="readme-top"></a>

<!-- GENERAL GAME INFO -->
<br />
<div align="center">

  <h2 align="center">Castlevania 1986</h2>

  <p align="center">
    You play as Simon Belmont, descendant of a legendary vampire hunters who goes into castle of dracula to him.
    <br />
    <strong>Original game : </strong>
    <a href="https://en.wikipedia.org/wiki/Castlevania_(1986_video_game)"><strong>General info »</strong></a>
    ·
    <a href="https://www.youtube.com/watch?v=QenVVpI60Ok"><strong>Youtube video »<strong></a>
    <br />
    <br />
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
    </li>
    <li>
      <a href="#my-version">My version</a>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
    </li>
    <li><a href="#how-to-play">How To Play</a></li>
    <li><a href="#class-structure">Class structure</a></li>
    <li><a href="#checklist">Checklist</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

TODO: add screenshot 

Here's why:
TODO: describe why you chose this game 
* I liked the games mechanics
* I already knew about the Castlevania series

<p align="right">(<a href="#readme-top">back to top</a>)</p>


## My version

This section gives a clear and detailed overview of which parts of the original game I planned to make.

### The minimum I will most certainly develop:
* .. Player movement
* .. Enemy movement
* .. Map
* .. Weapon Pick ups
* .. Player animations
* .. Enemy animation
* .. Map teleports& stairs
* .. items Pick ups
* .. Bossfight at the end
* .. Camera movement
* .. Axe weapon

### What I will probably make as well:
* .. Knife Weapon

### What I plan to create if I have enough time left:
* .. Cutscenes
* .. Debug mode

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- GETTING STARTED -->
## Getting Started

You would need to open as a project in Visual Studio (preferably 2022);

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.
* Visual Studio 2022

### How to run the project

Explain which project (version) must be run.
* no exta steps, just open it in visual studio

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- HOW TO PLAY -->
## How to play

Use this space to show useful examples of how a game can be played. 
Additional screenshots and demos work well in this space. 

### Controls
* A/D, Left key/Right key - movement on the ground + movement on the stairs
* W/S, UP key/Down key movement on the stairs + getting on the stairs
* Space - jump
* Z - Whip attack
* X - Axe throw (doesn't work if you dont have hearts or axe)
* Enter to start the game from the menu
* F1 To enter debug mode (shows all hitboxes)
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CLASS STRUCTURE -->
## Class structure 

Inheritance:
        Entity
          | 
    -------------------------------------------------------------------------------
    |              |          |           |       	|           |   	  |
   Enemy         Palyer     Block     Projectile  	Chest    LevelTexture   CutsceneTrigger
    |  					  |		    |
    --------------------------------	  --------------    --------
    |     |       |         |      |	  |      |     |    |      |
   Bat  Zombie  Fishman    Dog   Boss    Whip   Knife Axe  Candle  FirePlace



### Object composition 
If you applied object composition (optional) explain where and how:

My Class GameManager Owns, and manages all other classes.
Many Classes like Bat, Zombie, Fishman, Dog, Boss, Player, own animations

### Inheritance 

As shown above many of my Classes share same parent called Entity, Also Many of them have their own derived classes(Enemy, Projectile ,Chest)

### ..

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CHECKLIST -->
## Checklist

- [x] Accept / set up github project
- [x] week 01 topics applied
    - [x] const keyword applied proactively (variables, functions,..)
    - [x] static keyword applied proactively (class variables, static functions,..)
    - [x] object composition (optional)
- [x] week 02 topics applied
- [x] week 03 topics applied
- [x] week 04 topics applied
- [x] week 05 topics applied
- [x] week 06 topics applied
- [ ] week 07 topics applied
- [ ] week 08 topics applied
- [ ] week 09 topics applied (optional)
- [ ] week 10 topics applied (optional)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Your Name - Mykhailo Kudenko

Mykhailo.KUDENKO@student.howest.be

Project Link: https://github.com/MykhailoKudenko/FINAL-GAME-RETAKE-Mykhailo-Kudenko.git

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Use this space to list resources you find helpful and would like to give credit to. 

* [all textures](https://www.spriters-resource.com/nes/cv/)
* ..

<p align="right">(<a href="#readme-top">back to top</a>)</p>

