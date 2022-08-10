# Aplicatie-gestionarea-unui-hotel-MIHotels

Utilizare/Detalii aplicatie:
***pentru a trece de la un cont de utilizator la administrator (sau invers) se va reveni la meniul principal si se va alege optiunea dorita, A NU SE PARASI CONSOLA***

1. Meniu principal/utilizator/administrator
-se bazeaza pe alegeri numerice, vizibile in consola

2. Utilizator
-utilizator predefinit: username: ionutmihalii, parola: abcdefg
-se pot defini si alti utilizatori
-un utilizator poate efectua o serie de actiuni, vizibile in meniu utilizator(cautare unitati cazare, rezervare camera, vizualizare istoric rezervari, oferire recenzie...)

3. Administrator
-unicitatea lui este data de username: adminMIH si parola: cazare2022
-datorita constructiei meniului, poate efectua operatiuni de adaugare cazare, acceptare/refuzare cereri de rezerevare, vizualizare statistici

4. Unitati cazare
-predefinite: CasaDuca, HotelAro
-se pot defini unele noi din meniul de administrator
-camerele trimise spre aprobare vor fi marcate cu un mesaj special si rezervarea acestora este interzisa

5. Sistem de erori
-aplicatia va semnala eroare in 2 situatii:
	1. utilizatorul/administratorul gresesc parola/user-ul de mai mult de 3 ori
	2. cand se alege, in oricare dintre meniuri, o optiune numerica inexistenta
	3. cand se incearca rezervarea unei camere marcata ca fiind rezervata

6. Fisiere (.txt)
-detaliile aferente cazarilor predefinite si recenziile unei unitati de cazari sunt retinute in acest tip de fisiere
	1. numeUnitate.txt -detaliile cazarii
	2. numeUnitate_rez.txt -recenziile unitatii de cazare

7. Actiuni.log
-fisier in care se vor retine urmatoarele actiuni:
	1. EROARE-cand se capteaza o exceptie
	2. ALERTA-cand apare o problema la autentificare
	3. REZERVARE-cand se incearca rezervarea unei camere de 2 ori

8. Clase si functii
-MIHotels: clasa unde se intampla actiunile
-Cazare: clasa in care vor fi retinute unitatie de cazare si se vor determina o serie de proprietati(nr_rezervari, gradul de ocupare,...)
-LogareUtilizator: clasa in care vor fi retinuti utilizatorii, se va efectua verificarea existentei lor(in cazul crearii unuia nou) si se vor efectua toate actiunile specifice unui user
-Log: clasa pentru scrierea in fisierul Actiuni.log
-IException, AbsException, LogareException, MeniuException, RezervareException: clasele destinate generarii de erori in rularea aplicatiei
