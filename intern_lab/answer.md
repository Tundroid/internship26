Task 1

1)/home/Mabeltech/internship2026/intern_lab

2)the cd / takes you to the root directory and cd ~ takes you to the home directory

3)the cd . shows you your current directory while cd .. shows the parent directory

4)the absolute path starts with / and starts from the root directory e.g /home/Mabeltech/internship2026/intern_lab but the relative path start from the  current directory e.g internship2026/intern_lab

5)ls -a



Task 3

1.Total number of names
command: cat names.txt | wc -l
answer: 50

2.Number of unique names
command: sort names.txt | uniq | wc -l
answer: 43

3.Alphabetically sorted names.
command: sort -u names.txt >> answer.md
answer:

Albelt
Alex
Blessing
Boris
Chiara
Cynthia
Daniel
Elsie
Evania
Felix
Fred
Gaddiel
Henry
Iris
Jane
John
Joy
Kelly
Lambert
Mabel
Mary
Nancy
Obed
Patrice
Peace
Peter
Precious
Purity
Rachel
Rita 
Rose
Roy
Roy 
Sandra
Steve
Thierry
Tina
Tina 
Titus
Vanesa
Walex
Yvonne
Zita

4.Names beginning with A
command: cat names.txt | grep 'A' | sort | uniq 
answer:

Albelt
Alex

5.Names beginning with M.
command: cat names.txt | grep 'M' | sort | uniq
answer:

Mabel
Mary

6) The five most frequently occurring names.
command:
      2 Steve
      2 Peter
      2 Mabel
      2 Lambert
      2 Kelly
