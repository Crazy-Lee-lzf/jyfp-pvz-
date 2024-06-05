# Microsoft Developer Studio Project File - Name="2220151888" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=2220151888 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "2220151888.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "2220151888.mak" CFG="2220151888 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "2220151888 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "2220151888 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "2220151888 - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "2220151888 - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "2220151888 - Win32 Release"
# Name "2220151888 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\2220151888.cpp
# End Source File
# Begin Source File

SOURCE=.\2220151888.rc
# End Source File
# Begin Source File

SOURCE=.\2220151888Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DIY.cpp
# End Source File
# Begin Source File

SOURCE=.\Login.cpp
# End Source File
# Begin Source File

SOURCE=.\PictureEx.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\2220151888.h
# End Source File
# Begin Source File

SOURCE=.\2220151888Dlg.h
# End Source File
# Begin Source File

SOURCE=.\DIY.h
# End Source File
# Begin Source File

SOURCE=.\Login.h
# End Source File
# Begin Source File

SOURCE=.\PictureEx.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\2220151888.ico
# End Source File
# Begin Source File

SOURCE=.\res\2220151888.rc2
# End Source File
# Begin Source File

SOURCE=.\res\bg.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Blover1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Cabbage-pult1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Cactus1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Cattail1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Cherry_Bomb1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Chomper1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Cob_Cannon1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Coffee_Bean1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Doom-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\DP.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Explode-o-nut1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Flower_Pot1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Fume-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Garlic1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Gatling_Pea1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Gloom-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=".\res\Gold-Magnet1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Grave_Buster1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\House.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Hypno-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=".\res\Ice-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Imitater1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Jalapeno1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Kernel-pult1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Lily_Pad1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Magnet-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Marigold1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Melon-pult1.jpg"
# End Source File
# Begin Source File

SOURCE=".\res\OIP-C.jpg"
# End Source File
# Begin Source File

SOURCE=".\res\Pea-Shooter1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Plantern1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Potato_Mine1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Puff-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Pumpkin1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Repeater1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Scaredy-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=".\res\Sea-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Snow_Pea1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Spikerock1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Spikeweed1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Split_Pea1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Squash1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Starfruit1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Sun-shroom1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Sunflower1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Tall-nut1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Tangle_Kelp1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Threepeater1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Torchwood1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Twin_Sunflower1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Umbrella_Leaf1.jpg
# End Source File
# Begin Source File

SOURCE=".\res\Wall-nut1.jpg"
# End Source File
# Begin Source File

SOURCE=.\res\Winter_Melon1.jpg
# End Source File
# Begin Source File

SOURCE=.\res\XTC.jpg
# End Source File
# Begin Source File

SOURCE=.\res\YG.jpg
# End Source File
# Begin Source File

SOURCE=.\res\Zombie.gif
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
