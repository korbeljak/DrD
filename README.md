# DrD project

The DrD project is a FOSS implementation of a Czech tabletop role-playing game
(RPG) "Dračí doupě" in 1.6 rule version in C/C++.

It aims to be open for any contributions and inviting to DrD community.

Planned features:
  * An extensible C engine as a library [Ongoing]
  * Platform independence [Ongoing]
  * GUI (vxWidgets) [To Do]
  * Android support (possible iOS support) [To Do]
  * DiceCMD dice rolling command line utility for Linux, Windows and macOS [macOS abstraction layer devs needed!]
  * Leveraging of existing, standard human readable or editable formats [To Do]
  * Extensibility for the GM (custom races, classes, items) [To Do]
  * NPC manager [To Do]
  * PC manager with xlsx imports/exports [To Do]
  * Encounter generator (NPCs) [To Do]
  * Basic and Advanced Combat resolver [To Do]
  * Map editor [To Do]
  * LAN/Internet connection for the whole group management and play or remote
    sessions [To Do]
  * Switchable Basic, Advanced and Expert rulebook support. [To Do]
  * FATE rules extensions [To Do]
  
Current DrD uses CMake as a build system abstraction.

## DiceCMD

To build DrD's DiceCMD utility with extensive mathematic support:

 1. Point CMake's Source Directory to /projects/dicecmd
 2. Run configure & generate
 3. Run make or any other method you like (MS VS Project, etc.)
 4. run ./dicecmd -r "1d6+2" get result of 3-9


```

```
