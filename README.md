# TUBES_ALSTRUKDAT-18
Anggota :
1. Vic Finnegan Dyell - 18220019
2. Vito Christian Samudra - 18220080
3. Muhammad Rakha Wiratama - 18220070
4. Arga Daniel Reynardo - 18220023
5. Aulia Fajriaturrakhmah - 18220024

Command untuk mengcompile:
1. driverskill :
 gcc listskill.c driverskill.c -o driverskill
2. drivermap
 gcc map.c drivermap.c -o drivermap
3. drivermesin
 gcc driver_mesin.c mesin_kata.c mesin_kar.c -o drivermesin
4. driverplayer
 gcc player.c driverplayer.c ../map_portal/map.c ../listskill/listskill.c -o driverplaye
5. driverstatus
 gcc status.c driverstatus.c ..\listskill\listskill.c ..\player\player.c  ..\map_portal\map.c -o driverstatu
6. driverundo
 gcc status.c undo.c  driverundo.c ..\listskill\listskill.c ..\player\player.c  ..\map_portal\map.c -o driverundo
7. main
 gcc main.c .\src\listskill\listskill.c .\src\mesin_kar_mesin_kata\mesin_kata.c .\src\mesin_kar_mesin_kata\mesin_kar.c .\src\map_portal\map.c .\src\status\status.c .\src\status\undo.c .\src\player\player.c -o main
