#
# Borland C++ IDE generated makefile
#
.AUTODEPEND


#
# Borland C++ tools
#
IMPLIB  = Implib
BCCDOS  = Bcc +BccDos.cfg 
TLINK   = TLink
TLIB    = TLib
TASM    = Tasm
#
# IDE macros
#


#
# Options
#
IDE_LFLAGSDOS =  -LE:\BC45\LIB
IDE_BFLAGS = 
LLATDOS_proj0000dexe =  -c -Tde
RLATDOS_proj0000dexe =  -31 -k
BLATDOS_proj0000dexe = 
CNIEAT_proj0000dexe = -IE:\BC45\INCLUDE -D
LNIEAT_proj0000dexe = -x
LEAT_proj0000dexe = $(LLATDOS_proj0000dexe)
REAT_proj0000dexe = $(RLATDOS_proj0000dexe)
BEAT_proj0000dexe = $(BLATDOS_proj0000dexe)

#
# Dependency List
#
Dep_proj0000 = \
   proj0000.exe

proj0000 : BccDos.cfg $(Dep_proj0000)
  echo MakeNode 

Dep_proj0000dexe = \
   shapes.obj\
   vgadrv.obj\
   misc_io.obj\
   math3d.h\
   kbdio.obj\
   proj0000.obj

proj0000.exe : $(Dep_proj0000dexe)
  $(TLINK)   @&&|
 /v $(IDE_LFLAGSDOS) $(LEAT_proj0000dexe) $(LNIEAT_proj0000dexe) +
E:\BC45\LIB\c0s.obj+
shapes.obj+
vgadrv.obj+
misc_io.obj+
kbdio.obj+
proj0000.obj
$<,$*
E:\BC45\LIB\graphics.lib+
E:\BC45\LIB\bidss.lib+
E:\BC45\LIB\fp87.lib+
E:\BC45\LIB\maths.lib+
E:\BC45\LIB\cs.lib

|

shapes.obj :  shapes.cpp
  $(BCCDOS) -c @&&|
 $(CEAT_proj0000dexe) $(CNIEAT_proj0000dexe) -o$@ shapes.cpp
|

misc_io.obj :  misc_io.cpp
  $(BCCDOS) -c @&&|
 $(CEAT_proj0000dexe) $(CNIEAT_proj0000dexe) -o$@ misc_io.cpp
|

kbdio.obj :  kbdio.cpp
  $(BCCDOS) -c @&&|
 $(CEAT_proj0000dexe) $(CNIEAT_proj0000dexe) -o$@ kbdio.cpp
|

proj0000.obj :  proj0000.cpp
  $(BCCDOS) -c @&&|
 $(CEAT_proj0000dexe) $(CNIEAT_proj0000dexe) -o$@ proj0000.cpp
|

# Compiler configuration file
BccDos.cfg : 
   Copy &&|
-W-
-R
-v
-vi
-H
-H=proj0000.csm
-A-
-ff
-ms
-f287
| $@


