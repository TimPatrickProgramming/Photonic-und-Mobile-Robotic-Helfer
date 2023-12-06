chcp 65001

set programmname=main_helfer_photonics_mobile_robotics
set programmname_2=geom
set programmname_3=mechanik
set programmname_4=elektronikAufgaben
set programmname_5=elektronikFormeln
set programmname_6=vector
set programmname_7=brechungsgesetz
set programmname_8=brechungsindex
set programmname_9=totalreflektion
set programmname_10=rezepte
set programmname_11=hangman

echo %~n1 wird Ausgeführt

REM chcp 1252

REM cd Documents\Studium_FHGR\1_Semester\Informatik_1\C_Programme

REM für float evtl "gcc -std=c99 %programmname%.c -o %programmname%" benutzen

gcc -std=c99 %programmname%.c %programmname_2%.c %programmname_3%.c %programmname_4%.c %programmname_5%.c %programmname_6%.c %programmname_7%.c %programmname_8%.c %programmname_9%.c %programmname_10%.c %programmname_11%.c -o %programmname% 

REM gcc %programmname%.c -o %programmname%

%programmname%

pause