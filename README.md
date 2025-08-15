<a name="readme-top"></a>

<!-- GENERAL GAME INFO -->
<br />
<div align="center">

  <h2 align="center">Castlevania 1986</h2>

  <p align="center">
    You play as Simon Belmont, descendant of a legendary vampire hunters who goes into castle of dracula to him.
    <br />
    <strong>Original game : </strong>
    <a href="https://www.google.be/"><strong>General info »</strong></a>
    ·
    <a href="https://www.google.be/"><strong>Youtube video »<strong></a>
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

### What I will probably make as well:
* .. Camera movement

### What I plan to create if I have enough time left:
* .. Cutscenes
* .. Bossfight at the end

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
<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CLASS STRUCTURE -->
## Class structure 

Inheritance:
        Enemy
          | 
    -----------------------------------------------
    |              |          |           |       |
   Zombie         Dog       Bat         Fish    Boss

Has a reference to:
Player --> objects, enemies, PlayerHitboxes, Stairs, Cutscenes, Drops, Axes, AimCamera
Enemy --> objects, PlayerHitboxes, Drops
Chests --> PlayerAttacks, Drops

### Object composition 
If you applied object composition (optional) explain where and how:

Many Classes such as player and enemy have a reference to a vector of objects of different type in main.
They use it for different things (player uses reference to enemies to check if he is inside them).

### Inheritance 
Explain where you applied inheritance (mandatory):
All enemies share same mother class = "Enemy". Which is purely virtual

### ..

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- CHECKLIST -->
## Checklist

- [x] Accept / set up github project
- [ ] week 01 topics applied
    - [x] const keyword applied proactively (variables, functions,..)
    - [x] static keyword applied proactively (class variables, static functions,..)
    - [x] object composition (optional)
- [x] week 02 topics applied
- [x] week 03 topics applied
- [ ] week 04 topics applied
- [ ] week 05 topics applied
- [ ] week 06 topics applied
- [ ] week 07 topics applied
- [ ] week 08 topics applied
- [ ] week 09 topics applied (optional)
- [ ] week 10 topics applied (optional)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Your Name - Mykhailo Kudenko

Mykhailo.KUDENKO@student.howest.be

Project Link: https://github.com/HowestDAE/dae13-MykhailoKudenko

<p align="right">(<a href="#readme-top">back to top</a>)</p>


<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Use this space to list resources you find helpful and would like to give credit to. 

* [all textures](https://www.spriters-resource.com/nes/cv/)
* ..

<p align="right">(<a href="#readme-top">back to top</a>)</p>

